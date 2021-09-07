//
// Created by mikoaj on 05.09.2021.
//

#ifndef UNTITLED4_TURNSERVO_H
#define UNTITLED4_TURNSERVO_H

#include "Hyperlapser.h"
#include "State.h"
#include <Arduino.h>

class TurnServo : public State {
public:
    TurnServo(Hyperlapser *newOwner);

    void upButton() override;

    void downButton() override;

    void confirmButton() override;

};

#endif //UNTITLED4_TURNSERVO_H
