/* Copyright 2019 westfoxtrot
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

#define LAYOUT_iso( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K50, K51, K52, K53, K54, 		  K55, K56, K57, K58,\
      K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K60, K61, K62,		     	  K65, K66, K67, K68,   \
		K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K70, K71, K72, K73,         K75, K76, K77, K78,   \
	K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K80, K81, K82, 		K83,      K85, K86, K87, K88,   \
	K40, K41, K42,                   K46,            K49, K90, K91,    K92, K93, K95, K96, K97, K98   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39 }, \
    { K40, K41, K42, ___, ___, ___, K46, ___, ___, K49 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58 }, \
    { K60, K61, K62, ___, ___, K65, K66, K67, K68 }, \
    { K70, K71, K72, K73, ___, K75, K76, K77, K78 }, \
    { K80, K81, K82, K83, ___, K85, K86, K87, K88 }, \
    { K90, K91, K92, K93, ___, K95, K96, K97, K98 } \
}

#define _DL 0
#define _FN 1

#define SPECIAL LT(_FN, DE_CIRC)    //capslock layer switch + stargate key on tap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DL] = LAYOUT_iso (
      KC_ESC,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   DE_SS,   DE_ACUT, KC_BSPC, _______,     KC_DEL, KC_PSCR,KC_PSLS,KC_PAST,
      KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,  DE_Z,  KC_U,  KC_I,  KC_O,    KC_P,   DE_UE,   DE_PLUS,                       KC_P7,   KC_P8,  KC_P9,  KC_PMNS,
      SPECIAL, KC_A,    KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    DE_OE,  DE_AE,   DE_HASH, KC_ENT,               KC_P4,   KC_P5,  KC_P6,  KC_PPLS,
      KC_LSFT, DE_LESS, DE_Y,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, DE_MINS, KC_RSFT,        KC_UP,         KC_P1,   KC_P2,  KC_P3,  KC_PENT,
      KC_LCTL, KC_LGUI, KC_LALT,             KC_SPC,                     _______, KC_RALT, KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT,        KC_P0,  KC_PDOT, KC_NO
  ),

  [_FN] = LAYOUT_iso (
      DE_RING, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______,       KC_NLCK, _______, _______, RESET,
      _______, _______, KC_UP,   _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,                        RGB_TOG, RGB_MOD, RGB_RMOD,_______,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               RGB_HUI, RGB_SAI, RGB_VAI, _______,
      _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,               RGB_HUD, RGB_SAD, RGB_VAD, _______,
      _______, _______, _______,             KC_LGUI,                _______, _______, _______,                         _______, _______, _______,               _______, _______, _______
  )
};

bool led_update_user(led_t led_state) {
    return false;
}
