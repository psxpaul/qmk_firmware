#include QMK_KEYBOARD_H
#include "print.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV    1
#define _SYM    2
#define _NUM    3
#define _MOUSE  4

// QWERTY HRMs
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SC RCTL_T(KC_SCLN)

// Thumb keys
#define THUMB_L1 LT(_SYM, KC_BSPC)
#define THUMB_L2 LT(_NUM, KC_DEL)
#define THUMB_L3 LT(_NAV, KC_ESC)
#define THUMB_R3 LT(_NAV, KC_TAB)
#define THUMB_R2 LT(_NUM, KC_ENT)
#define THUMB_R1 LT(_SYM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_4x6(
        KC_TAB,   KC_Q,          KC_W,             KC_E,             KC_R,             KC_T,                     KC_Y,     KC_U,             KC_I,           KC_O,             KC_P,             KC_BSLS,
        KC_ESC,   HOME_A,        HOME_S,           HOME_D,           HOME_F,           KC_G,                     KC_H,     HOME_J,           HOME_K,         HOME_L,           HOME_SC,          KC_QUOT,
        KC_LSFT,  KC_Z,          KC_X,             KC_C,             KC_V,             KC_B,                     KC_N,     KC_M,             KC_COMM,        KC_DOT,           KC_SLSH,          KC_RSFT,
                                                   THUMB_L1,         THUMB_L2,         THUMB_L3,                 THUMB_R3, THUMB_R2,         THUMB_R1
    ),
    [_SYM] = LAYOUT_4x6(
        KC_GRV,   KC_EXLM,       KC_AT,            KC_HASH,          KC_DLR,           KC_PERC,                  KC_CIRC,  KC_AMPR,          KC_ASTR,        KC_LPRN,          KC_RPRN,          KC_MINS,
        KC_TILD,  LCTL_T(KC_1),  LALT_T(KC_2),     LGUI_T(KC_3),     LSFT_T(KC_4),     KC_5,                     KC_6,     RSFT_T(KC_7),     RGUI_T(KC_8),   RALT_T(KC_9),     RCTL_T(KC_0),     KC_EQL,
        KC_F11,   KC_F1,         KC_F2,            KC_F3,            KC_F4,            KC_F5,                    KC_F6,    KC_F7,            KC_F8,          KC_F9,            KC_F10,           KC_F12,
                                                   _______,          _______,          _______,                  _______,  _______,          _______
    ),
    [_NUM] = LAYOUT_4x6(
      G(KC_GRV),  XXXXXXX,       KC_7,             KC_8,             KC_9,             KC_MINS,                  XXXXXXX,  KC_7,             KC_8,           KC_9,             KC_PMNS,          KC_MINS,
        XXXXXXX,  XXXXXXX,       LALT_T(KC_4),     LGUI_T(KC_5),     LSFT_T(KC_6),     KC_PLUS,                  XXXXXXX,  RSFT_T(KC_4),     RGUI_T(KC_5),   RALT_T(KC_6),     RCTL_T(KC_PPLS),  KC_PLUS,
        XXXXXXX,     KC_0,       KC_1,             KC_2,             KC_3,             KC_EQL,                   KC_0,     KC_1,             KC_2,           KC_3,             KC_EQL,           KC_EQL,
                                                   _______,          _______,          _______,                  _______,  _______,          _______
    ),
    [_NAV] = LAYOUT_4x6(
        XXXXXXX,  KC_PGUP,       XXXXXXX,          KC_UP,            XXXXXXX,          KC_HOME,                  KC_PGUP,  KC_LBRC,          KC_LCBR,        KC_RCBR,          KC_RBRC,          XXXXXXX,
        XXXXXXX,  XXXXXXX,       LALT_T(KC_LEFT),  LGUI_T(KC_DOWN),  LSFT_T(KC_RGHT),  KC_SPC,                   KC_LEFT,  RSFT_T(KC_DOWN),  RGUI_T(KC_UP),  RALT_T(KC_RGHT),  XXXXXXX,          XXXXXXX,
        XXXXXXX,  KC_PGDN,       KC_VOLD,          KC_MUTE,          KC_VOLU,          KC_END,                   KC_PGDN,  KC_LPRN,          KC_LT,          KC_GT,            KC_RPRN,          XXXXXXX,
                                                   _______,          _______,          _______,                  _______,  _______,          _______
    ),
    [_MOUSE] = LAYOUT_4x6(
        XXXXXXX,  XXXXXXX,       XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,  XXXXXXX,          XXXXXXX,        XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,  XXXXXXX,       MS_BTN1,          MS_BTN2,          MS_BTN3,          XXXXXXX,                  XXXXXXX,  MS_BTN1,          MS_BTN2,        MS_BTN3,          XXXXXXX,          XXXXXXX,
        XXXXXXX,  XXXXXXX,       XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,  XXXXXXX,          XXXXXXX,        XXXXXXX,          XXXXXXX,          XXXXXXX,
                                                   _______,          _______,          _______,                  _______,  _______,          _______
    )
};

void keyboard_post_init_user(void) {
    // debug_enable = true;

    pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 1500); //Set cpi on right side to a reasonable value for mousing.
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = -1 * left_report.y;
    left_report.x = 0;
    left_report.y = 0;

    dprintf("Combining mouse reports(h: %d|%d, v: %d|%d)", left_report.h, right_report.h, left_report.v, right_report.v);

    return pointing_device_combine_reports(left_report, right_report);
}