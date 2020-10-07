#include QMK_KEYBOARD_H

enum layer_names {
    _WASD,
    _NP,
    _F_WASD,
    _F_NP,
};

// BTW, these shouldn't affect numpad mode because that uses like KC_P1 instead of KC_1.
// Chunks of 5 for easy counting
const uint16_t PROGMEM combo_12[]   = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_23[]   = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_13[]   = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM combo_123[]  = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_1g[]   = {KC_1, KC_G, COMBO_END};

const uint16_t PROGMEM combo_2c[]   = {KC_2, KC_C, COMBO_END};
const uint16_t PROGMEM combo_3r[]   = {KC_3, KC_R, COMBO_END};
const uint16_t PROGMEM combo_gc[]   = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cr[]   = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_gr[]   = {KC_G, KC_R, COMBO_END};

const uint16_t PROGMEM combo_gcr[]  = {KC_G, KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_tabg[] = {KC_TAB, KC_G, COMBO_END};
const uint16_t PROGMEM combo_tabc[] = {KC_TAB, KC_C, COMBO_END};
const uint16_t PROGMEM combo_tabr[] = {KC_TAB, KC_R, COMBO_END};

// Actually assign the combos:
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_12,   KC_4),
    COMBO(combo_23,   KC_5),
    COMBO(combo_13,   KC_6),
    COMBO(combo_123,  KC_7),
    COMBO(combo_1g,   KC_8),
    COMBO(combo_2c,   KC_9),
    COMBO(combo_3r,   KC_0),
    COMBO(combo_gc,   KC_F1),
    COMBO(combo_cr,   KC_F2),
    COMBO(combo_gr,   KC_F3),
    COMBO(combo_gcr,  KC_F4),
    COMBO(combo_tabg, KC_F5),
    COMBO(combo_tabc, KC_F6),
    COMBO(combo_tabr, KC_F7),
};

// enum custom_keycodes {
//   NP = SAFE_RANGE,
//   BL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WASD] = LAYOUT_ortho_6x4(
        KC_1,    KC_2,    KC_3,    MO(_F_WASD),
        KC_G,    KC_C,    KC_R,    KC_TAB,
        KC_E,    KC_W,    KC_Q,    KC_LSHIFT,
        KC_A,    KC_S,    KC_D,    KC_LSHIFT,
        KC_F,    KC_X,    KC_V,    KC_LCTRL,
        KC_SPC,  KC_Z,    KC_Z,    KC_LCTRL
    ),

    [_NP] = LAYOUT_ortho_6x4(
        KC_ESC,  KC_TAB,  KC_BSPC, MO(_F_NP),
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_ENT,
        KC_P0,   KC_DOT,  KC_PDOT, KC_ENT
    ),

    [_F_WASD] = LAYOUT_ortho_6x4(
        KC_ESC,  KC_H,    KC_LALT, _______,
        _______, KC_I,    _______, KC_ENT,
        _______, _______, _______, KC_BSPC,
        BL_BRTG, _______, _______, KC_BSPC,
        BL_TOGG, BL_DEC,  BL_INC,  _______,
        KC_ENT,  _______, DF(_NP), _______
    ),

    [_F_NP] = LAYOUT_ortho_6x4(
        _______, _______, _______,   _______,
        _______, _______, _______,   _______,
        _______, _______, _______,   _______,
        BL_BRTG, _______, _______,   _______,
        BL_TOGG, BL_DEC,  BL_INC,    KC_PENT,
        _______, _______, DF(_WASD), KC_PENT
    ),

};
