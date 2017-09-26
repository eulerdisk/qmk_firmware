#include "infinity60.h"

#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define ENT_CTL MT(MOD_LCTL, KC_ENT)

#define L_ALT   MT(MOD_LALT, KC_LEFT)
#define D_RALT  MT(MOD_RALT, KC_DOWN)
#define R_RCTL  MT(MOD_RCTL, KC_RIGHT)

#define O_C_ALT OSM(MOD_LALT|MOD_LCTL)
#define O_S_ALT OSM(MOD_LSFT|MOD_LALT)
#define O_C_SFT OSM(MOD_LSFT|MOD_LCTL)

#define LSHIFT KC_LSHIFT
#define RSHIFT KC_RSHIFT

#define SPC_LA1 LT(1, KC_SPC)

const uint16_t fn_actions[] = {
    [0] = MT(MOD_LSFT, RSFT(KC_9))
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,   KC_5,    KC_6,   KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NO,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      ESC_CTL,  KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  ENT_CTL,  \
      LSHIFT,   KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  RSHIFT,   KC_NO,    \
      KC_NO,    KC_LALT,  KC_LGUI,  SPC_LA1,  L_ALT,  D_RALT,  KC_UP,  R_RCTL),

    [1] = LAYOUT_60_ansi_split_bs_rshift(
      KC_PWR,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_NO,  \
      KC_TRNS,  KC_MS_L,  KC_MS_U,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,  KC_VOLD,   KC_VOLU,  KC_MUTE,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
      KC_CAPS,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_TRNS,  KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
      KC_TRNS,  KC_WH_L,  KC_WH_U,  KC_WH_D,  KC_WH_R,  KC_TRNS,  KC_MPLY,  KC_MPRV,   KC_MNXT,  KC_MSTP,   KC_TRNS,  KC_TRNS,  KC_NO,    \
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  O_C_ALT,  O_C_SFT,  O_S_ALT,  KC_TRNS),
};

enum function_id {
    LSHIFT_LPAREN
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

