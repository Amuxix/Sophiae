#include "raw_hid.h"
#include "action_layer.h"

#define RAW_EPSIZE 32

RGB webhid_leds[RGB_MATRIX_LED_COUNT];

char *LAYER_STATE_CHANGE = "LSC";
char *LAYER_STATE_SET = "LSS";
char *CURRENT_LAYER_STATE = "CLS";

void auto_layer_set(layer_state_t state) {
  char message[RAW_EPSIZE];
  memset(message, '\0', RAW_EPSIZE);
  strcpy(message, LAYER_STATE_CHANGE);
  memcpy(&message[strlen(LAYER_STATE_CHANGE)], (char *)&state, sizeof(layer_state_t));
  raw_hid_send((uint8_t *) message, RAW_EPSIZE);
}

void send_error(void) {
  char response[RAW_EPSIZE] = "ERR";
  memset(response + 3, 0, RAW_EPSIZE - 3);
  raw_hid_send((uint8_t *) response, RAW_EPSIZE);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strncmp((char *)data, LAYER_STATE_SET, strlen(LAYER_STATE_SET)) == 0) {
    layer_state_t *state = (layer_state_t *) &data[strlen(LAYER_STATE_SET)];
    layer_state_set(*state);
    raw_hid_send(data, RAW_EPSIZE);
    return;
  } else if (strncmp((char *)data, CURRENT_LAYER_STATE, strlen(CURRENT_LAYER_STATE)) == 0) {
    auto_layer_set(layer_state);
    return;
  }
  send_error();
}