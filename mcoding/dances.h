#define ON_DANCE(id) on_dance_ ## id
#define DANCE_FINISHED(id) dance_ ## id ## _finished
#define DANCE_RESET(id) dance_ ## id ## _reset

#define SINGLE_TAP__SINGLE_HOLD__DOUBLE_TAP__DOUBLE_HOLD(id, single_tap, single_hold, double_tap, double_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, single_tap); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__double_tap__double_hold__finished(state, id, single_tap, single_hold, double_tap, double_hold); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__double_tap__double_hold__reset(state, id, single_tap, single_hold, double_tap, double_hold); \
  }

#define SINGLE_TAP__SINGLE_HOLD(id, single_tap, single_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, single_tap); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__finished(state, id, single_tap, single_hold); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    single_tap__single_hold__reset(state, id, single_tap, single_hold); \
  }

#define SINGLE_TAP__DOUBLE_TAP(id, single_tap, double_tap) \
  SINGLE_TAP__SINGLE_HOLD__DOUBLE_TAP__DOUBLE_HOLD(id, single_tap, single_tap, double_tap, double_tap)

#define TAP_DANCE_ADVANCED(id) [id] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE(id), DANCE_FINISHED(id), DANCE_RESET(id))
