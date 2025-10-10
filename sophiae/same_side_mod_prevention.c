enum home_mods_t {
  LEFT_GUI = 1,
  LEFT_ALT = 2,
  LEFT_CTL = 4,
  RIGHT_GUI = 16,
  RIGHT_ALT = 32,
  RIGHT_CTL = 64,
};

uint8_t home_mods = 0;

uint8_t keycodes[4] = {0, 0, 0, 0};

void add_keycode(uint8_t keycode) {
  if (keycodes[0] == 0) {
    keycodes[0] = keycode;
  } else if (keycodes[1] == 0) {
    keycodes[1] = keycode;
  } else if (keycodes[2] == 0) {
    keycodes[2] = keycode;
  } else {
    keycodes[3] = keycode;
  }
}

void remove_keycode(uint8_t keycode) {
  if (keycodes[0] == keycode) {
    keycodes[0] = keycodes[1];
    keycodes[1] = keycodes[2];
    keycodes[2] = keycodes[3];
    keycodes[3] = 0;
  } else if (keycodes[1] == keycode) {
    keycodes[1] = keycodes[2];
    keycodes[2] = keycodes[3];
    keycodes[3] = 0;
  } else if (keycodes[2] == keycode) {
    keycodes[2] = keycodes[3];
    keycodes[3] = 0;
  } else if (keycodes[3] == keycode) {
    keycodes[3] = 0;
  }
}

void send_and_clear_held_keycodes(void) {
  if (keycodes[0] != 0) tap_code(keycodes[0]);
  if (keycodes[1] != 0) tap_code(keycodes[1]);
  if (keycodes[2] != 0) tap_code(keycodes[2]);
  if (keycodes[3] != 0) tap_code(keycodes[3]);
  keycodes[0] = 0;
  keycodes[1] = 0;
  keycodes[2] = 0;
  keycodes[3] = 0;
}

bool key_on_same_side_as_active_mod(bool is_left) {
  return home_mods != 0 && (is_left ? home_mods < 8 : home_mods > 8);
}

bool is_mod_tap_hold(uint16_t keycode, keyrecord_t *record) {
  return IS_QK_MOD_TAP(keycode) && record->tap.count == 0;
}

uint8_t get_mod(uint16_t keycode, bool is_left) {
  uint8_t mod = (uint8_t) ((keycode >> 8) & 0x0F);
  switch (mod) {
    case MOD_LGUI:
      return is_left ? LEFT_GUI : RIGHT_GUI;
    case MOD_LALT:
      return is_left ? LEFT_ALT : RIGHT_ALT;
    case MOD_LCTL:
      return is_left ? LEFT_CTL : RIGHT_CTL;
    default:
      return 0;
  }
}

void unregister_if_opposite_side_mod_not_on(uint8_t left_mod, uint8_t right_mod, uint8_t mod, bool is_left) {
  bool left_mod_on = (home_mods & left_mod) > 0;
  bool right_mod_on = (home_mods & right_mod) > 0;
  bool opposite_side_mod_on = (is_left && right_mod_on) || (!is_left && left_mod_on);
  if (!opposite_side_mod_on) unregister_mods(mod);
}

bool on_key_down(uint16_t keycode, keyrecord_t *record, bool is_left) {
  if (is_mod_tap_hold(keycode, record)) {
    uint8_t key = (uint8_t) (keycode & 0xFF);
    uint8_t mod = get_mod(keycode, is_left);
    if (home_mods == 0 || key_on_same_side_as_active_mod(is_left)) {
      dprintf("Mod-tap held on same side as mod on or no mods on\n");
      add_keycode(key);
      home_mods |= mod;
      return true;
    } else {
      dprintf("Mod-tap held with opposite side mod on\n");
      register_code(key);
      return false;
    }
  } else { //basic or tap on mod-tap
    if (key_on_same_side_as_active_mod(is_left)) {
      dprintf("Key with same side mod\n");
      // Key on tapped is on same side as active mod
      // Disable tapped key side mods if opposite side equivalent not on
      unregister_if_opposite_side_mod_not_on(LEFT_GUI, RIGHT_GUI, MOD_LGUI, is_left);
      unregister_if_opposite_side_mod_not_on(LEFT_ALT, RIGHT_ALT, MOD_LALT, is_left);
      unregister_if_opposite_side_mod_not_on(LEFT_CTL, RIGHT_CTL, MOD_LCTL, is_left);
      // Give some time for apps to register mods being unregistered
      wait_ms(DYNAMIC_MACRO_DELAY);
      // Send corresponding taps
      send_and_clear_held_keycodes();
    }
    return true;
  }
}

bool on_key_up(uint16_t keycode, keyrecord_t *record, bool is_left) {
  if (is_mod_tap_hold(keycode, record)) {
    uint8_t key = (uint8_t) (keycode & 0xFF);
    uint8_t mod = get_mod(keycode, is_left);
    if (home_mods == 0 || key_on_same_side_as_active_mod(is_left)) {
      remove_keycode(key);
      home_mods &= ~mod;
    } else {
      unregister_code(key);
      return false;
    }
  }
  return true;
}

bool prevent_same_side_mods(uint16_t keycode, keyrecord_t *record) {
  bool not_on_base_layer = get_top_layer(layer_state) != BASE;
  bool not_basic_or_mod_tap = !IS_QK_BASIC(keycode) && !IS_QK_MOD_TAP(keycode); // Key is not basic key or a mod tap do nothing
  bool in_thumb_cluster = record->event.key.row == 5 || record->event.key.row == 11; // Key is on thumb clusters
  bool is_left = record->event.key.row < MATRIX_ROWS / 2;
  bool key_down = record->event.pressed == 1;
  dprintf("not_basic_or_mod_tap %d, in_thumb_cluster %d, key_down %d, is_mod_tap_hold %d, row %d, col %d, is_left %d\n", not_basic_or_mod_tap, in_thumb_cluster, key_down, IS_QK_MOD_TAP(keycode) && record->tap.count == 0, record->event.key.row, record->event.key.col, is_left);
  if (not_on_base_layer || not_basic_or_mod_tap || in_thumb_cluster) return true;

  if (key_down) {
    return on_key_down(keycode, record, is_left);
  } else {
    return on_key_up(keycode, record, is_left);
  }
}