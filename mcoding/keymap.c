#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "layers.c"
#include "keycodes.c"
#include "ledmap.c"
#include "dances.c"
#include "macros.c"
#include "alternates.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    DM_PLY1,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            CG_TOGG,                    XXXXXXX,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    DM_PLY2,          KC_F1,            KC_L,             KC_Y,             KC_P,             KC_B,             XXXXXXX,                    XXXXXXX,          KC_Z,             KC_F,             KC_O,             KC_U,             KC_F10,           KC_F12,
    XXXXXXX,          KC_W,             LGUI_T(KC_R),     LALT_T(KC_S),     LCTL_T(KC_T),     KC_G,             CW_TOGG,                    OSL(SHORTCUTS),   KC_M,             LCTL_T(KC_N),     LALT_T(KC_E),     LGUI_T(KC_I),     KC_QUOTE,         XXXXXXX,
    XXXXXXX,          KC_C,             KC_J,             KC_V,             KC_D,             KC_K,                                                           KC_X,             KC_H,             KC_COLN,          KC_COMMA,         KC_A,             XXXXXXX,
    XXXXXXX,          KC_Q,             TD(COPY_CUT),     TD(PASTE),        LT_KPD(KC_ESC),                     TD(MUTE_UNMUTE),            TD(LAUNCH_PAUSE),                   LT_KPD(KC_DEL),   TD(UNDO),         TD(REDO),         KC_DOT,           XXXXXXX,
                                                                            LSFT_T(KC_BSPC),  LT_MOV(KC_TAB),   QK_AREP,                    KC_APPLICATION,   LT_SYM(KC_ENTER), RSFT_T(KC_SPACE)
  ),
  [CANARY_G] = LAYOUT_moonlander(
    _______,          XXXXXXX,          KC_2,             KC_3,             KC_4,             KC_5,             _______,                    _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          KC_F11,
    _______,          KC_1,             _______,          _______,          _______,          _______,          _______,                    _______,          _______,          _______,          _______,          _______,          KC_0,             KC_F12,
    KC_LALT,          LALT_T(KC_W),     KC_R,             KC_S,             KC_T,             _______,          _______,                    _______,          _______,          KC_N,             KC_E,             KC_I,             RALT_T(KC_QUOTE), KC_RALT,
    KC_LSFT,          LSFT_T(KC_C),     _______,          _______,          _______,          _______,                                                        _______,          _______,          _______,          _______,          RSFT_T(KC_A),     KC_RSFT,
    KC_LCTL,          LCTL_T(KC_Q),     _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          RCTL_T(KC_DOT),   KC_RCTL,
                                                                            KC_BSPC,          _______,          KC_LGUI,                    _______,          _______,          KC_SPACE
  ),
  [QWERTY_G] = LAYOUT_moonlander(
    _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             _______,                    _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          KC_F11,
    _______,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             _______,                    _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_0,             KC_F12,
    KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             _______,                    _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_RALT,
    KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,                                                           KC_N,             KC_M,             _______,          _______,          KC_QUOTE,         KC_RSFT,
    KC_LCTL,          XXXXXXX,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          _______,          KC_RCTL,
                                                                            KC_SPACE,         _______,          KC_LGUI,                    _______,          _______,          KC_BSPC
  ),
  [QWERTY_SG] = LAYOUT_moonlander(
    _______,          _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                       _______,          KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_F11,
    _______,          XXXXXXX,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                       _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_F12,
    KC_LALT,          KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,                       _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_QUOTE,
    KC_LSFT,          KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,                                                           KC_B,             KC_N,             KC_M,             KC_COLN,          KC_COMMA,         KC_RSFT,
    KC_LCTL,          KC_LCTL,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          _______,          KC_RCTL,
                                                                            KC_SPACE,         _______,          KC_LGUI,                    _______,          _______,          KC_BSPC
  ),
  [KEYPAD_SYMB] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F14,           KC_F15,           KC_F16,           KC_F17,           _______,                    _______,          KC_F18,           KC_F19,           KC_F20,           KC_F21,           XXXXXXX,          KC_F23,
    XXXXXXX,          KC_F13,           KC_PERC,          KC_DLR,           KC_HASH,          US_DEG,           _______,                    _______,          KC_INSERT,        KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_F22,           KC_F24,
    XXXXXXX,          US_EURO,          LGUI_T(KC_LBRC),  TD(LALT_LBRACK),  TD(LCTL_LPAREN),  KC_LABK,          _______,                    QK_LLCK,          KC_KP_MINUS,      LCTL_T(KC_KP_4),  LALT_T(KC_KP_5),  LGUI_T(KC_KP_6),  KC_KP_SLASH,      XXXXXXX,
    XXXXXXX,          LEFT_ARROW,       KC_RBRC,          KC_RCBR,          KC_RPRN,          KC_RABK,                                                        KC_KP_PLUS,       KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ASTERISK,   XXXXXXX,
    XXXXXXX,          RIGHT_ARROW,      XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          KC_KP_0,          KC_EQUAL,         KC_KP_DOT,        XXXXXXX,
                                                                            _______,          _______,          _______,                    KC_PSCR,          _______,          _______
  ),
  [EXTRA_SYMB] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    XXXXXXX,          KC_F1,            KC_GRAVE,         KC_CIRC,          KC_TILD,          US_DIAE,          _______,                    _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_F10,           KC_F12,
    DM_REC1,          KC_SCLN,          KC_QUES,          KC_UNDS,          KC_EQUAL,         KC_AMPR,          _______,                    QK_LLCK,          XXXXXXX,          KC_LCTL,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX,
    DM_RSTP,          KC_EXLM,          KC_BSLS,          KC_AT,            KC_DQUO,          KC_PIPE,                                                        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    DM_REC2,          EQ_RIGHT_ARROW,   XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                                                                            _______,          _______,          _______,                    _______,          _______,          _______
  ),
  [MOVEMENT] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    XXXXXXX,          KC_F1,            XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,                    _______,          LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RIGHT),   KC_F10,           KC_F12,
    XXXXXXX,          XXXXXXX,          KC_LGUI,          KC_LALT,          KC_LCTL,          XXXXXXX,          _______,                    QK_LLCK,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT,         KC_MNXT,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                                                        KC_HOME,          KC_PGDN,          KC_PAGE_UP,       KC_END,           KC_MPLY,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            KC_VOLD,          KC_MUTE,          KC_VOLU,          KC_MPRV,          XXXXXXX,
                                                                            _______,          _______,          _______,                    _______,          _______,          _______
  ),
  [SHORTCUTS] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          TO(CANARY_G),       TO(QWERTY_G),   TO(QWERTY_SG),    XXXXXXX,          XXXXXXX,                    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          TO(BASE),         XXXXXXX,            XXXXXXX,        XXXXXXX,          BOLD,             XXXXXXX,                    XXXXXXX,          LSA(KC_Z),        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,            XXXXXXX,        XXXXXXX,          XXXXXXX,          XXXXXXX,                    QK_LLCK,          XXXXXXX,          XXXXXXX,          XXXXXXX,          ITALIC,           XXXXXXX,          XXXXXXX,
    XXXXXXX,          KC_CALCULATOR,    XXXXXXX,            XXXXXXX,        XXXXXXX,          XXXXXXX,                                                        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          LCS(KC_ESC),      _______,            _______,        XXXXXXX,                            _______,                    _______,                            XXXXXXX,          _______,          _______,          XXXXXXX,          XXXXXXX,
                                                                            UNINDENT,         XXXXXXX,          XXXXXXX,                    XXXXXXX,          XXXXXXX,          INDENT
  ),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_R):
            return LONG_TAPPING_TERM;
        case LALT_T(KC_S):
            return LONG_TAPPING_TERM;
        case LCTL_T(KC_T):
            return LONG_TAPPING_TERM;
        case LCTL_T(KC_N):
            return LONG_TAPPING_TERM;
        case LALT_T(KC_E):
            return LONG_TAPPING_TERM;
        case LGUI_T(KC_I):
            return LONG_TAPPING_TERM;
        case LT_MOV(KC_TAB):
            return LONG_TAPPING_TERM;
        case LT_SYM(KC_ENTER):
            return LONG_TAPPING_TERM;
        case TD(COPY_CUT):
            return TAPPING_TERM + 45;
        case TD(PASTE):
            return TAPPING_TERM + 45;
        case TD(MUTE_UNMUTE):
            return TAPPING_TERM + 45;
        case TD(LAUNCH_PAUSE):
            return TAPPING_TERM + 45;
        case RSFT_T(KC_SPACE):
            return TAPPING_TERM + 30;
        //CANARY_G
        case LALT_T(KC_W):
            return LONG_TAPPING_TERM;
        case LSFT_T(KC_C):
            return LONG_TAPPING_TERM;
        case LCTL_T(KC_Q):
            return LONG_TAPPING_TERM;
        case RALT_T(KC_QUOTE):
            return LONG_TAPPING_TERM;
        case RSFT_T(KC_A):
            return LONG_TAPPING_TERM;
        case RCTL_T(KC_DOT):
            return LONG_TAPPING_TERM;
        //KEYPAD_SYMB
        case LGUI_T(KC_LBRC):
            return LONG_TAPPING_TERM;
        case LGUI_T(KC_KP_6):
            return LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
      break;
    case CANARY_G:
      set_layer_color(CANARY_G);
      break;
    case QWERTY_G:
      set_layer_color(QWERTY_G);
      break;
    case QWERTY_SG:
      set_layer_color(QWERTY_SG);
      break;
    case KEYPAD_SYMB:
      set_layer_color(KEYPAD_SYMB);
      break;
    case EXTRA_SYMB:
      set_layer_color(EXTRA_SYMB);
      break;
    case MOVEMENT:
      set_layer_color(MOVEMENT);
      break;
    case SHORTCUTS:
      set_layer_color(SHORTCUTS);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    bool LED_1 = false;
    bool LED_2 = false;
    bool LED_4 = false;
    bool LED_5 = false;

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case CANARY_G:
        case QWERTY_G:
        case QWERTY_SG:
            LED_2 = true;
            break;
        case KEYPAD_SYMB:
            LED_1 = true;
            break;
        case EXTRA_SYMB:
            LED_4 = true;
            break;
        case MOVEMENT:
            LED_5 = true;
            break;
        default:
            break;
    }

    ML_LED_1(LED_1);
    ML_LED_2(LED_2);
    ML_LED_4(LED_4);
    ML_LED_5(LED_5);
    return state;
}
