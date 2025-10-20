#include "print.h"
#include "command.h"

#define MAGIC_KEY_SAME_SIDE_PREVENTION_DEBUG P
#define MAGIC_KEY_MAC_MODE_DEBUG M

static void command_extra_help(void) {
  print(/* clang-format off */
    "\n\t- Extra Magic -\n"

    STR(MAGIC_KEY_SAME_SIDE_PREVENTION_DEBUG) ":	Same side prevention Debug Message Toggle\n"
    STR(MAGIC_KEY_MAC_MODE_DEBUG) ":	Mac mode Debug Message Toggle\n"
  );
}

bool debug_same_side = false;
bool debug_mac_mode = false;

bool command_extra(uint8_t code) {
  switch (code) {
    case MAGIC_KC(MAGIC_KEY_HELP):
    case MAGIC_KC(MAGIC_KEY_HELP_ALT):
      command_extra_help();
      return false;

    case MAGIC_KC(MAGIC_KEY_SAME_SIDE_PREVENTION_DEBUG):
      debug_same_side = !debug_same_side;
      if (debug_same_side) {
        print("\nsame side: on\n");
        debug_enable = true;
      } else {
        print("\nsame side: off\n");
      }
      break;

    case MAGIC_KC(MAGIC_KEY_MAC_MODE_DEBUG):
      debug_mac_mode = !debug_mac_mode;
      if (debug_mac_mode) {
        print("\nmac mode: on\n");
        debug_enable = true;
      } else {
        print("\nmac mode: off\n");
      }
      break;

    default:
      return false;
  }
  return true;
}