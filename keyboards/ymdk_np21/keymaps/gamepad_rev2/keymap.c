#include QMK_KEYBOARD_H

enum layer_names {
    _WASD,
    _NP,
    _F_WASD,
    _F_NP,
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
