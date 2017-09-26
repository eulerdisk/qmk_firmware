/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OTHER,
};

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)

#define LCTRLE  MT(MOD_LCTL, KC_ESC)
#define RCTRLQ  MT(MOD_LCTL, KC_QUOT)
#define LSHIFT  KC_LSFT
#define RSHIFT  KC_RSFT
#define LA_LEFT MT(MOD_LALT, KC_LEFT)

/* #define LSHIFT MT(MOD_LSFT, KC_BSLS) */
/* #define RSHIFT MT(MOD_RSFT, KC_SLSH) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bsls |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | C/Esc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |C/Quot|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |L/Spc | Del  | Bksp |R/Ent | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
  {LCTRLE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTRLQ },
  {LSHIFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSHIFT },
  {_______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_DEL,  KC_BSPC, RAISE,   LA_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |   {  |  [   |  (   |   -  |   =  |   )  |   ]  |   }  |   >  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, _______},
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   _  |   +  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Home | PgDn | PgUp | End  | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS, KC_PIPE},
  {_______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Other
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Mute | Vol+ | Vol- |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_OTHER] = {
  {_______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(_LOWER, _RAISE, _OTHER);
    return true;
}
