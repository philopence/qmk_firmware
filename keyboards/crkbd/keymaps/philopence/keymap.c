/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _COLMAK_DH,
    _EXT,
    _SYM,
    _NUM,
    _FUN,
    _QWERTY,
};

#define EXT_SPC LT(_EXT, KC_SPC)
#define SYM_ESC LT(_SYM, KC_ESC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define FUN_BSPC LT(_FUN, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)
#define SFT_BSPC RSFT_T(KC_BSPC)

#define H_A HYPR_T(KC_A)
#define LA_R LALT_T(KC_R)
#define LC_S LCTL_T(KC_S)
#define LS_T LSFT_T(KC_T)
#define LG_G LGUI_T(KC_G)

#define RG_M RGUI_T(KC_M)
#define RS_N RSFT_T(KC_N)
#define RC_E RCTL_T(KC_E)
#define RA_I RALT_T(KC_I)
#define H_O HYPR_T(KC_O)

#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LSFT OSM(MOD_LSFT)

#define OSM_RGUI OSM(MOD_RGUI)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RSFT OSM(MOD_RSFT)

#define OSM_HYPR OSM(MOD_HYPR)

const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {LA_R, LC_S, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {LC_S, LS_T, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_d_combo[] = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM y_u_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM u_l_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM i_e_combo[] = {RA_I, RC_E, COMBO_END};
const uint16_t PROGMEM e_n_combo[] = {RC_E, RS_N, COMBO_END};
const uint16_t PROGMEM dot_comm_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_h_combo[] = {KC_COMM, KC_H, COMBO_END};

combo_t key_combos[] = {
  COMBO(w_f_combo, KC_LBRC),
  COMBO(f_p_combo, KC_RBRC),
  COMBO(r_s_combo, KC_LPRN),
  COMBO(s_t_combo, KC_RPRN),
  COMBO(x_c_combo, KC_LCBR),
  COMBO(c_d_combo, KC_RCBR),

  COMBO(y_u_combo, KC_MINS),
  COMBO(u_l_combo, KC_PLUS),
  COMBO(i_e_combo, KC_EQL),
  COMBO(e_n_combo, KC_UNDS),
  COMBO(dot_comm_combo, KC_SCLN),
  COMBO(comm_h_combo, KC_COLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLMAK_DH] = LAYOUT_split_3x6_3(
    XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
    XXXXXXX,     H_A,    LA_R,    LC_S,    LS_T,    LG_G,    RG_M,    RS_N,    RC_E,    RA_I,     H_O, XXXXXXX,
    XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
                               NUM_TAB, EXT_SPC, SYM_ESC, SYM_ENT, KC_LSFT,FUN_BSPC
  ),


  [_EXT] = LAYOUT_split_3x6_3(
    XXXXXXX,TG(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
    XXXXXXX,OSM_HYPR,OSM_LALT,OSM_LCTL,OSM_LSFT,OSM_LGUI, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, XXXXXXX,  KC_DEL
  ),


  [_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX,  KC_GRV, XXXXXXX,
    XXXXXXX, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, XXXXXXX, KC_TILD,  KC_DLR, KC_PERC, KC_CIRC, KC_PIPE, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, KC_BSLS, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
    XXXXXXX,OSM_HYPR,OSM_LALT,OSM_LCTL,OSM_LSFT,OSM_LGUI, KC_MINS,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT, XXXXXXX
  ),

  [_FUN] = LAYOUT_split_3x6_3(
    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,OSM_RGUI,OSM_RSFT,OSM_RCTL,OSM_RALT,OSM_HYPR, XXXXXXX,
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_QWERTY] = LAYOUT(
    XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
    XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
    XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
                               NUM_TAB, EXT_SPC, SYM_ESC, SYM_ENT,SFT_BSPC, TG(_QWERTY)
  )
};
