enum custom_keycodes {
  AO = ML_SAFE_RANGE, // Start in a safe range
  OES,
  CAO,
  COES,
  LEFT_ARROW,
  RIGHT_ARROW,
  EQ_RIGHT_ARROW,
  BOLD,
  UNINDENT,
  ITALIC,
  INDENT,
};

const uint16_t PROGMEM FOU[] = { KC_F, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM LYP[] = { KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM HCOLONCOMMA[] = { KC_H, KC_COLN, KC_COMMA, COMBO_END};
const uint16_t PROGMEM jvd[] = { KC_J, KC_V, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(FOU, AO),
  COMBO(LYP, OES),
  COMBO(HCOLONCOMMA, CAO),
  COMBO(jvd, COES),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AO:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_A) SS_TAP(X_O), 5);
      }
      break;
    case OES:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_O) SS_TAP(X_E) SS_TAP(X_S), 5);
      }
      break;
    case CAO:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_A) SS_TAP(X_O), 5);
      }
      break;
    case COES:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_O) SS_TAP(X_E) SS_TAP(X_S), 5);
      }
      break;
    case LEFT_ARROW:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_MINUS), 5);
      }
      break;
    case RIGHT_ARROW:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_TAP(X_MINUS) SS_LSFT(SS_TAP(X_DOT)), 5);
      }
      break;
    case EQ_RIGHT_ARROW:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_TAP(X_EQUAL) SS_LSFT(SS_TAP(X_DOT)), 5);
      }
      break;
    case BOLD:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_RCTL(SS_TAP(X_B)) SS_TAP(X_RIGHT) SS_LCTL(SS_TAP(X_RIGHT)), 5);
      }
      break;
    case UNINDENT:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_LSFT(SS_TAP(X_TAB)) SS_LSFT(SS_TAP(X_RIGHT)), 5);
      }
      break;
    case ITALIC:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_LCTL(SS_TAP(X_I)) SS_TAP(X_RIGHT) SS_LCTL(SS_TAP(X_RIGHT)), 5);
      }
      break;
    case INDENT:
      if (record->event.pressed) {
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_TAP(X_TAB) SS_LSFT(SS_TAP(X_RIGHT)), 5);
      }
      break;
  }
  return true;
}
