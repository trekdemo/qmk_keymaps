#include QMK_KEYBOARD_H
#include "trekdemo.h"

enum layers {
  _COLEMAK = 0,
  _EXT,
  _SYM,
  _ADJUST,
  _NUM,
  _MOUSE
};

// ==[ Switch to Adjust ]======================================================
__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  state = update_tri_layer_state(state, _EXT, _SYM, _ADJUST);
  return layer_state_set_keymap (state);
}

#ifndef DRGSCRL
#define DRGSCRL KC_NO
#endif /* !DRGSCRL */

// -- Thumb keys ---------------------------------------------------------------
// .-----------------.   .-----------------.
// | NUM | EXT | MOU |   |     | SYM | Hyp |
// | Esc | Bsp | Tab |   | Ent | Spc |     |
// '-----------------'   '-----------------'
// .-----------.               .-----------.
// | NUM | EXT |               | SYM | Hyp |
// | Esc | Bsp |               | Spc |     |
// '-----------'               '-----------'

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x5_3(
    KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,   KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT,
    LALT__A, LCTRL_R, LCMD__S, LSHFT_T, KC_G   ,   KC_M   , RSHFT_N, RCMD__E, RCTRL_I, RALT__O,
    KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,   KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,
    LT(_NUM, KC_ESC), LT(_EXT, KC_BSPC) , LT(_MOUSE, KC_TAB),   KC_ENT , LT(_SYM, KC_SPC), KC_HYPR
  ),

  [_NUM] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PERC, KC_7   , KC_8   , KC_9   , KC_EQL ,
    KC_LOPT, KC_LCTL, KC_LCMD, KC_LSFT, XXXXXXX,   KC_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS,
    U_UNDO , U_CUT  , U_COPY , XXXXXXX, U_PASTE,   KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH,
                      _______, _______, _______,   KC_ENT , KC_0   , KC_DOT
  ),

  [_EXT] = LAYOUT_split_3x5_3(
    KC_ESC , CMDLCBR, CMDLBRC, CMDRBRC, CMDRCBR,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
    KC_LOPT, KC_LCTL, KC_LCMD, KC_LSFT, DRGSCRL,   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD,
    U_UNDO , U_CUT  , U_COPY , XXXXXXX, U_PASTE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_MUTE,
                      _______, _______, _______,   _______, _______, _______
  ),

  [_SYM] = LAYOUT_split_3x5_3(
    KC_ESC , XXXXXXX, XXXXXXX, KC_BSLS, KC_TILD,   KC_AMPR, KC_LPRN, KC_RPRN, KC_PERC, KC_EQL ,
    KC_EXLM, KC_AT  , KC_UNDS, KC_COLN, KC_DLR ,   KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, KC_MINS,
    KC_CIRC, XXXXXXX, KC_HASH, KC_SCLN, KC_GRV ,   XXXXXXX, KC_LCBR, KC_RCBR, KC_ASTR, KC_SLSH,
                      _______, _______, _______,   _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_split_3x5_3(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F10 ,
    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,   XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,
    XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,  XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F12 ,
                      _______, _______, _______,   _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,
    _______, _______, _______,   KC_BTN3, KC_BTN1, KC_BTN2
  )
};
