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
#include "print.h"

enum layer_names { _BASE, _SYM_NAV, _FN_NUM, _MISC };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───┬───┬────────────────┬─────────────────┬───────────────────┐   ┌────────────────────┬─────────────────┬────────────────┬───┬───┬─────┐
//    │   tab   │ q │ w │       f        │        p        │  MT(MOD_LCTL, b)  │   │  MT(MOD_RCTL, j)   │        l        │       u        │ y │ ; │  \  │
//    ├─────────┼───┼───┼────────────────┼─────────────────┼───────────────────┤   ├────────────────────┼─────────────────┼────────────────┼───┼───┼─────┤
//    │ QK_GESC │ a │ r │ LT(_FN_NUM, s) │ LT(_SYM_NAV, t) │  MT(MOD_LGUI, g)  │   │  MT(MOD_RGUI, m)   │ LT(_SYM_NAV, n) │ LT(_FN_NUM, e) │ i │ o │ ent │
//    ├─────────┼───┼───┼────────────────┼─────────────────┼───────────────────┤   ├────────────────────┼─────────────────┼────────────────┼───┼───┼─────┤
//    │    =    │ z │ x │       c        │        d        │  MT(MOD_LALT, v)  │   │  MT(MOD_RALT, k)   │        h        │       ,        │ . │ / │  -  │
//    └─────────┴───┴───┼────────────────┼─────────────────┼───────────────────┤   ├────────────────────┼─────────────────┼────────────────┼───┴───┴─────┘
//                      │      left      │ LT(_MISC, rght) │ MT(MOD_LSFT, spc) │   │ MT(MOD_RSFT, bspc) │   LT(3, down)   │       up       │
//                      └────────────────┴─────────────────┴───────────────────┘   └────────────────────┴─────────────────┴────────────────┘
[_BASE] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q , KC_W , KC_F              , KC_P                , MT(MOD_LCTL, KC_B)   ,     MT(MOD_RCTL, KC_J)    , KC_L               , KC_U              , KC_Y   , KC_SCLN , KC_BSLS,
  QK_GESC , KC_A , KC_R , LT(_FN_NUM, KC_S) , LT(_SYM_NAV, KC_T)  , MT(MOD_LGUI, KC_G)   ,     MT(MOD_RGUI, KC_M)    , LT(_SYM_NAV, KC_N) , LT(_FN_NUM, KC_E) , KC_I   , KC_O    , KC_ENT ,
  KC_EQL  , KC_Z , KC_X , KC_C              , KC_D                , MT(MOD_LALT, KC_V)   ,     MT(MOD_RALT, KC_K)    , KC_H               , KC_COMM           , KC_DOT , KC_SLSH , KC_MINS,
                          KC_LEFT           , LT(_MISC, KC_RIGHT) , MT(MOD_LSFT, KC_SPC) ,     MT(MOD_RSFT, KC_BSPC) , LT(3, KC_DOWN)     , KC_UP
),

//    ┌─────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬─────┬─────┬──────┐
//    │     │ S(1) │ S(2) │ S([) │ S(]) │ S(') │   │ down │ rght │ pgdn │     │     │ mute │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼─────┼─────┼──────┤
//    │     │ S(3) │ S(6) │ S(9) │ S(0) │  '   │   │      │      │      │     │     │ volu │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼─────┼─────┼──────┤
//    │     │ S(5) │ S(4) │  [   │  ]   │  `   │   │  up  │ left │ pgup │     │     │ vold │
//    └─────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼─────┴─────┴──────┘
//                        │ S(,) │ S(.) │  .   │   │      │      │      │
//                        └──────┴──────┴──────┘   └──────┴──────┴──────┘
[_SYM_NAV] = LAYOUT_split_3x6_3(
  _______ , S(KC_1) , S(KC_2) , S(KC_LBRC) , S(KC_RBRC) , S(KC_QUOT) ,     KC_DOWN , KC_RIGHT , KC_PGDN , _______ , _______ , KC_MUTE,
  _______ , S(KC_3) , S(KC_6) , S(KC_9)    , S(KC_0)    , KC_QUOT    ,     _______ , _______  , _______ , _______ , _______ , KC_VOLU,
  _______ , S(KC_5) , S(KC_4) , KC_LBRC    , KC_RBRC    , KC_GRV     ,     KC_UP   , KC_LEFT  , KC_PGUP , _______ , _______ , KC_VOLD,
                                S(KC_COMM) , S(KC_DOT)  , KC_DOT     ,     _______ , _______  , _______
),

//    ┌─────┬─────┬────┬─────┬─────┬─────┐   ┌─────┬───┬───┬───┬─────┬─────┐
//    │ f11 │ f10 │ f9 │ f8  │ f7  │     │   │     │ 7 │ 8 │ 9 │     │     │
//    ├─────┼─────┼────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┼─────┼─────┤
//    │ f12 │     │ f6 │ f5  │ f4  │     │   │     │ 4 │ 5 │ 6 │     │     │
//    ├─────┼─────┼────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┼─────┼─────┤
//    │     │     │ f3 │ f2  │ f1  │     │   │     │ 1 │ 2 │ 3 │     │     │
//    └─────┴─────┴────┼─────┼─────┼─────┤   ├─────┼───┼───┼───┴─────┴─────┘
//                     │     │     │     │   │     │ 0 │ . │
//                     └─────┴─────┴─────┘   └─────┴───┴───┘
[_FN_NUM] = LAYOUT_split_3x6_3(
  KC_F11  , KC_F10  , KC_F9 , KC_F8   , KC_F7   , _______ ,     _______ , KC_7 , KC_8   , KC_9 , _______ , _______,
  KC_F12  , _______ , KC_F6 , KC_F5   , KC_F4   , _______ ,     _______ , KC_4 , KC_5   , KC_6 , _______ , _______,
  _______ , _______ , KC_F3 , KC_F2   , KC_F1   , _______ ,     _______ , KC_1 , KC_2   , KC_3 , _______ , _______,
                              _______ , _______ , _______ ,     _______ , KC_0 , KC_DOT
),

//    ┌─────────┬─────┬─────┬──────┬──────┬─────┐   ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────────────┐
//    │ QK_BOOT │     │     │      │      │     │   │ RGB_TOG │         │         │         │         │     QK_BOOT      │
//    ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤
//    │         │     │     │ btn2 │ btn1 │     │   │         │ RGB_HUI │ RGB_VAI │ RGB_SAI │ RGB_SPI │ RGB_MODE_FORWARD │
//    ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤
//    │         │     │     │      │      │     │   │         │ RGB_HUD │ RGB_VAD │ RGB_SAD │ RGB_SPD │ RGB_MODE_REVERSE │
//    └─────────┴─────┴─────┼──────┼──────┼─────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴──────────────────┘
//                          │      │      │     │   │         │         │         │
//                          └──────┴──────┴─────┘   └─────────┴─────────┴─────────┘
[_MISC] = LAYOUT_split_3x6_3(
  QK_BOOT , _______ , _______ , _______    , _______    , _______ ,     RGB_TOG , _______ , _______ , _______ , _______ , QK_BOOT         ,
  _______ , _______ , _______ , KC_MS_BTN2 , KC_MS_BTN1 , _______ ,     _______ , RGB_HUI , RGB_VAI , RGB_SAI , RGB_SPI , RGB_MODE_FORWARD,
  _______ , _______ , _______ , _______    , _______    , _______ ,     _______ , RGB_HUD , RGB_VAD , RGB_SAD , RGB_SPD , RGB_MODE_REVERSE,
                                _______    , _______    , _______ ,     _______ , _______ , _______
)
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


enum combos {
    TMUX_LEADER
};

const uint16_t PROGMEM tmux_leader_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM tmux_leader_combo_2[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[] = {[TMUX_LEADER] = COMBO(tmux_leader_combo, LCTL(KC_B))};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!layer_state_is(_MISC)) {
        if (mouse_report.y > 0) {
            SEND_STRING(SS_TAP(X_DOWN));
        }

        if (mouse_report.y < 0) {
            SEND_STRING(SS_TAP(X_UP));
        }

        if (mouse_report.x < 0) {
            SEND_STRING(SS_TAP(X_LEFT));
        }

        if (mouse_report.x > 0) {
            SEND_STRING(SS_TAP(X_RIGHT));
        }

        mouse_report.h = 0;
        mouse_report.v = 0;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}
