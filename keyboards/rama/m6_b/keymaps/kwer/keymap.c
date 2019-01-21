#include QMK_KEYBOARD_H
#include "../../../../zeal60/rgb_backlight.h"
#include "../../../../zeal60/rgb_backlight_keycodes.h"

extern backlight_config g_config;

#define D_MUTE LCA(S(KC_M))
#define D_DEAF LCA(S(KC_D))

//Layer renaming
#define _DFL  0                    //default
#define _SND  1                    //sound
#define _POD  2                    //podcast layer
#define _LED  3                    //LED configurations

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DFL] = LAYOUT(
		TO(_SND), TO(_POD), TO(_LED),
		LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB), LCTL(LGUI(KC_RIGHT))

	),
	[_SND] = LAYOUT(
		TO(_DFL), KC_MSEL, KC_MUTE,
		KC_MPRV, KC_MPLY, KC_MNXT
	),
	[_POD] = LAYOUT(
		D_DEAF, TO(_DFL), D_MUTE,
		KC_NO, KC_R, KC_P
	),
	[_LED] = LAYOUT(
		EF_DEC, EF_INC, TO(_DFL),
		M(0), H1_INC, H1_DEC
	)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
		case 0:
			if (record->event.pressed) {
        g_config.color_1.h = 24;
        g_config.color_1.s = 255;
        g_config.effect = 1;
        g_config.brightness = 255;
        g_config.layer_1_indicator.color.h = 188;
        g_config.layer_1_indicator.color.s = 255;
        g_config.layer_1_indicator.index = 0;
        g_config.layer_2_indicator.color.h = 188;
        g_config.layer_2_indicator.color.s = 255;
        g_config.layer_2_indicator.index = 3;
        g_config.layer_3_indicator.color.h = 188;
        g_config.layer_3_indicator.color.s = 255;
        g_config.layer_3_indicator.index = 5;
        backlight_config_save();
			}
			break;
	}
	return MACRO_NONE;
}

