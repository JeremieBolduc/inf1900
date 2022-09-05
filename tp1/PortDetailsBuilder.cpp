#include "PortDetailsBuilder.h"

PortDetailsBuilder::PortDetailsBuilder()
{
    this->clear();
}

PortDetailsBuilder::~PortDetailsBuilder()
{
    for (int i = 0; i < this->trashSize; i++)
    {
        delete (trash + i);
    }
}

PortDetailsBuilder clear()
{
    this->product = new PortDetails();
    *(trash + trashSize) = this->product;
    return this;
}

PortDetailsBuilder PortDetailsBuilder::setPort(volatile uint8_t *port)
{
    this->product->DDRx = port;

    return this;
}

PortDetailsBuilder PortDetailsBuilder::addPin(uint8_t index, PinMode mode)
{

    *(this->product->PINs + this->product->pinCount) = PinDetails(index, mode);
    this->product->pinCount++;

    return this;
}

PortDetails *PortDetailsBuilder::build const override()
{
    return this->product;
}