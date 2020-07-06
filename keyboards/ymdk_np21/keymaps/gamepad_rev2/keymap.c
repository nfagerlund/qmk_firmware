#include QMK_KEYBOARD_H

#define _WASD 0
#define _BL 1

enum custom_keycodes {
  NP = SAFE_RANGE,
  BL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty */

  [_WASD] = LAYOUT_ortho_6x4(
    KC_1,    KC_2,    KC_3,    MO(_BL),
    KC_G,    KC_C,    KC_R,    KC_TAB,
    KC_E,    KC_W,    KC_Q,    KC_LSHIFT,
    KC_A,    KC_S,    KC_D,    KC_LSHIFT,
    KC_F,    KC_X,    KC_V,    KC_LCTRL,
    KC_SPC,  KC_Z,    KC_Z,    KC_LCTRL
  ),

  [_BL] = LAYOUT_ortho_6x4(
    KC_ESC,  KC_H,    KC_LALT, _______,
    BL_TOGG, BL_DEC,  BL_INC,  KC_GRAVE,
    KC_7,    KC_8,    KC_9,    KC_BSPC,
    KC_4,    KC_5,    KC_6,    KC_BSPC,
    KC_1,    KC_2,    KC_3,    KC_ENT,
    KC_0,    _______, _______, KC_ENT
  )

};
