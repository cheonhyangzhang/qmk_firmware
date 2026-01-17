#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include QMK_KEYBOARD_H

#include <stdio.h>
/*
 * 0: base layer
 * 1: mouse layer
 * 2: one hand layer
 * 3: command layer
 * 4: navigation layer
 * 5: number layer
 * 6: window management layer
 * 7: bootloader layer
*/

// basic key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  [0] = LAYOUT_split_3x6_3(
    MO(7),      LAG_T(KC_NO),   KC_W,           KC_E,         KC_R,         KC_T,       KC_Y,   KC_U,          KC_I,         KC_O,           KC_NO,     MO(7),
    KC_Q,           KC_A,           LALT_T(KC_S),   LGUI_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H,   LCTL_T(KC_J),  LGUI_T(KC_K), LALT_T(KC_L),   KC_P,      KC_SCLN,
    KC_CAPS_LOCK,   KC_Z,           KC_X,           KC_C,         KC_V,         KC_B,       KC_N,   KC_M,          KC_COMM,      KC_DOT,         KC_QUOT,   KC_RSFT,
                                    MO(5),     KC_LSFT,      MO(3),   KC_SPC, MO(4),      KC_NO
  ),
  [1] = LAYOUT_split_3x6_3(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,             KC_NO,          KC_NO,      KC_NO,          KC_NO,      KC_NO,
      KC_NO,    KC_NO,    KC_LALT,  KC_LGUI,  KC_LCTL,  KC_NO,       KC_MS_WH_DOWN,     KC_MS_WH_RIGHT, KC_MS_UP,   KC_MS_WH_LEFT,  KC_NO,      KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_MS_WH_UP,       KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_BTN2, KC_SPC,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_MS_BTN1,        KC_TRNS,        KC_ESC
  ),
  [2] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, KC_NO,    KC_E, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,      KC_NO,      KC_NO,          KC_NO,
    KC_NO, KC_A, KC_TRNS,    KC_NO, KC_SPC, KC_BSPC, KC_NO, LCTL(KC_LEFT),  KC_UP,      LCTL(KC_RIGHT), KC_NO,          KC_NO,
    KC_NO, KC_Z, LALT_T(KC_X),    KC_NO, KC_NO, KC_B, LGUI(KC_Z), KC_LEFT,        KC_DOWN,    KC_RIGHT,       LGUI(KC_BSPC),  KC_NO,
    KC_NO, KC_NO, KC_TRNS, KC_SPC, KC_TRNS, KC_ESC
  ),

  [3] = LAYOUT_split_3x6_3(
    LCTL(LGUI(KC_Q)),   KC_NO,        LSFT(LGUI(KC_Z)),   LGUI(KC_W),   LGUI(KC_R),     LGUI(KC_T),     KC_CIRC,            KC_AMPR,      KC_LPRN,            KC_RPRN,        KC_NO,    LCTL(KC_F8),
    LGUI(KC_TAB),       LGUI(KC_A),   KC_TAB,             TO(0),    KC_ESC,         LGUI(KC_F),     KC_ASTR,            KC_BSPC,      LCTL(KC_X),         KC_MINUS,       KC_COLN,  KC_NO,
    LSFT(KC_TAB),       LGUI(KC_Z),   LGUI(KC_X),         LCTL(KC_C),   LGUI(KC_C),     LGUI(KC_V),     LALT(LGUI(KC_V)),   KC_LBRC,      KC_RBRC,            LSFT(KC_MINUS), KC_NO,  KC_RSFT,
                                                          KC_NO,        KC_NO,          KC_NO,          KC_ENT,             MO(4),     KC_NO
  ),
  [4] = LAYOUT_split_3x6_3(
     LCTL(KC_F3),             KC_NO,              KC_NO,              KC_LCBR,        KC_RCBR,    KC_NO,              LGUI(KC_GRV),     LALT(LGUI(KC_Y)),   KC_UP,      KC_EQUAL,     KC_NO,      KC_NO,
     KC_NO,             LGUI(KC_1),         LSFT(LCTL(KC_TAB)), LCTL(KC_TAB),   KC_DLR,     KC_PERC,    LSFT(LGUI(KC_C)),   KC_LEFT,    KC_DOWN,    KC_RGHT,      LGUI(KC_Y), LGUI(KC_BSPC),
     LGUI(LSFT(KC_T)),  KC_EXLM,            KC_AT,          KC_HASH,    KC_TILD,            KC_GRV,     LSFT(LGUI(KC_N)),   KC_BSLS,    TO(1), KC_SLASH,     KC_NO,      TO(2),
                                                            KC_NO,          KC_LSFT,    MO(3),   KC_NO,              KC_NO,      KC_NO
  ),
  [5] = LAYOUT_split_3x6_3(
      LGUI(KC_BSPC),    KC_NO,          LCTL(LSFT(KC_PGUP)),      LGUI(LSFT(KC_5)),         LCTL(LSFT(KC_PGDN)),      KC_NO,              KC_NO,          KC_7, KC_8,   KC_9, KC_NO,   KC_KB_MUTE,
      KC_NO,  KC_NO,    LGUI(KC_LBRC),  LCTL(LGUI(LSFT(KC_4))),   LGUI(KC_RBRC),  LSFT(LGUI(KC_G)),   KC_PGUP,        KC_4, KC_5,   KC_6, KC_DOT,  KC_KB_VOLUME_UP,
      TO(2),  KC_NO,    KC_NO,          LGUI(LSFT(KC_4)),         KC_NO,          KC_NO,              KC_PGDN,        KC_1, KC_2,   KC_3, KC_NO,   KC_KB_VOLUME_DOWN,
                                        KC_NO,                    KC_NO,          KC_NO,              LSFT(KC_ENT),   KC_0, KC_NO
  ),
  [6] = LAYOUT_split_3x6_3(
      KC_NO,     KC_NO,                  KC_NO,                  LGUI(LALT(LSFT(KC_L))),       LGUI(LALT(LSFT(KC_H))),       LALT(LSFT(KC_Z)),     KC_NO,          LCTL(KC_LEFT),         LCTL(KC_UP),         LCTL(KC_RIGHT),         KC_NO,  KC_NO,
      LCTL(KC_1),             LCTL(KC_2),             LCTL(KC_3),             LCTL(KC_4),  LCTL(KC_5),           LALT(LSFT(KC_SPC)),     KC_NO,          LGUI(LALT(LSFT(KC_J))),   LALT(LSFT(KC_ENT)), LGUI(LALT(LSFT(KC_K))),   KC_NO,  LSFT(LALT(KC_M)),
      LCTL(LSFT(LALT(KC_1))), LCTL(LSFT(LALT(KC_2))), LCTL(LSFT(LALT(KC_3))), LCTL(LSFT(LALT(KC_4))), LCTL(LSFT(LALT(KC_5))), LALT(LSFT(KC_T)),       KC_NO,          KC_NO,              KC_NO,              KC_NO,              KC_NO,  KC_NO,
                                                                            KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,          KC_NO,              KC_NO
  ),
  [7] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,      KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT
  ),
};

/*
// this is to help print out the key pressed to generate heat map data
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        const bool is_combo = record->event.type == COMBO_EVENT;
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             is_combo ? 254 : record->event.key.row,
             is_combo ? 254 : record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
    #endif
    switch (keycode) {
    //...
    }
    return true;
}
*/

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, 3, 4, 6);
    return state;
}
