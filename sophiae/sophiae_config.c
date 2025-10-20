typedef union {
  struct {
    bool mac_mode : 1;
    uint32_t reserved : 31; // For possible future use
  };
  uint8_t raw;
} sophiae_config_t;

sophiae_config_t sophiae_config = {
  .mac_mode = false,
  .reserved = 0
};

void eeconfig_init_user(void) {
  // Set default config on eprom reset
  sophiae_config.raw = 0;
  sophiae_config.mac_mode = false; // We want this disabled by default
  eeconfig_update_user(sophiae_config.raw);
}