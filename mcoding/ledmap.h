// clang-format off
#define LED_LAYOUT_moonlander( \
    l00, l01, l02, l03, l04, l05, l06,   l60, l61, l62, l63, l64, l65, l66, \
    l10, l11, l12, l13, l14, l15, l16,   l70, l71, l72, l73, l74, l75, l76, \
    l20, l21, l22, l23, l24, l25, l26,   l80, l81, l82, l83, l84, l85, l86, \
    l30, l31, l32, l33, l34, l35,             l91, l92, l93, l94, l95, l96, \
    l40, l41, l42, l43, l44,      l53,   lb3,      la2, la3, la4, la5, la6, \
                        l50, l51, l52,   lb4, lb5, lb6 \
) \
{ \
    l00, l10, l20, l30, l40, \
    l01, l11, l21, l31, l41, \
    l02, l12, l22, l32, l42, \
    l03, l13, l23, l33, l43, \
    l04, l14, l24, l34, l44, \
    l05, l15, l25, l35, \
    l06, l16, l26, \
    l50, l51, l52, l53, \
\
    l66, l76, l86, l96, la6, \
    l65, l75, l85, l95, la5, \
    l64, l74, l84, l94, la4, \
    l63, l73, l83, l93, la3, \
    l62, l72, l82, l92, la2, \
    l61, l71, l81, l91, \
    l60, l70, l80, \
    lb6, lb5, lb4, lb3 \
}

// clang-format on