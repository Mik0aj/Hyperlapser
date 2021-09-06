////
//// Created by mikoaj on 05.09.2021.
////

#ifndef UNTITLED4_CHOOSENUMBER_H
#define UNTITLED4_CHOOSENUMBER_H

#include "Hyperlapser.h"
#include "State.h"
#include <Arduino.h>

class ChooseNumber : public State {
public:
    ChooseNumber(Hyperlapser *newOwner);

    void upButton() override;

    void downButton() override;

    void confirmButton() override;

};


#endif //UNTITLED4_CHOOSENUMBER_H
