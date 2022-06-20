#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H

#define U_REDO  LCMD(KC_Z)
#define U_PASTE LCMD(KC_V)
#define U_COPY  LCMD(KC_C)
#define U_CUT   LCMD(KC_X)
#define U_UNDO  LCMD(KC_Z)

#define CMDLBRC  LCMD(KC_LBRC)
#define CMDRBRC  LCMD(KC_RBRC)
#define CMDLCBR  LCMD(KC_LCBR)
#define CMDRCBR  LCMD(KC_RCBR)

enum layers {
  _COLEMAK = 0,
  _LWR,
  _RAISE,
  _ADJUST,
  _NUM,
  _MOUSE
};

// == Home-row Mod helpers =====================================================
//  .-----------------------.    .-----------------------.
//  | Alt | Ctl | Cmd | Sft |    | Sft | Cmd | Ctl | Alt |
//  '-----------------------'    '-----------------------'
#define ______________MOD_L2_L____________  KC_LOPT, KC_LCTL, KC_LCMD, KC_LSFT
#define ______________MOD_L2_R____________  KC_RSFT, KC_RCMD, KC_RCTL, KC_ROPT


// -- Thumb keys ---------------------------------------------------------------
//                   .-----------------.   .-----------------.
//                   | NUM | NAV | MOU |   |     | RSA | Hyp |
//                   | Esc | Bsp | Tab |   | Ent | Spc |     |
//                   '-----------------'   '-----------------'
#define _________THUMB_L_________ LT(_NUM, KC_ESC), LT(_LWR, KC_BSPC) , LT(_MOUSE, KC_TAB)
#define _________THUMB_R_________          KC_ENT , LT(_RAISE, KC_SPC), KC_HYPR

// These are helpers to define home-row mods
#define FL5(kc) LALT_T(kc)
#define FL4(kc) LCTL_T(kc)
#define FL3(kc) LCMD_T(kc)
#define FL2(kc) LSFT_T(kc)

#define FR2(kc) RSFT_T(kc)
#define FR3(kc) RCMD_T(kc)
#define FR4(kc) RCTL_T(kc)
#define FR5(kc) RALT_T(kc)

#endif
