// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&ko_make_basic(MOD_MASK_ALT, KC_1, KC_F1),
	&ko_make_basic(MOD_MASK_ALT, KC_2, KC_F2),
	&ko_make_basic(MOD_MASK_ALT, KC_3, KC_F3),
	&ko_make_basic(MOD_MASK_ALT, KC_4, KC_F4),
	&ko_make_basic(MOD_MASK_ALT, KC_5, KC_F5),
	&ko_make_basic(MOD_MASK_ALT, KC_6, KC_F6),
	&ko_make_basic(MOD_MASK_ALT, KC_7, KC_F7),
	&ko_make_basic(MOD_MASK_ALT, KC_8, KC_F8),
	&ko_make_basic(MOD_MASK_ALT, KC_9, KC_F9),
	&ko_make_basic(MOD_MASK_ALT, KC_0, KC_F10),
	NULL // key overrides needs to be null terminated
};