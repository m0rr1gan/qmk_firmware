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

#include "meridian.h"

bool capsEnabled = false;
bool initialSetUp = true;

//Initialize B12 for in-switch caps lock
void keyboard_pre_init_kb(void){
   setPinOutput(B12);
   keyboard_pre_init_user();
}

//Initialize all RGB indicators to 'off'
__attribute__((weak))
   void keyboard_pre_init_user(void) {
      rgblight_setrgb_at(0, 0, 0, 0); // [..., 0] = top LED
      rgblight_setrgb_at(0, 0, 0, 1); // [..., 1] = middle LED
      rgblight_setrgb_at(0, 0, 0, 2); // [..., 2] = bottom LED
   }

//Indicator light function
bool led_update_kb(led_t led_state) {
   bool res = led_update_user(led_state);
   if (initialSetUp) {
      initialSetUp = false;
      rgblight_setrgb_at(0, 0, 0, 0); // [..., 0] = top LED
      rgblight_setrgb_at(0, 0, 0, 1); // [..., 1] = middle LED
      rgblight_setrgb_at(0, 0, 0, 2); // [..., 2] = bottom LED
   }
   return res;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case KC_CAPSLOCK:
         if (record->event.pressed) {
            capsEnabled = !capsEnabled;
            if (capsEnabled) {
               rgblight_setrgb_at(255, 0, 0, 0);
            } else {
               rgblight_setrgb_at(0, 0, 0, 0);
            }
         }
         return true;
      default:
         return true; // Process all other keycodes normally
   } 
}

layer_state_t layer_state_set_kb(layer_state_t state) {
   if (get_highest_layer(state) == 1) {
      rgblight_setrgb_at(255, 255, 255, 1);
   } else {
      rgblight_setrgb_at(0, 0, 0, 1);
   }

   if (get_highest_layer(state) == 2) {
      rgblight_setrgb_at(0, 0, 255, 2);
   } else {
      rgblight_setrgb_at(0, 0, 0, 2);
   }
   return state;
}
