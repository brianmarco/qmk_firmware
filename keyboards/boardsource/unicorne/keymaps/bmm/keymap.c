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

#include <stdint.h>
#include "action.h"
#include "action_layer.h"
#include "keyboard.h"
#include "keycodes.h"
#include "modifiers.h"
#include "print.h"
#include "progmem.h"
#include "report.h"
#include "song_list.h"
#include QMK_KEYBOARD_H

enum layer_names { _BASE, _SYM_NAV, _FN_NUM, _MISC, _QWERTY };

enum combos { TAB, TMUX_LEADER, ESC, ENTER, EQ, MINS, QWERTY };

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

// Variables to store accumulated scroll values
// float scroll_accumulated_h = 0;
// float scroll_accumulated_v = 0;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───┬───┬───────┬───────────┬─────────┐   ┌──────────┬──────────┬───────┬───┬───┬─────┐
//    │   tab   │ q │ w │   f   │     p     │  BMM_B  │   │  BMM_J   │    l     │   u   │ y │ ; │  \  │
//    ├─────────┼───┼───┼───────┼───────────┼─────────┤   ├──────────┼──────────┼───────┼───┼───┼─────┤
//    │ QK_GESC │ a │ r │ BMM_S │   BMM_T   │  BMM_G  │   │  BMM_M   │  BMM_N   │ BMM_E │ i │ o │ ent │
//    ├─────────┼───┼───┼───────┼───────────┼─────────┤   ├──────────┼──────────┼───────┼───┼───┼─────┤
//    │    =    │ z │ x │   c   │     d     │  BMM_V  │   │  BMM_K   │    h     │   ,   │ . │ / │  -  │
//    └─────────┴───┴───┼───────┼───────────┼─────────┤   ├──────────┼──────────┼───────┼───┴───┴─────┘
//                      │ left  │ BMM_RIGHT │ BMM_SPC │   │ BMM_BSPC │ BMM_DOWN │  up   │
//                      └───────┴───────────┴─────────┘   └──────────┴──────────┴───────┘
[_BASE] = LAYOUT_split_3x6_3(
  _______  , KC_Q , KC_W , KC_F    , KC_P      , BMM_B   ,     BMM_J    , KC_L     , KC_U    , KC_Y   , KC_SCLN , _______,
  _______ , KC_A , KC_R , BMM_S   , BMM_T     , BMM_G   ,     BMM_M    , BMM_N    , BMM_E   , KC_I   , KC_O    , _______ ,
  _______  , KC_Z , KC_X , KC_C    , KC_D      , BMM_V   ,     BMM_K    , KC_H     , KC_COMM , KC_DOT , KC_SLSH , _______,
                          KC_LEFT , BMM_RIGHT , BMM_SPC ,     BMM_BSPC , BMM_DOWN , KC_UP
),

//    ┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌─────┬──────┬──────┬─────┬──────┬─────┐
//    │ pscr │ S(1) │ S(2) │ S([) │ S(]) │ S(') │   │     │      │      │     │ mute │     │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤   ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │      │ S(3) │ S(6) │ S(9) │ S(0) │  '   │   │     │      │      │     │ volu │     │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤   ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │      │ S(5) │ S(4) │  [   │  ]   │  `   │   │     │      │      │     │ vold │     │
//    └──────┴──────┴──────┼──────┼──────┼──────┤   ├─────┼──────┼──────┼─────┴──────┴─────┘
//                         │  <   │  >   │  ~   │   │ del │ pgdn │ pgup │
//                         └──────┴──────┴──────┘   └─────┴──────┴──────┘
[_SYM_NAV] = LAYOUT_split_3x6_3(
  KC_PSCR , S(KC_1) , S(KC_2) , S(KC_LBRC) , S(KC_RBRC) , S(KC_QUOT) ,     _______ , _______ , _______ , _______ , KC_MUTE , _______,
  _______ , S(KC_3) , S(KC_6) , S(KC_9)    , S(KC_0)    , KC_QUOT    ,     _______ , _______ , _______ , _______ , KC_VOLU , _______,
  _______ , S(KC_5) , S(KC_4) , KC_LBRC    , KC_RBRC    , KC_GRV     ,     _______ , _______ , _______ , _______ , KC_VOLD , _______,
                                KC_LT      , KC_GT      , KC_TILD    ,     KC_DEL  , KC_PGDN , KC_PGUP
),

//    ┌─────┬─────┬────┬─────┬─────┬─────┐   ┌─────┬───┬───┬───┬───┬─────┐
//    │     │ f10 │ f9 │ f8  │ f7  │     │   │     │ 7 │ 8 │ 9 │ \ │     │
//    ├─────┼─────┼────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┼───┼─────┤
//    │     │ f11 │ f6 │ f5  │ f4  │     │   │  0  │ 4 │ 5 │ 6 │ + │     │
//    ├─────┼─────┼────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┼───┼─────┤
//    │     │ f12 │ f3 │ f2  │ f1  │     │   │     │ 1 │ 2 │ 3 │ - │     │
//    └─────┴─────┴────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┴───┴─────┘
//                     │     │     │     │   │     │ 0 │ . │
//                     └─────┴─────┴─────┘   └─────┴───┴───┘
[_FN_NUM] = LAYOUT_split_3x6_3(
  _______ , KC_F10 , KC_F9 , KC_F8   , KC_F7   , _______ ,     _______ , KC_7 , KC_8   , KC_9 , KC_BSLS , _______,
  _______ , KC_F11 , KC_F6 , KC_F5   , KC_F4   , _______ ,     KC_0    , KC_4 , KC_5   , KC_6 , KC_PLUS , _______,
  _______ , KC_F12 , KC_F3 , KC_F2   , KC_F1   , _______ ,     _______ , KC_1 , KC_2   , KC_3 , KC_MINS , _______,
                             _______ , _______ , _______ ,     _______ , KC_0 , KC_DOT
),

//    ┌─────┬─────────┬─────┬──────┬──────┬─────┐   ┌─────────┬──────────────────┬──────────────────┬─────────┬─────────┬─────┐
//    │     │ QK_BOOT │     │      │      │     │   │         │                  │                  │         │ QK_BOOT │     │
//    ├─────┼─────────┼─────┼──────┼──────┼─────┤   ├─────────┼──────────────────┼──────────────────┼─────────┼─────────┼─────┤
//    │     │         │     │ btn2 │ btn1 │     │   │ RGB_TOG │     RGB_HUI      │     RGB_VAI      │ RGB_SAI │ RGB_SPI │     │
//    ├─────┼─────────┼─────┼──────┼──────┼─────┤   ├─────────┼──────────────────┼──────────────────┼─────────┼─────────┼─────┤
//    │     │         │     │      │      │     │   │         │     RGB_HUD      │     RGB_VAD      │ RGB_SAD │ RGB_SPD │     │
//    └─────┴─────────┴─────┼──────┼──────┼─────┤   ├─────────┼──────────────────┼──────────────────┼─────────┴─────────┴─────┘
//                          │      │      │     │   │         │ RGB_MODE_REVERSE │ RGB_MODE_FORWARD │
//                          └──────┴──────┴─────┘   └─────────┴──────────────────┴──────────────────┘
[_MISC] = LAYOUT_split_3x6_3(
  _______ , QK_BOOT , _______ , _______    , _______    , _______ ,     _______ , _______          , _______          , _______ , QK_BOOT , _______,
  _______ , _______ , _______ , KC_MS_BTN2 , KC_MS_BTN1 , _______ ,     RGB_TOG , RGB_HUI          , RGB_VAI          , RGB_SAI , RGB_SPI , _______,
  _______ , _______ , _______ , _______    , _______    , _______ ,     _______ , RGB_HUD          , RGB_VAD          , RGB_SAD , RGB_SPD , _______,
                                _______    , _______    , _______ ,     _______ , RGB_MODE_REVERSE , RGB_MODE_FORWARD
),

//    ┌─────────┬───┬───┬──────┬───────────┬─────┐   ┌──────┬──────────┬────┬───┬───┬──────┐
//    │   tab   │ q │ w │  e   │     r     │  t  │   │  y   │    u     │ i  │ o │ p │  \   │
//    ├─────────┼───┼───┼──────┼───────────┼─────┤   ├──────┼──────────┼────┼───┼───┼──────┤
//    │ QK_GESC │ a │ s │  d   │     f     │  g  │   │  h   │    j     │ l  │ l │ ; │  '   │
//    ├─────────┼───┼───┼──────┼───────────┼─────┤   ├──────┼──────────┼────┼───┼───┼──────┤
//    │  lsft   │ z │ x │  c   │     v     │  b  │   │  n   │    m     │ ,  │ . │ / │ rsft │
//    └─────────┴───┴───┼──────┼───────────┼─────┤   ├──────┼──────────┼────┼───┴───┴──────┘
//                      │ left │ BMM_RIGHT │ spc │   │ bspc │ BMM_DOWN │ up │
//                      └──────┴───────────┴─────┘   └──────┴──────────┴────┘
[_QWERTY] = LAYOUT_split_3x6_3(
  _______ , KC_Q , KC_W , KC_E    , KC_R      , KC_T   ,     KC_Y    , KC_U     , KC_I    , KC_O   , KC_P    , _______,
  _______ , KC_A , KC_S , KC_D    , KC_F      , KC_G   ,     KC_H    , KC_J     , KC_L    , KC_L   , KC_SCLN , _______,
  _______ , KC_Z , KC_X , KC_C    , KC_V      , KC_B   ,     KC_N    , KC_M     , KC_COMM , KC_DOT , KC_SLSH , _______,
                          KC_LEFT , BMM_RIGHT , KC_SPC ,     KC_BSPC , BMM_DOWN , KC_UP
)
};

const uint16_t PROGMEM tab_combo[]         = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM tmux_leader_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM esc_combo[]         = {BMM_S, BMM_T, COMBO_END};
const uint16_t PROGMEM enter_combo[]       = {BMM_N, BMM_E, COMBO_END};
const uint16_t PROGMEM eq_combo[]          = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM mins_combo[]        = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM qwerty_combo[]      = {KC_LEFT, KC_UP, COMBO_END};

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

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

float         qwerty_song[][2]  = SONG(QWERTY_SOUND);
float         colemak_song[][2] = SONG(COLEMAK_SOUND);
layer_state_t previous_layer    = _BASE;

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t new_layer = get_highest_layer(state);

    switch (new_layer) {
        case _QWERTY:
            PLAY_SONG(qwerty_song);
            break;
        case _BASE:
            if (previous_layer == _QWERTY) {
                PLAY_SONG(colemak_song);
            }
            break;
        default:
            break;
    }

    previous_layer = new_layer;
    return state;
}

// mouse_xy_report_t prev_x;
// mouse_xy_report_t prev_y;

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (!layer_state_is(_MISC)) {
//         if (mouse_report.x > 14 && mouse_report.x != prev_x) {
//             SEND_STRING(SS_TAP(X_RIGHT));
//             // prev_x = mouse_report.x;
//         }
//         else if (mouse_report.x < -14 && mouse_report.x != prev_x) {
//             SEND_STRING(SS_TAP(X_LEFT));
//             // prev_x = mouse_report.x;
//         }
//         else if (mouse_report.y == 15 && mouse_report.y != prev_y) {
//             SEND_STRING(SS_TAP(X_DOWN));
//             // prev_y = mouse_report.y;
//         }
//         else if (mouse_report.y == -15 && mouse_report.y != prev_y) {
//             SEND_STRING(SS_TAP(X_UP));
//             // prev_y = mouse_report.y;
//         }
//
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//         mouse_report.h = 0;
//         mouse_report.v = 0;
//     }
//
//     return mouse_report;
// }

/*
qmk:json:start
{
  "name": "Unicorne",
  "variant": "qmk",
  "layout": [
    "x x x x x x _ x x x x x x",
    "x x x x x x _ x x x x x x",
    "x x x x x x _ x x x x x x",
    "_ _ _ x x x _ x x x _ _ _"
  ]
}
qmk:json:end
*/
