/* Copyright 2018 westfoxtrot
 * Copyright 2019 kwerdenker
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _DL 0
#define _FN 1
#define _LE 2

#define SPECIAL LT(_FN, DE_CIRC)    //capslock layer switch + stargate key on tap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DL] = LAYOUT_iso (
      KC_ESC,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   DE_SS,   DE_ACUT, KC_BSPC, _______,     KC_DEL, KC_PSCR,KC_PSLS,KC_PAST,
      KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,  DE_Z,  KC_U,  KC_I,  KC_O,    KC_P,   DE_UE,   DE_PLUS,                       KC_P7,   KC_P8,  KC_P9,  KC_PMNS,
      SPECIAL, KC_A,    KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    DE_OE,  DE_AE,   DE_HASH, KC_ENT,               KC_P4,   KC_P5,  KC_P6,  KC_PPLS,
      KC_LSFT, DE_LESS, DE_Y,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, DE_MINS, KC_RSFT,        KC_UP,         KC_P1,   KC_P2,  KC_P3,  KC_PENT,
      KC_LCTL, _______, KC_LALT,             KC_SPC,                     _______, KC_RALT, TG(_LE),       KC_LEFT, KC_DOWN, KC_RGHT,        KC_P0,  KC_PDOT, KC_NO
  ),

  [_FN] = LAYOUT_iso (
      DE_RING, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______,       KC_NLCK, _______, _______, _______,
      _______, _______, KC_UP,   _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,                        _______, _______, _______, _______,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               _______, _______, _______, _______,
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               _______, _______, _______, _______,
      _______, _______, _______,             KC_LGUI,                _______, _______, _______,                         _______, _______, _______,               _______, _______, _______
  ),

  [_LE] = LAYOUT_iso (
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, RESET,
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,                        RGB_TOG, RGB_MOD, RGB_RMOD,_______,
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               RGB_HUI, RGB_SAI, RGB_VAI, _______,
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               RGB_HUD, RGB_SAD, RGB_VAD, _______,
      _______, _______, _______,             _______,                _______, _______, _______,                         _______, _______, _______,               _______, _______, _______
  ),
};



void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool led_update_user(led_t led_state) {
    writePin(F4, led_state.num_lock);
    writePin(F1, led_state.num_lock);
    writePin(F5, led_state.num_lock);
    return false;
}
