#include "trekdemo.h"

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  state = update_tri_layer_state(state, _LWR, _RAISE, _ADJUST);
  return layer_state_set_keymap (state);
}

/* ==[ Combos ]=====================================================
 *
 * ╭-----------------------------╮   ╭-----------------------------╮
 * |     | XXX | XXX |     |     |   |     |     | XXX | XXX |     |
 * |-----------------x-----x-----|   |-----x-----x-----------------|
 * |     |     |     |     |     |   |     |     |     |     |     |
 * |-----------------x-----x-----|   |-----x-----x-----------------|
 * |     | XXX | XXX |     |     |   |     |     | XXX | XXX |     |
 * ╰-----------------------------╯   ╰-----------------------------╯
 *             ╭-----------------╮   ╭-----------------╮
 *             |     |     |     |   |     |     |     |
 *             ╰-----------------╯   ╰-----------------╯
 */
const uint16_t PROGMEM topLeft[]     = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM topRight[]    = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM bottomRight[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM bottomLeft[]  = {KC_X, KC_C, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(topLeft, KC_TAB),           COMBO(topRight, CAPS_WORD),
  COMBO(bottomLeft, OSM(MOD_LSFT)), COMBO(bottomRight, OSM(MOD_RSFT)),
};
