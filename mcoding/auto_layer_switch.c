#include "raw_hid.h"
#include "print.h"

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
    uprintf("%i Changing to layer", data[2]);
    raw_hid_send(data, length);
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);
    wait_ms(250);
    ML_LED_5(true);
    wait_ms(250);
    ML_LED_5(false);

    switch (data[2]) {
      case BASE:
        layer_move(BASE);
        break;
      case CANARY_G:
        layer_move(CANARY_G);
        break;
      case QWERTY_G:
        layer_move(QWERTY_G);
        break;
      case QWERTY_SG:
        layer_move(QWERTY_SG);
        break;
      case KEYPAD_SYMB:
        layer_move(KEYPAD_SYMB);
        break;
      case EXTRA_SYMB:
        layer_move(EXTRA_SYMB);
        break;
      case MOVEMENT:
        layer_move(MOVEMENT);
        break;
      case SHORTCUTS:
        layer_move(SHORTCUTS);
        break;
      default:
        break;
    }
  } else {
    char response[RAW_EPSIZE] = "ERROR";
    memset(response + 5, 0, RAW_EPSIZE - 5);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  }
}