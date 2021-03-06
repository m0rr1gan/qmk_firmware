/*
Copyright 2020 Holten Campbell

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

// multi keys
#define KC_L1SP LT(1, KC_SPC)

#define KC_LGES LGUI_T(KC_ESC)
#define KC_LGDL LGUI_T(KC_DEL)
#define KC_RGDL RGUI_T(KC_DEL)

#define KC_LCAN LCA_T(KC_NO)
#define KC_LSGN SGUI_T(KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_bs_rshift(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, TG(2),
		KC_LALT, KC_LSGN,                   KC_LGDL, KC_L1SP, KC_SPC,  KC_RGUI,                                     KC_RCTL, KC_LCAN, KC_RALT
    ),
    [1] = LAYOUT_split_bs_rshift(
                RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC,
                _______, KC_HOME, KC_PGUP, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_DEL,
                KC_CAPS, KC_END,  KC_PGDN, KC_VOLD, KC_VOLU, KC_MUTE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,                     _______,
                _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            _______, _______,
                _______, _______,                   _______, _______, _______, _______,                                     _______, _______, _______
    ),
    [2] = LAYOUT_split_bs_rshift(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   _______,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_UP,   _______,
		_______, _______,                   _______, KC_SPC,  _______,  _______,                                    KC_LEFT, KC_DOWN, KC_RGHT
    )
};
