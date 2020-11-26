#include QMK_KEYBOARD_H

enum layer_names {
    WASD,
    NUMPAD,
    PENT_MODE,
    F_WASD,
    F_NP,
};

// BTW, these shouldn't affect numpad mode because that uses like KC_P1 instead of KC_1.
const uint16_t PROGMEM combo_12[]   = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_23[]   = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_13[]   = {KC_1, KC_3, COMBO_END};

const uint16_t PROGMEM combo_1g[]   = {KC_1, KC_G, COMBO_END};
const uint16_t PROGMEM combo_2c[]   = {KC_2, KC_C, COMBO_END};
const uint16_t PROGMEM combo_3r[]   = {KC_3, KC_R, COMBO_END};

// Actually assign the combos:
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_12,   KC_4),
    COMBO(combo_23,   KC_5),
    COMBO(combo_13,   KC_6),
    COMBO(combo_1g,   KC_7),
    COMBO(combo_2c,   KC_8),
    COMBO(combo_3r,   KC_9),
};

// enum custom_keycodes {
//   NP = SAFE_RANGE,
//   BL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WASD] = LAYOUT_ortho_6x4(
        KC_1,    KC_2,    KC_3,    MO(F_WASD),
        KC_G,    KC_C,    KC_R,    KC_TAB,
        KC_E,    KC_W,    KC_Q,    KC_LSHIFT,
        KC_A,    KC_S,    KC_D,    KC_LSHIFT,
        KC_F,    KC_X,    KC_V,    KC_LCTRL,
        KC_SPC,  KC_Z,    KC_Z,    KC_LCTRL
    ),

    [NUMPAD] = LAYOUT_ortho_6x4(
        KC_ESC,  KC_TAB,  KC_BSPC, MO(F_NP),
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_ENT,
        KC_P0,   KC_PDOT, KC_PDOT, KC_ENT
    ),

    // If you want real "numpad enter" instead of a return key.
    [PENT_MODE] = LAYOUT_ortho_6x4(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, KC_PENT,
        _______, _______, _______, KC_PENT
    ),

    [F_WASD] = LAYOUT_ortho_6x4(
        KC_ESC,  KC_H,    KC_LALT, _______,
        KC_0,    KC_I,    _______, KC_ENT,
        KC_F1,   KC_F2,   KC_F3,   KC_BSPC,
        BL_BRTG, _______, _______, KC_BSPC,
        BL_TOGG, BL_DEC,  BL_INC,  _______,
        KC_ENT,  _______, DF(NUMPAD), _______
    ),

    [F_NP] = LAYOUT_ortho_6x4(
        _______, _______, _______,  _______,
        _______, _______, _______,  _______,
        _______, _______, _______,  _______,
        BL_BRTG, _______, _______,  _______,
        BL_TOGG, BL_DEC,  BL_INC,   TG(PENT_MODE),
        _______, _______, DF(WASD), TG(PENT_MODE)
    ),

};

// Switch off numpad-enter mode when returning to wasd!
// Note that the argument to this function is the new *default layer mask*
// (which usually only has one bit set), not the full layer state for the entire
// stack.
layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (biton32(state) == WASD) {
        layer_off(PENT_MODE);
    }
    return state;
}
