#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                           KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                           KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                           KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                           KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                            KC_BSPC, KC_DEL,  KC_LALT, MO(_FN),                    MO(_FN), KC_RALT, KC_ENT,  KC_SPC,
                                                              KC_LCTL, KC_LGUI,                    KC_RGUI, KC_RCTL

                                 // actual: KC_LALT, MO(_FN), KC_LCTL, KC_LGUI,                    MO(_FN), KC_RALT, ???????, KC_SPC,
                                  //                          KC_BSPC, KC_DEL,                     KC_LGUI, ???????
    ),

    [_FN] = LAYOUT_5x6(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                          KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,
        _______, _______, _______, KC_UP,   _______, KC_HOME,                                                        KC_PGUP, KC_LBRC, KC_LCBR,  KC_RCBR,  KC_RBRC,  KC_F12,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,                                                         KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,  _______,  KC_EQL,
        _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_END,                                                         KC_PGDN, _______, _______,  _______,  _______,  _______,
                                            _______, _______, _______, QK_BOOT,                    QK_BOOT, _______, _______,  _______,
                                                              _______, _______,                    _______, _______
    ),
};
