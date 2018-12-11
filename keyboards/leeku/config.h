/*
Copyright 2015 Ralf Schmitt <ralf@bunkertor.net>
Copyright 2018 Sebastian Spindler <thinkkwer@gmail.com>

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
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6050
#define DEVICE_VER      0x0100
#define MANUFACTURER    LeeKu
#define PRODUCT         L3
#define DESCRIPTION     QMK keyboard firmware for L3

/* matrix */
#define MATRIX_ROWS 6
#define MATRIX_COLS 20
//The folowing defines are unnecessary due to the custom matrix.c but I'll leave them in for documentation
/*#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS {C2, C3, C4, C5, C6, C7}
#define MATRIX_COL_PINS {A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2, B3, B4, B5, B6, B7, D4, D5, D6, D7}
#define UNUSED_PINS //{D0, D1, D2, D3, C0, C1}*/

/* backlight*/
#define BACKLIGHT_LEVELS 1
#define NO_BACKLIGHT_CLOCK

/* Set 0 if need no debouncing */
#define DEBOUNCING_DELAY 4

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define RGBLED_NUM 20
//#define RGBLIGHT_ANIMATIONS

/* Mouse movement tuning */
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    10

/* I2C parameters */
#define I2C_BITRATE_KHZ 400
#define I2C_TARGET_ADDR 0xB0

#endif
