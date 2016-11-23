#include "backlight.h"

Backlight::Backlight(Tlc5940* tlc, Ze::Keyboard* keyboard) {
    this->tlc = tlc;
    this->keyboard = keyboard;
}

LED::LED(led_t port) {
    this->port = port;
    this->brightness = 0;
}

bool LED::is_dummy() {
    return this->port = LED_DUMMY;
}
