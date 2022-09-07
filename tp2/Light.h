#pragma once
#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>

class Light{
public:
    Light();
    Light(volatile uint8_t&, uint8_t, uint8_t);
    ~Light();
    void greenLight(const int&);
    void redLight(const int&);
    void switchLight(const int&);

private:
    uint8_t _port;
    uint8_t _greenLightPin;
    uint8_t _redLightPin;
};