#include "raw_hid.h"
#include "print.h"
#include "action_layer.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

uint8_t layer = 0;
void move_layer(void) {
  layer_move(layer);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
    layer = data[2];
    move_layer();
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);
    wait_ms(250);
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);
    raw_hid_send(data, length);
    uprintf("%i Changing to layer", data[2]);
  } else {
    char response[RAW_EPSIZE] = "ERROR";
    memset(response + 5, 0, RAW_EPSIZE - 5);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  }
}