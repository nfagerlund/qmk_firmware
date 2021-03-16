#include QMK_KEYBOARD_H

// Layer names
enum nf_layers {
    DVORAK_WIN,
    QWERTY_MAC,
    F_ALL,
    CAP_WIN,    // Makes capslock on Windows act like ctrl on Mac.
};

// Tricky custom keycodes
enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    // DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    NF_KILL,               //Select to end of line, then ctrl+x (windows)
    NF_FLIP,               //Switch default layouts
    NF_CTLO,               //Insert newline after cursor (windows)
};

// Combos
// "Smash escape:" hit `/~ and 1 at the same time to type Esc without using fn.
const uint16_t PROGMEM combo_grv1[]  = {KC_GRV, KC_1, COMBO_END};

// Assign combos
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_grv1, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK_WIN] = LAYOUT_65_ansi_blocker(
        KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
        KC_TAB,      KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_HOME, \
        MO(CAP_WIN), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  KC_PGUP, \
        KC_LSFT,     KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL,     KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RCTL, MO(F_ALL), KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [QWERTY_MAC] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        MO(F_ALL), KC_LALT, KC_LGUI,                          KC_SPC,                             KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [F_ALL] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  C(KC_BSPC), KC_MUTE, \
        _______, _______, _______, _______, _______, _______, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,  \
        _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            NF_FLIP,                            _______, _______, C(KC_LEFT), KC_PGDN, C(KC_RGHT)  \
    ),
    [CAP_WIN] = LAYOUT_65_ansi_blocker(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, C(KC_BSPC), C(KC_DEL), \
        _______, _______, _______, _______, KC_UP,   _______, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_HOME, NF_CTLO, KC_END,  _______, _______, KC_DEL,  _______, _______, KC_DOWN, _______, _______,          _______, _______, \
        _______, _______, _______, _______, NF_KILL, _______, KC_LEFT, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_OTHER_FN (get_mods() & MOD_BIT(KC_RALT) || get_mods() & MOD_BIT(KC_LCTL))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case NF_KILL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)SS_LCTL("x"));
                // https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h
            }
            return false;
        case NF_CTLO:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER)SS_TAP(X_HOME)SS_TAP(X_LEFT));
            }
            return false;
        case NF_FLIP:
            // ctrl + fn + space: cycle default layers.
            // (ctrl and fn are "as labeled," because mac layout moves modifiers around.)
            if (record->event.pressed && MODS_OTHER_FN) {
                switch(biton32(default_layer_state)) {
                    case DVORAK_WIN:
                        default_layer_set(1UL<<QWERTY_MAC);
                        break;
                    default:
                        default_layer_set(1UL<<DVORAK_WIN);
                        break;
                }
                // or:
                // set_single_persistent_default_layer(DVORAK_WIN);
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        // case DBG_MTRX:
        //     if (record->event.pressed) {
        //         TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
        //     }
        //     return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        // case RGB_TOG:
        //     if (record->event.pressed) {
        //       switch (rgb_matrix_get_flags()) {
        //         case LED_FLAG_ALL: {
        //             rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
        //             rgb_matrix_set_color_all(0, 0, 0);
        //           }
        //           break;
        //         case LED_FLAG_KEYLIGHT: {
        //             rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
        //             rgb_matrix_set_color_all(0, 0, 0);
        //           }
        //           break;
        //         case LED_FLAG_UNDERGLOW: {
        //             rgb_matrix_set_flags(LED_FLAG_NONE);
        //             rgb_matrix_disable_noeeprom();
        //           }
        //           break;
        //         default: {
        //             rgb_matrix_set_flags(LED_FLAG_ALL);
        //             rgb_matrix_enable_noeeprom();
        //           }
        //           break;
        //       }
        //     }
        //     return false;
        default:
            return true; //Process all other keycodes normally
    }
}
