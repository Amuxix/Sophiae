enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
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

#define ON_DANCE(id) on_dance_ ## id
#define ON_DANCE_FINISHED(id) dance_ ## id ## _finished
#define ON_DANCE_RESET(id) dance_ ## id ## _reset
#define DANCE(id) DANCE_ ## id

#define ST_SH_DT_DH(id, single_tap, single_hold, double_tap, double_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, LCTL(KC_C)); \
  } \
 \
  void ON_DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_dt_dh_finished(state, DANCE(id), single_tap, single_hold, double_tap, double_hold); \
  } \
 \
  void ON_DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_dt_dh_reset(state, DANCE(id), single_tap, single_hold, double_tap, double_hold); \
  }


ST_SH_DT_DH(0, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X))

/*void on_dance_0(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LCTL(KC_C));
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  st_sh_dt_dh_finished(state, DANCE_0, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X));
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  st_sh_dt_dh_reset(state, DANCE_0, LCTL(KC_C), LCS(KC_C), LCTL(KC_X), LCS(KC_X));
}*/

void on_dance_1(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LCTL(KC_V));
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  st_sh_finished(state, DANCE_1, LCTL(KC_V), LCS(KC_V));
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  st_sh_reset(state, DANCE_1, LCTL(KC_V), LCS(KC_V));
}

void on_dance_2(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LCTL(KC_BSLS));
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_2].step = dance_step(state);
  switch (dance_state[DANCE_2].step) {
    case SINGLE_TAP: register_code16(LCTL(KC_BSLS)); break;
    case DOUBLE_TAP: register_code16(LCS(KC_BSLS)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_BSLS)); register_code16(LCTL(KC_BSLS));
  }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_2].step) {
    case SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
    case DOUBLE_TAP: unregister_code16(LCS(KC_BSLS)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
  }
  dance_state[DANCE_2].step = 0;
}

void on_dance_3(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LCTL(KC_Z));
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_3].step = dance_step(state);
  switch (dance_state[DANCE_3].step) {
    case SINGLE_TAP: register_code16(LCTL(KC_Z)); break;
    case SINGLE_HOLD: register_code16(LCS(KC_Z)); break;
    case DOUBLE_TAP: register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z));
  }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_3].step) {
    case SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
    case SINGLE_HOLD: unregister_code16(LCS(KC_Z)); break;
    case DOUBLE_TAP: unregister_code16(LCTL(KC_Z)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
  }
  dance_state[DANCE_3].step = 0;
}

void on_dance_4(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LCTL(KC_Y));
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_4].step = dance_step(state);
  switch (dance_state[DANCE_4].step) {
    case SINGLE_TAP: register_code16(LCTL(KC_Y)); break;
    case SINGLE_HOLD: register_code16(LCS(KC_Y)); break;
    case DOUBLE_TAP: register_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y));
  }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_4].step) {
    case SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
    case SINGLE_HOLD: unregister_code16(LCS(KC_Y)); break;
    case DOUBLE_TAP: unregister_code16(LCTL(KC_Y)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
  }
  dance_state[DANCE_4].step = 0;
}

void on_dance_5(tap_dance_state_t *state, void *user_data) {
  on_dance(state, LALT(KC_SPACE));
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_5].step = dance_step(state);
  switch (dance_state[DANCE_5].step) {
    case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
    case SINGLE_HOLD: register_code16(KC_MEDIA_PLAY_PAUSE); break;
    case DOUBLE_TAP: register_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
  }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_5].step) {
    case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    case SINGLE_HOLD: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    case DOUBLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
  }
  dance_state[DANCE_5].step = 0;
}

void on_dance_6(tap_dance_state_t *state, void *user_data) {
  on_dance(state, KC_LCBR);
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_6].step = dance_step(state);
  switch (dance_state[DANCE_6].step) {
    case SINGLE_TAP: register_code16(KC_LCBR); break;
    case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
    case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
  }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_6].step) {
    case SINGLE_TAP: unregister_code16(KC_LCBR); break;
    case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
    case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
  }
  dance_state[DANCE_6].step = 0;
}

void on_dance_7(tap_dance_state_t *state, void *user_data) {
  on_dance(state, KC_LPRN);
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_7].step = dance_step(state);
  switch (dance_state[DANCE_7].step) {
    case SINGLE_TAP: register_code16(KC_LPRN); break;
    case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
    case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
  }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_7].step) {
    case SINGLE_TAP: unregister_code16(KC_LPRN); break;
    case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
    case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
  }
  dance_state[DANCE_7].step = 0;
}

void on_dance_8(tap_dance_state_t *state, void *user_data) {
  on_dance(state, QK_REPEAT_KEY);
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[DANCE_8].step = dance_step(state);
  switch (dance_state[DANCE_8].step) {
    case SINGLE_TAP: register_code16(QK_REPEAT_KEY); break;
    case DOUBLE_TAP: register_code16(QK_ALT_REPEAT_KEY); break;
    case DOUBLE_SINGLE_TAP: tap_code16(QK_REPEAT_KEY); register_code16(QK_REPEAT_KEY);
  }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[DANCE_8].step) {
    case SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
    case DOUBLE_TAP: unregister_code16(QK_ALT_REPEAT_KEY); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
  }
  dance_state[DANCE_8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
[DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
[DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
[DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
[DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
[DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
[DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
[DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
[DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
[DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};