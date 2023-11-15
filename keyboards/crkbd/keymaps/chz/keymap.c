#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include QMK_KEYBOARD_H

#include <stdio.h>
// tap dance section start
enum tap_dance_codes {
  MINUS_UNDERSCORE,
  EQUAL_PLUS,
};
// tap dance section end
enum layer_names {
    _BASE,
    _MOUSE,
    _CMD,
    _NAV,
    _NUM,
    _ONEHAND,
    _WIN,
};

// basic key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_NO,    KC_NO,  KC_W,         KC_E,         KC_R,         KC_T,       KC_Y,   KC_U,          KC_I,         KC_O,           KC_NO,    KC_NO,
    KC_Q,     KC_A,   LALT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H,   LCTL_T(KC_J),  LGUI_T(KC_K), LALT_T(KC_L),   KC_P,     KC_QUOT,
    KC_NO,    KC_Z,   KC_X,         KC_C,         KC_V,         KC_B,       KC_N,   KC_M,          KC_COMM,      KC_DOT,         KC_NO,    KC_NO,
                                    MO(_NUM),     KC_LSFT,      MO(_CMD),   KC_SPC, MO(_NAV),      KC_NO
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,          KC_MS_WH_RIGHT,   KC_MS_UP,     KC_MS_WH_LEFT,  KC_NO,      KC_NO,
      KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_BASE),  KC_MS_WH_DOWN,  KC_MS_LEFT,       KC_MS_DOWN,   KC_MS_RIGHT,    KC_TRNS,    KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_MS_WH_UP,    KC_NO,            KC_SPC,       KC_MS_BTN2,     KC_NO,      KC_NO,
                                    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_MS_BTN1,     KC_TRNS,          KC_NO
  ),
  [_CMD] = LAYOUT_split_3x6_3(
    KC_NO,              KC_NO,        LGUI(LSFT(KC_P)),   LGUI(KC_W),     LGUI(KC_R),     LGUI(KC_T),               KC_CIRC,      KC_AMPR,      KC_LPRN,    KC_RPRN,        KC_NO,            KC_NO,
    LSFT(KC_TAB),       LGUI(KC_A),   KC_TAB,             LGUI(KC_F),     KC_ESC,         LSFT(LGUI(KC_V)),         KC_ASTR,      KC_BSPC,      LCTL(KC_H), KC_MINUS,       KC_COLN,          KC_SCLN,
    LSFT(LGUI(KC_Z)),   LGUI(KC_Z),   LGUI(KC_X),         LCTL(KC_C),     LGUI(KC_C),     LGUI(KC_V),               KC_EQUAL,     KC_LBRC,      KC_RBRC,    LSFT(KC_MINUS), LSFT(KC_EQUAL),   KC_NO,
                                                          KC_NO,          KC_NO,          KC_NO,                    KC_ENT,       MO(_NAV),     KC_NO
  ),
  [_NAV] = LAYOUT_split_3x6_3(
     LCTL(LGUI(KC_Q)),  KC_NO,              KC_NO,              KC_LCBR,        KC_RCBR,  KC_NO,    LSFT(LGUI(KC_N)), TO(_BASE),          KC_UP,    TO(_MOUSE),   KC_NO,        KC_NO,
     KC_NO,             KC_EXLM,            KC_AT,              KC_HASH,        KC_DLR,   KC_PERC,  LALT(KC_BSPC),    KC_LEFT,            KC_DOWN,  KC_RGHT,      LGUI(KC_Y),   LGUI(KC_BSPC),
     KC_NO,             LGUI(KC_1),         LSFT(LCTL(KC_TAB)), LCTL(KC_TAB),   KC_TILD,  KC_GRV,   KC_NO,            LALT(LGUI(KC_V)),   KC_BSLS,  KC_SLASH,     KC_NO,        KC_NO,
                                                                KC_NO,          KC_LSFT,  MO(_CMD), KC_NO,            KC_NO,              KC_NO
  ),
  [_NUM] = LAYOUT_split_3x6_3(
      LGUI(LSFT(KC_W)), KC_NO,          KC_NO,          LGUI(LSFT(KC_5)),         KC_NO,          KC_NO,              KC_NO,          KC_7, KC_8,   KC_9, KC_NO,   KC_NO,
      KC_NO,            LGUI(KC_PLUS),  LGUI(KC_LBRC),  LCTL(LGUI(LSFT(KC_4))),   LGUI(KC_RBRC),  LSFT(LGUI(KC_G)),   KC_PGUP,        KC_4, KC_5,   KC_6, KC_DOT,  KC_BSLS,
      KC_NO,            LGUI(KC_MINUS), KC_NO,          LGUI(LSFT(KC_4)),         KC_NO,          KC_NO,              KC_PGDN,        KC_1, KC_2,   KC_3, KC_NO,   KC_NO,
                                                        KC_NO,                    KC_NO,          KC_NO,              LSFT(KC_ENT),   KC_0, KC_NO
  ),
  [_ONEHAND] = LAYOUT_split_3x6_3(
      TO(_BASE),  LGUI(KC_A), LGUI(KC_W), LSFT(LCTL(KC_TAB)), LCTL(KC_TAB),     KC_NO,          LGUI(KC_UP),    LGUI(KC_U),     KC_UP,      LGUI(KC_O), KC_NO,      KC_BSPC,
      LGUI(KC_A), KC_LSFT,    KC_LGUI,    LGUI(KC_C),         LALT(LGUI(KC_V)), LGUI(KC_V),     KC_X,           KC_LEFT,        KC_DOWN,    KC_RGHT,    LGUI(KC_Z), KC_NO,
      KC_NO,      LGUI(KC_Z), KC_X,       KC_HASH,            KC_ENT,           LGUI(KC_BSPC),  LGUI(KC_Z),     LGUI(KC_BSPC),  KC_DOWN,    KC_UP,      KC_NO,      LGUI(KC_DOWN),
                                          KC_NO,              KC_NO,            KC_SPC,         KC_SPC,         KC_NO,          KC_NO
  ),
  [_WIN] = LAYOUT_split_3x6_3(
      KC_NO,              KC_NO,                  KC_NO,                  LALT(LSFT(KC_H)),       LALT(LSFT(KC_L)),       KC_NO,                    LGUI(KC_GRV), LGUI(KC_U),       LGUI(KC_I),   LGUI(KC_O),       KC_NO,      KC_NO,
      LSFT(LALT(KC_M)),   LCTL(KC_1),             LCTL(KC_2),             LCTL(KC_3),             LCTL(KC_4),             LALT(LSFT(KC_SPC)),       KC_NO,        LALT(LSFT(KC_J)), KC_NO,        LALT(LSFT(KC_K)), KC_NO,      KC_NO,
      LALT(LSFT(KC_ENT)), LCTL(LSFT(LALT(KC_1))), LCTL(LSFT(LALT(KC_2))), LCTL(LSFT(LALT(KC_3))), LCTL(LSFT(LALT(KC_4))), LALT(LSFT(KC_T)),         KC_NO,        KC_NO,            KC_NO,        KC_NO,            KC_NO,      KC_NO,
                                                                          KC_NO,                  KC_NO,                  KC_NO,                    KC_NO,        KC_NO,            KC_NO
  )
};

// tap dance operations start
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[9];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_MINUS)); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_MINUS)); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_EQUAL)); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_EQUAL)); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[7].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [MINUS_UNDERSCORE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [EQUAL_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
};
// tap dance operations end

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

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _CMD, _NAV, _WIN);
}
