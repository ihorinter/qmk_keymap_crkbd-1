#include QMK_KEYBOARD_H
#include <stdio.h>

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN LGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(

       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,

       KC_ENT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,

       KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,

                                          KC_LOPT,  KC_BSPC,  MO(1),     TO(2), LCMD_T(KC_SPC), KC_RSFT


  ),

  [1] = LAYOUT_split_3x6_3(

      HYPR(KC_Z), XXXXXXX, XXXXXXX, KC_UP,         XXXXXXX, LCTL(KC_SPC),                        LCTL(LOPT(KC_SPC)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

      XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,       KC_RGHT, LCTL(LCMD(KC_SPC)),                  XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

      HYPR(KC_S), XXXXXXX, XXXXXXX, LCTL(KC_LEFT), HYPR(KC_V), LCTL(KC_RGHT),                    XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

                                                           _______, _______, XXXXXXX,    XXXXXXX, _______, _______

  ),

  [2] = LAYOUT_split_3x6_3(

       KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,    LSFT(KC_MINS), KC_MINS,                         KC_COMM,    KC_7,    KC_8,    KC_9,  KC_PLUS, XXXXXXX,
 
       KC_ENT, XXXXXXX, XXXXXXX, LSFT(KC_9), LSFT(KC_0),    KC_QUES,                         KC_DOT,     KC_4,    KC_5,    KC_6,  KC_ASTR, XXXXXXX,
 
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,    KC_RBRC,       KC_EXLM,                         KC_0,       KC_1,    KC_2,    KC_3,  KC_EQL, _______,
 
                                          _______, _______,   TO(0),      TO(3), _______, _______
 
  ),

  [3] = LAYOUT_split_3x6_3(

        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

                                          _______, _______,   TO(0),    XXXXXXX, _______, _______

  )
};

#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   }
//   return rotation;
// }

// #define L_BASE 0
// #define L_LOWER 2
// #define L_RAISE 4
// #define L_ADJUST 8
// 
// void oled_render_layer_state(void) {
//     oled_write_P(PSTR("Layer: "), false);
//     switch (layer_state) {
//         case L_BASE:
//             oled_write_ln_P(PSTR("Default"), false);
//             break;
//         case L_LOWER:
//             oled_write_ln_P(PSTR("Lower"), false);
//             break;
//         case L_RAISE:
//             oled_write_ln_P(PSTR("Raise"), false);
//             break;
//         case L_ADJUST:
//         case L_ADJUST|L_LOWER:
//         case L_ADJUST|L_RAISE:
//         case L_ADJUST|L_LOWER|L_RAISE:
//             oled_write_ln_P(PSTR("Adjust"), false);
//             break;
//     }
// }


// char keylog_str[24] = {};
// 
// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
// 
// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//   char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//   if (keycode < 60) {
//     name = code_to_name[keycode];
//   }
// 
//   // update keylog
//   snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//            record->event.key.row, record->event.key.col,
//            keycode, name);
// }
// 
// void oled_render_keylog(void) {
//     oled_write(keylog_str, false);
// }

// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }


void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}

// bool oled_task_user(void) {
//     if (is_keyboard_master()) {
//         oled_render_layer_state();
//         oled_render_keylog();
//     } else {
//         oled_render_logo();
//     }
//     return false;
// }
// 
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     set_keylog(keycode, record);
//   }
//   return true;
// }
#endif // OLED_ENABLE
