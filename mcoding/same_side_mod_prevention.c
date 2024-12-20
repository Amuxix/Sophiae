uint16_t MAX = 65535;
uint16_t LEFT_GUI_T = 65535;
uint16_t LEFT_ALT_T = 65535;
uint16_t LEFT_CTL_T = 65535;
uint16_t LEFT_SFT_T = 65535;
uint16_t RIGHT_GUI_T = 65535;
uint16_t RIGHT_ALT_T = 65535;
uint16_t RIGHT_CTL_T = 65535;
uint16_t RIGHT_SFT_T = 65535;

uint16_t min(uint16_t a, uint16_t b) {
  return a < b ? a : b;
}

void tap_code_in_timely_order(uint16_t gui_t, uint16_t alt_t, uint16_t ctl_t, uint16_t sft_t, uint16_t gui_kc, uint16_t alt_kc, uint16_t ctl_kc, uint16_t sft_kc) {
  uint16_t min_time = min(min(gui_t, alt_t), min(ctl_t, sft_t));
  if (min_time == MAX) {
    return;
  } else if (min_time == gui_t) {
    tap_code(gui_kc);
    tap_code_in_timely_order(MAX, alt_t, ctl_t, sft_t, gui_kc, alt_kc, ctl_kc, sft_t);
  } else if (min_time == alt_t) {
    tap_code(alt_kc);
    tap_code_in_timely_order(gui_t, MAX, ctl_t, sft_t, gui_kc, alt_kc, ctl_kc, sft_t);
  } else if (min_time == ctl_t) {
    tap_code(ctl_kc);
    tap_code_in_timely_order(gui_t, alt_t, MAX, sft_t, gui_kc, alt_kc, ctl_kc, sft_t);
  } else if (min_time == sft_t) {
    tap_code(sft_kc);
    tap_code_in_timely_order(gui_t, alt_t, ctl_t, MAX, gui_kc, alt_kc, ctl_kc, sft_t);
  }
  return;
}

bool prevent_same_side_mods(uint16_t keycode, keyrecord_t *record) {
  bool is_left_side_key = record->event.key.row <= MATRIX_ROWS / 2;
  bool is_hold = !is_tap(record_press_type(record));
  uint8_t mods = get_mods() | get_weak_mods();

  bool left_mod_on = LEFT_GUI_T < MAX || LEFT_ALT_T < MAX || LEFT_CTL_T < MAX || LEFT_SFT_T < MAX;
  bool right_mod_on = RIGHT_GUI_T < MAX || RIGHT_ALT_T < MAX || RIGHT_CTL_T < MAX || RIGHT_SFT_T < MAX;

  if (is_hold) {
    switch (keycode) {
      case LGUI_T(KC_R):
        LEFT_GUI_T = record->event.time;
        break;
      case LALT_T(KC_S):
        LEFT_ALT_T = record->event.time;
        break;
      case LCTL_T(KC_T):
        LEFT_CTL_T = record->event.time;
        break;
      case LSFT_T(KC_BSPC):
        LEFT_SFT_T = record->event.time;
        break;
      case LGUI_T(KC_I):
        RIGHT_GUI_T = record->event.time;
        break;
      case LALT_T(KC_E):
        RIGHT_ALT_T = record->event.time;
        break;
      case LCTL_T(KC_N):
        RIGHT_CTL_T = record->event.time;
        break;
      case RSFT_T(KC_SPACE):
        RIGHT_SFT_T = record->event.time;
        break;
      default:
        break;
    }
  } else {
    if (is_left_side_key) {
      if (left_mod_on) {
        // Key on left side of kb was tapped and a mod from left side is active
        // Disable left side mods
        if (LEFT_GUI_T < MAX && RIGHT_GUI_T == MAX) unregister_mods(MOD_LGUI);
        if (LEFT_ALT_T < MAX && RIGHT_ALT_T == MAX) unregister_mods(MOD_LALT);
        if (LEFT_CTL_T < MAX && RIGHT_CTL_T == MAX) unregister_mods(MOD_LCTL);
        if (LEFT_SFT_T < MAX && RIGHT_SFT_T == MAX) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        tap_code_in_timely_order(LEFT_GUI_T, LEFT_ALT_T, LEFT_CTL_T, LEFT_SFT_T, KC_R, KC_S, KC_T, KC_BSPC);
        LEFT_GUI_T = MAX;
        LEFT_ALT_T = MAX;
        LEFT_CTL_T = MAX;
        LEFT_SFT_T = MAX;
      }
    } else {
      if (right_mod_on) {
        // Key on right side of kb was tapped and a mod from right side is active
        // Disable right side mods
        if (RIGHT_GUI_T < MAX && LEFT_GUI_T == MAX) unregister_mods(MOD_LGUI);
        if (RIGHT_ALT_T < MAX && LEFT_ALT_T == MAX) unregister_mods(MOD_LALT);
        if (RIGHT_CTL_T < MAX && LEFT_CTL_T == MAX) unregister_mods(MOD_LCTL);
        if (RIGHT_SFT_T < MAX && LEFT_SFT_T == MAX) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        tap_code_in_timely_order(RIGHT_GUI_T, RIGHT_ALT_T, RIGHT_CTL_T, RIGHT_SFT_T, KC_I, KC_E, KC_N, KC_SPACE);
        RIGHT_GUI_T = MAX;
        RIGHT_ALT_T = MAX;
        RIGHT_CTL_T = MAX;
        RIGHT_SFT_T = MAX;
      }
    }
  }

  // reset times
  if ((mods & MOD_LGUI) == 0) {
    LEFT_GUI_T = MAX;
    RIGHT_GUI_T = MAX;
  }
  if ((mods & MOD_LALT) == 0) {
    LEFT_ALT_T = MAX;
    RIGHT_ALT_T = MAX;
  }
  if ((mods & MOD_LCTL) == 0) {
    LEFT_CTL_T = MAX;
    RIGHT_CTL_T = MAX;
  }
  if ((mods & MOD_LSFT) == 0) {
    LEFT_SFT_T = MAX;
    RIGHT_SFT_T = MAX;
  }

  return true;
}