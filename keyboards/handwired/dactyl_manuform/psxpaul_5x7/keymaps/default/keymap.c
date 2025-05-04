#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV    1
#define _NUM    2
#define _TAB    3

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SC RCTL_T(KC_SCLN)

bool mod_state_lctl = false;
bool mod_state_rctl = false;
bool mod_state_lsft = false;
bool mod_state_rsft = false;
bool mod_state_lalt = false;
bool mod_state_ralt = false;
bool mod_state_lgui = false;
bool mod_state_rgui = false;

// Layer state management
layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _QWERTY) {
        unregister_mods(MOD_MASK_CTRL | MOD_MASK_SHIFT | MOD_MASK_ALT | MOD_MASK_GUI);
        // reset modifier state for all modifiers
        mod_state_lctl = false;
        mod_state_rctl = false;
        mod_state_lsft = false;
        mod_state_rsft = false;
        mod_state_lalt = false;
        mod_state_ralt = false;
        mod_state_lgui = false;
        mod_state_rgui = false;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,                                     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSLS,  XXXXXXX,
        XXXXXXX,    KC_ESC,   HOME_A,  HOME_S,   HOME_D,   HOME_F,     KC_G,                                     KC_H,   HOME_J,   HOME_K,   HOME_L,  HOME_SC,  KC_QUOT,  XXXXXXX,
        XXXXXXX,   KC_LSFT,     KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,                                     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,                                                                       XXXXXXX, XXXXXXX,
                                                   GUI_T(KC_BSPC), LT(_TAB, KC_DEL),         LT(_NUM, KC_ENT), GUI_T(KC_SPC),
                                                          XXXXXXX, LT(_NAV, KC_ESC),         LT(_NAV, KC_TAB), XXXXXXX,
                                                                           XXXXXXX, XXXXXXX,         XXXXXXX,  XXXXXXX
    ),

    [_NAV] = LAYOUT_5x7(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  XXXXXXX,  KC_PGUP,  XXXXXXX,    KC_UP,  XXXXXXX,  KC_HOME,                                  KC_PGUP,  KC_LBRC,  KC_LCBR,  KC_RCBR,  KC_RBRC,  XXXXXXX,  _______,
        _______,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_SPC,                                  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  XXXXXXX,  XXXXXXX,  _______,
        _______,  XXXXXXX,  KC_PGDN,  KC_VOLD,  KC_MUTE,  KC_VOLU,   KC_END,                                  KC_PGDN,  KC_LPRN,    KC_LT,    KC_GT,  KC_RPRN,  XXXXXXX,  _______,
                                      _______,  _______,                                                                _______,  _______,
                                                          _______,  _______,                                  _______,  _______,
                                                                    _______, _______,                _______, _______,
                                                                    _______, _______,                _______, _______
    ),

    [_NUM] = LAYOUT_5x7(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   KC_GRV,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,                                  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,  _______,
        _______,  KC_TILD,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_EQL,  _______,
        _______,   KC_F11,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F12,  _______,
                                      _______,  _______,                                                                _______,  _______,
                                                          _______,  _______,                                  _______,  _______,
                                                                    _______, _______,                _______, _______,
                                                                    _______, _______,                _______, _______
    ),

    [_TAB] = LAYOUT_5x7(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,G(KC_GRV),  XXXXXXX,  G(KC_7),  G(KC_8),  G(KC_9),  XXXXXXX,                                  XXXXXXX,     KC_7,     KC_8,     KC_9,  KC_MINS,  XXXXXXX,  _______,
        _______,  XXXXXXX,  XXXXXXX,  G(KC_4),  G(KC_5),  G(KC_6),  XXXXXXX,                                  XXXXXXX,     KC_4,     KC_5,     KC_6,  KC_PLUS,  XXXXXXX,  _______,
        _______,  XXXXXXX,  XXXXXXX,  G(KC_1),  G(KC_2),  G(KC_3),  XXXXXXX,                                     KC_0,     KC_1,     KC_2,     KC_3,   KC_EQL,  XXXXXXX,  _______,
                                      _______,  _______,                                                                _______,  _______,
                                                           _______, _______,                                  _______, _______,
                                                                    _______, _______,                _______, _______,
                                                                    _______, _______,                _______, _______
    ),
};

// Detect when modifiers are active
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case HOME_A: mod_state_lctl = true; break;
            case HOME_S: mod_state_lalt = true; break;
            case HOME_D: mod_state_lgui = true; break;
            case HOME_F: mod_state_lsft = true; break;
            case HOME_J: mod_state_rsft = true; break;
            case HOME_K: mod_state_rgui = true; break;
            case HOME_L: mod_state_ralt = true; break;
            case HOME_SC: mod_state_rctl = true; break;
        }
        return true;
    } else if (IS_LAYER_ON(_QWERTY)) {
        switch (keycode) {
            case HOME_A: mod_state_lctl = false; break;
            case HOME_S: mod_state_lalt = false; break;
            case HOME_D: mod_state_lgui = false; break;
            case HOME_F: mod_state_lsft = false; break;
            case HOME_J: mod_state_rsft = false; break;
            case HOME_K: mod_state_rgui = false; break;
            case HOME_L: mod_state_ralt = false; break;
            case HOME_SC: mod_state_rctl = false; break;
        }
        return true;
    } else {
        switch (keycode) {
            case HOME_A:
            case HOME_S:
            case HOME_D:
            case HOME_F:
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case HOME_SC: return false;   // do not process the keyup on the layer
            default: return true;
        }
    }
}
