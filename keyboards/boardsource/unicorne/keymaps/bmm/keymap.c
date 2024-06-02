/*
Copyright 2022 Cole Smith <cole@boadsource.xyz>

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
    _BASE,
    _SYM_NAV,
    _FN_NUM,
    _MISC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q, KC_W, KC_F,             KC_P,                MT(MOD_LCTL,KC_B),    MT(MOD_RCTL, KC_J),   KC_L,               KC_U,             KC_Y,    KC_SCLN, KC_BSLS
    KC_GESC, KC_A, KC_R, LT(_FN_NUM,KC_S), LT(_SYM_NAV,KC_T),   MT(MOD_LGUI, KC_G),   MT(MOD_RGUI, KC_M),   LT(_SYM_NAV, KC_N), LT(_FN_NUM,KC_E), KC_I,    KC_O,    KC_ENT
    KC_EQL,  KC_Z, KC_X, KC_C,             KC_D,                MT(MOD_LALT,KC_V),    MT(MOD_RALT,KC_K),    KC_H,               KC_COMM,          KC_DOT,  KC_SLSH, KC_MINS
                         KC_LEFT,          LT(_MISC, KC_RIGHT), MT(MOD_LSFT,KC_SPC),  MT(MOD_RSFT,KC_BSPC), LT(3,KC_DOWN),      KC_UP
  ),
  [_SYM_NAV] = LAYOUT_split_3x6_3(
    _______, S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), S(KC_QUOT), MT(MOD_LCTL,KC_B),    KC_DOWN, KC_RIGHT, KC_PGDN, KC_MUTE, RGB_TOG, _______
    _______, S(KC_3), S(KC_6), S(KC_9),    S(KC_0),    KC_QUOT,    MT(MOD_LGUI, KC_G),   _______, _______,  _______, KC_VOLU, RBG_HUI, _______
    _______, S(KC_5), S(KC_4), KC_LBRC,    KC_RBRC,    KC_GRV,     MT(MOD_LALT,KC_V),    KC_UP,   KC_LEFT,  KC_PGUP, KC_VOLD, RGB_HUD, _______
                               S(KC_COMM), S(KC_DOT),  KC_DOT,     MT(MOD_RSFT,KC_BSPC), _______,  _______
  ),
  [_FN_NUM] = LAYOUT_split_3x6_3(
    KC_F11,  KC_F10,     KC_F9, KC_F8,   KC_F7,   _______,    _______, _______, KC_7,   KC_8, KC_9, _______, _______
    KC_F12,  KC_MS_BTN2, KC_F6, KC_F5,   KC_F4,   KC_MS_BTN1, _______, _______, KC_4,   KC_5, KC_6, _______, _______
    _______, _______,    KC_F3, KC_F2,   KC_F1,   _______,    _______, _______, KC_1,   KC_2, KC_3, _______, _______
                                _______, _______, _______,    _______, KC_0,    KC_PDOT
  ),
  [_MISC] = LAYOUT_split_3x6_3(
    _______,  _______,  _______, _______, _______, _______,    _______, _______, _______,  _______, _______, _______, _______
    _______,  _______,  _______, _______, _______, _______,    _______, _______, _______,  _______, _______, _______, _______
    _______,  _______,  _______, _______, _______, _______,    _______, _______, _______,  _______, _______, _______, _______
                                 _______, _______, _______,    _______, _______, _______
  )

  // [_SYM_NAV] = LAYOUT_split_3x6_3(
  //   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //   KC_TAB,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  //   KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_QUOT,
  //                     XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
  // ),
  //
  // [_FN_NUM] = LAYOUT_split_3x6_3(
  //   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //   KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //   KC_CAPS, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_DQT,
  //                     XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,  XXXXXXX, KC_DEL
  // ),
  //
  // [_MISC] = LAYOUT_split_3x6_3(
  //   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //   KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //   KC_CAPS, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_DQT,
  //                     XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,  XXXXXXX, KC_DEL
  // )
};
