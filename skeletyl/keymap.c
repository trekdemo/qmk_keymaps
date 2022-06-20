#include QMK_KEYBOARD_H
#include "trekdemo.h"

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t new_state = update_tri_layer_state(state, _LWR, _RAISE, _ADJUST);

  return new_state;
}

// Allow the expansion of defined values
#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_wrapper(
    KC_Q      , KC_W      , KC_F      , KC_P      , KC_B,  KC_J    , KC_L      , KC_U      , KC_Y      , KC_QUOT,
    FL5(KC_A) , FL4(KC_R) , FL3(KC_S) , FL2(KC_T) , KC_G,  KC_M    , FR2(KC_N) , FR3(KC_E) , FR4(KC_I) , FR5(KC_O),
    KC_Z      , KC_X      , KC_C      , KC_D      , KC_V,  KC_K    , KC_H      , KC_COMM   , KC_DOT    , KC_SLSH,
                                  _________THUMB_L_________,    _________THUMB_R_________
  ),


  [_NUM] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PERC, KC_7   , KC_8   , KC_9   , KC_EQL ,
    ______________MOD_L2_L____________, XXXXXXX,   KC_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH,
                      _______, _______, _______,   KC_ENT , KC_0   , KC_DOT
  ),

  [_LWR] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU,
    ______________MOD_L2_L____________, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD,
    XXXXXXX, CMDLCBR, CMDLBRC, CMDRBRC, CMDRCBR, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_MUTE,
                      _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,
                      _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2
  ),

  // A possible new symbol layout
  // http://xahlee.info/comp/computer_language_char_distribution.html
  // https://getreuer.info/posts/keyboards/symbol-layer/index.html
  // .-----------------------------.   .-----------------------------.
  // |     |     |     |  \  |  ~  |   |  &  |  (  |  )  |  %  |  =  |
  // |-----------------x-----x-----|   |-----x-----x-----------------|
  // |  !  |  @  |  _  |  :  |  $  |   |  |  |  [  |  ]  |  +  |  -  |
  // |-----------------x-----x-----|   |-----x-----x-----------------|
  // |  ^  |     |  #  |  ;  |  `  |   |     |  {  |  }  |  *  |  /  |
  // '-----------------------------'   '-----------------------------'
  //             .-----------------.   .-----------------.
  //             |     |     |     |   |     |  X  |     |
  //             '-----------------'   '-----------------'
  [_RAISE] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_TILD, KC_AMPR, KC_LPRN, KC_RPRN, KC_PERC, KC_EQL ,
    KC_EXLM, KC_AT  , KC_UNDS, KC_COLN, KC_DLR , KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, KC_MINS,
    KC_CIRC, XXXXXXX, KC_HASH, KC_SCLN, KC_GRV , XXXXXXX, KC_LCBR, KC_RCBR, KC_ASTR, KC_SLSH,
                      _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  ,
    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,  _______, _______, _______
  )
};

const uint16_t PROGMEM topLeft[]     = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM topRight[]    = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM bottomRight[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM bottomLeft[]  = {KC_X, KC_C, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(topLeft, KC_TAB),
    COMBO(topRight, KC_BSPC),
    COMBO(bottomLeft, KC_ESC),
    COMBO(bottomRight, OSM(MOD_LSFT)),
};
