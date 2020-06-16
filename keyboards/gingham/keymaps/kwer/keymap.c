/* Copyright 2018 Yiancar
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

#include "keymap_extras/keymap_german.h"

//Layer renaming
#define _DL  0                     //default
#define _FUN 1                     //function layer

//Keymapping renaming
#define ______  KC_TRNS            //renaming KC_TRNS for readability in keymaps
#define MONKEY  LCTL(LALT(KC_DEL)) //ctrl+alt+del == monkey grip
#define SPECIAL LT(_FUN, DE_CIRC)  //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DL] = LAYOUT_60_iso_split_bs_rshift(
      KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,      KC_5,    KC_6,    KC_7,   KC_8,    KC_9, KC_0,   DE_SS,   DE_ACUT, KC_BSPC,       KC_BSPC,  \
      KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,      KC_T,    DE_Z,    KC_U,   KC_I,    KC_O, KC_P,   DE_UE,   DE_PLUS,                         \
      SPECIAL, KC_A,    KC_S,    KC_D,   KC_F,      KC_G,    KC_H,    KC_J,   KC_K,    KC_L, DE_OE,  DE_AE,   DE_HASH,               KC_ENT,   \
      KC_LSFT, DE_LESS, DE_Y,    KC_X,   KC_C,      KC_V,    KC_B,    KC_N,   KC_M, KC_COMM, KC_DOT, DE_MINS, MT(MOD_RSFT, KC_UP),   KC_PSCR,  \
      KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC                        , KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT),

  [_FUN] = LAYOUT_60_iso_split_bs_rshift(
      RESET,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,  KC_F12, KC_DEL, KC_DEL,   \
      ______, KC_PGUP, KC_UP,   KC_PGDN,  ______,  ______, ______, ______, ______, ______, ______, ______,  ______,                   \
      ______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_HOME, ______, ______, KC_END, ______, ______, ______, ______,  ______,         ______,   \
      ______, ______, ______,   ______,   ______,  ______, ______, ______, ______, ______, ______, ______,           KC_UP, ______,   \
      ______, ______, ______,                              ______                        , ______, KC_LEFT, KC_DOWN,        KC_RIGHT  )
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
