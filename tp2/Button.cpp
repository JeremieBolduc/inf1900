#include "Button.h"
constexpr uint8_t DELAY = 25;

Button::Button(volatile uint8_t &port, uint8_t pinNumber)
{
    _port = port;
    _pinNumber = pinNumber;
}

Button::~Button() {}

bool Button::isPressed() {
    return PIND & (1 << _pinNumber);
}

bool Button::isDebounced() {
    if (isPressed()){
        _delay_ms(DELAY);
        return isPressed();
    }

    return false;
}

bool Button::wasReleased() {
    if (isPressed()){
        _delay_ms(DELAY);
    }

    return !isPressed();

    // while ( isPressed ());
    // return true;
}