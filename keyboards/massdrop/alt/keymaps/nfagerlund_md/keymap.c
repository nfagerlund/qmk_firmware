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
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_EDG_I,            //LED Edge Brightness Increase
    L_EDG_D,            //LED Edge Brightness Decrease
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_RATIOD,
    L_RATIOI,
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT,            //Restart into bootloader after hold timeout

    NF_KILL,               //Select to end of line, then ctrl+x (windows)
    NF_FLIP,               //Switch default layouts
    NF_CTLO,               //Insert newline after cursor (windows)
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

// Combos
// "Smash escape:" hit `/~ and 1 at the same time to type Esc without using fn.
// Play/pause: [ + ] (as marked)
// Track back: P + [ (as marked)
// Track forward: ] + \ (as marked)
const uint16_t PROGMEM combo_grv1[]  = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM combo_double_bracket_qw[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_double_bracket_dv[] = {KC_SLSH, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_bracket_p_qw[] = {KC_P, KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo_bracket_p_dv[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_bracket_bs_qw[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo_bracket_bs_dv[] = {KC_EQL, KC_BSLS, COMBO_END};

// Assign combos
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_grv1, KC_ESC),
    COMBO(combo_double_bracket_qw, KC_MPLY),
    COMBO(combo_double_bracket_dv, KC_MPLY),
    COMBO(combo_bracket_p_qw, KC_MPRV),
    COMBO(combo_bracket_p_dv, KC_MPRV),
    COMBO(combo_bracket_bs_qw, KC_MNXT),
    COMBO(combo_bracket_bs_dv, KC_MNXT),
};

// Set up swap-hands config -- this applies the swapped key positions to whatever the
// current layer situation is, so as long as I manage to stay within the constraint
// of "no swapping to invisible keys," it should save me some hassle.
//
// This value is a 2-dimensional array mapping from old column/row to new column/row,
// but the outer structure is (row, col) and the inner types are (col, row). :dizzy:
//
// As per alt.h, we're 5x15 with "_" representing KC_NO in the non-existent slots:
//
// ` 1 2 3 4 5 6 7 8 9 0 - = < X
// T q w e r t y u i o p [ ] \ H
// C a s d f g h j k l ; ' _ R U
// S _ z x c v b n m , . / S ^ D
// ^ W A _ _ _ ! _ _ _ A F < v >
//

#define _SWD_GRAVE {0, 0}
#define _SWD_1 {1, 0}
#define _SWD_2 {2, 0}
#define _SWD_3 {3, 0}
#define _SWD_4 {4, 0}
#define _SWD_5 {5, 0}
#define _SWD_6 {6, 0}
#define _SWD_7 {7, 0}
#define _SWD_8 {8, 0}
#define _SWD_9 {9, 0}
#define _SWD_0 {10, 0}
#define _SWD_HYPHEN {11, 0}
#define _SWD_EQUALS {12, 0}
#define _SWD_BACKSP {13, 0}
#define _SWD_DEL {14, 0}

#define _SWD_TAB {0, 1}
#define _SWD_Q {1, 1}
#define _SWD_W {2, 1}
#define _SWD_E {3, 1}
#define _SWD_R {4, 1}
#define _SWD_T {5, 1}
#define _SWD_Y {6, 1}
#define _SWD_U {7, 1}
#define _SWD_I {8, 1}
#define _SWD_O {9, 1}
#define _SWD_P {10, 1}
#define _SWD_LBRC {11, 1}
#define _SWD_RBRC {12, 1}
#define _SWD_BACKSL {13, 1}
#define _SWD_HOME {14, 1}

#define _SWD_CAPS {0, 2}
#define _SWD_A {1, 2}
#define _SWD_S {2, 2}
#define _SWD_D {3, 2}
#define _SWD_F {4, 2}
#define _SWD_G {5, 2}
#define _SWD_H {6, 2}
#define _SWD_J {7, 2}
#define _SWD_K {8, 2}
#define _SWD_L {9, 2}
#define _SWD_SEMI {10, 2}
#define _SWD_QUOT {11, 2}
#define _SWD_NO_1 {12, 2}
#define _SWD_RET {13, 2}
#define _SWD_PGUP {14, 2}

#define _SWD_LSHIFT {0, 3}
#define _SWD_NO_2 {1, 3}
#define _SWD_Z {2, 3}
#define _SWD_X {3, 3}
#define _SWD_C {4, 3}
#define _SWD_V {5, 3}
#define _SWD_B {6, 3}
#define _SWD_N {7, 3}
#define _SWD_M {8, 3}
#define _SWD_COMMA {9, 3}
#define _SWD_PERIOD {10, 3}
#define _SWD_SLASH {11, 3}
#define _SWD_RSHIFT {12, 3}
#define _SWD_UP {13, 3}
#define _SWD_PGDOWN {14, 3}

#define _SWD_LCTRL {0, 4}
#define _SWD_LWIN {1, 4}
#define _SWD_LALT {2, 4}
#define _SWD_NO_3 {3, 4}
#define _SWD_NO_4 {4, 4}
#define _SWD_NO_5 {5, 4}
#define _SWD_SPACE {6, 4}
#define _SWD_NO_6 {7, 4}
#define _SWD_NO_7 {8, 4}
#define _SWD_NO_8 {9, 4}
#define _SWD_RALT {10, 4}
#define _SWD_FN {11, 4}
#define _SWD_LEFT {12, 4}
#define _SWD_DOWN {13, 4}
#define _SWD_RIGHT {14, 4}


const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {_SWD_SLASH, _SWD_0, _SWD_9, _SWD_8, _SWD_7, _SWD_6, _SWD_6, _SWD_5, _SWD_4, _SWD_3, _SWD_2, _SWD_1, _SWD_GRAVE, _SWD_BACKSP, _SWD_DEL},
    {_SWD_BACKSP, _SWD_P, _SWD_O, _SWD_I, _SWD_U, _SWD_Y, _SWD_T, _SWD_R, _SWD_E, _SWD_W, _SWD_Q, _SWD_LBRC, _SWD_RBRC, _SWD_BACKSL, _SWD_HOME},
    {_SWD_RET, _SWD_SEMI, _SWD_L, _SWD_K, _SWD_J, _SWD_H, _SWD_G, _SWD_F, _SWD_D, _SWD_S, _SWD_A, _SWD_QUOT, _SWD_NO_1, _SWD_RET, _SWD_PGUP},
    {_SWD_LSHIFT, _SWD_NO_2, _SWD_PERIOD, _SWD_COMMA, _SWD_M, _SWD_N, _SWD_B, _SWD_V, _SWD_C, _SWD_X, _SWD_Z, _SWD_SLASH, _SWD_RSHIFT, _SWD_UP, _SWD_PGDOWN},
    {_SWD_LCTRL, _SWD_LWIN, _SWD_LALT, _SWD_NO_3, _SWD_NO_4, _SWD_NO_5, _SWD_SPACE, _SWD_NO_6, _SWD_NO_7, _SWD_NO_8, _SWD_RALT, _SWD_FN, _SWD_LEFT, _SWD_DOWN, _SWD_RIGHT},
}

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
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,  \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, L_T_MD,  L_T_ONF, _______, L_EDG_M, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            NF_FLIP,                            _______, _______, C(KC_LEFT), KC_PGDN, C(KC_RGHT)  \
    ),
    [CAP_WIN] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  C(KC_BSPC), C(KC_DEL), \
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

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_OTHER_FN (get_mods() & MOD_BIT(KC_RALT) || get_mods() & MOD_BIT(KC_LCTL))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case NF_KILL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT)SS_LCTRL("x"));
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
            // (ctrl and fn are "as labeled," which is what the weird
            // MODS_OTHER_FN thing is about -- fn switches sides on mac qwerty,
            // because I prefer it that way.)
            if (record->event.pressed && MODS_OTHER_FN) {
                switch(biton32(default_layer_state)) {
                    case DVORAK_WIN:
                        default_layer_set(1UL<<QWERTY_MAC);
                        break;
                    default:
                        default_layer_set(1UL<<DVORAK_WIN);
                }

                // or:
                // set_single_persistent_default_layer(DVORAK_WIN);
            }
            return false;

        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_RATIOI:
            if (record->event.pressed) {
                led_ratio_brightness += 0.2;
                if (led_ratio_brightness > 2.0) { led_ratio_brightness = 2.0; }
            }
            return false;
        case L_RATIOD:
            if (record->event.pressed) {
                led_ratio_brightness -= 0.2;
                if (led_ratio_brightness < 0.0) { led_ratio_brightness = 0.0; }
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
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
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below

    //All LEDs use the user's selected pattern (this is the factory default)
     { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    //Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },

    //Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },

    //All LEDs use the user's selected pattern
    //On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    //When layer 1 is active, key LEDs use red    (id0  32 -  16: 1111 1111 1111 1111 1000 0000 0000 0000 = 0xFFFF8000) (except top row 15 - 1)
    //When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //When layer 1 is active, key LEDs use red    (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    //When layer 1 is active, edge LEDs use green (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //When layer 1 is active, edge LEDs use green (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF8000, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255, .layer = 1 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFFFFFFF8, .id3 = 0x000003FF, .g = 127, .layer = 1 },

    //All key LEDs use red while edge LEDs use the active pattern
    //All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    //Edge uses active pattern (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //Edge uses active pattern (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFFFFFFF8, .id3 = 0x000003FF },

    //end must be set to 1 to indicate end of instruction set
     { .end = 1 }
};
