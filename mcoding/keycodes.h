#define LT_KPD(kc) LT(KEYPAD_SYMB, kc)
#define LT_SYM(kc) LT(EXTRA_SYMB, kc)
#define LT_MOV(kc) LT(MOVEMENT, kc)

#define LCS(kc) (QK_LCTL | QK_LSFT | (kc))

#define US_DEG S(ALGR(KC_SCLN))
#define US_EURO ALGR(KC_5)
#define US_DIAE S(ALGR(KC_QUOT))