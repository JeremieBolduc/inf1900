#include <avr/io.h>
#include "PinDetails.h"

struct PortDetails
{
    PortDetails()
    {
        DDRx = nullptr;
        PINs = nullptr;
        pinCount = 0;
    }

    PortDetails(volatile uint8_t *DDRx, PinDetails *pins, uint8_t pinCount)
    {
        DDRx = x;
        PINs = y;
        pinCount = z;
    }

    volatile uint8_t *DDRx;
    PinDetails *PINs;
    uint8_t pinCount;
};