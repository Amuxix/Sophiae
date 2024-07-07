#include "raw_hid.h"
#include "print.h"
#include "action_layer.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
      uint8_t layer = data[2] - 48; // Convert from ascii
      uprintf("Changing to layer %i\n", layer);
      layer_move(layer);
      raw_hid_send(data, length);
    } else {
      char response[RAW_EPSIZE] = "ERROR";
      memset(response + 5, 0, RAW_EPSIZE - 5);
      raw_hid_send((uint8_t *) response, RAW_EPSIZE);
    }
}