
#include "keymap_german.h"
#include "../../l3.h"
#include "../../led_l3.h"

#include "../../tinycmd/tinycmdapi.h"

//Layer renaming
#define _DL  0  //default

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	[_DL] = KEYMAP_MX1800 (
		KC_ESC,  KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12,                         KC_INS,  KC_HOME,KC_PGUP,KC_PSCR,
		                                                                                                                            KC_DEL,  KC_END, KC_PGDN,KC_SLCK,
		KC_GRV,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO, KC_BSPC,      KC_NLCK, KC_PSLS,KC_PAST,KC_BRK,
		KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,              KC_P7,   KC_P8,  KC_P9,  KC_PMNS,
		KC_CAPS, KC_A,    KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,              KC_P4,   KC_P5,  KC_P6,  KC_PPLS,
		KC_LSFT, KC_NUBS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,                KC_P1,   KC_P2,  KC_P3,  KC_PENT,
		KC_LGUI, KC_LALT, KC_LALT,               KC_SPC,                   KC_RALT, KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT,               KC_P0,  KC_PDOT,KC_NO ),
};

// Custom triggering of the status LEDs via co-controller API
// Caps and scroll lock LEDs are used as layer indicators
void led_set_user(uint8_t usb_led)
{
    tinycmd_three_lock(usb_led & (1<<USB_LED_NUM_LOCK),
    		usb_led & (1<<USB_LED_CAPS_LOCK),
			usb_led & (1<<USB_LED_SCROLL_LOCK),
			false);
    _delay_ms(10);
}
