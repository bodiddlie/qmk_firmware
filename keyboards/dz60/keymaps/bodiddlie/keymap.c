#include QMK_KEYBOARD_H
#include "dz60.h"

enum layers {
  _BASE,
  _FN,
  _MOUSE
};

/* 
 * 
 *  COMBOS
 * 
 */

const uint16_t PROGMEM test_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
   * |-----------------------------------------------------------------------------------------+
   * | Esc/Fn  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Rshft|  U  | ESC |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Alt  |  Cmd  |              Space                | Alt |  Fn  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

	[_BASE] = LAYOUT_directional(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, 
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
      LT(_FN, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL, 
      KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
    ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |    DEL    |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |      |     | Vol-| Vol+ | Mute |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     | Left| Down| Up |Right|      |      |            |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |           |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |RGB_V|RGB_R|RGB_V|
   * `-----------------------------------------------------------------------------------------'
   */

	[_FN] = LAYOUT_directional(
      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, G(KC_BSPC), G(KC_BSPC), 
      XXXXXXX, XXXXXXX, A(KC_RIGHT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, 
      _______, XXXXXXX, XXXXXXX, A(KC_BSPC), G(KC_DEL), XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_LEFT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_MOUSE), XXXXXXX, RGB_MOD, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, RGB_VAD, RGB_RMOD, RGB_VAI
  ),

	[_MOUSE] = LAYOUT_directional(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX, XXXXXXX, KC_MS_BTN2, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_BASE)
  )
};
