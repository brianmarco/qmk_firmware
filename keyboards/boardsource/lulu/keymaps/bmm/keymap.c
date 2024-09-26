// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

enum layer_names { _BASE, _FN_NUM, _SYM_NAV, _MISC, _QWERTY, _LOWER, _RAISE, _ADJUST };

const uint16_t PROGMEM BMM_B = MT(MOD_LCTL, KC_B);
const uint16_t PROGMEM BMM_J = MT(MOD_RCTL, KC_J);
const uint16_t PROGMEM BMM_S = LT(_FN_NUM, KC_S);
const uint16_t PROGMEM BMM_T = LT(_SYM_NAV, KC_T);
const uint16_t PROGMEM BMM_G = MT(MOD_LGUI, KC_G);
const uint16_t PROGMEM BMM_M = MT(MOD_RGUI, KC_M);
const uint16_t PROGMEM BMM_N = LT(_SYM_NAV, KC_N);
const uint16_t PROGMEM BMM_E = LT(_FN_NUM, KC_E);
const uint16_t PROGMEM BMM_V = MT(MOD_LALT, KC_V);
const uint16_t PROGMEM BMM_K = MT(MOD_RALT, KC_K);

const uint16_t PROGMEM BMM_RIGHT = LT(_MISC, KC_RIGHT);
const uint16_t PROGMEM BMM_SPC   = MT(MOD_LSFT, KC_SPC);
const uint16_t PROGMEM BMM_BSPC  = MT(MOD_RSFT, KC_BSPC);
const uint16_t PROGMEM BMM_DOWN  = LT(_MISC, KC_DOWN);

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬──────┬──────┬───────┬─────┐           ┌─────┬───────┬──────┬──────┬───┬──────┐
//    │ esc  │ 1 │  2   │  3   │   4   │  5  │           │  6  │   7   │  8   │  9   │ 0 │  `   │
//    ├──────┼───┼──────┼──────┼───────┼─────┤           ├─────┼───────┼──────┼──────┼───┼──────┤
//    │ tab  │ q │  w   │  e   │   r   │  t  │           │  y  │   u   │  i   │  o   │ p │  -   │
//    ├──────┼───┼──────┼──────┼───────┼─────┤           ├─────┼───────┼──────┼──────┼───┼──────┤
//    │ lctl │ a │  s   │  d   │   f   │  g  │           │  h  │   j   │  k   │  l   │ ; │  '   │
//    ├──────┼───┼──────┼──────┼───────┼─────┼───┐   ┌───┼─────┼───────┼──────┼──────┼───┼──────┤
//    │ lsft │ z │  x   │  c   │   v   │  b  │ [ │   │ ] │  n  │   m   │  ,   │  .   │ / │ rsft │
//    └──────┴───┼──────┼──────┼───────┼─────┼───┘   └───┼─────┼───────┼──────┼──────┼───┴──────┘
//               │ lalt │ lgui │ LOWER │ spc │           │ ent │ RAISE │ bspc │ rgui │
//               └──────┴──────┴───────┴─────┘           └─────┴───────┴──────┴──────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1 , KC_2    , KC_3    , KC_4  , KC_5   ,                         KC_6   , KC_7  , KC_8    , KC_9    , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R  , KC_T   ,                         KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_MINS,
  KC_LCTL , KC_A , KC_S    , KC_D    , KC_F  , KC_G   ,                         KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V  , KC_B   , KC_LBRC ,     KC_RBRC , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                   KC_LALT , KC_LGUI , LOWER , KC_SPC ,                         KC_ENT , RAISE , KC_BSPC , KC_RGUI
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │               │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │  `  │  !  │  @  │  #  │  $  │  %  │               │  ^  │  &  │  *  │  (  │  )  │  ~  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │     │   │     │ no  │  _  │  +  │  {  │  }  │  |  │
//    └─────┴─────┼─────┼─────┼─────┼─────┼─────┘   └─────┼─────┼─────┼─────┼─────┼─────┴─────┘
//                │     │     │     │     │               │     │     │     │     │
//                └─────┴─────┴─────┴─────┘               └─────┴─────┴─────┴─────┘
[_LOWER] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  KC_GRV  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_TILD,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , XXXXXXX , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE,
                      _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______
),

//    ┌─────────┬──────────┬─────────┬─────────┬─────────┬─────────┐               ┌─────┬──────┬──────┬─────┬──────┬─────┐
//    │ RGB_MOD │ RGB_RMOD │ RGB_SAI │ RGB_SAD │ RGB_VAI │ RGB_VAD │               │     │      │      │     │      │     │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │    `    │    1     │    2    │    3    │    4    │    5    │               │  6  │  7   │  8   │  9  │  0   │     │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │   f1    │    f2    │   f3    │   f4    │   f5    │   f6    │               │ no  │ left │ down │ up  │ rght │ no  │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┼─────┐   ┌─────┼─────┼──────┼──────┼─────┼──────┼─────┤
//    │   f7    │    f8    │   f9    │   f10   │   f11   │   f12   │     │   │     │  +  │  -   │  =   │  [  │  ]   │  \  │
//    └─────────┴──────────┼─────────┼─────────┼─────────┼─────────┼─────┘   └─────┼─────┼──────┼──────┼─────┼──────┴─────┘
//                         │         │         │         │         │               │     │      │      │     │
//                         └─────────┴─────────┴─────────┴─────────┘               └─────┴──────┴──────┴─────┘
[_RAISE] = LAYOUT(
  RGB_MOD , RGB_RMOD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_GRV  , KC_1     , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______,
  KC_F1   , KC_F2    , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX,
  KC_F7   , KC_F8    , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ ,     _______ , KC_PLUS , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
                       _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______
),

//    ┌────┬────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬────┬────┐
//    │ no │ no │ no  │ no  │ no  │ no  │             │ no  │ no  │ no  │ no  │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼────┼────┤
//    │ no │ no │ no  │ no  │ no  │ no  │             │ no  │ no  │ no  │ no  │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼────┼────┤
//    │ no │ no │ no  │ no  │ no  │ no  │             │ no  │ no  │ no  │ no  │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼─────┼────┐   ┌────┼─────┼─────┼─────┼─────┼────┼────┤
//    │ no │ no │ no  │ no  │ no  │ no  │ no │   │ no │ no  │ no  │ no  │ no  │ no │ no │
//    └────┴────┼─────┼─────┼─────┼─────┼────┘   └────┼─────┼─────┼─────┼─────┼────┴────┘
//              │     │     │     │     │             │     │     │     │     │
//              └─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┘
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                      _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______
),

//    ┌─────────┬───┬─────┬───────┬───────────┬─────────┐                       ┌──────────┬──────────┬───────┬─────┬───┬─────┐
//    │   esc   │ 1 │  2  │   3   │     4     │    5    │                       │    6     │    7     │   8   │  9  │ 0 │  `  │
//    ├─────────┼───┼─────┼───────┼───────────┼─────────┤                       ├──────────┼──────────┼───────┼─────┼───┼─────┤
//    │   tab   │ q │  w  │   f   │     p     │  BMM_B  │                       │  BMM_J   │    l     │   u   │  y  │ ; │  \  │
//    ├─────────┼───┼─────┼───────┼───────────┼─────────┤                       ├──────────┼──────────┼───────┼─────┼───┼─────┤
//    │ QK_GESC │ a │  r  │ BMM_S │   BMM_T   │  BMM_G  │                       │  BMM_M   │  BMM_N   │ BMM_E │  i  │ o │ ent │
//    ├─────────┼───┼─────┼───────┼───────────┼─────────┼─────────┐   ┌─────────┼──────────┼──────────┼───────┼─────┼───┼─────┤
//    │    =    │ z │  x  │   c   │     d     │  BMM_V  │ kB_MUTE │   │ RGB_TOG │  BMM_K   │    h     │   ,   │  .  │ / │  -  │
//    └─────────┴───┼─────┼───────┼───────────┼─────────┼─────────┘   └─────────┼──────────┼──────────┼───────┼─────┼───┴─────┘
//                  │     │ left  │ BMM_RIGHT │ BMM_SPC │                       │ BMM_BSPC │ BMM_DOWN │  up   │     │
//                  └─────┴───────┴───────────┴─────────┘                       └──────────┴──────────┴───────┴─────┘
[_BASE] = LAYOUT(
  KC_ESC  , KC_1 , KC_2    , KC_3    , KC_4      , KC_5    ,                            KC_6     , KC_7     , KC_8    , KC_9    , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q , KC_W    , KC_F    , KC_P      , BMM_B   ,                            BMM_J    , KC_L     , KC_U    , KC_Y    , KC_SCLN , KC_BSLS,
  QK_GESC , KC_A , KC_R    , BMM_S   , BMM_T     , BMM_G   ,                            BMM_M    , BMM_N    , BMM_E   , KC_I    , KC_O    , KC_ENT ,
  KC_EQL  , KC_Z , KC_X    , KC_C    , KC_D      , BMM_V   , KC_KB_MUTE ,     RGB_TOG , BMM_K    , KC_H     , KC_COMM , KC_DOT  , KC_SLSH , KC_MINS,
                   KC_TRNS , KC_LEFT , BMM_RIGHT , BMM_SPC ,                            BMM_BSPC , BMM_DOWN , KC_UP   , KC_TRNS
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬───┬───┬─────┬─────┬─────┐
//    │ esc │  1  │  2  │  3  │  4  │  5  │               │  6  │ 7 │ 8 │  9  │  0  │  `  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼───┼───┼─────┼─────┼─────┤
//    │ f11 │ f10 │ f9  │ f8  │ f7  │     │               │     │ 7 │ 8 │  9  │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼───┼───┼─────┼─────┼─────┤
//    │ f12 │     │ f6  │ f5  │ f4  │     │               │     │ 4 │ 5 │  6  │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼───┼───┼─────┼─────┼─────┤
//    │ f13 │     │ f3  │ f2  │ f1  │     │     │   │     │     │ 1 │ 2 │  3  │     │     │
//    └─────┴─────┼─────┼─────┼─────┼─────┼─────┘   └─────┼─────┼───┼───┼─────┼─────┴─────┘
//                │     │     │     │     │               │     │ 0 │ . │     │
//                └─────┴─────┴─────┴─────┘               └─────┴───┴───┴─────┘
[_FN_NUM] = LAYOUT(
  KC_ESC , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7 , KC_8   , KC_9    , KC_0    , KC_GRV ,
  KC_F11 , KC_F10  , KC_F9   , KC_F8   , KC_F7   , _______ ,                         _______ , KC_7 , KC_8   , KC_9    , _______ , _______,
  KC_F12 , _______ , KC_F6   , KC_F5   , KC_F4   , _______ ,                         _______ , KC_4 , KC_5   , KC_6    , _______ , _______,
  KC_F13 , _______ , KC_F3   , KC_F2   , KC_F1   , _______ , _______ ,     _______ , _______ , KC_1 , KC_2   , KC_3    , _______ , _______,
                     _______ , _______ , _______ , _______ ,                         _______ , KC_0 , KC_DOT , _______
),

//    ┌──────┬──────┬──────┬──────┬──────┬──────┐               ┌──────┬──────┬──────┬─────┬─────┬──────┐
//    │ esc  │  1   │  2   │  3   │  4   │  5   │               │  6   │  7   │  8   │  9  │  0  │  `   │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤               ├──────┼──────┼──────┼─────┼─────┼──────┤
//    │ pscr │ S(1) │ S(2) │ S([) │ S(]) │ S(') │               │ down │ rght │ pgdn │     │     │ mute │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤               ├──────┼──────┼──────┼─────┼─────┼──────┤
//    │      │ S(3) │ S(6) │ S(9) │ S(0) │  '   │               │      │      │      │     │     │ volu │
//    ├──────┼──────┼──────┼──────┼──────┼──────┼─────┐   ┌─────┼──────┼──────┼──────┼─────┼─────┼──────┤
//    │      │ S(5) │ S(4) │  [   │  ]   │  `   │     │   │     │  up  │ left │ pgup │     │     │ vold │
//    └──────┴──────┼──────┼──────┼──────┼──────┼─────┘   └─────┼──────┼──────┼──────┼─────┼─────┴──────┘
//                  │      │ S(,) │ S(.) │  .   │               │ del  │      │      │     │
//                  └──────┴──────┴──────┴──────┘               └──────┴──────┴──────┴─────┘
[_SYM_NAV] = LAYOUT(
  KC_ESC  , KC_1    , KC_2    , KC_3       , KC_4       , KC_5       ,                         KC_6    , KC_7     , KC_8    , KC_9    , KC_0    , KC_GRV ,
  KC_PSCR , S(KC_1) , S(KC_2) , S(KC_LBRC) , S(KC_RBRC) , S(KC_QUOT) ,                         KC_DOWN , KC_RIGHT , KC_PGDN , _______ , _______ , KC_MUTE,
  _______ , S(KC_3) , S(KC_6) , S(KC_9)    , S(KC_0)    , KC_QUOT    ,                         _______ , _______  , _______ , _______ , _______ , KC_VOLU,
  _______ , S(KC_5) , S(KC_4) , KC_LBRC    , KC_RBRC    , KC_GRV     , _______ ,     _______ , KC_UP   , KC_LEFT  , KC_PGUP , _______ , _______ , KC_VOLD,
                      _______ , S(KC_COMM) , S(KC_DOT)  , KC_DOT     ,                         KC_DEL  , _______  , _______ , _______
),

//    ┌─────────┬─────┬─────┬──────┬──────┬─────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────────────┐
//    │   esc   │  1  │  2  │  3   │  4   │  5  │               │    6    │    7    │    8    │    9    │    0    │        `         │
//    ├─────────┼─────┼─────┼──────┼──────┼─────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤
//    │ QK_BOOT │     │     │      │      │     │               │ RGB_TOG │         │         │         │         │     QK_BOOT      │
//    ├─────────┼─────┼─────┼──────┼──────┼─────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤
//    │         │     │     │ btn2 │ btn1 │     │               │         │ RGB_HUI │ RGB_VAI │ RGB_SAI │ RGB_SPI │ RGB_MODE_FORWARD │
//    ├─────────┼─────┼─────┼──────┼──────┼─────┼─────┐   ┌─────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤
//    │         │     │     │      │      │     │     │   │     │         │ RGB_HUD │ RGB_VAD │ RGB_SAD │ RGB_SPD │ RGB_MODE_REVERSE │
//    └─────────┴─────┼─────┼──────┼──────┼─────┼─────┘   └─────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────────────────┘
//                    │     │      │      │     │               │         │         │         │         │
//                    └─────┴──────┴──────┴─────┘               └─────────┴─────────┴─────────┴─────────┘
[_MISC] = LAYOUT(
  KC_ESC  , KC_1    , KC_2    , KC_3       , KC_4       , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_GRV          ,
  QK_BOOT , _______ , _______ , _______    , _______    , _______ ,                         RGB_TOG , _______ , _______ , _______ , _______ , QK_BOOT         ,
  _______ , _______ , _______ , KC_MS_BTN2 , KC_MS_BTN1 , _______ ,                         _______ , RGB_HUI , RGB_VAI , RGB_SAI , RGB_SPI , RGB_MODE_FORWARD,
  _______ , _______ , _______ , _______    , _______    , _______ , _______ ,     _______ , _______ , RGB_HUD , RGB_VAD , RGB_SAD , RGB_SPD , RGB_MODE_REVERSE,
                      _______ , _______    , _______    , _______ ,                         _______ , _______ , _______ , _______
)
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

enum combos { TMUX_LEADER, COPY, PASTE, QWERTY };

const uint16_t PROGMEM tmux_leader_combo[] = {BMM_T, BMM_N, COMBO_END};
const uint16_t PROGMEM copy_combo[]        = {BMM_T, BMM_G, COMBO_END};
const uint16_t PROGMEM paste_combo[]       = {BMM_M, BMM_N, COMBO_END};
const uint16_t PROGMEM qwerty_combo[]      = {KC_TAB, KC_BSLS, COMBO_END};

const uint16_t PROGMEM BMM_KC_TMUX_LEADER = LCTL(KC_B);

// clang-format off
combo_t key_combos[] = {
    [TMUX_LEADER] = COMBO(tmux_leader_combo, BMM_KC_TMUX_LEADER),
    [COPY] = COMBO(copy_combo, KC_COPY),
    [PASTE] = COMBO(paste_combo, KC_PASTE),
    [QWERTY] = COMBO(qwerty_combo, TG(_QWERTY))
};
// clang-format on
