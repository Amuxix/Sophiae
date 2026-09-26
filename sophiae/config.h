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
#define SERIAL_NUMBER "9q5dN/KryAPa"
// #define RAW_USAGE_PAGE 0xFF60
// #define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT
#define COMBO_COUNT 4

#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60

#define MOONLANDER_USER_LEDS
// Uncomment to persist config changes (e.g. mac_mode) to EEPROM across power cycles
// #define SAVE_TO_EEPROM

// Macro settings
// 10ms between key presses
#define DYNAMIC_MACRO_DELAY 10