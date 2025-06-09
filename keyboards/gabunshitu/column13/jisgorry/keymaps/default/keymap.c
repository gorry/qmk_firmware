/* Copyright 2021 ABplus Inc. kazhida
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
#include "keymap_japanese.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _FUNCS
};

#define KL_KANA LT(_LOWER, JP_ZKHK)
#define KL_EISU LT(_RAISE, KC_APP)
#define KL_ESC  LT(_FUNCS, KC_ESC)
#define KS_SPC  LSFT_T(KC_SPC)
#define KA_SPC  LALT_T(KC_SPC)
//#define cmd(KC) LGUI(KC)
#define cmd(KC) LCTL(KC)
#define sft(KC) RSFT(KC)
#define s(KC) RSFT(KC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    KL_ESC,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      JP_MINS,   KC_BSPC,
    KC_TAB,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      JP_AT,     KC_ENT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_UP,     JP_SLSH,
    KC_LCTL,   KC_LALT,   KL_EISU,   KL_KANA,   KC_SPC,               JP_SCLN,   JP_COLN,   JP_BSLS,   KC_LEFT,   KC_DOWN,   KC_RIGHT
),
[_LOWER] = LAYOUT(
    QK_LLCK,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      JP_CIRC,   KC_DEL,
    _______,   sft(KC_1), sft(KC_2), sft(KC_3), sft(KC_4), sft(KC_5), sft(KC_6), sft(KC_7), sft(KC_8), sft(KC_9), JP_LBRC,   KC_INS,
    KC_RSFT,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_PGUP,   JP_RBRC,
    KC_RCTL,   KC_RALT,   _______,   _______,   _______,              s(JP_LBRC),s(JP_RBRC),JP_YEN,    KC_HOME,   KC_PGDN,   KC_END
),
[_RAISE] = LAYOUT(
    QK_LLCK,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_RSFT,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_RCTL,   KC_RALT,   _______,   _______,   _______,              _______,   _______,   _______,   KC_PSCR,   KC_SCRL,   KC_PAUS
),
[_FUNCS] =  LAYOUT(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   KC_LWIN,   _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______
)
};

#undef s


//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case QMKBEST:
//            if (record->event.pressed) {
//                // when keycode QMKBEST is pressed
//                SEND_STRING("QMK is the best thing ever!");
//            } else {
//                // when keycode QMKBEST is released
//            }
//            break;
//        case QMKURL:
//            if (record->event.pressed) {
//                // when keycode QMKURL is pressed
//                SEND_STRING("https://qmk.fm/\n");
//            } else {
//                // when keycode QMKURL is released
//            }
//            break;
//    }
//    return true;
//}
