#include "backlight.h"

Backlight::Backlight() {
    this->tlc = nullptr;
    this->keyboard = nullptr;
    this->style = BacklightStyle::STANDARD;
}

void Backlight::init(Tlc5940* tlc, Ze::Board* keyboard) {
    this->tlc = tlc;
    this->keyboard = keyboard;
    
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED l;
            l.port = LED_GRID[row][col];
            l.brightness = 0.0;
            leds[row][col] = l;
        }
    }
}


void Backlight::print_grid() {
    Serial.println("-------------------------");

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint16_t b = leds[row][col].brightness;
            Serial.print(b);
            if (b < 10) {
                Serial.print(" ");
            }
        }
        Serial.println("");
    }
    Serial.println("");
}

void Backlight::setup(BacklightStyle style) {
    this->style = style;
    switch (style) {
        case STANDARD:
            standard_setup(this->leds);
            break;
    }
}

void Backlight::update() {
    switch (style) {
        case STANDARD:
            standard_update(this->leds, this->keyboard);
            break;
    }

    // update the tlc
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED curr = leds[row][col];
            tlc->set(curr.port, (uint16_t)(curr.brightness * MAX_BRIGHTNESS));
        }
    }
    tlc->update();
}
