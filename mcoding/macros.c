#define WINDOWS_MAC_KEY(windows_key, mac_key) \
  if (MAC_MODE) { \
    SS_TAP(mac_key); \
  } else { \
    TAP_KEY(windows_key); \
  }

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
  HOME,
  END,
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
    SEND_STRING_DELAY(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_RCTL(SS_TAP(modifier)) SS_TAP(X_RIGHT) SS_LCTL(SS_TAP(X_RIGHT)), 5); \
  } else { \
    SEND_STRING_DELAY(SS_LGUI(SS_LSFT(SS_TAP(X_LEFT))) SS_LGUI(SS_TAP(modifier)) SS_TAP(X_RIGHT) SS_LGUI(SS_TAP(X_RIGHT)), 5); \
  } \
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CAO:
        if (!MAC_MODE) {
          SEND_STRING_DELAY(SS_LALT(SS_LCTL(SS_TAP(X_COMMA)), 5);
        } else {
          SEND_STRING_DELAY(SS_TAP(X_QUOTE), 5);
        }
      case AO:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_A) SS_TAP(X_O), 5);
        break;
      case COES:
        if (!MAC_MODE) {
          SEND_STRING_DELAY(SS_LALT(SS_LCTL(SS_TAP(X_COMMA)), 5);
        } else {
          SEND_STRING_DELAY(SS_TAP(X_QUOTE), 5);
        }
      case OES:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_GRAVE)) SS_TAP(X_O) SS_TAP(X_E) SS_TAP(X_S), 5);
        break;
      case LEFT_ARROW:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_MINUS), 5);
        break;
      case RIGHT_ARROW:
        SEND_STRING_DELAY(SS_TAP(X_MINUS) SS_LSFT(SS_TAP(X_DOT)), 5);
        break;
      case EQ_RIGHT_ARROW:
        SEND_STRING_DELAY(SS_TAP(X_EQUAL) SS_LSFT(SS_TAP(X_DOT)), 5);
        break;
      case BOLD:
        STRING_MODIFIER(X_B)
        break;
      case ITALIC:
        STRING_MODIFIER(X_I)
        break;
      case INDENT:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_TAP(X_TAB) SS_LSFT(SS_TAP(X_RIGHT)), 5);
        break;
      case UNINDENT:
        SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_LEFT)) SS_LSFT(SS_TAP(X_TAB)) SS_LSFT(SS_TAP(X_RIGHT)), 5);
        break;
      case MAC_MODE_TOGG:
        MAC_MODE = !MAC_MODE;
        keymap_config.swap_lctl_lgui = MAC_MODE;
        keymap_config.swap_rctl_rgui = MAC_MODE;
        break;
      case EURO:
        WINDOWS_MAC_KEY(S(LALT(KC_2)), ALGR(KC_5))
        break;
      case POUND:
        WINDOWS_MAC_KEY(LALT(KC_3), LALT(KC_3))
        break;
      case HOME:
        WINDOWS_MAC_KEY(KC_HOME, LGUI(KC_LEFT))
        break;
      case END:
        WINDOWS_MAC_KEY(KC_END, LGUI(KC_RIGHT))
        break;
    }
  }
  if (macro_id != 0 && dynamic_macro_valid_key_user(keycode, record)) {
    /*
      Macro recording in progress
      Key is valid
      Send macro after it was recorded
     */
    switch (keycode) {
      case QK_DYNAMIC_MACRO_RECORD_START_1:
      case QK_DYNAMIC_MACRO_RECORD_START_2:
      case QK_DYNAMIC_MACRO_RECORD_STOP:
        return false; //Do nothing with start and stop buttons
      case QK_DYNAMIC_MACRO_PLAY_1:
        if (macro_id != 1) {
          // No nesting of same macro
          dynamic_macro_play(macro_buffer, macro_end, +1);
        }
        break;
      case QK_DYNAMIC_MACRO_PLAY_2:
        if (macro_id != 2) {
          // No nesting of same macro
          dynamic_macro_play(r_macro_buffer, r_macro_end, -1);
        }
        break;
    }
  }
  return true;
}
