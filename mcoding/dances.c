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
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
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

static tap dance_state[13];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: register_code16(LCTL(LSFT(KC_X))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LSFT(KC_X))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_V)); register_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_V)); register_code16(LCTL(KC_V));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_BSLS));
        tap_code16(LCTL(KC_BSLS));
        tap_code16(LCTL(KC_BSLS));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_BSLS));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_BSLS)); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_BSLS))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_BSLS)); register_code16(LCTL(KC_BSLS));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_BSLS))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Z));
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_Z))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_Z))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Y));
        tap_code16(LCTL(KC_Y));
        tap_code16(LCTL(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Y));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Y)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_Y))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_Y))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: register_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[5].step = 0;
}
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case DOUBLE_TAP: layer_move(BASE); break;
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
    }
    dance_state[6].step = 0;
}
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case DOUBLE_HOLD: layer_on(EXTRA_SYMB); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
              case DOUBLE_HOLD:
                if(!is_layer_locked(EXTRA_SYMB)) {
                  layer_off(EXTRA_SYMB);
                }
                break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(QK_REPEAT_KEY);
        tap_code16(QK_REPEAT_KEY);
        tap_code16(QK_REPEAT_KEY);
    }
    if(state->count > 3) {
        tap_code16(QK_REPEAT_KEY);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(QK_REPEAT_KEY); break;
        case DOUBLE_TAP: register_code16(QK_ALT_REPEAT_KEY); break;
        case DOUBLE_SINGLE_TAP: tap_code16(QK_REPEAT_KEY); register_code16(QK_REPEAT_KEY);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
        case DOUBLE_TAP: unregister_code16(QK_ALT_REPEAT_KEY); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
    }
    dance_state[10].step = 0;
}

void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_C));
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: register_code16(LSG_T(KC_C)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_X)); break;
        case DOUBLE_HOLD: register_code16(LSG_T(KC_X)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_C)); register_code16(LGUI(KC_C));
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LSG_T(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_HOLD: unregister_code16(LSG_T(KC_X)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
    }
    dance_state[11].step = 0;
}

void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_V));
        tap_code16(LGUI(KC_V));
        tap_code16(LGUI(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_V));
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_V)); break;
        case SINGLE_HOLD: register_code16(LSG_T(KC_V)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_V)); register_code16(LGUI(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_V)); register_code16(LGUI(KC_V));
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(LSG_T(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_V)); break;
    }
    dance_state[12].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};