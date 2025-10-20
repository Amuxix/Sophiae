#include QMK_KEYBOARD_H
#include "version.h"

#include "debug.c"
#include "sophiae_config.c"
#include "keycodes.h"
#include "enums.c"
#include "utils.c"
#include "caps_word.c"
#include "dances.c"
#include "same_side_mod_prevention.c"
#include "custom_keys.c"
#include "ledmap.c"
#include "alternates.c"
#include "auto_layer_switch.c"
#include "overrides.c"

void keyboard_post_init_user(void) {
  sophiae_config.raw = eeconfig_read_user();
  rgb_matrix_enable();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LGUI_T(KC_R):
    case LALT_T(KC_S):
    case LCTL_T(KC_T):
    case LCTL_T(KC_N):
    case LALT_T(KC_E):
    case LGUI_T(KC_I):
    case LT_MOV(KC_TAB):
    case LT_SYM(KC_ENTER):
    //CANARY_G
    case LALT_T(KC_W):
    case LSFT_T(KC_C):
    case LCTL_T(KC_Q):
    case RALT_T(KC_QUOTE):
    case RSFT_T(KC_A):
    case RCTL_T(KC_DOT):
    //KEYPAD_SYMB
    case LGUI_T(KC_LBRC):
    case LGUI_T(KC_KP_6):
      return TAPPING_TERM + 20;
    case TD(COPY_CUT):
    case TD(PASTE):
    case TD(MUTE_UNMUTE):
    case TD(LAUNCH_PAUSE):
    case TD(CAPS_WORDS_DANCE):
      return TAPPING_TERM + 45;
    case RSFT_T(KC_SPACE):
      return TAPPING_TERM + 30;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  auto_layer_set(state);
  STATUS_LED_1(IS_LAYER_ON_STATE(state, CANARY_G));
  STATUS_LED_2(IS_LAYER_ON_STATE(state, QWERTY_G) || IS_LAYER_ON_STATE(state, QWERTY_SG));
  //STATUS_LED_3(IS_LAYER_ON_STATE(state, SPACE_SWAP));
  STATUS_LED_3(false);
  STATUS_LED_4(IS_LAYER_ON_STATE(state, KEYPAD_SYMB));
  STATUS_LED_5(IS_LAYER_ON_STATE(state, MOVEMENT));
  STATUS_LED_6(IS_LAYER_ON_STATE(state, EXTRA_SYMB));
  return state;
}
