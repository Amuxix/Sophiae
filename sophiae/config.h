/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define TAP_CODE_DELAY 20
#undef TAPPING_TERM
#define TAPPING_TERM 130

#define ONESHOT_TAP_TOGGLE 0

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"9q5dN/545VB"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT
#define COMBO_COUNT 4

#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60

#define MOONLANDER_USER_LEDS
// Macro settings
// 10ms betweed key presses
#define DYNAMIC_MACRO_DELAY 10