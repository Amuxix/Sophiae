bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        case KC_1 ... KC_0:
        case KC_KP_1 ... KC_KP_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;  // Keep Caps Word Active.
        default:
            return false;  // Deactivate Caps Word.
    }
}