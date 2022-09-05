#define F_CPU 8000000

#include <avr/io.h>
#include "Button.h"
#include "Light.h"
#include "PortDetails.h"
#include "PortDetailsBuilder.h"
#include "PinMode.h"

void init(PortDetails (&portDetailsArr)[4]);