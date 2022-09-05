#include "Builder.h"
#include "PortDetails.h"
#include "PinMode.h"

class PortDetailsBuilder : public Builder<PortDetails *>
{
private:
public:
    PortDetailsBuilder();
    ~PortDetailsBuilder();

    PortDetailsBuilder setPort(volatile uint8_t *port);
    PortDetailsBuilder addPin(uint8_t index, PinMode mode);
    PortDetailsBuilder clear();
    PortDetails *build();
};