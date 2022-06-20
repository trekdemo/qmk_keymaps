/*
 * https://docs.qmk.fm/#/feature_userspace?id=configuration-options-configh
 *
 * Additionally, config.h here will be processed like the same file in your keymap
 * folder. This is handled separately from the <name>.h file.
 *
 * The reason for this, is that <name>.h won’t be added in time to add settings
 * (such as #define TAPPING_TERM 100), and including the <name.h> file in any
 * config.h files will result in compile issues.
 *
 * You should use the config.h for configuration options,
 * and the <name>.h file for user or keymap specific settings (such as the enum
 * for layer or keycodes)
 */
#pragma once

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Prevent normal rollover on alphas from accidentally triggering mods.
#undef TAPPING_TERM
#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// https://docs.qmk.fm/#/feature_combo
#define COMBO_COUNT 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
