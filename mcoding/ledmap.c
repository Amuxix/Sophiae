#define LAVENDER_TEA  {202,122,255}
#define FOXY_FUCHSIA  {205,255,192}
#define VITAMIN_C     {  0,245,245}
#define TRAD_ROSE     {243,255,185}
#define SKYAN         {140,162,251}
#define BABY_MOUTH    {249,77, 245}
#define WHITE         {  0,  0,255}
#define BLINKING_TERM { 63,255,202}
#define SERICOURT     { 64,255,116}
#define HOT_BUTTER    { 29,255,231}
#define SOIL_AVAGDDU  { 28,255,134}
#define SKY_BLUE      {152,140,255}
#define SAPPHIRE_BLUE {150,255,190}
#define CAMARON_PINK  {253,125,255}
#define XXXXXXXXXXXXX {  0,  0,  0}

#define CAPS_WORDS_LED_ID 31
#define GUI_CTRL_SWAP_LED_ID 29
#define LAYER_LOCK_LED_ID 67
#define SPACE_SWAP_LED_ID 65

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// clang-format off
uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = LED_LAYOUT_moonlander(
      LAVENDER_TEA,  XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX, LAVENDER_TEA,
      LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX,                XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
      XXXXXXXXXXXXX, LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  VITAMIN_C,                    TRAD_ROSE,     LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,                                               LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA,  XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX,
                                                                  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,                 LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA
    ),
    [CANARY_G] = LED_LAYOUT_moonlander(
      LAVENDER_TEA,  XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX, LAVENDER_TEA,
      LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX,                XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
      LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  VITAMIN_C,                    TRAD_ROSE,     LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,
      LAVENDER_TEA,  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,                                               LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA,  LAVENDER_TEA,
      LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
                                                                  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,                 LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA
    ),
    [QWERTY_G] = LED_LAYOUT_moonlander(
      FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,                    VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  XXXXXXXXXXXXX, FOXY_FUCHSIA,
      FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  XXXXXXXXXXXXX,                XXXXXXXXXXXXX, FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,
      FOXY_FUCHSIA,  VITAMIN_C,     VITAMIN_C,     VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,                    TRAD_ROSE,     FOXY_FUCHSIA,  VITAMIN_C,     VITAMIN_C,     VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,
      FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,                                               FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,     FOXY_FUCHSIA,
      FOXY_FUCHSIA,  XXXXXXXXXXXXX, FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,
                                                                  VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,                 FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C
    ),
    [QWERTY_SG] = LED_LAYOUT_moonlander(
      SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         VITAMIN_C,                    SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,
      BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,                   XXXXXXXXXXXXX, BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,
      WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         VITAMIN_C,                    TRAD_ROSE,     WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,
      BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,                                                 BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,
      SKYAN,         SKYAN,         SKYAN,         SKYAN,         VITAMIN_C,                    BABY_MOUTH,                   BABY_MOUTH,                   VITAMIN_C,     SKYAN,         SKYAN,         SKYAN,         SKYAN,
                                                                  SKYAN,         SKYAN,         SKYAN,                        SKYAN,         SKYAN,         SKYAN
    ),
    [KEYPAD_SYMB] = LED_LAYOUT_moonlander(
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, VITAMIN_C,                    VITAMIN_C,     BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, XXXXXXXXXXXXX, BLINKING_TERM,
      XXXXXXXXXXXXX, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, XXXXXXXXXXXXX,                XXXXXXXXXXXXX, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM,
      XXXXXXXXXXXXX, BLINKING_TERM, SERICOURT,     SERICOURT,     SERICOURT,     BLINKING_TERM, VITAMIN_C,                    TRAD_ROSE,     BLINKING_TERM, SERICOURT,     SERICOURT,     SERICOURT,     BLINKING_TERM, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, SERICOURT,     BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM,                                              BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, BLINKING_TERM, XXXXXXXXXXXXX, XXXXXXXXXXXXX, VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, XXXXXXXXXXXXX,
                                                                  SERICOURT,     BLINKING_TERM, BLINKING_TERM,                BLINKING_TERM, BLINKING_TERM, SERICOURT
    ),
    [EXTRA_SYMB] = LED_LAYOUT_moonlander(
      HOT_BUTTER,    XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  XXXXXXXXXXXXX, LAVENDER_TEA,
      HOT_BUTTER,    LAVENDER_TEA,  HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    XXXXXXXXXXXXX,                XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,
      XXXXXXXXXXXXX, HOT_BUTTER,    SOIL_AVAGDDU,  SOIL_AVAGDDU,  SOIL_AVAGDDU,  HOT_BUTTER,    VITAMIN_C,                    TRAD_ROSE,     XXXXXXXXXXXXX, SOIL_AVAGDDU,  SOIL_AVAGDDU,  SOIL_AVAGDDU,  XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, SOIL_AVAGDDU,  HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,                                                 XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, HOT_BUTTER,    XXXXXXXXXXXXX, XXXXXXXXXXXXX, VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
                                                                  SOIL_AVAGDDU,  HOT_BUTTER,    HOT_BUTTER,                   HOT_BUTTER,    HOT_BUTTER,    SOIL_AVAGDDU
    ),
    [MOVEMENT] = LED_LAYOUT_moonlander(
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
      XXXXXXXXXXXXX, LAVENDER_TEA,  XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,                XXXXXXXXXXXXX, SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      LAVENDER_TEA,  LAVENDER_TEA,
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, SAPPHIRE_BLUE, SAPPHIRE_BLUE, SAPPHIRE_BLUE, XXXXXXXXXXXXX, VITAMIN_C,                    TRAD_ROSE,     SKY_BLUE,      SAPPHIRE_BLUE, SAPPHIRE_BLUE, SAPPHIRE_BLUE, SKY_BLUE,      XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,                                              SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SAPPHIRE_BLUE, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      XXXXXXXXXXXXX,
                                                                  SAPPHIRE_BLUE,  SKY_BLUE,     SKY_BLUE,                     SKY_BLUE,      SKY_BLUE,      SAPPHIRE_BLUE
    ),
    [SHORTCUTS] = LED_LAYOUT_moonlander(
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, LAVENDER_TEA,  VITAMIN_C,       BABY_MOUTH,  XXXXXXXXXXXXX, XXXXXXXXXXXXX,                XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, FOXY_FUCHSIA,  XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, SKY_BLUE,      XXXXXXXXXXXXX,                XXXXXXXXXXXXX, CAMARON_PINK,  XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,                LAVENDER_TEA,  XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, SKY_BLUE,      XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, TRAD_ROSE,     XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,                                              XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
      XXXXXXXXXXXXX, CAMARON_PINK,  XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,                WHITE,                        WHITE,                        XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX, XXXXXXXXXXXXX,
                                                                  CAMARON_PINK,  XXXXXXXXXXXXX, XXXXXXXXXXXXX,                XXXXXXXXXXXXX, XXXXXXXXXXXXX, CAMARON_PINK
    ),
};
// clang-format on

void set_led_color(int layer, int led, HSV hsv, bool force) {
  if (led == CAPS_WORDS_LED_ID && is_caps_word_on()) return; // cool effect
  if (led == LAYER_LOCK_LED_ID && is_layer_locked(layer)) return; // cool effect

  if (led == SPACE_SWAP_LED_ID && IS_LAYER_ON(SPACE_SWAP)) {
    hsv = (HSV)SAPPHIRE_BLUE;
  }

  if (led == GUI_CTRL_SWAP_LED_ID && MAC_MODE) {
    hsv = (HSV)SAPPHIRE_BLUE;
  }

  if (!hsv.h && !hsv.s && !hsv.v) {
    rgb_matrix_set_color(led, 0, 0, 0);
  } else {
    RGB rgb = hsv_to_rgb(hsv);
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
}

void set_led_color_from_layermap(int layer, int led) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][led][0]),
      .s = pgm_read_byte(&ledmap[layer][led][1]),
      .v = pgm_read_byte(&ledmap[layer][led][2]),
    };
    set_led_color(layer, led, hsv, false);
}

void set_layer_color(int layer) {
  for (int led = 0; led < RGB_MATRIX_LED_COUNT; led++) {
    set_led_color_from_layermap(layer, led);
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (get_highest_layer(layer_state & ~((layer_state_t)1 << SPACE_SWAP))) {
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
