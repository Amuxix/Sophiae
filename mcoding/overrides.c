// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&ko_make_basic(MOD_MASK_ALT, KC_1, KC_F1), // Alt+1 = F1
	&ko_make_basic(MOD_MASK_ALT, KC_2, KC_F2), // Alt+2 = F2
	&ko_make_basic(MOD_MASK_ALT, KC_3, KC_F3), // Alt+3 = F3
	&ko_make_basic(MOD_MASK_ALT, KC_4, KC_F4), // Alt+4 = F4
	&ko_make_basic(MOD_MASK_ALT, KC_5, KC_F5), // Alt+5 = F5
	&ko_make_basic(MOD_MASK_ALT, KC_6, KC_F6), // Alt+6 = F6
	&ko_make_basic(MOD_MASK_ALT, KC_7, KC_F7), // Alt+7 = F7
	&ko_make_basic(MOD_MASK_ALT, KC_8, KC_F8), // Alt+8 = F8
	&ko_make_basic(MOD_MASK_ALT, KC_9, KC_F9), // Alt+9 = F9
	&ko_make_basic(MOD_MASK_ALT, KC_0, KC_F10), // Alt+0 = F10
	NULL // key overrides needs to be null terminated
};