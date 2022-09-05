#include <avr/io.h>
#include "PinMode.h"

struct PinDetails
{
    PinDetails(uint8_t index, PinMode mode)
    {
        index = index;
        mode = (uint8_t)mode;
    }

    uint8_t index;
    uint8_t mode;
};