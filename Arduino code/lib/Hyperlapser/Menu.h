//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_MENU_H
#define UNTITLED4_MENU_H

#include "Hyperlapser.h"
#include "State.h"
#include "TurnServo.h"
#include <Arduino.h>

class Menu : public State {
public:
    Menu(Hyperlapser *newOwner);

    void upButton() override;

    void downButton() override;

    void confirmButton() override;

};


#endif //UNTITLED4_MENU_H
