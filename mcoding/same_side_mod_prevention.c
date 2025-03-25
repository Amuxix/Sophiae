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

void send_and_clear_keycodes(void) {
  if (keycodes[0] != 0) register_code(keycodes[0]);
  if (keycodes[1] != 0) register_code(keycodes[1]);
  if (keycodes[2] != 0) register_code(keycodes[2]);
  if (keycodes[3] != 0) register_code(keycodes[3]);
  keycodes[0] = 0;
  keycodes[1] = 0;
  keycodes[2] = 0;
  keycodes[3] = 0;
}

//Mod from left side of keyboard, not right mod key
bool left_mod_on(void) {
  return home_mods > 0 && home_mods < 8;
}

bool right_mod_on(void) {
  return home_mods > 8;
}

bool handle_key_down(bool is_left, uint8_t key, uint8_t mod) {
  if ((is_left && right_mod_on()) || (!is_left && left_mod_on())) {
    register_code(key);
    return false;
  } else {
    add_keycode(key);
    home_mods |= mod;
    return true;
  }
}

bool is_modtap_hold(uint16_t keycode, keyrecord_t *record) {
  return record->tap.count == 0;
}

uint8_t get_mod(uint16_t keycode, bool is_left_side_key) {
  uint8_t mod = (uint8_t) ((keycode >> 8) & 0x0F);
  switch (mod) {
    case MOD_LGUI:
      return is_left_side_key ? LEFT_GUI : RIGHT_GUI;
    case MOD_LALT:
      return is_left_side_key ? LEFT_ALT : RIGHT_ALT;
    case MOD_LCTL:
      return is_left_side_key ? LEFT_CTL : RIGHT_CTL;
  }
}

bool on_key_down(uint16_t keycode, keyrecord_t *record) {
  bool is_left_side_key = record->event.key.row < MATRIX_ROWS / 2;

  if (is_modtap_hold(keycode, record)) {
    uint8_t key = (uint8_t) (keycode & 0xFF);
    uint8_t mod = get_mod(keycode, is_left_side_key);
    return handle_key_down(is_left_side_key, key, mod);
  } else { //basic or tap on mod-tap
    if (is_left_side_key) {
      if (left_mod_on()) {
        // Key on left side of kb was tapped and a mod from left side is active
        // Disable left side mods if right side equivalent not on
        if ((home_mods & LEFT_GUI) > 0 && (home_mods & RIGHT_GUI) == 0) unregister_mods(MOD_LGUI);
        if ((home_mods & LEFT_ALT) > 0 && (home_mods & RIGHT_ALT) == 0) unregister_mods(MOD_LALT);
        if ((home_mods & LEFT_CTL) > 0 && (home_mods & RIGHT_CTL) == 0) unregister_mods(MOD_LCTL);
        // Give some time for apps to register mods being unregistered
        wait_ms(DYNAMIC_MACRO_DELAY);
        // Send corresponding taps
        send_and_clear_keycodes();
      }
    } else {
      if (right_mod_on()) {
        // Key on right side of kb was tapped and a mod from right side is active
        // Disable right side mods if left side equivalent not on
        if ((home_mods & RIGHT_GUI) > 0 && (home_mods & LEFT_GUI) == 0) unregister_mods(MOD_LGUI);
        if ((home_mods & RIGHT_ALT) > 0 && (home_mods & LEFT_ALT) == 0) unregister_mods(MOD_LALT);
        if ((home_mods & RIGHT_CTL) > 0 && (home_mods & LEFT_CTL) == 0) unregister_mods(MOD_LCTL);
        // Give some time for apps to register mods being unregistered
        wait_ms(DYNAMIC_MACRO_DELAY);
        // Send corresponding taps
        send_and_clear_keycodes();
      }
    }
  }
  return true;
}

bool on_key_up(uint16_t keycode, keyrecord_t *record) {
  bool is_left_side_key = record->event.key.row < MATRIX_ROWS / 2;
  if (is_modtap_hold(keycode, record)) {
    uint8_t key = (uint8_t) (keycode & 0xFF);
    uint8_t mod = get_mod(keycode, is_left_side_key);
    remove_keycode(key);
    home_mods &= ~mod;
  }
  return true;
}

bool prevent_same_side_mods(uint16_t keycode, keyrecord_t *record) {
  if (!IS_QK_BASIC(keycode) && !IS_QK_MOD_TAP(keycode)) return true; // Nothing special to do here
  if (record->event.key.col == 5 || record->event.key.col == 11) return true; // Ignore the thumb clusters

  if (record->event.pressed == 1) {
    return on_key_down(keycode, record);
  } else {
    return on_key_up(keycode, record);
  }
}