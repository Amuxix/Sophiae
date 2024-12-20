bool LEFT_GUI = false;
bool LEFT_ALT = false;
bool LEFT_CTL = false;
bool LEFT_SFT = false;
bool RIGHT_GUI = false;
bool RIGHT_ALT = false;
bool RIGHT_CTL = false;
bool RIGHT_SFT = false;


bool prevent_same_side_mods(uint16_t keycode, keyrecord_t *record) {
  bool is_left_side_key = record->event.key.row <= MATRIX_ROWS / 2;
  bool is_tap = record->event.pressed && record->tap.count > 0;
  bool is_hold = record->event.pressed && !record->tap.interrupted;
  uint8_t mods = get_mods() | get_weak_mods();

  bool left_mod_on = LEFT_GUI || LEFT_ALT || LEFT_CTL || LEFT_SFT;
  bool right_mod_on = RIGHT_GUI || RIGHT_ALT || RIGHT_CTL || RIGHT_SFT;

  switch (keycode) {
    case LGUI_T(KC_R):
      LEFT_GUI = is_hold;
      break;
    case LALT_T(KC_S):
      LEFT_ALT = is_hold;
      break;
    case LCTL_T(KC_T):
      LEFT_CTL = is_hold;
      break;
    case LSFT_T(KC_BSPC):
      LEFT_SFT = is_hold;
      break;
    case LGUI_T(KC_I):
      RIGHT_GUI = is_hold;
      break;
    case LALT_T(KC_E):
      RIGHT_ALT = is_hold;
      break;
    case LCTL_T(KC_N):
      RIGHT_CTL = is_hold;
      break;
    case RSFT_T(KC_SPACE):
      RIGHT_SFT = is_hold;
      break;
    default:
      break;
  }

  if (is_tap) {
    if (is_left_side_key) {
      if (left_mod_on) {
        // Key on left side of kb was tapped and a mod from left side is active
        // Disable left side mods
        if (LEFT_GUI && !RIGHT_GUI) unregister_mods(MOD_LGUI);
        if (LEFT_ALT && !RIGHT_ALT) unregister_mods(MOD_LALT);
        if (LEFT_CTL && !RIGHT_CTL) unregister_mods(MOD_LCTL);
        if (LEFT_SFT && !RIGHT_SFT) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        if (LEFT_GUI) {
          tap_code(KC_R);
          LEFT_GUI = false;
        }
        if (LEFT_ALT) {
          tap_code(KC_S);
          LEFT_ALT = false;
        }
        if (LEFT_CTL) {
          tap_code(KC_T);
          LEFT_CTL = false;
        }
        if (LEFT_SFT) {
          tap_code(KC_BSPC);
          LEFT_SFT = false;
        }
      }
    } else {
      if (right_mod_on) {
        // Key on right side of kb was tapped and a mod from right side is active
        // Disable right side mods
        if (RIGHT_GUI && !LEFT_GUI) unregister_mods(MOD_LGUI);
        if (RIGHT_ALT && !LEFT_ALT) unregister_mods(MOD_LALT);
        if (RIGHT_CTL && !LEFT_CTL) unregister_mods(MOD_LCTL);
        if (RIGHT_SFT && !LEFT_SFT) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        if (RIGHT_GUI) {
          tap_code(KC_I);
          RIGHT_GUI = false;
        }
        if (RIGHT_ALT) {
          tap_code(KC_E);
          RIGHT_ALT = false;
        }
        if (RIGHT_CTL) {
          tap_code(KC_N);
          RIGHT_CTL = false;
        }
        if (RIGHT_SFT) {
          tap_code(KC_SPACE);
          RIGHT_SFT = false;
        }
      }
    }
  }

  return true;
}