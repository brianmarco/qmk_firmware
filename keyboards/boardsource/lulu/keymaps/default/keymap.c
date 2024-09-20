// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "action.h"
#include "action_layer.h"
#include "keyboard.h"
#include "keycodes.h"
#include "modifiers.h"
#include "print.h"
#include "progmem.h"
#include "report.h"

enum layers { _QWERTY, _RAISE, _LOWER, _ADJUST };

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

//    ┌─────────┬──────────┬─────────┬─────────┬─────────┬─────────┐                   ┌─────┬──────┬──────┬─────┬──────┬─────┐
//    │ RGB_MOD │ RGB_RMOD │ RGB_SAI │ RGB_SAD │ RGB_VAI │ RGB_VAD │                   │     │      │      │     │      │     │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │    `    │    1     │    2    │    3    │    4    │    5    │                   │  6  │  7   │  8   │  9  │  0   │     │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │   f1    │    f2    │   f3    │   f4    │   f5    │   f6    │                   │ no  │ left │ down │ up  │ rght │ no  │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┼─────────┐   ┌─────┼─────┼──────┼──────┼─────┼──────┼─────┤
//    │   f7    │    f8    │   f9    │   f10   │   f11   │   f12   │ RGB_TOG │   │     │  +  │  -   │  =   │  [  │  ]   │  \  │
//    └─────────┴──────────┼─────────┼─────────┼─────────┼─────────┼─────────┘   └─────┼─────┼──────┼──────┼─────┼──────┴─────┘
//                         │         │         │         │         │                   │     │      │      │     │
//                         └─────────┴─────────┴─────────┴─────────┘                   └─────┴──────┴──────┴─────┘
[_RAISE] = LAYOUT(
  RGB_MOD , RGB_RMOD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_GRV  , KC_1     , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______,
  KC_F1   , KC_F2    , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX,
  KC_F7   , KC_F8    , KC_F9   , KC_F10  , KC_F11  , KC_F12  , RGB_TOG ,     _______ , KC_PLUS , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
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

// clang-format off
combo_t key_combos[] = {
    [TMUX_LEADER] = COMBO(tmux_leader_combo, BMM_KC_TMUX_LEADER),
    [COPY] = COMBO(copy_combo, KC_COPY),
    [PASTE] = COMBO(paste_combo, KC_PASTE),
    [QWERTY] = COMBO(qwerty_combo, TG(_QWERTY))
};
// clang-format on
