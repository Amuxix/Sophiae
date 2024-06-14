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
  uint8_t step;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

static tap dance_state[MAX_DANCES];

uint8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    //two keystrokes and then a different keystroke before dance is finished
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

void on_dance(tap_dance_state_t *state, uint16_t kc) {
  if (state->count == 3) {
    tap_code16(kc);
    tap_code16(kc);
    tap_code16(kc);
  }
  if (state->count > 3) {
    tap_code16(kc);
  }
}

void st_sh_dt_dh_finished(tap_dance_state_t *state, int dance_id, uint16_t single_tap, uint16_t single_hold, uint16_t double_tap, uint16_t double_hold) {
  dance_state[dance_id].step = dance_step(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: register_code16(single_tap); break;
    case SINGLE_HOLD: register_code16(single_hold); break;
    case DOUBLE_TAP: register_code16(double_tap); break;
    case DOUBLE_HOLD: register_code16(double_hold); break;
    case DOUBLE_SINGLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
  }
}

void st_sh_dt_dh_reset(tap_dance_state_t *state, int dance_id, uint16_t single_tap, uint16_t single_hold, uint16_t double_tap, uint16_t double_hold) {
  wait_ms(10);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: unregister_code16(single_tap); break;
    case SINGLE_HOLD: unregister_code16(single_hold); break;
    case DOUBLE_TAP: unregister_code16(double_tap); break;
    case DOUBLE_HOLD: unregister_code16(double_hold); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}

void st_sh_finished(tap_dance_state_t *state, int dance_id, uint16_t single_tap, uint16_t single_hold) {
  dance_state[dance_id].step = dance_step(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: register_code16(single_tap); break;
    case SINGLE_HOLD: register_code16(single_hold); break;
    case DOUBLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
    case DOUBLE_HOLD: tap_code16(single_tap); register_code16(single_tap); break;
    case DOUBLE_SINGLE_TAP: tap_code16(single_tap); register_code16(single_tap); break;
  }
}

void st_sh_reset(tap_dance_state_t *state, int dance_id, uint16_t single_tap, uint16_t single_hold) {
  wait_ms(10);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: unregister_code16(single_tap); break;
    case SINGLE_HOLD: unregister_code16(single_hold); break;
    case DOUBLE_TAP: unregister_code16(single_tap); break;
    case DOUBLE_HOLD: unregister_code16(single_tap); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}

ST_SH_DT_DH(COPY_CUT, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X))

ST_SH(PASTE, LCTL(KC_V), LCS(KC_V))

ST_SH_DT_DH(MUTE_UNMUTE, LCTL(KC_BSLS), LCTL(KC_BSLS), LCS(KC_BSLS), LCS(KC_BSLS))

ST_SH(UNDO, LCTL(KC_Z), LCS(KC_Z))

ST_SH(REDO, LCTL(KC_Y), LCS(KC_Y))

ST_SH(LAUNCH_PAUSE, KC_MEDIA_PLAY_PAUSE, LCTL(KC_SPACE))

ST_SH(LALT_LBRACK, KC_LCBR, KC_LEFT_ALT)

ST_SH(LCTL_LPAREN, KC_LPRN, KC_LEFT_CTRL)

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