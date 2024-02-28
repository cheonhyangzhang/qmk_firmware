#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include QMK_KEYBOARD_H

#include <stdio.h>
enum layer_names {
    _BASE,
    _MOUSE,
    _CMD,
    _NAV,
    _NUM,
    _WIN,
    _BOOT,
};

// basic key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    LCTL(LGUI(KC_Q)),   KC_NO,  KC_W,           KC_E,         KC_R,         KC_T,       KC_Y,   KC_U,          KC_I,         KC_O,           KC_NO,     KC_NO,
    KC_Q,               KC_A,   LALT_T(KC_S),   LGUI_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H,   LCTL_T(KC_J),  LGUI_T(KC_K), LALT_T(KC_L),   KC_P,      KC_NO,
    MO(_BOOT),          KC_Z,   KC_X,           KC_C,         KC_V,         KC_B,       KC_N,   KC_M,          KC_COMM,      KC_DOT,         KC_QUOT,   MO(_BOOT),
                                                MO(_NUM),     KC_LSFT,      MO(_CMD),   KC_SPC, MO(_NAV),      KC_NO
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,          KC_MS_WH_RIGHT,   KC_MS_UP,     KC_MS_WH_LEFT,  KC_NO,      KC_NO,
      KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_BASE),  KC_MS_WH_DOWN,  KC_MS_LEFT,       KC_MS_DOWN,   KC_MS_RIGHT,    KC_NO,      KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_MS_WH_UP,    TO(_BASE),        KC_SPC,       KC_MS_BTN2,     KC_NO,      KC_NO,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_MS_BTN1,     KC_TRNS,          KC_NO
  ),
  [_CMD] = LAYOUT_split_3x6_3(
    KC_NO,              KC_NO,        LGUI(LSFT(KC_P)),   LGUI(KC_W),     LGUI(KC_R),     LGUI(KC_T),               KC_CIRC,      KC_AMPR,      KC_LPRN,      KC_RPRN,        KC_NO,            KC_NO,
    LSFT(LGUI(KC_Z)),   LGUI(KC_A),   KC_TAB,             LGUI(KC_F),     KC_ESC,         LSFT(LGUI(KC_V)),         KC_ASTR,      KC_BSPC,      LCTL(KC_A),   KC_MINUS,       KC_COLN,          KC_SCLN,
    LSFT(KC_TAB),       LGUI(KC_Z),   LGUI(KC_X),         LCTL(KC_C),     LGUI(KC_C),     LGUI(KC_V),               KC_NO,        KC_LBRC,      KC_RBRC,      LSFT(KC_MINUS), KC_NO,            KC_NO,
                                                          KC_NO,          KC_NO,          KC_NO,                    KC_ENT,       MO(_NAV),     KC_NO
  ),
  [_NAV] = LAYOUT_split_3x6_3(
     KC_NO,             KC_NO,      KC_NO,              KC_LCBR,        KC_RCBR,    KC_NO,      LSFT(LGUI(KC_N)), TO(_BASE),          KC_UP,      KC_EQUAL,     KC_NO,      KC_NO,
     LCTL(KC_SPC),      KC_EXLM,    KC_AT,              KC_HASH,        KC_DLR,     KC_PERC,    LALT(KC_BSPC),    KC_LEFT,            KC_DOWN,    KC_RGHT,      LGUI(KC_Y), LGUI(KC_BSPC),
     LGUI(LSFT(KC_T)),  LGUI(KC_1), LSFT(LCTL(KC_TAB)), LCTL(KC_TAB),   KC_TILD,    KC_GRV,     LALT(LGUI(KC_V)), TO(_MOUSE),         KC_PIPE,    KC_SLASH,     KC_BSLS,    KC_NO,
                                                        KC_NO,          KC_LSFT,    MO(_CMD),   KC_NO,            KC_NO,              KC_NO
  ),
  [_NUM] = LAYOUT_split_3x6_3(
      KC_NO,  KC_NO,          KC_NO,          LGUI(LSFT(KC_5)),         KC_NO,          KC_NO,              KC_NO,          KC_7, KC_8,   KC_9, KC_NO,   KC_NO,
      LGUI(KC_BSPC),  LGUI(KC_PLUS),  LGUI(KC_LBRC),  LCTL(LGUI(LSFT(KC_4))),   LGUI(KC_RBRC),  LSFT(LGUI(KC_G)),   KC_PGUP,        KC_4, KC_5,   KC_6, KC_DOT,  KC_NO,
      KC_NO,  LGUI(KC_MINUS), KC_NO,          LGUI(LSFT(KC_4)),         KC_NO,          KC_NO,              KC_PGDN,        KC_1, KC_2,   KC_3, KC_NO,   KC_NO,
                                              KC_NO,                    KC_NO,          KC_NO,              LSFT(KC_ENT),   KC_0, KC_NO
  ),
  [_WIN] = LAYOUT_split_3x6_3(
      LSFT(LALT(KC_Z)), KC_NO,                  KC_NO,                  LALT(LSFT(KC_L)),       LALT(LSFT(KC_H)),       KC_NO,                LGUI(KC_GRV), KC_NO,                LGUI(KC_I),         KC_NO,                  KC_NO,      KC_NO,
      LSFT(LALT(KC_M)), LCTL(KC_1),             LCTL(KC_2),             LCTL(KC_3),             LCTL(KC_4),             LALT(LSFT(KC_SPC)),   KC_NO,        LALT(LSFT(KC_J)),     LALT(LSFT(KC_ENT)), LALT(LSFT(KC_K)),       KC_NO,      LSFT(LALT(KC_M)),
      KC_NO,            LCTL(LSFT(LALT(KC_1))), LCTL(LSFT(LALT(KC_2))), LCTL(LSFT(LALT(KC_3))), LCTL(LSFT(LALT(KC_4))), LALT(LSFT(KC_T)),     KC_NO, LSFT(LCTL(KC_TAB)),   KC_NO,              LCTL(KC_TAB), KC_NO,    KC_NO,
      KC_NO,                  KC_NO,                  KC_NO,                    KC_NO,        KC_NO,                KC_NO
  ),
  [_BOOT] = LAYOUT_split_3x6_3(
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
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
  return update_tri_layer_state(state, _CMD, _NAV, _WIN);
}
