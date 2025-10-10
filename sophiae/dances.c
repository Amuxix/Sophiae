#include "dance_helpers.c" // This needs to be after tap_dance_codes because tap_dance_codes is used in the helpers

SINGLE_TAP__HOLD__DOUBLE_TAP__TAP_HOLD(COPY_CUT, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X))
SINGLE_TAP__HOLD(PASTE, LCTL(KC_V), LCS(KC_V))
SINGLE_TAP__DOUBLE_TAP(MUTE_UNMUTE, KC_F16, KC_F17)
SINGLE_TAP__HOLD(UNDO, LCTL(KC_Z), LCS(KC_Z))
SINGLE_TAP__HOLD(REDO, LCTL(KC_Y), LCS(KC_Y))
SINGLE_TAP__DOUBLE_TAP(LAUNCH_PAUSE, KC_MEDIA_PLAY_PAUSE, LALT(KC_SPACE))
SINGLE_TAP__HOLD(LALT_LBRACK, KC_LCBR, KC_LEFT_ALT)
SINGLE_TAP__HOLD(LCTL_LPAREN, KC_LPRN, KC_LEFT_CTRL)

void on_caps_words_dance(tap_dance_state_t *state, void *user_data) {
  switch (dance_step(state)) {
    case DOUBLE_TAP:
    case TAP_HOLD:
      CAPS_PHRASE_STATE = true;
    case SINGLE_TAP:
    case HOLD:
      caps_word_toggle();
      break;
  }
}

tap_dance_action_t tap_dance_actions[MAX_DANCES] = {
  TAP_DANCE(COPY_CUT),
  TAP_DANCE(PASTE),
  TAP_DANCE(MUTE_UNMUTE),
  TAP_DANCE(UNDO),
  TAP_DANCE(REDO),
  TAP_DANCE(LAUNCH_PAUSE),
  TAP_DANCE(LALT_LBRACK),
  TAP_DANCE(LCTL_LPAREN),
  TAP_DANCE_ADVANCED(CAPS_WORDS_DANCE, on_caps_words_dance, NULL),
};