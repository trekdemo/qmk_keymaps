#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H

#define U_PASTE LCMD(KC_V)
#define U_COPY  LCMD(KC_C)
#define U_CUT   LCMD(KC_X)
#define U_UNDO  LCMD(KC_Z)

#define CMDLBRC  LCMD(KC_LBRC)
#define CMDRBRC  LCMD(KC_RBRC)
#define CMDLCBR  LCMD(KC_LCBR)
#define CMDRCBR  LCMD(KC_RCBR)

// These are helpers to define home-row mods
#define LALT__A LALT_T(KC_A)
#define LCTRL_R LCTL_T(KC_R)
#define LCMD__S LCMD_T(KC_S)
#define LSHFT_T LSFT_T(KC_T)

#define RSHFT_N RSFT_T(KC_N)
#define RCMD__E RCMD_T(KC_E)
#define RCTRL_I RCTL_T(KC_I)
#define RALT__O RALT_T(KC_O)

#endif
