# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
# Set to yes to enable automatic layer switching via raw HID
AUTO_LAYER_SWITCH_ENABLE = no
ifeq ($(strip $(AUTO_LAYER_SWITCH_ENABLE)), yes)
    RAW_ENABLE = yes
    OPT_DEFS += -DAUTO_LAYER_SWITCH
else
    RAW_ENABLE = no
endif
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = no
COMMUNITY_MODULES += zsa/defaults
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
LAYER_LOCK_ENABLE = yes
REPEAT_KEY_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes