// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _EXT,
    _SYM,
    _NUM,
    _FUN,
};

#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LSFT OSM(MOD_LSFT)

#define OSM_RGUI OSM(MOD_RGUI)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RSFT OSM(MOD_RSFT)

#define OSM_HYPR OSM(MOD_HYPR)

#define EXT_SPC LT(_EXT, KC_SPC)
#define SYM_ESC LT(_SYM, KC_ESC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define FUN_BSPC LT(_FUN, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)
#define SFT_BSPC RSFT_T(KC_BSPC)

#define H_A HYPR_T(KC_A)
#define LA_S LALT_T(KC_S)
#define LC_D LCTL_T(KC_D)
#define LS_F LSFT_T(KC_F)
#define LG_G LGUI_T(KC_G)

#define RG_H RGUI_T(KC_H)
#define RS_J RSFT_T(KC_J)
#define RC_K RCTL_T(KC_K)
#define RA_L RALT_T(KC_L)
#define H_SCLN HYPR_T(KC_SCLN)

const uint16_t PROGMEM w_e_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM e_r_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM s_d_combo[] = {LA_S, LC_D, COMBO_END};
const uint16_t PROGMEM d_f_combo[] = {LC_D, LS_F, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM o_i_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM i_u_combo[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM l_k_combo[] = {RA_L, RC_K, COMBO_END};
const uint16_t PROGMEM k_j_combo[] = {RC_K, RS_J, COMBO_END};
const uint16_t PROGMEM dot_comm_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_m_combo[] = {KC_COMM, KC_M, COMBO_END};

combo_t key_combos[] = {
  COMBO(w_e_combo, KC_LBRC),
  COMBO(e_r_combo, KC_RBRC),
  COMBO(s_d_combo, KC_LPRN),
  COMBO(d_f_combo, KC_RPRN),
  COMBO(x_c_combo, KC_LCBR),
  COMBO(c_v_combo, KC_RCBR),

  COMBO(o_i_combo, KC_MINS),
  COMBO(i_u_combo, KC_PLUS),
  COMBO(l_k_combo, KC_EQL),
  COMBO(k_j_combo, KC_UNDS),
  COMBO(dot_comm_combo, KC_QUOT),
  COMBO(comm_m_combo, KC_DQUO),
};
//////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          H_A,    LA_S,    LC_D,    LS_F,    LG_G,                         RG_H,    RS_J,    RC_K,    RA_L,  H_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 NUM_TAB, EXT_SPC, SYM_ESC,    SYM_ENT,SFT_BSPC, FUN_DEL
                             //`--------------------------'  `--------------------------'
  ),

    [_EXT] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     OSM_HYPR,OSM_LALT,OSM_LCTL,OSM_LSFT,OSM_LGUI,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, XXXXXXX,                      KC_TILD,  KC_DLR, KC_PERC, KC_CIRC, KC_PIPE,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_LABK, KC_RABK, XXXXXXX, XXXXXXX,                       KC_GRV, KC_EXLM,   KC_AT, KC_HASH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     OSM_HYPR,OSM_LALT,OSM_LCTL,OSM_LSFT,OSM_LGUI,                      KC_MINS,    KC_4,    KC_5,    KC_6, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  KC_DOT, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

    [_FUN] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                     OSM_RGUI,OSM_RSFT,OSM_RCTL,OSM_RALT,OSM_HYPR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  )

};
