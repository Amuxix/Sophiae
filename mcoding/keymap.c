#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
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
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
};

enum layers {
  _BASE, //0
  _CANARY_G, //1
  _QWERTY_G, //2
  _QWERTY_SG, //3
  _KEYPAD_SYMB, //4
  _EXTRA_SYMB, //5
  _MOVEMENT, //6
  _SHORTCUTS //7
};

#define LT_KPD(key) LT(_KEYPAD_SYMB, key)
#define LT_SYM(key) LT(_EXTRA_SYMB, key)
#define LT_MOV(key) LT(_MOVEMENT, key)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
    DM_PLY1,          _______,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            _______,          KC_F11,
    DM_PLY2,          KC_F1,            KC_L,             KC_Y,             KC_P,             KC_B,             _______,                    _______,          KC_Z,             KC_F,             KC_O,             KC_U,             KC_F10,           KC_F12,
    _______,          KC_W,             LGUI_T(KC_R),     LALT_T(KC_S),     LCTL_T(KC_T),     KC_G,             CW_TOGG,                    OSL(_SHORTCUTS),  KC_M,             LCTL_T(KC_N),     LALT_T(KC_E),     LGUI_T(KC_I),     KC_QUOTE,         _______,
    _______,          KC_C,             KC_J,             KC_V,             KC_D,             KC_K,                                                           KC_X,             KC_H,             KC_COLN,          KC_COMMA,         KC_A,             _______,
    _______,          KC_Q,             TD(DANCE_0),      TD(DANCE_1),      LT_KPD(KC_ESC),                     TD(DANCE_2),                TD(DANCE_5),                        LT_KPD(KC_DEL),   TD(DANCE_3),      TD(DANCE_4),      KC_DOT,           _______,
                                                                            LSFT_T(KC_BSPC),  LT_MOV(KC_TAB),   TD(DANCE_10),               KC_APPLICATION,   LT_SYM(KC_ENTER), RSFT_T(KC_SPACE)
  ),
  [_CANARY_G] = LAYOUT_moonlander(
    _______,          XXXXXXX,          KC_2,             KC_3,             KC_4,             KC_5,             _______,                    _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          XXXXXXX,
    _______,          KC_1,             _______,          _______,          _______,          _______,          _______,                    _______,          _______,          _______,          _______,          _______,          KC_0,             XXXXXXX,
    KC_LALT,          LALT_T(KC_W),     KC_R,             KC_S,             KC_T,             _______,          _______,                    _______,          _______,          KC_N,             KC_E,             KC_I,             RALT_T(KC_QUOTE), KC_RALT,
    KC_LSFT,          LSFT_T(KC_C),     _______,          _______,          _______,          _______,                                                        _______,          _______,          _______,          _______,          RSFT_T(KC_A),     KC_RSFT,
    KC_LCTL,          LCTL_T(KC_Q),     _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          RCTL_T(KC_DOT),   KC_RCTL,
                                                                            KC_BSPC,          _______,          _______,                    _______,          _______,          KC_SPACE
  ),
  [_QWERTY_G] = LAYOUT_moonlander(
    _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             _______,                    _______,          KC_6,             KC_7,             KC_8,             KC_9,             XXXXXXX,          XXXXXXX,
    _______,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             _______,                    _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_0,             XXXXXXX,
    KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             _______,                    _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_RALT,
    KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,                                                           KC_N,             KC_M,             _______,          _______,          KC_QUOTE,         KC_RSFT,
    KC_LCTL,          XXXXXXX,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          _______,          KC_RCTL,
                                                                            KC_SPACE,         _______,          _______,                    TD(DANCE_6),      TD(DANCE_7),      KC_BSPC
  ),
  [_QWERTY_SG] = LAYOUT_moonlander(
    _______,          _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                       _______,          KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             XXXXXXX,
    _______,          XXXXXXX,          KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                       _______,          KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             XXXXXXX,
    KC_LALT,          KC_LALT,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,                       _______,          KC_H,             KC_J,             KC_K,             KC_L,             KC_P,             KC_QUOTE,
    KC_LSFT,          KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,                                                           KC_B,             KC_N,             KC_M,             KC_COLN,          KC_COMMA,         KC_RSFT,
    KC_LCTL,          KC_LCTL,          _______,          _______,          _______,                            _______,                    _______,                            _______,          _______,          _______,          _______,          KC_RCTL,
                                                                            KC_SPACE,         _______,          KC_TAB,                     _______,          _______,          KC_BSPC
  ),
  [_KEYPAD_SYMB] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F14,           KC_F15,           KC_F16,           KC_F17,           _______,                    _______,          KC_F18,           KC_F19,           KC_F20,           KC_F21,           XXXXXXX,          KC_F23,
    XXXXXXX,          KC_F13,           KC_PERC,          KC_DLR,           KC_HASH,          US_DEG,           _______,                    _______,          KC_INSERT,        KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_F22,           KC_F24,
    XXXXXXX,          US_EURO,          LGUI_T(KC_LBRC),  TD(DANCE_8),      TD(DANCE_9),      KC_LABK,          _______,                    QK_LLCK,          KC_KP_MINUS,      LCTL_T(KC_KP_4),  LALT_T(KC_KP_5),  LGUI_T(KC_KP_6),  KC_KP_SLASH,      XXXXXXX,
    XXXXXXX,          ST_MACRO_4,       KC_RBRC,          KC_RCBR,          KC_RPRN,          KC_RABK,                                                        KC_KP_PLUS,       KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ASTERISK,   XXXXXXX,
    XXXXXXX,          ST_MACRO_5,       XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          KC_KP_0,          KC_EQUAL,         KC_KP_DOT,        XXXXXXX,
                                                                            _______,          _______,          _______,                    KC_PSCR,          _______,          _______
  ),
  [_EXTRA_SYMB] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    XXXXXXX,          KC_F1,            KC_GRAVE,         KC_CIRC,          KC_TILD,          US_DIAE,          _______,                    _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_F10,           KC_F12,
    DM_REC1,          KC_SCLN,          KC_QUES,          KC_UNDS,          KC_EQUAL,         KC_AMPR,          _______,                    QK_LLCK,          XXXXXXX,          KC_LCTL,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX,
    DM_RSTP,          KC_EXLM,          KC_BSLS,          KC_AT,            KC_DQUO,          KC_PIPE,                                                        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    DM_REC2,          ST_MACRO_6,       XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            _______,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                                                                            _______,          _______,          _______,                    _______,          _______,          _______
  ),
  [_MOVEMENT] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,                    _______,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            XXXXXXX,          KC_F11,
    XXXXXXX,          KC_F1,            XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,                    _______,          LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RIGHT),   KC_F10,           KC_F12,
    XXXXXXX,          XXXXXXX,          KC_LGUI,          KC_LALT,          KC_LCTL,          XXXXXXX,          _______,                    QK_LLCK,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT,         KC_MNXT,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                                                        KC_HOME,          KC_PGDN,          KC_PAGE_UP,       KC_END,           KC_MPLY,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          _______,                            _______,                    _______,                            KC_VOLD,          KC_MUTE,          KC_VOLU,          KC_MPRV,          XXXXXXX,
                                                                            _______,          _______,          _______,                    _______,          _______,          _______
  ),
  [_SHORTCUTS] = LAYOUT_moonlander(
    XXXXXXX,          XXXXXXX,          TO(_CANARY_G),      TO(_QWERTY_G),  TO(_QWERTY_SG),   XXXXXXX,          XXXXXXX,                    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          TO(_BASE),        XXXXXXX,            XXXXXXX,        XXXXXXX,          ST_MACRO_7,       XXXXXXX,                    XXXXXXX,          LSA_T(KC_Z),      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,            XXXXXXX,        XXXXXXX,          XXXXXXX,          XXXXXXX,                    QK_LLCK,          XXXXXXX,          XXXXXXX,          XXXXXXX,          ST_MACRO_9,       XXXXXXX,          XXXXXXX,
    XXXXXXX,          KC_CALCULATOR,    XXXXXXX,            XXXXXXX,        XXXXXXX,          XXXXXXX,                                                        XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          C_S_T(KC_ESC),    _______,            _______,        XXXXXXX,                            _______,                    _______,                            XXXXXXX,          _______,          _______,          XXXXXXX,          XXXXXXX,
                                                                            ST_MACRO_8,       XXXXXXX,          XXXXXXX,                    XXXXXXX,          XXXXXXX,          ST_MACRO_10
  ),
};
// clang-format on

const uint16_t PROGMEM combo0[] = { KC_F, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_H, KC_COLN, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_J, KC_V, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, ST_MACRO_0),
    COMBO(combo1, ST_MACRO_1),
    COMBO(combo2, ST_MACRO_2),
    COMBO(combo3, ST_MACRO_3),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_R):
            return LONG_TAPPING_TERM;
        case MT(MOD_LALT, KC_S):
            return LONG_TAPPING_TERM;
        case MT(MOD_LCTL, KC_T):
            return LONG_TAPPING_TERM;
        case TD(DANCE_0):
            return TAPPING_TERM + 45;
        case TD(DANCE_1):
            return TAPPING_TERM + 45;
        case TD(DANCE_2):
            return TAPPING_TERM + 45;
        case TD(DANCE_10):
            return TAPPING_TERM + 45;
        case LT_MOV(KC_TAB):
            return LONG_TAPPING_TERM;
        case MT(MOD_LCTL, KC_N):
            return LONG_TAPPING_TERM;
        case MT(MOD_LALT, KC_E):
            return LONG_TAPPING_TERM;
        case MT(MOD_LGUI, KC_I):
            return LONG_TAPPING_TERM;
        case LT_SYM(KC_ENTER):
            return LONG_TAPPING_TERM;
        case MT(MOD_RSFT, KC_SPACE):
            return TAPPING_TERM + 30;
        case MT(MOD_LALT, KC_W):
            return LONG_TAPPING_TERM;
        case MT(MOD_LSFT, KC_C):
            return LONG_TAPPING_TERM;
        case MT(MOD_LCTL, KC_Q):
            return LONG_TAPPING_TERM;
        case KC_BSPC:
            return LONG_TAPPING_TERM;
        case _______:
            return LONG_TAPPING_TERM;
        case MT(MOD_RALT, KC_QUOTE):
            return LONG_TAPPING_TERM;
        case MT(MOD_RSFT, KC_A):
            return LONG_TAPPING_TERM;
        case MT(MOD_RCTL, KC_DOT):
            return LONG_TAPPING_TERM;
        case KC_SPACE:
            return LONG_TAPPING_TERM;
        case TD(DANCE_6):
            return TAPPING_TERM + 70;
        case TD(DANCE_7):
            return TAPPING_TERM + 45;
        case MT(MOD_LGUI, KC_LBRC):
            return LONG_TAPPING_TERM;
        case MT(MOD_LGUI, KC_KP_6):
            return LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

//this is each layers colours in RBG column by column
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    //[_BASE] = { {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,245,245}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {243,255,185}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245} },
    [_BASE] = LED_LAYOUT_moonlander(
      {202,122,255}, {0,0,0},       {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0},                      {0,0,0},       {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0},       {202,122,255},
      {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0},                      {0,0,0},       {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255},
      {0,0,0},       {202,122,255}, {205,255,192}, {205,255,192}, {205,255,192}, {202,122,255}, {0,245,245},                  {243,255,185}, {202,122,255}, {205,255,192}, {205,255,192}, {205,255,192}, {202,122,255}, {0,0,0},
      {0,0,0},       {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255},                                              {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {0,0,0},
      {0,0,0},       {202,122,255}, {202,122,255}, {202,122,255}, {0,245,245},                  {0,245,245},                  {0,245,245},                  {0,245,245},   {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0},
                                                                  {205,255,192}, {202,122,255}, {202,122,255},                {202,122,255}, {202,122,255}, {205,255,192},
    )

    { {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,245,245}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {243,255,185}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245} },

    [_CANARY_G] = { {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,245,245}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {243,255,185}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245} },

    [_QWERTY_G] = { {205,255,192}, {205,255,192}, {0,245,245}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {0,0,0}, {205,255,192}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,0,0}, {0,0,0}, {243,255,185}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245} },

    [_QWERTY_SG] = { {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {140,162,251}, {140,162,251}, {140,162,251}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {140,162,251}, {140,162,251}, {140,162,251}, {249,77,245} },

    [_KEYPAD_SYMB] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {0,245,245}, {64,255,116}, {63,255,202}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {202,122,255}, {64,255,116}, {63,255,202}, {63,255,202}, {0,245,245} },

    [_EXTRA_SYMB] = { {0,0,0}, {0,0,0}, {29,255,231}, {29,255,231}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,245,245}, {202,122,255}, {29,255,231}, {29,255,231}, {29,255,231}, {0,0,0}, {0,0,0}, {0,245,245}, {28,255,134}, {29,255,231}, {29,255,231}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,245,245}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {28,255,134}, {29,255,231}, {29,255,231}, {0,245,245} },

    [_MOVEMENT] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,245,245}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {150,255,190}, {152,140,255}, {152,140,255}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {0,0,0}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {0,0,0}, {152,140,255}, {152,140,255}, {0,0,0}, {0,0,0}, {205,255,192}, {150,255,190}, {152,140,255}, {152,140,255}, {0,245,245} },

    [_SHORTCUTS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,192}, {0,0,0}, {243,255,185}, {253,125,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,77,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,140,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,140,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,255} },

};

void set_led_color(int led, HSV hsv) {
  if (!hsv.h && !hsv.s && !hsv.v) {
    rgb_matrix_set_color(led, 0, 0, 0);
  } else {
    RGB rgb = hsv_to_rgb(hsv);
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
}

void set_layer_color(int layer) {
  for (int led = 0; led < RGB_MATRIX_LED_COUNT; led++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][led][0]),
      .s = pgm_read_byte(&ledmap[layer][led][1]),
      .v = pgm_read_byte(&ledmap[layer][led][2]),
    };
    set_led_color(led, hsv);
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _CANARY_G:
      set_layer_color(_CANARY_G);
      break;
    case _QWERTY_G:
      set_layer_color(_QWERTY_G);
      break;
    case _QWERTY_SG:
      set_layer_color(_QWERTY_SG);
      break;
    case _KEYPAD_SYMB:
      set_layer_color(_KEYPAD_SYMB);
      break;
    case _EXTRA_SYMB:
      set_layer_color(_EXTRA_SYMB);
      break;
    case _MOVEMENT:
      set_layer_color(_MOVEMENT);
      break;
    case _SHORTCUTS:
      set_layer_color(_SHORTCUTS);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

void caps_word_set_user(bool active) {
    if (active) {
        //HSV hsv = {.h = 0, .s = 245, .v = 245}
        //set_led_color(31, hsv)
        ML_LED_3(true);
        ML_LED_6(true);
    } else {
        //HSV hsv = {.h = 0, .s = 0, .v = 0}
        //set_led_color(31, hsv)
        ML_LED_3(false);
        ML_LED_6(false);
    }
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    if (is_launching || !keyboard_config.led_level) return state;
    bool LED_1 = false;
    bool LED_2 = false;
    bool LED_4 = false;
    bool LED_5 = false;

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _CANARY_G:
        case _QWERTY_G:
        case _QWERTY_SG:
            LED_2 = true;
            break;
        case _KEYPAD_SYMB:
            LED_1 = true;
            break;
        case _EXTRA_SYMB:
            LED_4 = true;
            break;
        case _MOVEMENT:
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

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[11];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: register_code16(LCTL(LSFT(KC_X))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LSFT(KC_X))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_V)); register_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_V)); register_code16(LCTL(KC_V));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_BSLS));
        tap_code16(LCTL(KC_BSLS));
        tap_code16(LCTL(KC_BSLS));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_BSLS));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_BSLS)); break;
        case DOUBLE_TAP: register_code16(C_S_T(KC_BSLS)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_BSLS)); register_code16(LCTL(KC_BSLS));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
        case DOUBLE_TAP: unregister_code16(C_S_T(KC_BSLS)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Z));
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: register_code16(C_S_T(KC_Z)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(C_S_T(KC_Z)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Y));
        tap_code16(LCTL(KC_Y));
        tap_code16(LCTL(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Y));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Y)); break;
        case SINGLE_HOLD: register_code16(C_S_T(KC_Y)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        case SINGLE_HOLD: unregister_code16(C_S_T(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: register_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[5].step = 0;
}
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case DOUBLE_TAP: layer_move(_BASE); break;
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
    }
    dance_state[6].step = 0;
}
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case DOUBLE_HOLD: layer_on(_EXTRA_SYMB); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
              case DOUBLE_HOLD:
                if(!is_layer_locked(_EXTRA_SYMB)) {
                  layer_off(_EXTRA_SYMB);
                }
                break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(QK_REPEAT_KEY);
        tap_code16(QK_REPEAT_KEY);
        tap_code16(QK_REPEAT_KEY);
    }
    if(state->count > 3) {
        tap_code16(QK_REPEAT_KEY);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(QK_REPEAT_KEY); break;
        case DOUBLE_TAP: register_code16(QK_ALT_REPEAT_KEY); break;
        case DOUBLE_SINGLE_TAP: tap_code16(QK_REPEAT_KEY); register_code16(QK_REPEAT_KEY);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
        case DOUBLE_TAP: unregister_code16(QK_ALT_REPEAT_KEY); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(QK_REPEAT_KEY); break;
    }
    dance_state[10].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
};
