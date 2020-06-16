/* Copyright 2019 Stanrc85
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
#include "sendstring_german.h"
//#include "rgblight.h"

#define _MEDIA  0
#define _NUMPAD 1
#define _RGB    2

enum custom_keycodes {
  HYPER = SAFE_RANGE,
  VSCODE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case HYPER:
		if (record->event.pressed) {
			SEND_STRING(SS_TAP(X_LGUI) "Hyper" SS_TAP(X_ENTER));
		}
		break;
	case VSCODE:
		if (record->event.pressed) {
			SEND_STRING(SS_TAP(X_LGUI) "Visual Studio Code" SS_TAP(X_ENTER));
		}
		break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MEDIA] = LAYOUT(
	TO(_NUMPAD), KC_MSEL, TO(_RGB),
	KC_MPRV,     KC_MPLY, KC_MNXT,
	HYPER,       KC_UP,   VSCODE,
	KC_LEFT,     KC_DOWN, KC_RIGHT),

  [_NUMPAD] = LAYOUT(
	KC_7,       KC_8, KC_9,
	KC_4,       KC_5, KC_6,
	KC_1,       KC_2, KC_3,
	TO(_MEDIA), KC_0, KC_ENT),

  [_RGB] = LAYOUT(
	RGB_SAI,   RGB_VAI, RGB_HUI,
	RGB_SAD,   RGB_VAD, RGB_HUD,
	RGB_TOG,   RGB_MOD, RGB_RMOD,
	TO(_MEDIA),  KC_NO, RGB_M_P),

};

uint32_t layer_state_set_user(uint32_t state) {
  rgblight_config_t eeprom;
  switch (biton32(state)) {
    case _NUMPAD:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
      break;
    default:
      eeprom.raw = eeconfig_read_rgblight();
      rgblight_mode_noeeprom(eeprom.mode);
      break;
  }

  return state;
}

//void keyboard_post_init_user(void) {
//  // Call the post init code.
//  rgblight_enable_noeeprom();
//  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD + 1);
//}
