// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk:json:start
{
  "name": "LAYOUT",
  "variant": "qmk",
  "layout": [
          "x x x x x x _ _ _ x x x x x x",
          "x x x x x x _ _ _ x x x x x x",
          "x x x x x x _ _ _ x x x x x x",
          "x x x x x x x _ x x x x x x x",
          "_ _ x x x x _ _ _ x x x x _ _"
  ]
}
qmk:json:end
*/

// NOTE: The rotation of the encoders is specified in keyboards/lulu/lulu.c

#include "keycodes.h"
#include QMK_KEYBOARD_H

enum {
    TD_SEMIC,
    TD_MACOS_COPYPASTA,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SEMIC]           = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_MACOS_COPYPASTA] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_C), LGUI(KC_C)),
};

enum layer_names {
    _BASE,
    _FN_NUM,
    _SYM_NAV,
    _MISC,
    _QWERTY,
};

const uint16_t PROGMEM BMM_KC_TMUX_LEADER = LCTL(KC_B);

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬──────┬──────┬─────┬─────┐           ┌─────┬─────┬──────┬──────┬───┬──────┐
//    │ esc  │ 1 │  2   │  3   │  4  │  5  │           │  6  │  7  │  8   │  9   │ 0 │  `   │
//    ├──────┼───┼──────┼──────┼─────┼─────┤           ├─────┼─────┼──────┼──────┼───┼──────┤
//    │ tab  │ q │  w   │  e   │  r  │  t  │           │  y  │  u  │  i   │  o   │ p │  -   │
//    ├──────┼───┼──────┼──────┼─────┼─────┤           ├─────┼─────┼──────┼──────┼───┼──────┤
//    │ lctl │ a │  s   │  d   │  f  │  g  │           │  h  │  j  │  k   │  l   │ ; │  '   │
//    ├──────┼───┼──────┼──────┼─────┼─────┼───┐   ┌───┼─────┼─────┼──────┼──────┼───┼──────┤
//    │ lsft │ z │  x   │  c   │  v  │  b  │ [ │   │ ] │  n  │  m  │  ,   │  .   │ / │ rsft │
//    └──────┴───┼──────┼──────┼─────┼─────┼───┘   └───┼─────┼─────┼──────┼──────┼───┴──────┘
//               │ lalt │ lgui │     │ spc │           │ ent │     │ bspc │ rgui │
//               └──────┴──────┴─────┴─────┘           └─────┴─────┴──────┴──────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1 , KC_2    , KC_3    , KC_4    , KC_5   ,                         KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T   ,                         KC_Y   , KC_U    , KC_I    , KC_O    , KC_P    , KC_MINS,
  KC_LCTL , KC_A , KC_S    , KC_D    , KC_F    , KC_G   ,                         KC_H   , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B   , KC_LBRC ,     KC_RBRC , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                   KC_LALT , KC_LGUI , _______ , KC_SPC ,                         KC_ENT , _______ , KC_BSPC , KC_RGUI
),

//    ┌─────┬─────┬─────┬───────┬───────────┬─────────┐                       ┌──────────────┬──────────┬───────┬─────┬──────────────┬─────┐
//    │     │     │     │       │           │         │                       │ pRINT_SCREEN │          │       │     │              │     │
//    ├─────┼─────┼─────┼───────┼───────────┼─────────┤                       ├──────────────┼──────────┼───────┼─────┼──────────────┼─────┤
//    │     │  q  │  w  │   f   │     p     │  BMM_B  │                       │    BMM_J     │    l     │   u   │  y  │ TD(TD_SEMIC) │     │
//    ├─────┼─────┼─────┼───────┼───────────┼─────────┤                       ├──────────────┼──────────┼───────┼─────┼──────────────┼─────┤
//    │     │  a  │  r  │ BMM_S │   BMM_T   │  BMM_G  │                       │    BMM_M     │  BMM_N   │ BMM_E │  i  │      o       │     │
//    ├─────┼─────┼─────┼───────┼───────────┼─────────┼─────────┐   ┌─────────┼──────────────┼──────────┼───────┼─────┼──────────────┼─────┤
//    │     │  z  │  x  │   c   │     d     │  BMM_V  │ kB_MUTE │   │ RGB_TOG │    BMM_K     │    h     │   ,   │  .  │      /       │     │
//    └─────┴─────┼─────┼───────┼───────────┼─────────┼─────────┘   └─────────┼──────────────┼──────────┼───────┼─────┼──────────────┴─────┘
//                │     │ left  │ BMM_RIGHT │ BMM_SPC │                       │   BMM_BSPC   │ BMM_DOWN │  up   │     │
//                └─────┴───────┴───────────┴─────────┘                       └──────────────┴──────────┴───────┴─────┘
[_BASE] = LAYOUT(
  _______ , _______ , _______ , _______ , _______   , _______ ,                            KC_PRINT_SCREEN , _______  , _______ , _______ , _______      , _______,
  _______ , KC_Q    , KC_W    , KC_F    , KC_P      , BMM_B   ,                            BMM_J           , KC_L     , KC_U    , KC_Y    , TD(TD_SEMIC) , _______,
  _______ , KC_A    , KC_R    , BMM_S   , BMM_T     , BMM_G   ,                            BMM_M           , BMM_N    , BMM_E   , KC_I    , KC_O         , _______,
  _______ , KC_Z    , KC_X    , KC_C    , KC_D      , BMM_V   , KC_KB_MUTE ,     RGB_TOG , BMM_K           , KC_H     , KC_COMM , KC_DOT  , KC_SLSH      , _______,
                      KC_TRNS , KC_LEFT , BMM_RIGHT , BMM_SPC ,                            BMM_BSPC        , BMM_DOWN , KC_UP   , KC_TRNS
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ f10 │ f9  │ f8  │ f7  │     │               │     │  7  │  8  │  9  │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ f11 │ f6  │ f5  │ f4  │     │               │     │  4  │  5  │  6  │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ f12 │ f3  │ f2  │ f1  │     │     │   │     │     │  1  │  2  │  3  │     │     │
//    └─────┴─────┼─────┼─────┼─────┼─────┼─────┘   └─────┼─────┼─────┼─────┼─────┼─────┴─────┘
//                │     │     │     │     │               │     │  0  │  .  │     │
//                └─────┴─────┴─────┴─────┘               └─────┴─────┴─────┴─────┘
[_FN_NUM] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_F10  , KC_F9   , KC_F8   , KC_F7   , _______ ,                         _______ , KC_7    , KC_8    , KC_9    , _______ , _______,
  _______ , KC_F11  , KC_F6   , KC_F5   , KC_F4   , _______ ,                         _______ , KC_4    , KC_5    , KC_6    , _______ , _______,
  _______ , KC_F12  , KC_F3   , KC_F2   , KC_F1   , _______ , _______ ,     _______ , _______ , KC_1    , KC_2    , KC_3    , _______ , _______,
                      _______ , _______ , _______ , _______ ,                         _______ , KC_0    , KC_DOT  , _______
),

//    ┌─────┬──────┬──────┬──────┬──────┬──────┐               ┌─────┬──────┬──────┬─────┬─────┬─────┐
//    │     │      │      │      │      │      │               │     │      │      │     │     │     │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤               ├─────┼──────┼──────┼─────┼─────┼─────┤
//    │     │  |   │  \   │ S([) │ S(]) │ S(') │               │     │      │      │     │     │     │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤               ├─────┼──────┼──────┼─────┼─────┼─────┤
//    │     │ S(6) │ S(4) │ S(9) │ S(0) │  '   │               │     │      │      │     │     │     │
//    ├─────┼──────┼──────┼──────┼──────┼──────┼─────┐   ┌─────┼─────┼──────┼──────┼─────┼─────┼─────┤
//    │     │ S(5) │ S(4) │  [   │  ]   │  `   │     │   │     │     │      │      │     │     │     │
//    └─────┴──────┼──────┼──────┼──────┼──────┼─────┘   └─────┼─────┼──────┼──────┼─────┼─────┴─────┘
//                 │      │ S(,) │ S(.) │  ~   │               │ del │ pgdn │ pgup │     │
//                 └──────┴──────┴──────┴──────┘               └─────┴──────┴──────┴─────┘
[_SYM_NAV] = LAYOUT(
  _______ , _______ , _______ , _______    , _______    , _______    ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_PIPE , KC_BSLS , S(KC_LBRC) , S(KC_RBRC) , S(KC_QUOT) ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , S(KC_6) , S(KC_4) , S(KC_9)    , S(KC_0)    , KC_QUOT    ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , S(KC_5) , S(KC_4) , KC_LBRC    , KC_RBRC    , KC_GRV     , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
                      _______ , S(KC_COMM) , S(KC_DOT)  , KC_TILD    ,                         KC_DEL  , KC_PGDN , KC_PGUP , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐                       ┌──────────────────┬─────────┬─────────┬─────────┬─────────┬─────┐
//    │     │     │     │     │     │     │                       │                  │         │         │         │         │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├──────────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │     │     │     │     │     │                       │                  │         │         │         │         │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├──────────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │     │     │     │     │     │                       │ RGB_MODE_FORWARD │ RGB_HUI │ RGB_VAI │ RGB_SAI │ RGB_SPI │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────────┐   ┌─────────┼──────────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │     │     │     │     │     │ QK_BOOT │   │ QK_BOOT │ RGB_MODE_REVERSE │ RGB_HUD │ RGB_VAD │ RGB_SAD │ RGB_SPD │     │
//    └─────┴─────┼─────┼─────┼─────┼─────┼─────────┘   └─────────┼──────────────────┼─────────┼─────────┼─────────┼─────────┴─────┘
//                │     │     │     │     │                       │                  │         │         │         │
//                └─────┴─────┴─────┴─────┘                       └──────────────────┴─────────┴─────────┴─────────┘
[_MISC] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______          , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______          , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         RGB_MODE_FORWARD , RGB_HUI , RGB_VAI , RGB_SAI , RGB_SPI , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT ,     QK_BOOT , RGB_MODE_REVERSE , RGB_HUD , RGB_VAD , RGB_SAD , RGB_SPD , _______,
                      _______ , _______ , _______ , _______ ,                         _______          , _______ , _______ , _______
)
};
// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

enum combos { TAB, TMUX_LEADER, ESC, ENTER, EQ, MINS, QWERTY };

const uint16_t PROGMEM tab_combo[]         = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM tmux_leader_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM esc_combo[]         = {BMM_S, BMM_T, COMBO_END};
const uint16_t PROGMEM enter_combo[]       = {BMM_N, BMM_E, COMBO_END};
const uint16_t PROGMEM eq_combo[]          = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM mins_combo[]        = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM qwerty_combo[]      = {KC_LEFT, KC_UP, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [TAB] = COMBO(tab_combo, KC_TAB),
    [TMUX_LEADER] = COMBO(tmux_leader_combo, BMM_KC_TMUX_LEADER),
    [ESC] = COMBO(esc_combo, KC_ESC),
    [ENTER] = COMBO(enter_combo, KC_ENT),
    [EQ] = COMBO(eq_combo, KC_EQL),
    [MINS] = COMBO(mins_combo, KC_MINS),
    [QWERTY] = COMBO(qwerty_combo, TG(_QWERTY))
};
// clang-format on
