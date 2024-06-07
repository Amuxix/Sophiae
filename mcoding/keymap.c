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
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    DM_PLY1,        KC_TRANSPARENT, KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_F11,         
    DM_PLY2,        KC_F1,          KC_L,           KC_Y,           KC_P,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Z,           KC_F,           KC_O,           KC_U,           KC_F10,         KC_F12,         
    KC_TRANSPARENT, KC_W,           MT(MOD_LGUI, KC_R),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_T),KC_G,           CW_TOGG,                                                                        OSL(7),         KC_M,           MT(MOD_LCTL, KC_N),MT(MOD_LALT, KC_E),MT(MOD_LGUI, KC_I),KC_QUOTE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_C,           KC_J,           KC_V,           KC_D,           KC_K,                                           KC_X,           KC_H,           KC_COLN,        KC_COMMA,       KC_A,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           TD(DANCE_0),    TD(DANCE_1),    LT(4,KC_ESCAPE),TD(DANCE_2),                                                                                                    TD(DANCE_5),    LT(4,KC_DELETE),TD(DANCE_3),    TD(DANCE_4),    KC_DOT,         KC_TRANSPARENT, 
    MT(MOD_LSFT, KC_BSPC),LT(6,KC_TAB),   KC_TRANSPARENT,                 KC_APPLICATION, LT(5,KC_ENTER), MT(MOD_RSFT, KC_SPACE)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_1,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_NO,          
    KC_LEFT_ALT,    MT(MOD_LALT, KC_W),KC_R,           KC_S,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_N,           KC_E,           KC_I,           MT(MOD_RALT, KC_QUOTE),KC_RIGHT_ALT,   
    KC_LEFT_SHIFT,  MT(MOD_LSFT, KC_C),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_RSFT, KC_A),KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_Q),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_RCTL, KC_DOT),KC_RIGHT_CTRL,  
    KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_0,           KC_NO,          
    KC_LEFT_ALT,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_P,           KC_RIGHT_ALT,   
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,       KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                 TD(DANCE_6),    TD(DANCE_7),    KC_BSPC
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,          
    KC_LEFT_ALT,    KC_LEFT_ALT,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_P,           KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_B,           KC_N,           KC_M,           KC_COLN,        KC_COMMA,       KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_SPACE,       KC_TRANSPARENT, KC_TAB,                         KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_F14,         KC_F15,         KC_F16,         KC_F17,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F18,         KC_F19,         KC_F20,         KC_F21,         KC_NO,          KC_F23,         
    KC_NO,          KC_F13,         KC_PERC,        KC_DLR,         KC_HASH,        US_DEG,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_INSERT,      KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_F22,         KC_F24,         
    KC_NO,          US_EURO,        MT(MOD_LGUI, KC_LBRC),TD(DANCE_8),    TD(DANCE_9),    KC_LABK,        KC_TRANSPARENT,                                                                 QK_LLCK,        KC_KP_MINUS,    MT(MOD_LCTL, KC_KP_4),MT(MOD_LALT, KC_KP_5),MT(MOD_LGUI, KC_KP_6),KC_KP_SLASH,    KC_NO,          
    KC_NO,          ST_MACRO_4,     KC_RBRC,        KC_RCBR,        KC_RPRN,        KC_RABK,                                        KC_KP_PLUS,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ASTERISK, KC_NO,          
    KC_NO,          ST_MACRO_5,     KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_0,        KC_EQUAL,       KC_KP_DOT,      KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_NO,          KC_F11,         
    KC_NO,          KC_F1,          KC_GRAVE,       KC_CIRC,        KC_TILD,        US_DIAE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F10,         KC_F12,         
    DM_REC1,        KC_SCLN,        KC_QUES,        KC_UNDS,        KC_EQUAL,       KC_AMPR,        KC_TRANSPARENT,                                                                 QK_LLCK,        KC_NO,          KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,          KC_NO,          
    DM_RSTP,        KC_EXLM,        KC_BSLS,        KC_AT,          KC_DQUO,        KC_PIPE,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    DM_REC2,        ST_MACRO_6,     KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_NO,          KC_F11,         
    KC_NO,          KC_F1,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_LEFT),  LSFT(KC_DOWN),  LSFT(KC_UP),    LSFT(KC_RIGHT), KC_F10,         KC_F12,         
    KC_NO,          KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          KC_TRANSPARENT,                                                                 QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MEDIA_NEXT_TRACK,KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_MEDIA_PLAY_PAUSE,KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          TO(1),          TO(2),          TO(3),          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          TO(0),          KC_NO,          KC_NO,          KC_NO,          ST_MACRO_7,     KC_NO,                                          KC_NO,          LALT(LSFT(KC_Z)),KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          QK_LLCK,        KC_NO,          KC_NO,          KC_NO,          ST_MACRO_9,     KC_NO,          KC_NO,          
    KC_NO,          KC_CALCULATOR,  KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          LCTL(LSFT(KC_ESCAPE)),KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          
    ST_MACRO_8,     KC_NO,          KC_NO,                          KC_NO,          KC_NO,          ST_MACRO_10
  ),
};
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
            return TAPPING_TERM + 20;
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 20;
        case MT(MOD_LCTL, KC_T):
            return TAPPING_TERM + 20;
        case TD(DANCE_0):
            return TAPPING_TERM + 45;
        case TD(DANCE_1):
            return TAPPING_TERM + 45;
        case TD(DANCE_2):
            return TAPPING_TERM + 45;
        case LT(6,KC_TAB):
            return TAPPING_TERM + 20;
        case MT(MOD_LCTL, KC_N):
            return TAPPING_TERM + 20;
        case MT(MOD_LALT, KC_E):
            return TAPPING_TERM + 20;
        case MT(MOD_LGUI, KC_I):
            return TAPPING_TERM + 20;
        case LT(5,KC_ENTER):
            return TAPPING_TERM + 20;
        case MT(MOD_RSFT, KC_SPACE):
            return TAPPING_TERM + 30;
        case MT(MOD_LALT, KC_W):
            return TAPPING_TERM + 20;
        case MT(MOD_LSFT, KC_C):
            return TAPPING_TERM + 20;
        case MT(MOD_LCTL, KC_Q):
            return TAPPING_TERM + 20;
        case KC_BSPC:
            return TAPPING_TERM + 20;
        case KC_TRANSPARENT:
            return TAPPING_TERM + 20;
        case MT(MOD_RALT, KC_QUOTE):
            return TAPPING_TERM + 20;
        case MT(MOD_RSFT, KC_A):
            return TAPPING_TERM + 20;
        case MT(MOD_RCTL, KC_DOT):
            return TAPPING_TERM + 20;
        case KC_SPACE:
            return TAPPING_TERM + 20;
        case TD(DANCE_6):
            return TAPPING_TERM + 70;
        case TD(DANCE_7):
            return TAPPING_TERM + 45;
        case MT(MOD_LGUI, KC_LBRC):
            return TAPPING_TERM + 20;
        case MT(MOD_LGUI, KC_KP_6):
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,245,245}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {243,255,185}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245} },

    [1] = { {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,245,245}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {205,255,192}, {202,122,255}, {0,245,245}, {202,122,255}, {202,122,255}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {243,255,185}, {205,255,192}, {202,122,255}, {202,122,255}, {0,245,245} },

    [2] = { {205,255,192}, {205,255,192}, {0,245,245}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {0,0,0}, {205,255,192}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,245,245}, {205,255,192}, {0,245,245}, {205,255,192}, {205,255,192}, {205,255,192}, {205,255,192}, {0,0,0}, {0,0,0}, {243,255,185}, {0,245,245}, {205,255,192}, {205,255,192}, {0,245,245} },

    [3] = { {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {140,162,251}, {140,162,251}, {140,162,251}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {140,162,251}, {249,77,245}, {0,0,255}, {249,77,245}, {140,162,251}, {249,77,245}, {0,0,255}, {140,162,251}, {140,162,251}, {140,162,251}, {249,77,245} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,0,0}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {0,245,245}, {64,255,116}, {63,255,202}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {64,255,116}, {63,255,202}, {0,245,245}, {63,255,202}, {63,255,202}, {63,255,202}, {63,255,202}, {0,0,0}, {0,0,0}, {202,122,255}, {64,255,116}, {63,255,202}, {63,255,202}, {0,245,245} },

    [5] = { {0,0,0}, {0,0,0}, {29,255,231}, {29,255,231}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,0,0}, {202,122,255}, {29,255,231}, {28,255,134}, {29,255,231}, {0,245,245}, {202,122,255}, {29,255,231}, {29,255,231}, {29,255,231}, {0,0,0}, {0,0,0}, {0,245,245}, {28,255,134}, {29,255,231}, {29,255,231}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {28,255,134}, {0,0,0}, {0,245,245}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {28,255,134}, {29,255,231}, {29,255,231}, {0,245,245} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,0,0}, {202,122,255}, {0,0,0}, {150,255,190}, {0,0,0}, {0,245,245}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {150,255,190}, {152,140,255}, {152,140,255}, {0,245,245}, {202,122,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {152,140,255}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {0,0,0}, {150,255,190}, {152,140,255}, {152,140,255}, {202,122,255}, {0,0,0}, {152,140,255}, {152,140,255}, {0,0,0}, {0,0,0}, {205,255,192}, {150,255,190}, {152,140,255}, {152,140,255}, {0,245,245} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,192}, {0,0,0}, {243,255,185}, {253,125,255}, {202,122,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,77,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,140,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,140,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {202,122,255}, {253,125,255}, {0,0,0}, {0,0,0}, {0,0,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_S));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_DELAY(100) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_COMMA))) SS_DELAY(100) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_S));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_MINUS));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(100) SS_RCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_LCTL(SS_TAP(X_RIGHT)));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LEFT)) SS_DELAY(100) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RIGHT)));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(100) SS_LCTL(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_LCTL(SS_TAP(X_RIGHT)));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LEFT)) SS_DELAY(100) SS_TAP(X_TAB) SS_DELAY(100) SS_LSFT(SS_TAP(X_RIGHT)));
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

static tap dance_state[10];

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
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_BSLS))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_BSLS)); register_code16(LCTL(KC_BSLS));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_BSLS)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_BSLS))); break;
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
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_Z))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_Z))); break;
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
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_Y))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Y)); register_code16(LCTL(KC_Y));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_Y))); break;
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
        case DOUBLE_TAP: layer_move(0); break;
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
        case DOUBLE_HOLD: layer_on(5); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
              case DOUBLE_HOLD: 
                if(!is_layer_locked(5)) {
                  layer_off(5);
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
};
