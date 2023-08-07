#include QMK_KEYBOARD_H
#include <stdio.h>
#include "render.h"

// OLED setup
#define IDLE_FRAMES 5
#define IDLE_SPEED 30
#define TAP_FRAMES 2
#define TAP_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 512

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  <-  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | ENT  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LCTRL|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSHIFT|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LSHIFT| LGUI | LAlt | / LOWER /       \Space \  |  -   |  =   |  '   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LSFT, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_MINS,    KC_EQL,  KC_QUOT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  |  <-  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |  '   |      |  =   |  F11 |  F12 |                    | HOME | PGUP | PGDN | END  | PRINT|  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |  +   |      |  "   |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |  ENT |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * | LCTRL|      |      |      |      |      |-------|    |-------|  INS | DEL  |      |      |      | CAPS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LSHIFT| LGUI | LAlt | / LOWER /       \Space \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  _______, KC_QUOT, XXXXXXX, KC_EQL,  KC_F11,  KC_F12,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_PSCR, _______,
  KC_CAPS, KC_PPLS, XXXXXXX, KC_DQUO, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_INS,  KC_DEL,  XXXXXXX, XXXXXXX,  XXXXXXX, KC_CAPS,
                             _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//#ifdef OLED_ENABLE
//    set_keylog(keycode, record);
//#endif
//    // set_timelog();
//  }
//  return true;
//}

//
// Rotate OLED display
//
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()) return OLED_ROTATION_180;
    else return OLED_ROTATION_270;
}


//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side
        render_status();
    } else {
        // Right side
        render_bongocat();
    }

	return 0;
}
