/*
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
#include "l3.h"
#include "config.h"
#include "led.h"
#include "tinycmd/tinycmdapi.h"
#include "led_l3.h"
#include "rgblight.h"
#include <util/delay.h>

extern rgblight_config_t rgblight_config;

void rgblight_set(void)
{
    if (0)
    {
        tinycmd_rgb_all(1, led[0].r, led[0].g, led[0].b, true);
        _delay_ms(10);
    } else {
      for (uint8_t i = 0; i < RGBLED_NUM; i++)
      {
        led[i].r = 0;
        led[i].g = 0;
        led[i].b = 0;
      }
      tinycmd_rgb_all(0, 0, 0, 0, true);
    }
}

void backlight_set(uint8_t level)
{
	if (level == 0) {
		// Turn out the lights
		backlightLedOff();
	} else {
		// Turn on the lights
		backlightLedOn();
	}
}
