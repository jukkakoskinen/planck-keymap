#include QMK_KEYBOARD_H
#include "keymap_finnish.h"

#define LOWER MO(1)
#define RAISE MO(2)

enum planck_layers {
    _DEFAULT,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    XY_EURO = S(FI_4),
    XY_BSLS = ALGR(S(FI_7)),
    XY_LCBR = ALGR(S(FI_8)),
    XY_RCBR = ALGR(S(FI_9))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_LOWER] = LAYOUT_planck_grid(
        _______, FI_EXLM, FI_DQUO, XY_EURO, FI_SLSH, FI_LABK, FI_LPRN, FI_LBRC, XY_LCBR, FI_PLUS, FI_ASTR, KC_DEL,
        _______, FI_QUES, FI_QUOT, FI_DLR,  XY_BSLS, FI_RABK, FI_RPRN, FI_RBRC, XY_RCBR, FI_MINS, FI_PERC, _______,
        _______, FI_CIRC, _______, _______, _______, _______, _______, _______, _______, FI_EQL,  FI_TILD, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_planck_grid(
        _______, FI_1,    FI_2,    FI_3,    FI_4,    FI_5,    FI_6,    FI_7,    FI_8,    FI_9,    FI_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
