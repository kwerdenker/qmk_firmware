/*
Copyright 2016 Ralf Schmitt <ralf@bunkertor.net>
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

#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include "quantum.h"

#define KEYMAP_MX1800( \
    K5A,      K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M,      K4P, K3O, K3P, K5N,\
                                                                               K1P, K2O, K2P, K5O,\
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N, K4O, K4Q, K4R, K4S, K5P,\
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3Q, K3R, K3S, K4T,\
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      K2Q, K2R, K2S, K2T,\
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M,      K1O, K1Q, K1R, K1S, K0T,\
    K0A, K0B, K0C,                K0G,                     K0J, K0M, K0N, K0O, K0P, K0R, K0S, K1T \
) { \
  { K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
  { K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N, K4O, K4P, K4Q, K4R, K4S, K4T }, \
  { K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, K3O, K3P, K3Q, K3R, K3S, KC_NO    }, \
  { K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N, K2O, K2P, K2Q, K2R, K2S, K2T }, \
  { K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, KC_NO,    K1O, K1P, K1Q, K1R, K1S, K1T }, \
  { K0A, K0B, K0C, KC_NO,    KC_NO,    KC_NO,    K0G, KC_NO,    KC_NO,    K0J, KC_NO,    KC_NO,    K0M, K0N, K0O, K0P, KC_NO,    K0R, K0S, K0T }  \
}

#define KEYMAP_COMPACT( \
    K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5Q, K3O, K3P, K2O, K2P,\
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N, K4O, K4Q, K4R, K4S, K5P,\
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3Q, K3R, K3S, K4T,\
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      K2Q, K2R, K2S, K2T,\
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M,      K1O, K1Q, K1R, K1S, K0T,\
    K0A, K0B, K0C, K0E, K0D,      K0G,      K0I,      K0J, K0K, K0M, K0N, K0O, K0P, K0R, K0S, K1T \
) { \
  { K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M, K5N, KC_NO,    K5P, K5Q, KC_NO,    KC_NO,    KC_NO    }, \
  { K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N, K4O, KC_NO,    K4Q, K4R, K4S, K4T }, \
  { K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, K3O, K3P, K3Q, K3R, K3S, KC_NO    }, \
  { K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N, K2O, K2P, K2Q, K2R, K2S, K2T }, \
  { K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, KC_NO,    K1O, KC_NO,    K1Q, K1R, K1S, K1T }, \
  { K0A, K0B, K0C, K0D, K0E, KC_NO,    K0G, KC_NO,    K0I, K0J, K0K, KC_NO,    K0M, K0N, K0O, K0P, KC_NO,    K0R, K0S, K0T }  \
}


#endif // KEYMAP_COMMON_H
