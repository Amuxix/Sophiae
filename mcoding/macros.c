enum custom_keycodes {
  ST_MACRO_0 = ML_SAFE_RANGE, // Start in a safe range
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  CG_TOGG,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(10) SS_TAP(X_A) SS_DELAY(10) SS_TAP(X_O));
      }
      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(10) SS_TAP(X_O) SS_DELAY(10) SS_TAP(X_E) SS_DELAY(10) SS_TAP(X_S));
      }
      break;
    case ST_MACRO_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_DELAY(10) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(10) SS_TAP(X_A) SS_DELAY(10) SS_TAP(X_O));
      }
      break;
    case ST_MACRO_3:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_DELAY(10) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(10) SS_TAP(X_O) SS_DELAY(10) SS_TAP(X_E) SS_DELAY(10) SS_TAP(X_S));
      }
      break;
    case ST_MACRO_4:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(10) SS_TAP(X_MINUS));
      }
      break;
    case ST_MACRO_5:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)));
      }
      break;
    case ST_MACRO_6:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)));
      }
      break;
    case ST_MACRO_7:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(10) SS_RCTL(SS_TAP(X_B)) SS_DELAY(10) SS_TAP(X_RIGHT) SS_DELAY(10) SS_LCTL(SS_TAP(X_RIGHT)));
      }
      break;
    case ST_MACRO_8:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_LEFT)) SS_DELAY(10) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(10) SS_LSFT(SS_TAP(X_RIGHT)));
      }
      break;
    case ST_MACRO_9:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(10) SS_LCTL(SS_TAP(X_I)) SS_DELAY(10) SS_TAP(X_RIGHT) SS_DELAY(10) SS_LCTL(SS_TAP(X_RIGHT)));
      }
      break;
    case ST_MACRO_10:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_LEFT)) SS_DELAY(10) SS_TAP(X_TAB) SS_DELAY(10) SS_LSFT(SS_TAP(X_RIGHT)));
      }
      break;
    case CG_TOGG:
      if (record->event.pressed) {
        tap_code(CG_TOGG);
        if (keymap_config.swap_lctl_lgui) {
          HSV hsv = {.h = 0, .s = 0, .v = 0};
          set_led_color(CAPS_WORDS_LED_ID, hsv, true);
          ML_LED_3(true);
        } else {
          uint8_t layer = get_highest_layer(layer_state);
          set_led_color_from_layermap(layer, CAPS_WORDS_LED_ID);
          ML_LED_3(false);
        }
      }
      break;
  }
  return true;
}
