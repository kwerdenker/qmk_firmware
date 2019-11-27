/*
Copyright 2019 Maarten Dekkers <maartenwut@gmail.com>

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

#pragma once

#include QMK_KEYBOARD_CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4705
#define PRODUCT_ID      0x0143
#define DEVICE_VER      0x0001
#define MANUFACTURER    Maartenwut
#define PRODUCT         J-01
#define DESCRIPTION     A custom 75% keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 17

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_COL_PINS {D1,D2,D3,D5,D4,D6,D7,B4,B5,B6,C6,C7,F7,F6,F5,F4,F1}
#define MATRIX_ROW_PINS {B2,B1,B3,B0,D0}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

#define BACKLIGHT_PIN B7
#define BACKLIGHT_LEVELS 4

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define QMK_ESC_OUTPUT D1 // usually COL
#define QMK_ESC_INPUT B2 // usually ROW