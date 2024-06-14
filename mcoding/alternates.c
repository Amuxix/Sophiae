uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  //remove defaults I don't want
  if ((mods & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) {
    switch (keycode) {
      case KC_F: return KC_NO;
      case KC_D: return KC_NO;
      case KC_N: return KC_NO;
      case KC_A: return KC_NO;
      case KC_O: return KC_NO;
    }
  }

  if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_Y: return LCTL(KC_Z);
      case KC_Z: return LCTL(KC_Y);
    }
  }

  bool shifted = (mods & MOD_MASK_SHIFT);
  switch (keycode) {
    case KC_TAB:
    if (shifted) {
      return KC_TAB;
    } else {
      return LSFT(KC_TAB);
    }
    case KC_D: return KC_NO;
    case KC_N: return KC_NO;
    case KC_A: return KC_NO;
    case KC_O: return KC_NO;
    //SFBs
    case KC_QUOTE: return KC_A;
    case KC_Y: return KC_S;
    case KC_U: return KC_I;
    case KC_R: return KC_L;
    case KC_P: return KC_T;
  }
  return KC_TRNS;
}