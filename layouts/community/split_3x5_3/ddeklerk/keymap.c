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

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK,
    _COLEMAKDH,
    _DVORAK,
    _WORKMAN,
    _NAVR,
    _MOUR,
    _MEDR,
    _NSL,
    _NSSL,
    _FUNL,
    _ADJUST
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMK,
    COLEDH,
    DVORAK,
    WORKMN
};

#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________ KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________ KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________ KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ______________COLEMAK_MOD_DH_L1____________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________ KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________ KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________ KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________ KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________ KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________ KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________ KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________ KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________ KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________ KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define _________________WORKMAN_L1________________ KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________ KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________ KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________ KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________ KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________ KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH

#define LAYOUT_split_3x5_3_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) LAYOUT_split_3x5_3( \
    K01,         K02,         K03,         K04,         K05,         K06,         K07,         K08,         K09,         K0A,         \
    LGUI_T(K11), LALT_T(K12), LCTL_T(K13), LSFT_T(K14), K15,         K16,         RSFT_T(K17), RCTL_T(K18), RALT_T(K19), RGUI_T(K1A), \
    K21,         ALGR_T(K22), K23,         K24,         K25,         K26,         K27,         K28,         ALGR_T(K29), K2A,         \
    LT(_MEDR, KC_ESC), LT(_NAVR, KC_SPC), LT(_MOUR, KC_TAB), \
    LT(_NSSL, KC_ENT), LT(_NSL, KC_BSPC), LT(_FUNL, KC_DEL)  \
)

#define LAYOUT_split_3x5_3_right_wrapper( \
    K01, K02, K03, K04, K05, \
    K11, K12, K13, K14, K15, \
    K21, K22, K23, K24, K25, \
    K31, K32, K33            \
) LAYOUT_split_3x5_3( \
    RESET,   _______, _______, _______, _______, K01,     K02,     K03,     K04,     K05, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, K11,     K12,     K13,     K14,     K15, \
    _______, KC_ALGR, _______, _______, _______, K21,     K22,     K23,     K24,     K25, \
                      _______, _______, _______, K31,     K32,     K33            \
)

#define LAYOUT_split_3x5_3_left_wrapper( \
    K01, K02, K03, K04, K05, \
    K11, K12, K13, K14, K15, \
    K21, K22, K23, K24, K25, \
              K31, K32, K33  \
) LAYOUT_split_3x5_3( \
    K01,     K02,     K03,     K04,     K05, _______, _______, _______, _______, RESET,   \
    K11,     K12,     K13,     K14,     K15, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, \
    K21,     K22,     K23,     K24,     K25, _______, _______, _______, KC_ALGR, _______, \
                      K31,     K32,     K33, _______, _______, _______                    \
)

#define LAYOUT_split_3x5_3_base_wrapper(...) LAYOUT_split_3x5_3_base(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),
    [_COLEMAK] = LAYOUT_split_3x5_3_base_wrapper(
        _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
    ),
    [_COLEMAKDH] = LAYOUT_split_3x5_3_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),
    [_DVORAK] = LAYOUT_split_3x5_3_base_wrapper(
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),
    [_WORKMAN] = LAYOUT_split_3x5_3_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),
    [_NAVR] = LAYOUT_split_3x5_3_right_wrapper(
        KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        KC_ENT,  KC_BSPC, KC_DEL
    ),
    [_MOUR] = LAYOUT_split_3x5_3_right_wrapper(
        _______, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        KC_BTN1, KC_BTN3, KC_BTN2
    ),
    [_MEDR] = LAYOUT_split_3x5_3_right_wrapper(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        _______, _______, _______, _______, _______,
        KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [_NSL] = LAYOUT_split_3x5_3_left_wrapper(
        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
        KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,
                          KC_DOT,  KC_0,    KC_MINS
    ),
    [_NSSL] = LAYOUT_split_3x5_3_left_wrapper(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
        KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,
                          KC_LBRC, KC_RBRC, KC_UNDS
    ),
    [_FUNL] = LAYOUT_split_3x5_3_left_wrapper(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,
                          KC_APP,  KC_SPC,  KC_TAB
    ),
    [_ADJUST] = LAYOUT_split_3x5_3_right_wrapper(
        _______, _______, _______, _______, _______,
        QWERTY,  COLEMK,  COLEDH,  DVORAK,  WORKMN,
        _______, _______, _______, _______, _______,
        _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAVR, _NSL, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case COLEDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case WORKMN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
            break;
    }
    return true;
}
