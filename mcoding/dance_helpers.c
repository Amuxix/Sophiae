#define ON_DANCE(id) on_dance_ ## id
#define DANCE_FINISHED(id) dance_ ## id ## _finished
#define DANCE_RESET(id) dance_ ## id ## _reset

#define TAP_DANCE_ADVANCED(id) [id] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE(id), DANCE_FINISHED(id), DANCE_RESET(id))

#define SINGLE_TAP__SINGLE_HOLD__DOUBLE_TAP__DOUBLE_HOLD(id, single_tap, single_hold, double_tap, double_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, (single_tap)); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__double_tap__double_hold__finished(state, id, (single_tap), (single_hold), (double_tap), (double_hold)); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__double_tap__double_hold__reset(state, id, (single_tap), (single_hold), (double_tap), (double_hold)); \
  }

#define SINGLE_TAP__SINGLE_HOLD(id, single_tap, single_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, (single_tap)); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__finished(state, id, (single_tap), (single_hold)); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__reset(state, id, (single_tap), (single_hold)); \
  }

#define SINGLE_TAP__DOUBLE_TAP(id, single_tap, double_tap) \
  SINGLE_TAP__SINGLE_HOLD__DOUBLE_TAP__DOUBLE_HOLD(id, single_tap, single_tap, double_tap, double_tap)

#define DO_CONFIG(keycode) ACTION_MODS_KEY(mod_config(QK_MODS_GET_MODS(keycode)), keycode_config(QK_MODS_GET_BASIC_KEYCODE(keycode)))

#define REGISTER_KEY(keycode) register_code16(DO_CONFIG(keycode))
#define UNREGISTER_KEY(keycode) unregister_code16(DO_CONFIG(keycode))
#define TAP_KEY(keycode) tap_code16(DO_CONFIG(keycode))


typedef struct {
  bool is_press_action;
  int8_t step;
} tap;

static tap dance_state[MAX_DANCES];

void on_dance(tap_dance_state_t *state, uint16_t kc) {
  if (state->count == MAX_TAPS) {
    for (int taps = 0; taps < MAX_TAPS; taps++) {
      TAP_KEY(kc);
    }
  }
  if (state->count > MAX_TAPS) {
    TAP_KEY(kc);
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
  dance_state[dance_id].step = dance_press_type(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: REGISTER_KEY(single_tap); break;
    case SINGLE_HOLD: REGISTER_KEY(single_hold); break;
    case DOUBLE_TAP: REGISTER_KEY(double_tap); break;
    case DOUBLE_HOLD: REGISTER_KEY(double_hold); break;
    case DOUBLE_SINGLE_TAP: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
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
    case SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
    case SINGLE_HOLD: UNREGISTER_KEY(single_hold); break;
    case DOUBLE_TAP: UNREGISTER_KEY(double_tap); break;
    case DOUBLE_HOLD: UNREGISTER_KEY(double_hold); break;
    case DOUBLE_SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}

void single_tap__single_hold__finished(
  tap_dance_state_t *state,
  int dance_id,
  uint16_t single_tap,
  uint16_t single_hold
) {
  dance_state[dance_id].step = dance_press_type(state);
  switch (dance_state[dance_id].step) {
    case SINGLE_TAP: REGISTER_KEY(single_tap); break;
    case SINGLE_HOLD: REGISTER_KEY(single_hold); break;
    case DOUBLE_TAP: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
    case DOUBLE_HOLD: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
    case DOUBLE_SINGLE_TAP: TAP_KEY(single_tap); REGISTER_KEY(single_tap); break;
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
    case SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
    case SINGLE_HOLD: UNREGISTER_KEY(single_hold); break;
    case DOUBLE_TAP: UNREGISTER_KEY(single_tap); break;
    case DOUBLE_HOLD: UNREGISTER_KEY(single_tap); break;
    case DOUBLE_SINGLE_TAP: UNREGISTER_KEY(single_tap); break;
  }
  dance_state[dance_id].step = 0;
}
