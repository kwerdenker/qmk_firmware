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
#include <avr/io.h>
#include "stdbool.h"

#include "led_l3.h"
#include "config.h"
#include "tinycmd/tinycmdapi.h"
#include "quantum.h"
#include "backlight.h"

uint8_t led_mode = LED_EFFECT_ALWAYS;
uint8_t rgb_effect_index = 5;
uint8_t rgb_speed_index = 4;

uint8_t led_preset[3][5] = {{0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF},
                            {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF},
                            {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF}};

uint16_t rgb_speed[5] = { 100, 200, 300, 400, 500};

void rgbOff(void)
{
  tinycmd_rgb_all(0, 0, 0, 0, true);
}

void rgbOn(void)
{
  tinycmd_rgb_all(1, 0, 0, 255, true);
}

void backlightLedOff(void)
{
  uint8_t led_preset[3][5] = {{0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF},
                              {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF},
                              {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF}};
  tinycmd_led_config_preset((uint8_t*)led_preset, true);
}

void backlightLedOn(void)
{
  uint8_t led_preset[3][5] = {{0, 0, 0, LED_EFFECT_ALWAYS, LED_EFFECT_ALWAYS},
                              {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF},
                              {0, 0, 0, LED_EFFECT_OFF, LED_EFFECT_OFF}};
  tinycmd_led_config_preset((uint8_t*)led_preset, true);
}

void ledChangeMode(void)
{
  if(led_mode == LED_EFFECT_ALWAYS) {
    led_mode = LED_EFFECT_FADING;
  } else if(led_mode == LED_EFFECT_FADING) {
    led_mode = LED_EFFECT_BASECAPS;
  } else if(led_mode == LED_EFFECT_BASECAPS) {
    led_mode = LED_EFFECT_ALWAYS;
  }
  backlightLedOn();
}

void rgbSetSpeed(void)
{
  if(++rgb_speed_index > 4)
  {
      rgb_speed_index = 0;
  }
  tinycmd_rgb_effect_speed(rgb_speed[rgb_speed_index], true);
}

void ledRgbPreset(void)
{
  uint8_t rgb_effect_param[6][4] = {{ RGB_EFFECT_BOOTHID, 0, 0, 0 },
                                    { RGB_EFFECT_FADE_BUF, FADE_HIGH_HOLD, FADE_LOW_HOLD, FADE_IN_ACCEL },
                                    { RGB_EFFECT_FADE_LOOP, FADE_HIGH_HOLD, FADE_LOW_HOLD, FADE_IN_ACCEL },
                                    { RGB_EFFECT_HEARTBEAT_BUF, HEARTBEAT_HIGH_HOLD, HEARTBEAT_LOW_HOLD, HEARTBEAT_IN_ACCEL },
                                    { RGB_EFFECT_HEARTBEAT_LOOP, HEARTBEAT_HIGH_HOLD, HEARTBEAT_LOW_HOLD, HEARTBEAT_IN_ACCEL },
                                    { RGB_EFFECT_BASIC, HEARTBEAT_HIGH_HOLD, HEARTBEAT_LOW_HOLD, HEARTBEAT_IN_ACCEL }};
  tinycmd_rgb_set_preset(rgb_effect_index, (rgb_effect_param_type *)&rgb_effect_param[rgb_effect_index], true);
}

void rgbChangeMode(void)
{
  rgb_effect_index++;
  if(rgb_effect_index == 6) {
    rgb_effect_index = 0;
  }
  rgbSetPreset();
}
