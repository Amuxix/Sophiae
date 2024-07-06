void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
    layer_move(data[2]);
    char response[RAW_EPSIZE] = "OK";
    memset(response + 2, 0, RAW_EPSIZE - 2);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  } else {
    char response[RAW_EPSIZE] = "ERROR";
    memset(response + 5, 0, RAW_EPSIZE - 5);
    raw_hid_send((uint8_t *) response, RAW_EPSIZE);
  }
}