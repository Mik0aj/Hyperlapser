//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_MENU_H
#define UNTITLED4_MENU_H


#include "State.h"
#include "Hyperlapser.h"

class Menu : public State {
    Hyperlapser hyperlapser;

    Menu(Hyperlapser newHyperlapser);

    void upButton();

    void downButton();

    void confirmButton();
};


#endif //UNTITLED4_MENU_H
