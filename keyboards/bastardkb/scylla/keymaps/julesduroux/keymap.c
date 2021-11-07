/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "sendstring_french.h"

#define FR_ALT MO(2)	// alt but pimped layer
#define FR_FN MO(3)	// function layer
#define FR_SHIFT MO(4) // shift but pimped layer
#define FR_SALT MO(5)	// shift + alt layer
#define FR_VERNUM TG(1)	// numpad

void keyboard_post_init_user() {
  layer_on(1);
}

enum custom_keycodes {
	FR_OE = SAFE_RANGE, //œ
	FR_AE, //æ
	FR_RACINE, //√
	FR_REG, //®
	FR_TM, //™
	FR_INF, //∞
	FR_SEQ, //≥
	FR_IEQ, //≤
	FR_DQO, //«
	FR_DQF,//»
	FR_ARROW, //→
	FR_MAJ_EAIGU, //É
	FR_MAK_EGRAVE, //È
	FR_MAJ_CCEDI, //Ç
	FR_MAJ_AGRAV, //À
	FR_MAJ_OE, //Œ
	FR_MAJ_AE, //Æ
	FR_MAJ_UGRAV, //Ù
	FR_POURM,//‰
};


char *alt_codes[] = {
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_6)), // Alt+0156 → œ
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_5)), // Alt+145 → æ
	SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_1)), // Alt+251 → √
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_4)), // Alt+0174 → ®
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)), // Alt+0153 → ™
	SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_6)), // Alt+236 → ∞
    SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+242 → ≥
	SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_3)), // Alt+243 → ≤
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_4)), // Alt+174 → «
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)), // Alt+175 → »
	SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6)), // Alt+26 → →
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → É
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_0)), // Alt+0200 → È
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+128 → Ç
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_2)), // Alt+0192 → À
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_0)), // Alt+0140 → Œ
	SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+146 → Æ
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_7)), // Alt+0217 → Ù
	SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_7)), // Alt+0137 → ‰
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) return true;

    switch (keycode) {
    case FR_OE: case FR_AE: case FR_RACINE: case FR_REG: case FR_TM: case FR_INF: case FR_SEQ: case FR_DQO: case FR_ARROW: case FR_MAJ_EAIGU: case FR_MAK_EGRAVE: case FR_MAJ_CCEDI: case FR_MAJ_AGRAV: case FR_MAJ_OE: case FR_MAJ_AE: case FR_MAJ_UGRAV: case FR_POURM: case FR_IEQ: case FR_DQF : {
        uint16_t index = keycode - FR_OE;
		
        send_string(alt_codes[index]);

        return false;
    }
    default:
        return true;
    }
}
			
	
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Layer 0 = numpad
   [0] = LAYOUT_split_4x6_5(
    FR_SLSH, FR_ASTR,   FR_7,   FR_8, FR_9,   FR_MINS,			    FR_SHIFT,   FR_SHIFT,   FR_SHIFT,   FR_SHIFT,   FR_SHIFT,   FR_SHIFT,
//---------------------------------------------------------//--------------------------------------------------------------//
    FR_LPRN, FR_RPRN, FR_4, FR_5, FR_6, FR_PLUS,			  FR_SHIFT, FR_SHIFT, FR_SHIFT, FR_SHIFT,  FR_SHIFT,  FR_SHIFT,
//---------------------------------------------------------//--------------------------------------------------------------//
    FR_SHIFT, FR_SHIFT, FR_1, FR_2, FR_3, FR_EQL,	      FR_SHIFT, FR_SHIFT, FR_SHIFT, FR_SHIFT, FR_SHIFT,  FR_SHIFT,
//---------------------------------------------------------//--------------------------------------------------------------//
    FR_VERNUM, KC_SPC, FR_COMM,  FR_0, FR_DOT, KC_ENT,        FR_SHIFT, FR_SHIFT, FR_SHIFT, FR_SHIFT, FR_SHIFT,  FR_SHIFT,
//---------------------------------------------------------//--------------------------------------------------------------//
                               KC_DEL, KC_TAB, FR_FN,		    KC_ENT,  KC_SPC, FR_ALT,
                       LM(1, MOD_LCTL),  LM(1, MOD_LGUI),       KC_DEL, KC_BSPC
  ),
//Layer 1 = default
  [1] = LAYOUT_split_4x6_5(
	FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, 			FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL, 
//-----------------------------------------------------------//-----------------------------------------------------------//
	KC_ESC, FR_A, FR_Z, FR_E, FR_R, FR_T, 							FR_Y, FR_U, FR_I, FR_O, FR_P, FR_CIRC,
//-----------------------------------------------------------//-----------------------------------------------------------//
	KC_PSCR, FR_Q, FR_S, FR_D, FR_F, FR_G,		 					FR_H, FR_J, FR_K, FR_L, FR_M, FR_COLN,
//-----------------------------------------------------------//-----------------------------------------------------------//
    _______, FR_W, FR_X, FR_C, FR_V, FR_LABK,						FR_ASTR, FR_B, FR_N, FR_COMM, FR_SCLN, FR_EXLM,
//-----------------------------------------------------------//-----------------------------------------------------------//
							FR_SHIFT, KC_TAB, FR_FN,		     		KC_ENT,  KC_SPC, FR_ALT,
                                 KC_LCTL,  KC_LGUI,      				KC_DEL, KC_BSPC
  ),
  
//Layer 2 = alt/AltGr
  [2] = LAYOUT_split_4x6_5(
    A(KC_F4), FR_TILD, FR_HASH, FR_LCBR, FR_LBRC, FR_PIPE, 			FR_GRV, FR_BSLS, RALT(FR_CCED), FR_AT, FR_RBRC, FR_RCBR,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, FR_AE, _______, FR_EURO, FR_REG, FR_TM,			  _______, FR_UGRV, _______, FR_OE,  FR_PERC,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    A(KC_PSCR), _______, FR_DLR, _______, FR_ARROW, _______,	      _______, _______, _______, FR_PIPE, FR_INF,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______, FR_CCED, FR_RACINE, FR_IEQ,        _______, _______, _______, FR_COLN, FR_EXLM,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               FR_SALT, _______, _______,		    _______, _______, _______,
                                        _______,  _______,       _______, _______
  ),
//Layer 3 = FN
   [3] = LAYOUT_split_4x6_5(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,			  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, KC_VOLU, _______, KC_UP, _______, KC_BRIU,			  _______, KC_WH_U, KC_PGUP, KC_HOME, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, KC_VOLD, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BRID,			  _______, KC_WH_D, KC_PGDN, KC_END, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______,			  _______, _______, _______, _______, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               _______, _______, _______,		    _______, _______, _______,
                                        _______,  _______,       _______, _______
  ),
//Layer 4 = shift
  [4] = LAYOUT_split_4x6_5(
    FR_1, FR_2, FR_3, FR_4, FR_5, FR_6, 			FR_7, FR_8, FR_9, FR_0, FR_DEG, FR_PLUS, 
//---------------------------------------------------------//--------------------------------------------------------------//
    KC_ESC, S(FR_A), S(FR_Z), S(FR_E), S(FR_R), S(FR_T), 							S(FR_Y), S(FR_U), S(FR_I), S(FR_O), S(FR_P), FR_DIAE,
//-----------------------------------------------------------//-----------------------------------------------------------//
	KC_PSCR, S(FR_Q), S(FR_S), S(FR_D), S(FR_F), S(FR_G),		 					S(FR_H), S(FR_J), S(FR_K), S(FR_L), S(FR_M), FR_SLSH,
//-----------------------------------------------------------//-----------------------------------------------------------//
    _______, S(FR_W), S(FR_X), S(FR_C), S(FR_V), FR_RABK,						FR_ASTR, S(FR_B), S(FR_N), FR_QUES, FR_DOT, FR_ASTR,
//-----------------------------------------------------------//-----------------------------------------------------------//
							FR_SHIFT, KC_TAB, FR_FN,		     		KC_ENT,  KC_SPC, FR_SALT,
                                 KC_LCTL,  KC_LGUI,      				KC_DEL, KC_BSPC
  ),
  //Layer 5 = shift + alt
   [5] = LAYOUT_split_4x6_5(
    _______,  FR_MAJ_EAIGU,   FR_DQO,   FR_DQF,   _______,   _______,			    FR_MAK_EGRAVE,   _______,   FR_MAJ_CCEDI,   FR_MAJ_AGRAV,   _______,   FR_ASTR,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, FR_MAJ_AE, _______, FR_EURO, FR_REG, FR_TM,			  _______, FR_MAJ_UGRAV, _______, FR_MAJ_OE,  FR_POURM,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, FR_DLR,    _______, FR_ARROW, _______,	      _______, _______, _______, FR_PIPE, _______,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______,  FR_MAJ_CCEDI, FR_RACINE, FR_SEQ,        _______, _______, _______, FR_COLN, FR_EXLM,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               _______, _______, _______,		    _______, _______, _______,
                                        _______,  _______,       _______, _______
  ),
};