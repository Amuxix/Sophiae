#include "raw_hid.h"
#include "print.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
    layer_move(data[2]);
    uprintf("%s Changing to layer", data[2])
    raw_hid_send(data, length);
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);
    wait_ms(250);
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);
  } else {
    char response[RAW_EPSIZE] = "ERROR";
    memset(response + 5, 0, RAW_EPSIZE - 5);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  }
}