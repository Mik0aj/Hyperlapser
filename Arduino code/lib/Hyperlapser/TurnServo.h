//
// Created by mikoaj on 05.09.2021.
//

#ifndef UNTITLED4_TURNSERVO_H
#define UNTITLED4_TURNSERVO_H

#include "State.h"
#include "Hyperlapser.h"

class TurnServo : public State{
    Hyperlapser hyperlapser;

    TurnServo(Hyperlapser newHyperlapser);

    void upButton();

    void downButton();

    void confirmButton();

};


#endif //UNTITLED4_TURNSERVO_H
