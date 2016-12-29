#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <Arduino.h>
#include "leds.h"
#include "led.h"
#include "keyboard.h"
#include "constants.h"
#include "standard.h"
#include <FastLED.h>

// The difference in brightness settings, must be a fraction of 1
const float BRIGHTNESS_UNIT = 0.1;

class Backlight {

    public:

        Backlight();

        void init(Ze::Board* keyboard, CRGB* ledstrip);

        /*
         * Prints the grid for debugging.
         */
        void print_grid();

        /*
         * Sets up a background style
         */
        void setup(BacklightStyle style);

        void update();

    private:

        BacklightStyle style;

        Ze::Board* keyboard;

        float brightness;

        CRGB* ledstrip;

        LED leds[Ze::NUM_ROWS][Ze::NUM_COLS];

        uint64_t it;

        bool already_changed_bright;

        uint8_t translate_grid_to_strip(uint8_t row, uint8_t col);

        void increase_brightness();

};

const led_t LED_GRID[Ze::NUM_ROWS][Ze::NUM_COLS] =
{

    //******************************************
    // ROW 0
    //******************************************
    
    {
        LED_ESC, 
        LED_1,
        LED_2,
        LED_3,
        LED_4,
        LED_5,
        LED_6,
        LED_7,
        LED_8,
        LED_9,
        LED_0,
        LED_MINUS, 
        LED_EQUAL,
        LED_BACKSPACE
    },

    //******************************************
    // ROW 1
    //******************************************

    {
        LED_TAB,
        LED_Q, 
        LED_W,
        LED_E, 
        LED_R,
        LED_T, 
        LED_Y,
        LED_U, 
        LED_I,
        LED_O, 
        LED_P,
        LED_LEFT_BRACE,
        LED_RIGHT_BRACE,
        LED_BACKSLASH
    },

    //******************************************
    // ROW 2
    //******************************************
    
    {
        LED_FN,
        LED_A, 
        LED_S,
        LED_D, 
        LED_F, 
        LED_G, 
        LED_H,
        LED_J,
        LED_K,
        LED_L, 
        LED_SEMICOLON, 
        LED_QUOTE,
        LED_DUMMY,
        LED_ENTER
    },

    //******************************************
    // ROW 3
    //******************************************
    
    {
        LED_LSHIFT,
        LED_NON_US_BS,
        LED_Z,
        LED_X,
        LED_C,
        LED_V,
        LED_B,
        LED_N,
        LED_M,
        LED_COMMA,
        LED_PERIOD,
        LED_SLASH,
        LED_DUMMY,
        LED_RSHIFT
    },

    //******************************************
    // ROW 4
    //******************************************
    
    {
        LED_CTRL,
        LED_SUPER,
        LED_ALT,
        LED_DUMMY,
        LED_DUMMY,
        LED_SPACE_LEFT,
        LED_SPACE_MAIN,
        LED_SPACE_RIGHT,
        LED_DUMMY,
        LED_DUMMY,
        LED_ALTGR,
        LED_PLAY_PAUSE,
        LED_VOL_DOWN,
        LED_VOL_UP
    }
};
#endif
