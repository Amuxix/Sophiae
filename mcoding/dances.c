#include "dances.h"

enum tap_dance_codes {
  COPY_CUT,
  PASTE,
  MUTE_UNMUTE,
  UNDO,
  REDO,
  LAUNCH_PAUSE,
  LALT_LBRACK,
  LCTL_LPAREN,
  MAX_DANCES,
};

typedef struct {
  bool is_press_action;
  int8_t step;
} tap;

// Holds are negative, taps are positive
enum {
  DOUBLE_HOLD = -2,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP,
  SINGLE_TAP,
  DOUBLE_TAP,
  MAX_TAPS
};

static tap dance_state[MAX_DANCES];

int8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    //two keystrokes and then a different keystroke before dance is finished
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MAX_TAPS;
}

void on_dance(tap_dance_state_t *state, uint16_t kc) {
  if (state->count == MAX_TAPS) {
    for (int taps = 0; taps < MAX_TAPS; taps++) {
      tap_code16(kc);
    }
  }
  if (state->count > MAX_TAPS) {
    tap_code16(kc);
  }
}

void single_tap__single_hold__double_tap__double_hold__finished(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t single_hold,
  uint16_t double_tap,
  uint16_t double_hold
) {
  dance_state[dance_id].step = dance_step(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: register_code16(single_tap); break;
    case SINGLE_HOLD: register_code16(single_hold); break;
    case DOUBLE_TAP: register_code16(double_tap); break;
    case DOUBLE_HOLD: register_code16(double_hold); break;
    case DOUBLE_SINGLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
  }
}

void single_tap__single_hold__double_tap__double_hold__reset(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t single_hold,
  uint16_t double_tap,
  uint16_t double_hold
) {
  wait_ms(TAP_CODE_DELAY);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: unregister_code16(single_tap); break;
    case SINGLE_HOLD: unregister_code16(single_hold); break;
    case DOUBLE_TAP: unregister_code16(double_tap); break;
    case DOUBLE_HOLD: unregister_code16(double_hold); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}

void single_tap__single_hold__finished(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t single_hold
) {
  dance_state[dance_id].step = dance_step(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: register_code16(single_tap); break;
    case SINGLE_HOLD: register_code16(single_hold); break;
    case DOUBLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
    case DOUBLE_HOLD: tap_code16(single_tap); register_code16(single_tap); break;
    case DOUBLE_SINGLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
  }
}

void single_tap__single_hold__reset(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t single_hold
) {
  wait_ms(TAP_CODE_DELAY);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: unregister_code16(single_tap); break;
    case SINGLE_HOLD: unregister_code16(single_hold); break;
    case DOUBLE_TAP: unregister_code16(single_tap); break;
    case DOUBLE_HOLD: unregister_code16(single_tap); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}
SINGLE_TAP__SINGLE_HOLD__DOUBLE_TAP__DOUBLE_HOLD(COPY_CUT, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X))

SINGLE_TAP__SINGLE_HOLD(PASTE, LCTL(KC_V), LCS(KC_V))

SINGLE_TAP__DOUBLE_TAP(MUTE_UNMUTE, LCTL(KC_BSLS), LCS(KC_BSLS))

SINGLE_TAP__SINGLE_HOLD(UNDO, LCTL(KC_Z), LCS(KC_Z))

SINGLE_TAP__SINGLE_HOLD(REDO, LCTL(KC_Y), LCS(KC_Y))

SINGLE_TAP__DOUBLE_TAP(LAUNCH_PAUSE, KC_MEDIA_PLAY_PAUSE, LCTL(KC_SPACE))

SINGLE_TAP__SINGLE_HOLD(LALT_LBRACK, KC_LCBR, KC_LEFT_ALT)

SINGLE_TAP__SINGLE_HOLD(LCTL_LPAREN, KC_LPRN, KC_LEFT_CTRL)

tap_dance_action_t tap_dance_actions[] = {
  TAP_DANCE_ADVANCED(COPY_CUT),
  TAP_DANCE_ADVANCED(PASTE),
  TAP_DANCE_ADVANCED(MUTE_UNMUTE),
  TAP_DANCE_ADVANCED(UNDO),
  TAP_DANCE_ADVANCED(REDO),
  TAP_DANCE_ADVANCED(LAUNCH_PAUSE),
  TAP_DANCE_ADVANCED(LALT_LBRACK),
  TAP_DANCE_ADVANCED(LCTL_LPAREN),
};