#include "raw_hid.h"
#include "print.h"
#include "action_layer.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

void raw_hid_receive(uint8_t *data, uint8_t length) {
  ML_LED_5(true);
  wait_ms(250);
  ML_LED_5(false);
  wait_ms(250);
  ML_LED_5(true);
  wait_ms(250);
  ML_LED_5(false);
  uprintf("%i Changing to layer\n", data[2]);
}