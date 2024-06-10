#include "ledmap.h"

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
#define _____________ {  0,  0,  0}

// clang-format off
uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = LED_LAYOUT_moonlander(
      LAVENDER_TEA,  _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________, LAVENDER_TEA,
      LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
      _____________, LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  VITAMIN_C,                    TRAD_ROSE,     LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  _____________,
      _____________, FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,                                               LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA,  _____________,
      _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,
                                                                  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,                 LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA
    ),
    [CANARY_G] = LED_LAYOUT_moonlander(
      LAVENDER_TEA,  _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________, _____________,
      LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,
      _____________, LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  VITAMIN_C,                    TRAD_ROSE,     LAVENDER_TEA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  LAVENDER_TEA,  _____________,
      _____________, FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,                                               LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA,  _____________,
      _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,
                                                                  FOXY_FUCHSIA,  LAVENDER_TEA,  LAVENDER_TEA,                 LAVENDER_TEA,  LAVENDER_TEA,  FOXY_FUCHSIA
    ),
    [QWERTY_G] = LED_LAYOUT_moonlander(
      FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  _____________,                _____________, FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  _____________, _____________,
      FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  _____________,                _____________, FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  _____________,
      VITAMIN_C,     VITAMIN_C,     VITAMIN_C,     VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,                    TRAD_ROSE,     FOXY_FUCHSIA,  VITAMIN_C,     VITAMIN_C,     VITAMIN_C,     FOXY_FUCHSIA,  VITAMIN_C,
      VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,                                               FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,     VITAMIN_C,
      VITAMIN_C,     _____________, FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C,
                                                                  VITAMIN_C,     FOXY_FUCHSIA,  FOXY_FUCHSIA,                 FOXY_FUCHSIA,  FOXY_FUCHSIA,  VITAMIN_C
    ),
    [QWERTY_SG] = LED_LAYOUT_moonlander(
      SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,                        SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,
      BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,                   BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,
      WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,                        WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,         WHITE,
      BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,                                                 BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,    BABY_MOUTH,
      SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,                        BABY_MOUTH,                   BABY_MOUTH,                   SKYAN,         SKYAN,         SKYAN,         SKYAN,         SKYAN,
                                                                  SKYAN,         SKYAN,         SKYAN,                        SKYAN,         SKYAN,         SKYAN
    ),
    [KEYPAD_SYMB] = LED_LAYOUT_moonlander(
      _____________, _____________, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, _____________,                _____________, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, _____________, BLINKING_TERM,
      _____________, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, _____________,                _____________, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM,
      _____________, BLINKING_TERM, SERICOURT,     SERICOURT,     SERICOURT,     BLINKING_TERM, VITAMIN_C,                    LAVENDER_TEA,  BLINKING_TERM, SERICOURT,     SERICOURT,     SERICOURT,     BLINKING_TERM, _____________,
      _____________, SERICOURT,     BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM,                                              BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, _____________,
      _____________, BLINKING_TERM, _____________, _____________, VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     BLINKING_TERM, BLINKING_TERM, BLINKING_TERM, _____________,
                                                                  SERICOURT,     BLINKING_TERM, BLINKING_TERM,                BLINKING_TERM, BLINKING_TERM, SERICOURT
    ),
    [EXTRA_SYMB] = LED_LAYOUT_moonlander(
      _____________, _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________, LAVENDER_TEA,
      _____________, LAVENDER_TEA,  HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    _____________,                _____________, _____________, _____________, _____________, _____________, LAVENDER_TEA,  LAVENDER_TEA,
      HOT_BUTTER,    HOT_BUTTER,    SOIL_AVAGDDU,  SOIL_AVAGDDU,  SOIL_AVAGDDU,  HOT_BUTTER,    VITAMIN_C,                    LAVENDER_TEA,  _____________, SOIL_AVAGDDU,  SOIL_AVAGDDU,  SOIL_AVAGDDU,  _____________, _____________,
      HOT_BUTTER,    SOIL_AVAGDDU,  HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,    HOT_BUTTER,                                                 _____________, _____________, _____________, _____________, _____________, _____________,
      HOT_BUTTER,    HOT_BUTTER,    _____________, _____________, VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,                    VITAMIN_C,     _____________, _____________, _____________, _____________,
                                                                  SOIL_AVAGDDU,  HOT_BUTTER,    HOT_BUTTER,                   HOT_BUTTER,    HOT_BUTTER,    SOIL_AVAGDDU
    ),
    [MOVEMENT] = LED_LAYOUT_moonlander(
      _____________, _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  _____________,                _____________, LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,  LAVENDER_TEA,
      _____________, LAVENDER_TEA,  _____________, _____________, _____________, _____________, _____________,                _____________, SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      LAVENDER_TEA,  LAVENDER_TEA,
      _____________, _____________, SAPPHIRE_BLUE, SAPPHIRE_BLUE, SAPPHIRE_BLUE, _____________, VITAMIN_C,                     FOXY_FUCHSIA, SKY_BLUE,      SAPPHIRE_BLUE, SAPPHIRE_BLUE, SAPPHIRE_BLUE, SKY_BLUE,      _____________,
      _____________, _____________, _____________, _____________, _____________, _____________,                                              SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SAPPHIRE_BLUE, _____________,
      _____________, _____________, _____________, _____________, VITAMIN_C,                    VITAMIN_C,                     VITAMIN_C,                   SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      SKY_BLUE,      _____________,
                                                                  SAPPHIRE_BLUE,  SKY_BLUE,     SKY_BLUE,                      SKY_BLUE,     SKY_BLUE,      SAPPHIRE_BLUE
    ),
    [SHORTCUTS] = LED_LAYOUT_moonlander(
      _____________, _____________, LAVENDER_TEA,  VITAMIN_C,       BABY_MOUTH,  _____________, _____________,                _____________, _____________, _____________, _____________, _____________, _____________, _____________,
      _____________, FOXY_FUCHSIA,  _____________, _____________, _____________, SKY_BLUE,      _____________,                _____________, CAMARON_PINK,  _____________, _____________, _____________, _____________, _____________,
      _____________, _____________, _____________, _____________, _____________, _____________, _____________,                LAVENDER_TEA,  _____________, _____________, _____________, SKY_BLUE,      _____________, _____________,
      _____________, TRAD_ROSE,     _____________, _____________, _____________, _____________,                                              _____________, _____________, _____________, _____________, _____________, _____________,
      _____________, CAMARON_PINK,  _____________, _____________, _____________,                WHITE,                        WHITE,                        _____________, _____________, _____________, _____________, _____________,
                                                                  CAMARON_PINK,  _____________, _____________,                _____________, _____________, CAMARON_PINK
    ),
};
// clang-format on