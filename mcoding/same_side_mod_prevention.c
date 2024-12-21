#include "print.h"

enum home_mods_t {
  LEFT_GUI = 1,
  LEFT_ALT = 2,
  LEFT_CTL = 4,
//  LEFT_SFT = 8,
  RIGHT_GUI = 16,
  RIGHT_ALT = 32,
  RIGHT_CTL = 64,
//  RIGHT_SFT = 128,
};

uint8_t home_mods = 0;

uint16_t keycodes[4] = {0, 0, 0, 0};

void add_keycode(uint16_t keycode) {
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

void remove_keycode(uint16_t keycode) {
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
  if (keycodes[0] != 0) tap_code(keycodes[0]);
  if (keycodes[1] != 0) tap_code(keycodes[1]);
  if (keycodes[2] != 0) tap_code(keycodes[2]);
  if (keycodes[3] != 0) tap_code(keycodes[3]);
  keycodes[0] = 0;
  keycodes[1] = 0;
  keycodes[2] = 0;
  keycodes[3] = 0;
}

bool handle_key_down(bool is_left, uint16_t key, uint8_t mod) {
  bool left_mod_on = (home_mods & 0x0f) > 0;
  bool right_mod_on = (home_mods & 0xf0) > 0;
  if ((is_left && right_mod_on) || (!is_left && left_mod_on)) {
    tap_code(key);
    return false;
  } else {
    add_keycode(key);
    home_mods |= mod;
    return true;
  }
}

bool on_key_down(uint16_t keycode, keyrecord_t *record) {
  bool is_left_side_key = record->event.key.row <= MATRIX_ROWS / 2;
  bool is_hold = record->tap.count == 0;

  bool left_mod_on = (home_mods & 0x0f) > 0;
  bool right_mod_on = (home_mods & 0xf0) > 0;

  if (is_hold) {
    switch (keycode) {
      case LGUI_T(KC_R):
        return handle_key_down(is_left_side_key, KC_R, LEFT_GUI);
      case LALT_T(KC_S):
        return handle_key_down(is_left_side_key, KC_S, LEFT_ALT);
      case LCTL_T(KC_T):
        return handle_key_down(is_left_side_key, KC_T, LEFT_CTL);
//      case LSFT_T(KC_BSPC):
//        return handle_key_down(is_left_side_key, KC_BSPC, LEFT_SFT);
      case LGUI_T(KC_I):
        return handle_key_down(is_left_side_key, KC_I, RIGHT_GUI);
      case LALT_T(KC_E):
        return handle_key_down(is_left_side_key, KC_E, RIGHT_ALT);
      case LCTL_T(KC_N):
        return handle_key_down(is_left_side_key, KC_N, RIGHT_CTL);
//      case RSFT_T(KC_SPACE):
//        return handle_key_down(is_left_side_key, KC_SPACE, RIGHT_SFT);
      default:
        break;
    }
  } else {
    if (is_left_side_key) {
      if (left_mod_on) {
        // Key on left side of kb was tapped and a mod from left side is active
        // Disable left side mods if right side equivalent not on
        if ((home_mods & LEFT_GUI) > 0 && (home_mods & RIGHT_GUI) == 0) unregister_mods(MOD_LGUI);
        if ((home_mods & LEFT_ALT) > 0 && (home_mods & RIGHT_ALT) == 0) unregister_mods(MOD_LALT);
        if ((home_mods & LEFT_CTL) > 0 && (home_mods & RIGHT_CTL) == 0) unregister_mods(MOD_LCTL);
//        if ((home_mods & LEFT_SFT) > 0 && (home_mods & RIGHT_SFT) == 0) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        send_and_clear_keycodes();
      }
    } else {
      if (right_mod_on) {
        // Key on right side of kb was tapped and a mod from right side is active
        // Disable right side mods if left side equivalent not on
        if ((home_mods & RIGHT_GUI) > 0 && (home_mods & LEFT_GUI) == 0) unregister_mods(MOD_LGUI);
        if ((home_mods & RIGHT_ALT) > 0 && (home_mods & LEFT_ALT) == 0) unregister_mods(MOD_LALT);
        if ((home_mods & RIGHT_CTL) > 0 && (home_mods & LEFT_CTL) == 0) unregister_mods(MOD_LCTL);
//        if ((home_mods & RIGHT_SFT) > 0 && (home_mods & LEFT_SFT) == 0) unregister_mods(MOD_LSFT);
        // Send corresponding taps
        send_and_clear_keycodes();
      }
    }
  }
  return true;
}

bool on_key_up(uint16_t keycode, keyrecord_t *record) {
  bool is_hold = record->tap.count == 0;
  if (is_hold) {
    switch (keycode) {
      case LGUI_T(KC_R):
        remove_keycode(KC_R);
        home_mods &= ~LEFT_GUI;
        break;
      case LALT_T(KC_S):
        remove_keycode(KC_S);
        home_mods &= ~LEFT_ALT;
        break;
      case LCTL_T(KC_T):
        remove_keycode(KC_T);
        home_mods &= ~LEFT_CTL;
        break;
//      case LSFT_T(KC_BSPC):
//        remove_keycode(KC_BSPC);
//        home_mods &= ~LEFT_SFT;
//        break;
      case LGUI_T(KC_I):
        remove_keycode(KC_I);
        home_mods &= ~RIGHT_GUI;
        break;
      case LALT_T(KC_E):
        remove_keycode(KC_E);
        home_mods &= ~RIGHT_ALT;
        break;
      case LCTL_T(KC_N):
        remove_keycode(KC_N);
        home_mods &= ~RIGHT_CTL;
        break;
//      case RSFT_T(KC_SPACE):
//        remove_keycode(KC_SPACE);
//        home_mods &= ~RIGHT_SFT;
//        break;
      default:
        break;
    }
  }
  return true;
}


bool prevent_same_side_mods(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed == 1) {
    return on_key_down(keycode, record);
  } else {
    return on_key_up(keycode, record);
  }
}