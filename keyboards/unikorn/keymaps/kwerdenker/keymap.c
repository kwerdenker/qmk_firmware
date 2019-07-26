/* Copyright 2019 MechMerlin
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
#include "keymap_extras/sendstring_german.h"

//Layer renaming
#define _DL  0                     //default
#define _FUN 1                     //function layer

#define ______  KC_TRNS            //renaming KC_TRNS for readability in keymaps
#define SPECIAL LT(_FUN, DE_CIRC)  //
#define MONKEY  LCTL(LALT(KC_DEL)) //ctrl+alt+del == monkey grip

enum custom_keycodes {
  MATE = SAFE_RANGE,
};

enum {
  TD_DEL_PRT = 0
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MATE:
      if (record->event.pressed) {
        SEND_STRING("https://media.discordapp.net/attachments/356237221306695680/575400060557459456/mate-bot.gif");
      }
      break;
  }
  return true;
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DEL_PRT]  = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_PSCR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DL] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,      KC_5,    KC_6,    KC_7,   KC_8,    KC_9, KC_0,   DE_SS,   DE_ACUT, KC_BSPC, ______,   \
      KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,      KC_T,    DE_Z,    KC_U,   KC_I,    KC_O, KC_P,   DE_UE,   DE_PLUS,          ______,   \
      SPECIAL, KC_A,    KC_S,    KC_D,   KC_F,      KC_G,    KC_H,    KC_J,   KC_K,    KC_L, DE_OE,  DE_AE,   DE_HASH,          KC_ENT,   \
      KC_LSFT, DE_LESS, DE_Y,    KC_X,   KC_C,      KC_V,    KC_B,    KC_N,   KC_M, KC_COMM, KC_DOT, DE_MINS,          KC_RSFT, TD(TD_DEL_PRT),  \
      KC_LCTL, KC_LGUI, KC_LALT,         ______,             KC_SPC,          ______,        KC_ALGR, MONKEY, ______, KC_RCTL    ),

  [_FUN] = LAYOUT_all(
      ______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,  KC_F12, KC_DEL, ______,   \
      RESET , KC_PGUP, KC_UP,   KC_PGDN,  ______,  ______, ______, ______, ______, ______, ______, ______,  ______,         ______,   \
      ______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_HOME, ______, ______, KC_END, ______, ______, ______, ______,  ______,         ______,   \
      ______, ______, ______,   ______,   ______,  ______, ______, ______, ______, ______, ______, ______,           KC_UP, MATE,     \
      ______, ______, ______,             ______,          KC_LGUI,         ______,        KC_LEFT, KC_DOWN, ______, KC_RIGHT  ),

};
