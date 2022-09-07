#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>

#include "Light.h"
#include "Button.h"

enum class STATE {INIT_STATE, STATE1, STATE2, STATE3};


void updateState(STATE& currentState, Button& button, Light& light){
    switch (currentState){
        case STATE::INIT_STATE:
            if (button.isPressed()) {
                //while(button.isPressed());
                currentState = STATE::STATE1;
            }
            break;
        case STATE::STATE1:
            if (button.isPressed()) {
                //while(button.isPressed());
                currentState = STATE::STATE2;
            }
            break;
        case STATE::STATE2:
            if (button.isPressed()) {
                //while(button.isPressed());
                currentState = STATE::STATE3;
            }
            break;
        case STATE::STATE3:
            currentState = STATE::INIT_STATE;
            light.greenLight(2000);
            break;
    }
}

int main() {
    DDRB = 0xff;
    DDRD = 0x00;

    STATE state = STATE::INIT_STATE;
    Button button = Button(PIND, PD2);
    Light light;

    while(true) {
        if (button.isPressed()) {
                        
            light.redLight(500);
        }
    }
    // while(true){
    //     // light.redLight(1000);

    //     if (state == STATE::INIT_STATE) {
    //         light.redLight(1000);
    //     }
    //     updateState(state, button, light);
    // }
    return 0;
}