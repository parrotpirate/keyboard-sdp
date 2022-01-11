#include QMK_KEYBOARD_H
// #include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

typedef struct {
    bool is_press_action;
    int  state;
} tap;

// enum { SINGLE_TAP = 1, SINGLE_HOLD = 2, DOUBLE_TAP = 3, DOUBLE_HOLD = 4, TRIPLE_TAP = 5 };
// Key tap states
enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    SINGLE_DOUBLE_TAP = 3,
    DOUBLE_TAP        = 4,
    DOUBLE_HOLD       = 5,
    DOUBLE_SINGLE_TAP = 6,  // Send two single taps
    TRIPLE_TAP        = 7,
    TRIPLE_HOLD       = 8,
};

// Tap dance enums
enum { TD_LSHIFT, TD_RSHIFT, TD_COLON, TD_LGUI, TD_RGUI, CT_FLSH, CAPS_TD, LCTRL_TD, RCTRL_TD, ESC_TD, TD_MIN_EQ, TD_DBL_SLS, TD_J_ESC, TD_ALFRED_CAT };

int cur_dance(qk_tap_dance_state_t *state);

// Track active layer
int active_layer;

// Track caps lock
int caps_state;

void td_lshift_finished(qk_tap_dance_state_t *state, void *user_data);
void td_lshift_reset(qk_tap_dance_state_t *state, void *user_data);
void td_rshift_finished(qk_tap_dance_state_t *state, void *user_data);
void td_rshift_reset(qk_tap_dance_state_t *state, void *user_data);
void td_rgui_finished(qk_tap_dance_state_t *state, void *user_data);
void td_rgui_reset(qk_tap_dance_state_t *state, void *user_data);
void td_colon_finished(qk_tap_dance_state_t *state, void *user_data);
void td_colon_reset(qk_tap_dance_state_t *state, void *user_data);
void z_finished(qk_tap_dance_state_t *state, void *user_data);
void z_reset(qk_tap_dance_state_t *state, void *user_data);
void caps_finished(qk_tap_dance_state_t *state, void *user_data);
void caps_reset(qk_tap_dance_state_t *state, void *user_data);
void z_td_finished(qk_tap_dance_state_t *state, void *user_data);
void z_td_reset(qk_tap_dance_state_t *state, void *user_data);
void q_td_finished(qk_tap_dance_state_t *state, void *user_data);
void q_td_reset(qk_tap_dance_state_t *state, void *user_data);
void esc_td_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_td_reset(qk_tap_dance_state_t *state, void *user_data);
void td_j_esc_finished(qk_tap_dance_state_t *state, void *user_data);
void td_j_esc_reset(qk_tap_dance_state_t *state, void *user_data);
void td_alfred_cat_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alfred_cat_reset(qk_tap_dance_state_t *state, void *user_data);

// ? COMBO KEYS
const uint16_t PROGMEM jkesc[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(jkesc, KC_ESC),
};

// ? Custom keycodes
enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    MC_DBL_ARW,
    MC_SGL_ARW,
    DYNAMIC_MACRO_RANGE,
    // ? Mouse layer lock
    DRAGLOCK = SAFE_RANGE,
    // ? Left click and turn off drag lock
    LEFTCLICK = EZ_SAFE_RANGE,
};
#define _DYN 3
// #include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0]    = LAYOUT_ergodox_pretty(KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5, DYN_MACRO_PLAY1, TD(CT_FLSH), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_DELETE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRANSPARENT, MO(_DYN), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH, TD(CAPS_TD), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TD(TD_COLON), RGUI_T(KC_QUOTE), TD(TD_LSHIFT), MT(MOD_LCTL, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_HYPR, KC_MEH, KC_N, KC_M, KC_COMMA, KC_DOT, MT(MOD_RCTL, KC_SLASH), TD(TD_RSHIFT), LCTL(KC_LBRACKET), KC_LALT, LCTL(KC_LALT), KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, KC_LBRACKET, KC_RBRACKET, DYN_REC_STOP, LALT_T(KC_APPLICATION), KC_HOME, KC_PGUP, RALT(KC_RGUI), KC_END, KC_PGDOWN, LT(1, KC_SPACE), KC_BSPACE, SCMD_T(KC_NO), LALT_T(KC_ESCAPE), KC_TAB, LT(1, KC_ENTER)),
    [1]    = LAYOUT_ergodox_pretty(KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, LGUI(KC_GRAVE), LGUI(KC_TAB), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRANSPARENT, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, RGUI_T(KC_NO), KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_UNDS, KC_COLN, KC_4, KC_5, KC_6, KC_KP_PLUS, KC_TRANSPARENT, MC_SGL_ARW, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, TD(TD_MIN_EQ), KC_TILDE, MO(_DYN), KC_AMPR, KC_1, KC_2, KC_3, TD(TD_DBL_SLS), MC_DBL_ARW, KC_TRANSPARENT, KC_AMPR, KC_UNDS, KC_LABK, KC_RABK, KC_KP_0, KC_DOT, KC_MINUS, KC_EQUAL, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_SPACE), LCTL(KC_LBRACKET), LGUI(KC_V), LGUI(KC_C), LALT(LCTL(LGUI(KC_SPACE))), KC_SPACE),
    [2]    = LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_F3, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_TRANSPARENT, KC_TRANSPARENT, TO(1), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_LBRACKET), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, LALT(KC_UP), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT, KC_TRANSPARENT, KC_MS_WH_LEFT, MEH(KC_C), KC_MS_WH_RIGHT, LALT(KC_DOWN), TG(4), TO(0), KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_LEFT), LALT(KC_RIGHT), KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LEFTCLICK, KC_MS_BTN2, DRAGLOCK, KC_TRANSPARENT, LALT(LCTL(LGUI(KC_SPACE))), TD(TD_ALFRED_CAT)),
    [_DYN] = LAYOUT_ergodox_pretty(KC_TRANSPARENT, DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_TRANSPARENT, DYN_REC_STOP, DEBUG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [4]    = LAYOUT_ergodox_pretty(KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_F3, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, KC_MS_UP, KC_MS_WH_UP, KC_TRANSPARENT, KC_TRANSPARENT, TO(1), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_LBRACKET), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, LALT(KC_UP), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TG(4), KC_TRANSPARENT, KC_LSHIFT, KC_TRANSPARENT, KC_MS_WH_LEFT, MEH(KC_C), KC_MS_WH_RIGHT, LALT(KC_DOWN), TG(4), TO(0), KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_LEFT), LALT(KC_RIGHT), KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LEFTCLICK, KC_MS_BTN2, DRAGLOCK, KC_TRANSPARENT, LALT(LCTL(LGUI(KC_SPACE))), TD(TD_ALFRED_CAT)),
};

static bool lctl             = false;
static bool rctl             = false;
bool        drag_lock_toggle = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_record_dynamic_macro(keycode, record)) {
    //     return false;
    // }
    switch (keycode) {
        case MC_SGL_ARW:
            if (record->event.pressed) {
                SEND_STRING("->");
            } else {
                return true;
            }
            return false;
        case MC_DBL_ARW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            } else {
                return true;
            }
            return false;
        case DRAGLOCK:
            if (record->event.pressed && !drag_lock_toggle) {
                register_code(KC_MS_BTN1);
                ergodox_right_led_3_on();
                drag_lock_toggle = true;
            } else if (record->event.pressed && drag_lock_toggle) {
                unregister_code(KC_MS_BTN1);
                ergodox_right_led_3_off();
                drag_lock_toggle = false;
                return true;
            }
            return false;
        case LEFTCLICK:
            if (record->event.pressed) {
                if (drag_lock_toggle) {
                    unregister_code(KC_MS_BTN1);
                    ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                    return true;
                } else {
                    register_code(KC_MS_BTN1);
                }
            } else {
                unregister_code(KC_MS_BTN1);
            }
            return false;

        default:
            return true;
    }
    return true;
}

// LED control
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}
// end led control

// Caps lock led control
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        caps_state = 1;
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    } else {
        caps_state = 0;
    }
}
// end caps lock led control

// Layer led control
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            active_layer = 1;
            break;
        case 2:
            ergodox_right_led_2_on();
            active_layer = 2;
            break;
        case 3:
            ergodox_right_led_3_on();
            active_layer = 3;
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            active_layer = 4;
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            active_layer = 5;
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            active_layer = 6;
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            active_layer = 7;
            break;
        default:
            active_layer = 0;
            break;
    }
    return state;
}
// end layer led control

// Tap dance logic
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed)
            return DOUBLE_TAP;
        else
            return DOUBLE_HOLD;
    }

    if (state->count == 3) {
        if (!state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 9;  // magic number. At some point this method will expand to work for more presses
}

int cur_dance_interrupt(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted)
            return SINGLE_DOUBLE_TAP;
        else if (state->pressed)
            return SINGLE_HOLD;
        else
            return SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 9;  // magic number. At some point this method will expand to work for more presses
}
// end tap dance logic

// Tap dance state intit
static tap td_lshift_state     = {.is_press_action = true, .state = 0};
static tap td_rshift_state     = {.is_press_action = true, .state = 0};
static tap td_colon_state      = {.is_press_action = true, .state = 0};
static tap lgui_tap_state      = {.is_press_action = true, .state = 0};
static tap td_rgui_state       = {.is_press_action = true, .state = 0};
static tap caps_tap_state      = {.is_press_action = true, .state = 0};
static tap ztdtap_state        = {.is_press_action = true, .state = 0};
static tap qtdtap_state        = {.is_press_action = true, .state = 0};
static tap esc_tap_state       = {.is_press_action = true, .state = 0};
static tap td_j_esc_state      = {.is_press_action = true, .state = 0};
static tap td_alfred_cat_state = {.is_press_action = true, .state = 0};

// left shift tap dance
void td_lshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_lshift_state.state = cur_dance(state);
    switch (td_lshift_state.state) {
        case SINGLE_TAP:  // type "("
            register_code(KC_LSFT);
            register_code(KC_9);
            unregister_code(KC_LSFT);
            break;
        case SINGLE_HOLD:  // hold "shift"
            register_code(KC_LSFT);
            break;
        case DOUBLE_TAP:  // type "{"
            register_code(KC_LSFT);
            register_code(KC_LBRC);
            unregister_code(KC_LSFT);
            break;
        case TRIPLE_TAP:  // type "["
            register_code(KC_LBRC);
            break;
    }
}

void td_lshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_lshift_state.state) {
        case SINGLE_TAP:  // type "("
            unregister_code(KC_LSFT);
            unregister_code(KC_9);
            break;
        case SINGLE_HOLD:  // release "shift"
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:  // type "{"
            unregister_code(KC_LSFT);
            unregister_code(KC_LBRC);
            break;
        case TRIPLE_TAP:  // type "["
            unregister_code(KC_LBRC);
    }
    td_lshift_state.state = 0;
}
// end left shift tap dance

// right shift tap dance
void td_rshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_rshift_state.state = cur_dance(state);
    switch (td_rshift_state.state) {
        case SINGLE_TAP:  // type ")"
            register_code(KC_RSFT);
            register_code(KC_0);
            unregister_code(KC_RSFT);
            break;
        case SINGLE_HOLD:  // hold "shift"
            register_code(KC_RSFT);
            break;
        case DOUBLE_TAP:  // type "}"
            register_code(KC_RSFT);
            register_code(KC_RBRC);
            unregister_code(KC_RSFT);
            break;
        case TRIPLE_TAP:  // type "]"
            register_code(KC_RBRC);
            break;
    }
}

void td_rshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_rshift_state.state) {
        case SINGLE_TAP:  // type ")"
            unregister_code(KC_RSFT);
            unregister_code(KC_0);
            break;
        case SINGLE_HOLD:  // release "shift"
            unregister_code(KC_RSFT);
            break;
        case DOUBLE_TAP:  // type "}"
            unregister_code(KC_RSFT);
            unregister_code(KC_RBRC);
            break;
        case TRIPLE_TAP:  // type "]"
            unregister_code(KC_RBRC);
    }
    td_rshift_state.state = 0;
}
// end right shift tap dance

void td_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_colon_state.state = cur_dance(state);
    switch (td_colon_state.state) {
        case SINGLE_TAP:
            if (active_layer == 2) {
                if (drag_lock_toggle) {
                    unregister_code(KC_MS_BTN1);
                    ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                }
                layer_off(2);
            } else if (active_layer == 4) {
                if (drag_lock_toggle) {
                    unregister_code(KC_MS_BTN1);
                    ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                }
                layer_off(4);
            } else
                register_code(KC_SCLN);
            break;
        case SINGLE_HOLD:
            layer_on(2);
            break;
        case DOUBLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_SCLN);
            break;
        case TRIPLE_TAP:
            if (active_layer == 2) {
                layer_off(2);
            } else if (active_layer == 4) {
                layer_off(4);
            } else {
                layer_on(2);
            }
            break;
        case TRIPLE_HOLD:
            layer_on(2);
    }
}

void td_colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_colon_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_SCLN);
            break;
        case SINGLE_HOLD:
            if (drag_lock_toggle) {
                unregister_code(KC_MS_BTN1);
                ergodox_right_led_3_off();
                drag_lock_toggle = false;
            }
            if (active_layer == 2) {
                layer_off(2);
            } else {
                layer_off(4);
            }

            break;
        case DOUBLE_TAP:
            unregister_code(KC_LSFT);
            unregister_code(KC_SCLN);
            break;
        case TRIPLE_HOLD:
            if (active_layer == 2) {
                layer_off(2);
            } else {
                layer_off(4);
            }
    }
    td_colon_state.state = 0;
}

void lgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    lgui_tap_state.state = cur_dance(state);
    switch (lgui_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_GRAVE);
            unregister_code(KC_LSFT);
            break;
    }
}

void lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lgui_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_LSFT);
            unregister_code(KC_GRAVE);
    }
    lgui_tap_state.state = 0;
}

void td_rgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_rgui_state.state = cur_dance(state);
    switch (td_rgui_state.state) {
        case SINGLE_TAP:
            register_code(KC_QUOTE);
            break;
        case SINGLE_HOLD:
            register_code(KC_RGUI);
            break;
        case DOUBLE_TAP:
            register_code16(RSFT(KC_QUOTE));
            break;
        case DOUBLE_HOLD:
            register_code(KC_RGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_QUOTE);
            register_code16(KC_QUOTE);
            break;
    }
}

void td_rgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_rgui_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_QUOTE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RGUI);
            break;
        case DOUBLE_TAP:
            unregister_code16(RSFT(KC_QUOTE));
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_RGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_QUOTE);
            break;
    }
    td_rgui_state.state = 0;
}

void caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    caps_tap_state.state = cur_dance(state);
    switch (caps_tap_state.state) {
        case SINGLE_TAP:
            if (caps_state == 1) {
                register_code(KC_CAPSLOCK);
                _delay_ms(100);
                unregister_code(KC_CAPSLOCK);
                caps_state = 0;
                ergodox_right_led_1_off();
                ergodox_right_led_2_off();
                ergodox_right_led_3_off();
            } else {
                register_code(KC_GRAVE);
            }
            break;
        case SINGLE_HOLD:
            register_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            register_code(KC_CAPSLOCK);
            _delay_ms(100);
            unregister_code(KC_CAPSLOCK);
            caps_state = 1;
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
    }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (caps_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_CAPSLOCK);
            caps_state = 0;
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
    }
    caps_tap_state.state = 0;
}

void z_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            register_code(KC_Z);
        } else {
            register_code(KC_LCTRL);
            lctl = true;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            register_code(KC_Z);
            unregister_code(KC_Z);
            register_code(KC_Z);
        } else if (state->pressed) {
            register_code(KC_LCTRL);
            lctl = true;
        } else {
            register_code(KC_LSFT);
            register_code(KC_Z);
            unregister_code(KC_LSFT);
        }
    }
}

void z_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            unregister_code(KC_Z);
            unregister_code(KC_LCTRL);
        } else {
            unregister_code(KC_LCTRL);
            lctl = false;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            unregister_code(KC_Z);
            unregister_code(KC_LCTRL);
        } else if (state->pressed) {
            unregister_code(KC_LCTRL);
            lctl = false;
        } else {
            unregister_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTRL);
        }
    }
    ztdtap_state.state = 0;
    lctl               = false;
}

void q_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    qtdtap_state.state = cur_dance(state);
    switch (qtdtap_state.state) {
        case SINGLE_TAP:
            register_code(KC_SLASH);
            break;
        case SINGLE_HOLD:
            register_code(KC_RCTRL);
            rctl = true;
            break;
        case DOUBLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_SLASH);
            unregister_code(KC_LSFT);
            break;
    }
}

void q_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (qtdtap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_SLASH);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RCTRL);
            rctl = false;
            break;
        case DOUBLE_TAP:
            unregister_code(KC_SLASH);
            unregister_code(KC_LSFT);
    }
    qtdtap_state.state = 0;
}

void dance_flsh_each(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            break;
        case 4:
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
            _delay_ms(50);
            ergodox_right_led_3_on();
            _delay_ms(50);
            ergodox_right_led_2_on();
            _delay_ms(50);
            ergodox_right_led_1_on();
            _delay_ms(50);
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
            _delay_ms(50);
            ergodox_right_led_3_on();
            _delay_ms(50);
            ergodox_right_led_2_on();
            _delay_ms(50);
            ergodox_right_led_1_on();
            _delay_ms(50);
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
    }
}

void dance_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        reset_keyboard();
        reset_tap_dance(state);
    }
}

void dance_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    _delay_ms(250);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    _delay_ms(250);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    _delay_ms(250);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    _delay_ms(250);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

// ALT/ESC/CTRL+[
void esc_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    esc_tap_state.state = cur_dance(state);
    switch (esc_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCTRL);
            register_code(KC_LBRACKET);
            break;
    }
}

void esc_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esc_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_LBRACKET);
            unregister_code(KC_LCTRL);
    }
    esc_tap_state.state = 0;
}

void td_j_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_j_esc_state.state = cur_dance_interrupt(state);
    switch (td_j_esc_state.state) {
        case SINGLE_TAP:
            register_code(KC_J);
            break;
        case SINGLE_HOLD:
            break;
        case SINGLE_DOUBLE_TAP:
            register_code(KC_J);
            break;
        case DOUBLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code(KC_J);
            unregister_code(KC_J);
            register_code(KC_J);
            break;
    }
}

void td_j_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_j_esc_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_J);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_J);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_J);
            break;
        case SINGLE_DOUBLE_TAP:
            unregister_code(KC_J);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_J);
            break;
    }
    td_j_esc_state.state = 0;
}

void td_alfred_cat_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_alfred_cat_state.state = cur_dance(state);
    switch (td_alfred_cat_state.state) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_SPACE);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCTRL);
            register_code(KC_LALT);
            register_code(KC_LGUI);
            register_code(KC_SPACE);
            break;
    }
}

void td_alfred_cat_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_alfred_cat_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_SPACE);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_SPACE);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
    }
    td_alfred_cat_state.state = 0;
}

// tap dance keycode config
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSHIFT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_lshift_finished, td_lshift_reset, 200),
    [TD_RSHIFT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_rshift_finished, td_rshift_reset, 200),
    [TD_COLON]      = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_colon_finished, td_colon_reset, 200),
    [TD_LGUI]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_finished, lgui_reset),
    [TD_RGUI]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_rgui_finished, td_rgui_reset, 175),
    [LCTRL_TD]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_td_finished, z_td_reset),
    [RCTRL_TD]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_td_finished, q_td_reset),
    [CAPS_TD]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, caps_finished, caps_reset, 200),
    [ESC_TD]        = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_td_finished, esc_td_reset),
    [CT_FLSH]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_flsh_each, dance_flsh_finished, dance_flsh_reset, 300),
    [TD_MIN_EQ]     = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
    [TD_DBL_SLS]    = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLASH),
    [TD_J_ESC]      = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_j_esc_finished, td_j_esc_reset, 175),
    [TD_ALFRED_CAT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_alfred_cat_finished, td_alfred_cat_reset, 200),
};
// end tap dance keycode config
