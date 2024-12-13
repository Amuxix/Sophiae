enum custom_keycodes {
  AO = ML_SAFE_RANGE, // Start in a safe range
  OES,
  CAO,
  COES,
  LEFT_ARROW,
  RIGHT_ARROW,
  EQ_RIGHT_ARROW,
  BOLD,
  ITALIC,
  INDENT,
  UNINDENT,
  MAC_MODE_TOGG,
  EURO,
  POUND,
  DEGREE,
  HOME,
  END,
  SNIPPING,
};

bool MAC_MODE = false;

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

#define STRING_MODIFIER(modifier) { \
  if (!MAC_MODE) { \
    SEND_STRING_DELAY(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_LCTL(SS_TAP(modifier)) SS_TAP(X_RIGHT) SS_LCTL(SS_TAP(X_RIGHT)), DYNAMIC_MACRO_DELAY); \
  } else { \
    SEND_STRING_DELAY(SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_LGUI(SS_TAP(modifier)) SS_TAP(X_RIGHT) SS_LALT(SS_TAP(X_RIGHT)), DYNAMIC_MACRO_DELAY); \
  } \
}

//Tap code is affected by mac mode so we need to send the
#define WINDOWS_MAC_KEY(windows_key, mac_key) \
  if (MAC_MODE) { \
    keymap_config.swap_lctl_lgui = !MAC_MODE; \
    keymap_config.swap_rctl_rgui = !MAC_MODE; \
    TAP_KEY(mac_key); \
    keymap_config.swap_lctl_lgui = MAC_MODE; \
    keymap_config.swap_rctl_rgui = MAC_MODE; \
  } else { \
    TAP_KEY(windows_key); \
  }

void send_c_cedilla(void) {
  if (!MAC_MODE) {
    SEND_STRING_DELAY(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))), DYNAMIC_MACRO_DELAY);
  } else {
    SEND_STRING_DELAY(SS_TAP(X_QUOTE) SS_TAP(X_C), DYNAMIC_MACRO_DELAY);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CAO:
        send_c_cedilla(); // No break continue to add ão
      case AO:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_A) SS_TAP(X_O), DYNAMIC_MACRO_DELAY);
        break;
      case COES:
        send_c_cedilla(); // No break continue to add ões
      case OES:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_O) SS_TAP(X_E) SS_TAP(X_S), DYNAMIC_MACRO_DELAY);
        break;
      case LEFT_ARROW:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_MINUS), DYNAMIC_MACRO_DELAY);
        break;
      case RIGHT_ARROW:
        SEND_STRING_DELAY(SS_TAP(X_MINUS) SS_LSFT(SS_TAP(X_DOT)), DYNAMIC_MACRO_DELAY);
        break;
      case EQ_RIGHT_ARROW:
        SEND_STRING_DELAY(SS_TAP(X_EQUAL) SS_LSFT(SS_TAP(X_DOT)), DYNAMIC_MACRO_DELAY);
        break;
      case BOLD:
        STRING_MODIFIER(X_B)
        break;
      case ITALIC:
        STRING_MODIFIER(X_I)
        break;
      case INDENT:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_TAP(X_TAB) SS_LSFT(SS_TAP(X_RIGHT)), DYNAMIC_MACRO_DELAY);
        break;
      case UNINDENT:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_LSFT(SS_TAP(X_TAB)) SS_LSFT(SS_TAP(X_RIGHT)), DYNAMIC_MACRO_DELAY);
        break;
      case MAC_MODE_TOGG:
        MAC_MODE = !MAC_MODE;
        keymap_config.swap_lctl_lgui = MAC_MODE;
        keymap_config.swap_rctl_rgui = MAC_MODE;
        break;
      case EURO:
        WINDOWS_MAC_KEY(ALGR(KC_5), S(LALT(KC_2)))
        break;
      case POUND:
        WINDOWS_MAC_KEY(S(ALGR(KC_4)), LALT(KC_3))
        break;
      case DEGREE:
        WINDOWS_MAC_KEY(S(ALGR(KC_SCLN)), LALT(KC_0))
        break;
      case HOME:
        WINDOWS_MAC_KEY(KC_HOME, LGUI(KC_LEFT))
        break;
      case END:
        WINDOWS_MAC_KEY(KC_END, LGUI(KC_RIGHT))
        break;
      case SNIPPING:
        WINDOWS_MAC_KEY(KC_PSCR, LGUI(LCS(KC_4)))
        break;
    }
  }
  return true;
}
