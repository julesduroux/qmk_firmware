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

#define FR_ALT MO(1)	// alt but pimped layer
#define FR_SALT MO(2)	// shift + alt layer
#define FR_FN MO(3)	// function layer

enum custom_keycodes {
    FR_EAIGU = SAFE_RANGE, //Éé
    FR_EGRAVE, //Èè
    FR_CCEDI, //Çç
	FR_AGRAV, //Àà
	FR_OE, //Œœ
	FR_AE, //Ææ
	FR_UGRAV, //Ùù
	FR_RACINE, //√
	FR_REG, //®
	FR_TM, //™
	FR_INF, //∞
	FR_SEQ, //≤≥
	FR_DQ, //«»
	FR_ARROW, //→
	FR_POUR, //%‰
	FR_MAJ_EAIGU ,
	FR_MAK_EGRAVE,
	FR_MAJ_CCEDI,
	FR_MAJ_AGRAV,
	FR_MAJ_OE,
	FR_MAJ_AE,
	FR_MAJ_UGRAV,
	FR_POURM,
	FR_IEQ,
	FR_DQF,
};


char *alt_codes[][2] = {
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_0)), // Alt+130 → é
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → É
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_8)), // Alt+138 → è
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → È
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_5)), // Alt+135 → ç
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+128 → Ç
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_3)), // Alt+133 → à
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_3)), // Alt+183 → À
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_6)), // Alt+0156 → œ
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_0)), // Alt+0140 → Œ
    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_5)), // Alt+145 → æ
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+146 → Æ
    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_1)), // Alt+151 → ù
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_5)), // Alt+235 → Ù
    },
	{
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_1)), // Alt+251 → √
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_1)), // Alt+251 → √
    },
	{
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_4)), // Alt+0174 → ®
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_4)), // Alt+0174 → ®
    },
	{
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)), // Alt+0153 → ™
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)), // Alt+0153 → ™
    },
	{
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_6)), // Alt+236 → ∞
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_6)), // Alt+236 → ∞
    },
	{
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_3)), // Alt+243 → ≤
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+242 → ≥
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_4)), // Alt+174 → «
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)), // Alt+175 → »
    },
	{
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6)), // Alt+26 → →
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_6)), // Alt+26 → →
    },
	{
        SS_LALT(SS_TAP(X_KP_3)SS_TAP(X_KP_7)), // Alt+37 → %
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_7)), // Alt+0137 → ‰
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → É
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → É
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → È
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → È
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+128 → Ç
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+128 → Ç
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_3)), // Alt+183 → À
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_3)), // Alt+183 → À
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_0)), // Alt+0140 → Œ
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_0)), // Alt+0140 → Œ
    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+146 → Æ
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+146 → Æ
    },
    {
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_5)), // Alt+235 → Ù
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_5)), // Alt+235 → Ù
    },
	{
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_7)), // Alt+0137 → ‰
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_7)), // Alt+0137 → ‰
    },
	{
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+242 → ≥
        SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+242 → ≥
    },
	{
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)), // Alt+175 → »
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)), // Alt+175 → »
    },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) return true;

    switch (keycode) {
    case FR_EAIGU : case FR_EGRAVE: case FR_CCEDI: case FR_AGRAV: case FR_OE: case FR_AE: case FR_UGRAV: case FR_RACINE: case FR_REG: case FR_TM: case FR_INF: case FR_SEQ: case FR_DQ: case FR_ARROW: case FR_POUR: case FR_MAJ_EAIGU: case FR_MAK_EGRAVE: case FR_MAJ_CCEDI: case FR_MAJ_AGRAV: case FR_MAJ_OE: case FR_MAJ_AE: case FR_MAJ_UGRAV: case FR_POURM: case FR_IEQ: case FR_DQF : {
        uint16_t index = keycode - FR_EAIGU;
        uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

        // Temporarily disable Shift so it doesn't interfere with the numpad keys.
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);

        // Choose Alt code based on which key was pressed and whether Shift was held.
        send_string(alt_codes[index][(bool)shift]);

        // Restore Shift keys to their previous state.
        if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
        if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

        return false;
    }
    default:
        return true;
    }
}
			
	
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Layer 0 = default
  [0] = LAYOUT_split_4x6_5(
	FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, 			FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL, 
//-----------------------------------------------------------//-----------------------------------------------------------//
	KC_TAB, FR_A, FR_Z, FR_E, FR_R, FR_T, 							FR_Y, FR_U, FR_I, FR_O, FR_P, FR_CIRC,
//-----------------------------------------------------------//-----------------------------------------------------------//
	KC_LSFT, FR_Q, FR_S, FR_D, FR_F, FR_G,		 					FR_H, FR_J, FR_K, FR_L, FR_M, FR_UGRV,
//-----------------------------------------------------------//-----------------------------------------------------------//
    KC_LCTL, FR_LABK, FR_W, FR_X, FR_C, FR_V, 						FR_B, FR_N, FR_COMM, FR_SCLN, FR_COLN, FR_EXLM,
//-----------------------------------------------------------//-----------------------------------------------------------//
							KC_LSFT, KC_TAB, FR_FN,		     		KC_ENT,  KC_SPC, FR_ALT,
                                 KC_LCTL,  KC_LGUI,      			KC_DEL, KC_BSPC
  ),
//Layer 1 = alt/AltGr
  [1] = LAYOUT_split_4x6_5(
    A(KC_F4), RALT(FR_EACU), RALT(FR_DQUO), RALT(FR_QUOT), RALT(FR_LPRN), RALT(FR_MINS), 			RALT(FR_EGRV), RALT(FR_UNDS), RALT(FR_CCED), RALT(FR_AGRV), RALT(FR_RPRN), RALT(FR_EQL),
//---------------------------------------------------------//--------------------------------------------------------------//
    A(KC_TAB), FR_AE, _______, RALT(FR_E), FR_REG, FR_TM,			  _______, FR_UGRAV, _______, FR_OE,  FR_POUR,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, FR_DLR, _______, _______, _______,	      _______, _______, _______, RALT(FR_MINS), FR_INF,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, FR_SEQ, _______, _______, FR_CCEDI, _______,        _______, _______, _______, _______, _______,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               FR_SALT, A(KC_TAB), _______,		    _______, _______, _______,
                                        _______,  _______,       _______, _______
  ),  
//Layer 2 = shift + alt
   [2] = LAYOUT_split_4x6_5(
    _______,  FR_MAJ_EAIGU,   FR_DQ,   FR_DQF,   _______,   _______,			    FR_MAK_EGRAVE,   _______,   _______,   FR_MAJ_AGRAV,   _______,   FR_ASTR,
//---------------------------------------------------------//--------------------------------------------------------------//
    LSFT(A(KC_TAB)), FR_MAJ_AE, _______, _______, _______, _______,			  _______, FR_MAJ_UGRAV, _______, FR_MAJ_OE,  FR_POURM,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______,    _______, _______, _______,	      _______, _______, _______, _______, _______,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, FR_IEQ, _______,  _______, FR_MAJ_CCEDI, _______,        _______, _______, _______, _______, _______,  _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               _______, LSFT(A(KC_TAB)), _______,		    _______, _______, _______,
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
};