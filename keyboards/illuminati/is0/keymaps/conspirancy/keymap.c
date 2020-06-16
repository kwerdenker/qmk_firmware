/* Copyright 2019 Ryota Goto
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
#include <keymap_extras/sendstring_german.h>

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  CONSPIRANCY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    CONSPIRANCY
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CONSPIRANCY:
      if (record->event.pressed) {
        SEND_STRING("They might tell you it's for the memes. They might tell you \"it's just a novelty item\". They might tell you \"it's so you have a use for your unused ISO enters\".\n\nThey are lying!\n\nThe iSO pad was designed by a secret keyboard kabal to forward their ISO4LIFE agenda. Think about it! Now you have a single ISO enter on your desk. You look at it every day. You smile about that lonely ISO enter. Nobody loves it. Everybody uses their superior ANSI bretheren. Silly ISO. But... it's so lonley, right? You know that feeling. From school, from work, from somewhere in your life. When nobody was interested in you? When you were alone? And so, some day you might think \"Maybe... I should buy an ISO board so that the little guy isn't so lonely anymore?\" AND THAT'S HOW THEY GET YOU! WAKE UP SHEEPLE!\n");
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
