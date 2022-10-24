/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { GP4, GP5, GP28, GP26 }
#define MATRIX_COL_PINS \
    { GP8, GP9, GP7, GP6, GP27 }

/* Handedness. */
#define SPLIT_HAND_PIN GP29
#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

/* serial.c configuration (for split keyboard). */
#define SOFT_SERIAL_PIN GP1

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* Cirque trackpad. */
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define CIRQUE_PINNACLE_SPI_CS_PIN GP21

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* #define CIRQUE_PINNACLE_TAP_ENABLE */
/* #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE */
/* #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE */

/* ----------------------------------------------------------------------------
 *                     _____         __
 *   _________  ____  / __(_)___ _  / /_
 *  / ___/ __ \/ __ \/ /_/ / __ `/ / __ \
 * / /__/ /_/ / / / / __/ / /_/ / / / / /
 * \___/\____/_/ /_/_/ /_/\__, (_)_/ /_/
 *                       /____/
 * ----------------------------------------------------------------------------
 */
// Turn my thirty-six key layout into a thirty-two
// clang-format off
#define LAYOUT_split_3x5_3(                             \
  k00, k01, k02, k03, k04,     k44, k43, k42, k41, k40, \
  k10, k11, k12, k13, k14,     k54, k53, k52, k51, k50, \
  k20, k21, k22, k23, k24,     k64, k63, k62, k61, k60, \
            k30, k31, k32,     k72, k71, k70            \
)                                                       \
{                                                       \
  {   k00,   k01,   k02,   k03,   k04 },                \
  {   k10,   k11,   k12,   k13,   k14 },                \
  {   k20,   k21,   k22,   k23,   k24 },                \
  {   k30, KC_NO,   k31, KC_NO, KC_NO },                \
  {   k40,   k41,   k42,   k43,   k44 },                \
  {   k50,   k51,   k52,   k53,   k54 },                \
  {   k60,   k61,   k62,   k63,   k64 },                \
  {   k70, KC_NO,   k71, KC_NO, KC_NO },                \
}
// clang-format on
