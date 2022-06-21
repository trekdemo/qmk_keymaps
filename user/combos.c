#include "combos.h"

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
