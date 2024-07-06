void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (strstr((char *) data, "LC")) {
    layer_move(data[2]);
    char response[length] = "OK";
    memset(response + 2, 0, length - 2);
    raw_hid_send((uint8_t *) response, length);
  } else {
    char response[length] = "ERROR";
    memset(response + 5, 0, length - 5);
    raw_hid_send((uint8_t *) response, length);
  }
}