#define ON_DANCE(id) on_dance_ ## id
#define DANCE_FINISHED(id) dance_ ## id ## _finished
#define DANCE_RESET(id) dance_ ## id ## _reset

#define ST_SH_DT_DH(id, single_tap, single_hold, double_tap, double_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, single_tap); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_dt_dh_finished(state, id, single_tap, single_hold, double_tap, double_hold); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_dt_dh_reset(state, id, single_tap, single_hold, double_tap, double_hold); \
  }

#define ST_SH(id, single_tap, single_hold) \
  void ON_DANCE(id)(tap_dance_state_t *state, void *user_data) { \
    on_dance(state, single_tap); \
  } \
 \
  void DANCE_FINISHED(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_finished(state, id, single_tap, single_hold); \
  } \
 \
  void DANCE_RESET(id)(tap_dance_state_t *state, void *user_data) { \
    st_sh_reset(state, id, single_tap, single_hold); \
  }

#define TAP_DANCE_ADVANCED(id) [id] = ACTION_TAP_DANCE_FN_ADVANCED(ON_DANCE(id), DANCE_FINISHED(id), DANCE_RESET(id))
