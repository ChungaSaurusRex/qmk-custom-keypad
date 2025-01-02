// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later 
// qmk compile -kb zandatsu -km default
// cd qmk_firmware
// qmk flash zandatsu_default.hex
/*
     *
	 -------------Physical Layout Approximation--------------------
	     16 buttons, 26 keys in alphabet, /2 = 13 keys in 2 layers -- Labelled with column numbers.
	 
	          (0) (1) (2) 
			  
	          (0) (1) (2) (3)
	    (0)   (1) (2) (3) (3)
	    (0)   (1) (2) (3) 
	 
	 
				          (3)
					
		TRIAL Simple Alphanumeric Typing Keymaps -- 1st half

	[0] = LAYOUT(
		KC_TAB,		KC_LSFT,	KC_ENT,		KC_G
        KC_Q,   	KC_W,   	KC_E,   	KC_R,
        KC_A,   	KC_S,   	KC_D,   	KC_F,
        KC_Z,   	KC_X,   	KC_C,   	KC_V,
											TG(1)
		)

							  
		TRIAL Simple Alphanumeric Typing Keymaps -- 2nd half

	[1] = LAYOUT(
		KC_TAB,		KC_LSFT,	KC_ENT,		KC_P,
        KC_T,   	KC_Y,   	KC_U,   	KC_I,
        KC_H,   	KC_J,   	KC_K,   	KC_L,
        KC_N,   	KC_M,   	KC_O,   	KC_B,
											TG(0)
		)
					
		
     */

#include QMK_KEYBOARD_H



void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

#define DEBUG_MATRIX_SCAN_RATE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif 
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
				KC_A,   KC_E,   KC_I,
				KC_B,   KC_F,   KC_J,   KC_N,
		KC_C,   KC_G,   KC_K,   KC_O,	KC_Q,
		KC_D,   KC_H,   KC_L,   KC_P,	KC_M
	)                           
};
