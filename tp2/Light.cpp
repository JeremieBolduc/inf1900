#include "Light.h"

Light::Light()
{
    _port = PORTB;
    _greenLightPin = PB1;
    _redLightPin = PB0;
}

Light::Light(volatile uint8_t &port, uint8_t greenPin, uint8_t redPin)
{
    _port = port;
    _greenLightPin = greenPin;
    _redLightPin = redPin;
}

Light::~Light() {}

void Light::switchLight(const int &delay)
{
    greenLight(delay);
    redLight(delay);
}

void Light::redLight(const int &delay)
{
    PORTB |= 1 << PB0;

    for (int i = 0; i < delay; i++)
    {
        _delay_ms(1);
    }

    PORTB &= 0 << PB0;
}

void Light::greenLight(const int &delay)
{
    PORTB |= 1 << PB1;

    for (int i = 0; i < delay; i++)
    {
        _delay_ms(1);
    }

    PORTB &= 0 << PB1;
}