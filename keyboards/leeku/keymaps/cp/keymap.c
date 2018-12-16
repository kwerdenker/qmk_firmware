#include "../../l3.h"
#include "../../led_l3.h"
#include "keymap_extras/keymap_german.h"
#include "../../tinycmd/tinycmdapi.h"

#define KEYMAP_COMPACT_ISO_7U( \
    K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M, K5Q,      K3O, K3P, K2O, K2P,\
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M,   K4O,    K4Q, K4R, K4S, K5P,\
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M,           K3Q, K3R, K3S, K4T,\
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      K2Q, K2R, K2S, K2T,\
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M,      K1O, K1Q, K1R, K1S, K0T,\
    K0A, K0C,                     K0G,                K0J,      K0M, K0N, K0O, K0P, K0R, K0S, K1T \
) { \
  { K5A, K5B, K5C,   K5D,   K5E,   K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M,   KC_NO, KC_NO, K5P,           K5Q,   KC_NO, KC_NO, KC_NO }, \
  { K4A, K4B, K4C,   K4D,   K4E,   K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M,   KC_NO, K4O,   KC_NO,         K4Q,   K4R,   K4S,   K4T     }, \
  { K3A, K3B, K3C,   K3D,   K3E,   K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M,   KC_NO, K3O,   K3P,           K3Q,   K3R,   K3S,   KC_NO   }, \
  { K2A, K2B, K2C,   K2D,   K2E,   K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M,   K2N,   K2O,   K2P,           K2Q,   K2R,   K2S,   K2T     }, \
  { K1A, K1B, K1C,   K1D,   K1E,   K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M,   KC_NO, K1O,   KC_NO,         K1Q,   K1R,   K1S,   K1T     }, \
  { K0A, KC_NO, K0C, KC_NO, KC_NO, KC_NO,    K0G, KC_NO,  KC_NO, K0J, KC_NO, KC_NO, K0M,   K0N, K0O, K0P, KC_NO, K0R,   K0S,   K0T  }  \
}

#define TAPPING_TERM 120 //time in microseconds a key is counted as tapped

//Layer renaming
#define _DL 0  //default
#define _FN 1  //Capslock function layer

//Keymapping renaming
#define ___     KC_TRNS            	//renaming KC_TRNS for readability in keymaps
#define MONKEY  LCTL(LALT(KC_DEL)) 	//ctrl+alt+del == monkey grip
#define SPECIAL LT(_FN, DE_CIRC)

//Macro renaming
#define KVM_SW  M(0)  //switch desktop macro for KVM
#define PROG_LP M(1)  //German space cadet version = ( when tapped, shift when hold
#define PROG_RP M(2)  //German space cadet version = ) when tapped, shift when hold
#define PROG_LC M(3)  //German space cadet version = { when tapped, shift when hold (layer 2)
#define PROG_RC M(4)  //German space cadet version = } when tapped, shift when hold (layer 2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	[_DL] = KEYMAP_COMPACT_ISO_7U (
		KC_ESC,  KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_DEL,               KC_HOME, KC_PGUP,KC_END, KC_PSCR,
		KC_GRV,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   DE_SS,   DE_ACUT, KC_BSPC,              KC_NLCK, KC_PGDN,KC_PSLS,KC_PAST,
		KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,  DE_Z,  KC_U,  KC_I,  KC_O,    KC_P,   DE_UE,   DE_PLUS,                       KC_P7,   KC_P8,  KC_P9,  KC_PMNS,
		SPECIAL, KC_A,    KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    DE_OE,  DE_AE,   DE_HASH, KC_ENT,               KC_P4,   KC_P5,  KC_P6,  KC_PPLS,
		PROG_LP, DE_LESS, DE_Y,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, DE_MINS, PROG_RP, KC_UP,                KC_P1,   KC_P2,  KC_P3,  KC_PENT,
		KC_LCTL, KC_LALT,                         KC_SPC,                  KC_RALT, MO(_FN),        KC_LEFT, KC_DOWN, KC_RGHT,               KC_P0,  KC_PDOT,KC_NO ),

	[_FN] = KEYMAP_COMPACT_ISO_7U (
    ___,  ___,   ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,  ___,  ___,               ___, ___,___,___,
		___,  ___,    ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,    ___,   ___,   ___,  ___,             ___,  ___,___,___,
		___,  ___,    ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,    ___,   ___,   ___,                    ___,   ___,  ___,  ___,
		___, ___,    ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,    ___,  ___,   ___, RESET,                ___,   ___,  ___,  ___,
		PROG_LC, ___, ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___, ___, ___, PROG_RC, ___,                ___,   ___,  ___,  ___,
		___, ___,                         KC_LGUI,                  ___, ___,        ___, ___, ___,               ___,  ___,___ ),
};

static uint16_t timer; //timer for counting key press times in macros

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch(id)
	{
		case 0:
			return (record->event.pressed ?
					MACRO( T(SLCK), W(100), T(SLCK), W(150), T(ENT), END )
					:MACRO( END ));
			break;
		case 1:
			if (record->event.pressed)
			{
				timer = timer_read();
				register_code (KC_LSFT);
			}
			else
			{
				if (timer_elapsed (timer) < TAPPING_TERM)
				{
					register_code (KC_8);
					unregister_code (KC_8);
				}
				unregister_code (KC_LSFT);
			}
			break;
		case 2:
			if (record->event.pressed)
			{
				timer = timer_read();
				register_code (KC_RSFT);
			}
			else
			{
				if (timer_elapsed (timer) < TAPPING_TERM)
				{
					register_code (KC_9);
					unregister_code (KC_9);
				}
				unregister_code (KC_RSFT);
			}
			break;
		case 3:
			if (record->event.pressed)
			{
				timer = timer_read();
				register_code (KC_LSFT);
			}
			else
			{
				if (timer_elapsed (timer) < TAPPING_TERM)
				{
					unregister_code (KC_LSFT);
					register_code (DE_ALGR);
					register_code (KC_7);
					unregister_code (KC_7);
					unregister_code (DE_ALGR);
				}
				unregister_code (KC_LSFT);
			}
			break;
		case 4:
			if (record->event.pressed)
			{
				timer = timer_read();
				register_code (KC_RSFT);
			}
			else
			{
				if (timer_elapsed (timer) < TAPPING_TERM)
				{
					unregister_code (KC_RSFT);
					register_code (DE_ALGR);
					register_code (KC_0);
					unregister_code (KC_0);
					unregister_code (DE_ALGR);
				}
				unregister_code (KC_RSFT);
			}
			break;
	}
	return MACRO_NONE;
};

// Custom triggering of the status LEDs via co-controller API
// Caps and scroll lock LEDs are used as layer indicators
void led_set_user(uint8_t usb_led)
{
    tinycmd_three_lock(usb_led & (1<<USB_LED_NUM_LOCK),
                       usb_led & (1<<USB_LED_CAPS_LOCK),
		                   (layer_state_is(_FN) ? 1 : 0),
                       false);
    _delay_ms(10);
}
