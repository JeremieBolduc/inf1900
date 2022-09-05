#include "main.h"

int main()
{
    PortDetailsBuilder portDetailsBuilder;

    portDetails portDetailsArr[4] = {

        *(portDetailsBuilder
              .clear()
              .setPort(&DDRA)
              .build()),

        *(portDetailsBuilder
              .clear()
              .setPort(&DDRB)
              .addPin(PB0, PinMode::OUT)
              .addPin(PB1, PinMode::OUT)
              .build()),

        *(portDetailsBuilder
              .clear()
              .setPort(&DDRC)
              .build()),

        *(portDetailsBuilder
              .clear()
              .setPort(&DDRD)
              .build())};

    init(portDetailsArr);

    Button button = Button(PIND, PD1);
    Light light;
    int var = 100;
    while (true)
    {
        if (button.isPressed())
        {
            light.switchLight(var);
        }
    }
}

void init(portDetails (&portDetailsArr)[4])
{
    for (int i = 0; i < sizeof(portDetailsArr); i++)
    {
        for (int j = 0; j < portDetailsArr[i].numberOfPins; j++)
        {
            *(portDetailsArr[i].DDRx) |= 1 << (portDetailsArr[i].PINs + j)->PINx;
        }
    }
}