#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUM    2

// List of modifier keys in the same order as in the `mod_state` array
const uint16_t mod_keys[] = {
    KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,  // Left modifiers
    KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI   // Right modifiers
};

// Calculate the number of modifiers using sizeof
#define NUM_MODIFIERS (sizeof(mod_keys) / sizeof(mod_keys[0]))

// Track the state of modifiers (left and right modifiers)
bool mod_state[NUM_MODIFIERS] = {false};  // Array to track the state of all modifiers

// Layer state management
layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _QWERTY) {
        unregister_mods(MOD_MASK_CTRL | MOD_MASK_SHIFT | MOD_MASK_ALT | MOD_MASK_GUI);
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        _______,    KC_GRV,     KC_1,    KC_2,    KC_3,   KC_4,   KC_5,
        _______,    KC_TAB,     KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
        _______,    KC_ESC,     MT(MOD_LCTL, KC_A),    MT(MOD_LALT, KC_S),    MT(MOD_LGUI, KC_D),   MT(MOD_LSFT, KC_F),   KC_G,
        _______,    KC_LSFT,    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                                                  _______, _______,
                                                                 KC_BSPC, LT(_NUM, KC_DEL),
                                                                          KC_LCTL, KC_LALT,
                                                                          KC_LGUI, MO(_FN),
        // right hand
                      KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,    _______,
                      KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,    _______,
                      KC_H,    MT(MOD_RSFT, KC_J),    MT(MOD_RGUI, KC_K),     MT(MOD_RALT, KC_L),     MT(MOD_RCTL, KC_SCLN),  KC_QUOT,    _______,
                      KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,    _______,
                               _______, _______,
                 LT(_NUM, KC_ENT), KC_SPC,
        KC_RALT, KC_RCTL,
        MO(_FN),  KC_RGUI
    ),

    [_FN] = LAYOUT_5x7(
        // left hand
        _______,   _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,
        _______,   _______,   _______,   _______,    KC_UP,    _______,   KC_HOME,
        _______,   _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   KC_SPC,
        _______,   _______,   _______,   KC_VOLD,   KC_MUTE,   KC_VOLU,   KC_END,
                                         _______,   _______,
                                                               _______, _______,
                                                                        _______, _______,
                                                                        _______, _______,
        // right hand
                       KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    _______,
                       KC_PGUP,   KC_LBRC,   KC_LCBR,   KC_RCBR,   KC_RBRC,   KC_F12,    _______,
                       KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______,   KC_EQL,    _______,
                       KC_PGDN,   _______,   _______,   _______,   _______,   _______,   _______,
                                             _______,   _______,
              _______, _______,
         _______, _______,
         _______, _______
    ),

    [_NUM] = LAYOUT_5x7(
        // left hand
        _______,    _______,     _______,    _______,    _______,   _______,   _______,
        _______,    _______,     _______,       KC_7,       KC_8,      KC_9,   _______,
        _______,    _______,     _______,       KC_4,       KC_5,      KC_6,   _______,
        _______,    _______,     _______,       KC_1,       KC_2,      KC_3,   _______,
                                             _______, _______,
                                                                    KC_0, _______,
                                                                          _______, _______,
                                                                          _______, _______,
        // right hand
                      _______,    _______,    _______,     _______,     _______,     _______,    _______,
                      _______,       KC_7,       KC_8,        KC_9,     _______,     _______,    _______,
                      _______,       KC_4,       KC_5,        KC_6,     _______,     _______,    _______,
                      _______,       KC_1,       KC_2,        KC_3,     _______,     _______,    _______,
                               _______, _______,
                 _______,    KC_0,
        _______, _______,
        _______, _______
    ),
};

// Detect when modifiers are active
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    for (int i = 0; i < NUM_MODIFIERS; i++) {
        if (keycode == mod_keys[i]) {
            if (record->event.pressed) {
                mod_state[i] = true;  // Set modifier state to active
                return true;
            } else if (IS_LAYER_ON(_QWERTY)) {
                mod_state[i] = false; // Set modifier state to inactive
                return true;
            } else {
                return false;   // do not process the keyup on the layer
            }
        }
    }
    return true;  // Default behavior for other keys
}
