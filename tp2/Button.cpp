#include "Button.h"

Button::Button()
{
    _port = PIND;
    _pinNumber = PD1;
}

Button::Button(volatile uint8_t &port, uint8_t pinNumber)
{
    _port = port;
    _pinNumber = pinNumber;
}

Button::~Button() {}

bool Button::isPressed() {
    if (PIND && 1 << _pinNumber){
        _delay_ms(25);
        if (PIND && 1 << _pinNumber)
            return true;
    }
    return false;
}