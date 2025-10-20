#include "sophiae.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    DM_PLY1,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            TG(SPACE_SWAP),             MAC_MODE_TOGG,    KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    DM_PLY2,          KC_F1,            KC_L,             KC_Y,             KC_P,             KC_B,             XXXXXXX,                    CG_TOGG,          KC_Z,             KC_F,             KC_O,             KC_U,             KC_F10,           KC_F12,
    XXXXXXX,          KC_W,             LGUI_T(KC_R),     LALT_T(KC_S),     LCTL_T(KC_T),     KC_G,             TD(CAPS_WORDS_DANCE),       OSL(SHORTCUTS),   KC_M,             LCTL_T(KC_N),     LALT_T(KC_E),     LGUI_T(KC_I),     KC_QUOTE,         XXXXXXX,
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
                                                                            KC_BSPC,          _______,          _______,                    _______,          _______,          KC_SPACE
  ),
  [QWERTY_G] = LAYOUT_moonlander(
    _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             _______,                    _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          KC_F11,
    _______,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             _______,                    _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_0,             KC_F12,
    KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             _______,                    _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_RALT,
    KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,                                                           KC_N,             KC_M,             KC_COLN,          KC_COMMA,         KC_QUOTE,         KC_RSFT,
    KC_LCTL,          XXXXXXX,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          KC_DOT,           KC_RCTL,
                                                                            KC_SPACE,         _______,          _______,                    _______,          _______,          KC_BSPC
  ),
  [QWERTY_SG] = LAYOUT_moonlander(
    _______,          _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                       _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          KC_F11,
    _______,          XXXXXXX,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                       _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_0,             KC_F12,
    KC_LALT,          KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,                       _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_RALT,
    KC_LSFT,          KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,                                                           KC_B,             KC_N,             KC_M,             KC_COMMA,         KC_QUOTE,         KC_RSFT,
    KC_LCTL,          KC_LCTL,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          KC_DOT,           KC_RCTL,
                                                                            KC_SPACE,         _______,          _______,                    _______,          _______,          KC_BSPC
  ),
  [SPACE_SWAP] = LAYOUT_moonlander(
    _______,          _______,          _______,          _______,          _______,          _______,          _______,                    _______,          _______,          _______,          _______,          _______,          _______,          _______,
    _______,          _______,          _______,          _______,          _______,          _______,          _______,                    _______,          _______,          _______,          _______,          _______,          _______,          _______,
    _______,          _______,          _______,          _______,          _______,          _______,          _______,                    _______,          _______,          _______,          _______,          _______,          _______,          _______,
    _______,          _______,          _______,          _______,          _______,          _______,                                                        _______,          _______,          _______,          _______,          _______,          _______,
    _______,          _______,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          _______,          _______,
                                                                            KC_SPACE,         _______,          _______,                    _______,          _______,          KC_BSPC
  ),
  [KEYPAD_SYMB] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F14,           KC_F15,           KC_F16,           KC_F17,           _______,                    _______,          KC_F18,           KC_F19,           KC_F20,           KC_F21,           XXXXXXX,          KC_F23,
    XXXXXXX,          KC_F13,           KC_PERC,          KC_DLR,           KC_HASH,          POUND,            _______,                    _______,          KC_INSERT,        KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_F22,           KC_F24,
    XXXXXXX,          EURO,             LGUI_T(KC_LBRC),  TD(LALT_LBRACK),  TD(LCTL_LPAREN),  KC_LABK,          _______,                    QK_LLCK,          KC_KP_MINUS,      LCTL_T(KC_KP_4),  LALT_T(KC_KP_5),  LGUI_T(KC_KP_6),  KC_KP_SLASH,      XXXXXXX,
    XXXXXXX,          LEFT_ARROW,       KC_RBRC,          KC_RCBR,          KC_RPRN,          KC_RABK,                                                        KC_KP_PLUS,       KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ASTERISK,   XXXXXXX,
    XXXXXXX,          RIGHT_ARROW,      XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          KC_KP_0,          KC_EQUAL,         KC_KP_DOT,        XXXXXXX,
                                                                            KC_BSPC,          _______,          _______,                    SNIPPING,         _______,          KC_SPACE
  ),
  [EXTRA_SYMB] = LAYOUT_moonlander(
    DM_REC1,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    DM_REC2,          KC_F1,            KC_GRAVE,         KC_CIRC,          KC_TILD,          DEGREE,           _______,                    _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_F10,           KC_F12,
    XXXXXXX,          KC_SCLN,          KC_QUES,          KC_UNDS,          KC_EQUAL,         KC_AMPR,          _______,                    QK_LLCK,          XXXXXXX,          KC_LCTL,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          KC_EXLM,          KC_BSLS,          KC_AT,            KC_DQUO,          KC_PIPE,                                                        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          EQ_RIGHT_ARROW,   XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                                                                            KC_BSPC,          _______,          _______,                    _______,          _______,          KC_SPACE
  ),
  [MOVEMENT] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    XXXXXXX,          KC_F1,            XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,                    _______,          LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RIGHT),   KC_F10,           KC_F12,
    XXXXXXX,          XXXXXXX,          KC_LGUI,          KC_LALT,          KC_LCTL,          XXXXXXX,          _______,                    QK_LLCK,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT,         KC_MNXT,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                                                        HOME,             KC_PGDN,          KC_PAGE_UP,       END,              KC_MPLY,          XXXXXXX,
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
