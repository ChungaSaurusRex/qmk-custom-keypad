// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later 
// Quick MSYS commands:
// 	qmk compile -kb zandatsu -km default
// 	cd qmk_firmware
// 	qmk flash zandatsu_default.hex
// 	qmk flash zandatsu_default.uf2 -e CONVERT_TO=rp2040_ce (with RP2040)
/*
   ...(0)(1)(2)(3)(4)
(0)       X  X  X
(1)       X  X  X  X
(2)    X  X  X  X  X
(3)    X  X  X  X  X
     */

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif 
    return true;
}

enum layers{
	zandatsu,
	rgb_config,
	xbox_emu
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [xbox_emu] = LAYOUT(
				 JS_0, JS_1, KC_ENT,
				 KC_Q, KC_E, KC_R, KC_N,
		KC_LSFT, KC_X, KC_F, KC_G, KC_M,
		KC_LCTL, KC_Z, KC_C, KC_V, TO(zandatsu)
	),		
	[rgb_config] = LAYOUT(
				 UG_TOGG, UG_NEXT, UG_HUEU,
				 UG_VALU, KC_F, KC_J, UG_SATU,
		KC_LSFT, KC_G, KC_K, KC_O, UG_SPDU,
		KC_LCTL, KC_X, KC_C, KC_V, TO(xbox_emu)
	),
    [zandatsu] = LAYOUT(
				 KC_LALT, KC_TAB, KC_ENT,
				 KC_Q, KC_E, KC_R, KC_N,
		KC_LSFT, KC_X, KC_F, KC_G, KC_M,
		KC_LCTL, KC_Z, KC_C, KC_V, TG(rgb_config)
	)	
};
