/* Copyright 2018 Sebastian Spindler (kwerdenker)
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

#include "singa.h"
#include "keymap_extras/keymap_german.h"
#include "rgblight.h"

#define LAYOUT_wkl_ISO( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, k13, k14, k15, \
  k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28,    k29,   k30, \
   k31,  k32, k33, k34, k35, k36, k37, k38, k39, k40, k41, k42, k43,         k45, \
    k46,   k47, k48, k49, k50, k51, k52, k53, k54, k55, k56, k57, k81,    k58,   k59, \
      k60, k82,    k61, k62, k63, k64, k65, k66, k67, k68, k69, k70,  k71,   k72, k73, \
   k74,        k75,                   k76,                   k77,  k78, k79, k80  \
){ \
  { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,   k09,   k10,   k11,   k12,   k13, k14   }, \
  { k16,   k17,   k18,   k19,   k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29, KC_NO }, \
  { k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38,   k39,   k40,   k41,   k42,   k43,   KC_NO, k45   }, \
  { k46,   k47,   k48,   k49,   k50,   k51,   k52,   k53,   k54,   k55,   k56,   k57,   k81, k58, k59   }, \
  { k60,   k82, k61,   k62,   k63,   k64,   k65,   k66,   k67,   k68,   k69,   k70,   k71,   k72, k73   }, \
  { k74,   KC_NO, k75,   KC_NO, KC_NO, k76,   KC_NO, KC_NO, k77,   KC_NO, KC_NO, KC_NO, k78,   k79, k80   }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k15, k30   } \
}

//Layer renaming
#define _DL  0                     //default
#define _FN  1                     //function layer
#define _LED 2                     //LED configurations

//Keymapping renaming
#define ______  KC_TRNS            //renaming KC_TRNS for readability in keymaps
#define RGB_MI  RGB_MODE_FORWARD   //increase RGB mode
#define RGB_MD  RGB_MODE_REVERSE   //decrease RGB mode
#define MONKEY  LCTL(LALT(KC_DEL)) //ctrl+alt+del == monkey grip
#define FUNC_SW LT(_FN, KC_GRV)  //function layer switch / dual key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //Defaul Layer
  [_DL] = LAYOUT_wkl_ISO(
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_PSCR,  \
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,        KC_BSPC,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UE,   DE_PLUS,                   KC_PGUP,  \
    FUNC_SW, KC_A,    KC_S,   KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_OE,   DE_AE,   DE_HASH,  KC_ENT,          KC_PGDN,  \
    KC_LSFT, DE_LESS, DE_Y,   KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,   KC_DOT,   DE_MINS, KC_RSFT,          KC_UP,   MONKEY,   \
    KC_LCTL,       KC_LALT,                                    KC_SPC,                               KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  //Function Layer
  [_FN] = LAYOUT_wkl_ISO(
    ______,  ______,  ______,  ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______, ______, ______,  \
    ______,  ______,  ______,  ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______,        ______,    ______,  \
    ______,  ______,  KC_UP,   ______,   KC_END, ______, ______, ______, ______, ______, ______, ______, ______,                  ______,  \
    ______,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_HOME, ______, ______, KC_END, ______, ______, ______, ______, ______,  ______,         ______,  \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,              ______, TG(_LED),   \
    ______,       ______,                                       KC_LGUI,                                ______,          ______, ______, ______ \
  ),

  //LED Control Layer
  [_LED] = LAYOUT_wkl_ISO(
    RESET,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_G, ______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  ______, ______, RGB_TOG,  \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,        ______,   ______,  \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,                  RGB_MI,  \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______,         RGB_MD,  \
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,                  ______, TG(_LED),   \
    ______,       ______,                                    ______,                                ______,          ______, ______, ______ \
  ),

};

uint32_t layer_state_set_user(uint32_t state) {
  rgblight_config_t eeprom;
  switch (biton32(state)) {
    case _FN:
      rgblight_setrgb(0xFF, 0x33, 0x00);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    default:
      eeprom.raw = eeconfig_read_rgblight();
      rgblight_mode_noeeprom(eeprom.mode);
      break;
  }

  return state;
}
