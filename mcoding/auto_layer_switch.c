#include "raw_hid.h"
#include "print.h"
#include "action_layer.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

void auto_layer_set(layer_state_t state) {
  // SPACE_BSPC_SWAP is special
  uint8_t layer = get_highest_layer(state & ~((layer_state_t)1 << SPACE_BSPC_SWAP));
  if (layer >= BASE && layer <= QWERTY_SG) {
    dprintf("Sending layer set %i\n", layer);
    char response[RAW_EPSIZE] = "LS";
    response[2] = (char)(layer + 48);
    memset(response + 3, 0, RAW_EPSIZE - 3);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  } else if (IS_LAYER_ON_STATE(state, SPACE_BSPC_SWAP)) {
    dprintf("Sending layer special set %i\n", layer);
    char response[RAW_EPSIZE] = "LSS";
    response[3] = (char)(layer + 48);
    memset(response + 4, 0, RAW_EPSIZE - 4);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  }
}

void send_error(void) {
  char response[RAW_EPSIZE] = "ERR";
  memset(response + 3, 0, RAW_EPSIZE - 3);
  raw_hid_send((uint8_t *) response, RAW_EPSIZE);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (data[0] == 'L' && data[1] == 'C') {
    uint8_t layer = data[2] - 48; // Convert from ascii
    if (layer >= BASE && layer <= QWERTY_SG) {
      dprintf("Changing to layer %i\n", layer);
      layer_move(layer);
      raw_hid_send(data, length);
      return;
    } else if (layer == SPACE_BSPC_SWAP) {
      dprintf("Turning special layer on %i\n", layer);
      layer_on(layer);
      raw_hid_send(data, length);
      return;
    }
  }
  send_error();
}