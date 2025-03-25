#define DANCE_FINISHED(id) dance_ ## id ## _finished
#define DANCE_RESET(id) dance_ ## id ## _reset

#define TAP_DANCE_ADVANCED(id, dance_finished, dance_reset) [id] = { .fn = {NULL, dance_finished, dance_reset, NULL}, .user_data = NULL, }
#define TAP_DANCE(id) TAP_DANCE_ADVANCED(id, DANCE_FINISHED(id), DANCE_RESET(id))

#define SINGLE_TAP__HOLD__DOUBLE_TAP__TAP_HOLD(id, single_tap, hold, double_tap, tap_hold) \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__hold__double_tap__tap_hold__finished(state, id, (single_tap), (hold), (double_tap), (tap_hold)); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__hold__double_tap__tap_hold__reset(state, id, (single_tap), (hold), (double_tap), (tap_hold)); \
  }

#define SINGLE_TAP__HOLD(id, single_tap, hold) \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__hold__finished(state, id, (single_tap), (hold)); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__hold__reset(state, id, (single_tap), (hold)); \
  }

#define SINGLE_TAP__DOUBLE_TAP(id, single_tap, double_tap) \
  SINGLE_TAP__HOLD__DOUBLE_TAP__TAP_HOLD(id, single_tap, single_tap, double_tap, double_tap)

#define DO_CONFIG(keycode) ACTION_MODS_KEY(mod_config(QK_MODS_GET_MODS(keycode)), keycode_config(QK_MODS_GET_BASIC_KEYCODE(keycode)))

#define REGISTER_KEY(keycode) register_code16(DO_CONFIG(keycode))
#define UNREGISTER_KEY(keycode) unregister_code16(DO_CONFIG(keycode))
#define TAP_KEY(keycode) tap_code16(DO_CONFIG(keycode))


// Holds are negative, taps are positive
typedef enum {
  SINGLE_TAP, // tap
  HOLD, // hold
  DOUBLE_TAP, // tap then tap
  TAP_HOLD, // tap then hold
} press_t;

static press_t dance_state[MAX_DANCES];

press_t dance_step(tap_dance_state_t *state) {
  switch (state->count) {
    case 1:
      if (state->interrupted || !state->pressed) return SINGLE_TAP;
      else return HOLD;
    case 2:
      else if (state->interrupted || !state->pressed) return DOUBLE_TAP;
      else return TAP_HOLD;
    default:
      return DOUBLE_TAP;
  }
}

void single_tap__hold__double_tap__tap_hold__finished(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t hold,
  uint16_t double_tap,
  uint16_t tap_hold
) {
  dance_state[dance_id] = dance_step(state);
  switch (dance_state[dance_id]) {
    case SINGLE_TAP: REGISTER_KEY(single_tap); break;
    case HOLD: REGISTER_KEY(hold); break;
    case DOUBLE_TAP: REGISTER_KEY(double_tap); break;
    case TAP_HOLD: REGISTER_KEY(tap_hold); break;
  }
}

void single_tap__hold__double_tap__tap_hold__reset(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t hold,
  uint16_t double_tap,
  uint16_t tap_hold
) {
  wait_ms(TAP_CODE_DELAY);
  switch (dance_state[dance_id]) {
    case SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
    case HOLD: UNREGISTER_KEY(hold); break;
    case DOUBLE_TAP: UNREGISTER_KEY(double_tap); break;
    case TAP_HOLD: UNREGISTER_KEY(tap_hold); break;
  }
  dance_state[dance_id] = 0;
}

void single_tap__hold__finished(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t hold
) {
  dance_state[dance_id] = dance_step(state);
  switch (dance_state[dance_id]) {
    case SINGLE_TAP: REGISTER_KEY(single_tap); break;
    case HOLD: REGISTER_KEY(hold); break;
    case DOUBLE_TAP: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
    case TAP_HOLD: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
  }
}

void single_tap__hold__reset(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t hold
) {
  wait_ms(TAP_CODE_DELAY);
  switch (dance_state[dance_id]) {
    case SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
    case HOLD: UNREGISTER_KEY(hold); break;
    case DOUBLE_TAP: UNREGISTER_KEY(single_tap); break;
    case TAP_HOLD: UNREGISTER_KEY(single_tap); break;
  }
  dance_state[dance_id] = 0;
}
