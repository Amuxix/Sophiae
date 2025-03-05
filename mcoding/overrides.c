#define L(layer) 1 << layer
#define NO_SHIFT_SYMBOLS_LAYERS L(BASE) | L(CANARY_G) | L(QWERTY_G) | L(QWERTY_SG)
#define ko_no_shift_base(trigger_key) ko_make_with_layers(MOD_MASK_SHIFT, trigger_key, trigger_key, NO_SHIFT_SYMBOLS_LAYERS)

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  // Remove shifted version of symbols
  &ko_no_shift_base(KC_COLN),
  &ko_no_shift_base(KC_COMMA),
  &ko_no_shift_base(KC_QUOTE),
  &ko_no_shift_base(KC_DOT),
  NULL // key overrides needs to be null terminated
};