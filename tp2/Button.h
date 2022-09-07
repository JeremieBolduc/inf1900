#pragma once
#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>

class Button {
public:
    Button();
    Button(volatile uint8_t&, uint8_t);
    ~Button();

    bool isPressed();

private:
    uint8_t _port;
    uint8_t _pinNumber;
};