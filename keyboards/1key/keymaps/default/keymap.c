#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
          RGB_MOD
          )
};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD + 1);
}
