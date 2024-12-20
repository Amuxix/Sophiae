// Holds are negative, taps are positive
typedef enum {
  DOUBLE_HOLD = -2, // tap then hold
  SINGLE_HOLD, // hold
  DOUBLE_SINGLE_TAP, // tap then hold and press a different key before hold time has enlapsed
  SINGLE_TAP, // tap
  DOUBLE_TAP, // tap then tap
  MAX_TAPS // two taps or more and then tap/hold
} press_t;

press_t press_type(uint8_t count, bool pressed, bool interrupted) {
  if (count == 1) {
    if (interrupted || !pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (count == 2) {
    //two keystrokes and then a different keystroke before dance is finished
    if (interrupted) return DOUBLE_SINGLE_TAP;
    else if (pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MAX_TAPS;
}

press_t record_press_type(keyrecord_t *record) {
  return press_type(record->tap.count, record->event.pressed, record->tap.interrupted);
}

press_t dance_press_type(tap_dance_state_t *state) {
  return press_type(state->count, state->pressed, state->interrupted);
}

bool is_tap(press_t press) {
  return press >= 0;
}