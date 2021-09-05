//
// Created by mikoaj on 05.09.2021.
//

#ifndef UNTITLED4_CHOOSENUMBER_H
#define UNTITLED4_CHOOSENUMBER_H

#include "State.h"
#include "Hyperlapser.h"

class ChooseNumber : public State {
    Hyperlapser hyperlapser;

    ChooseNumber(Hyperlapser newHyperlapser);

    void upButton();

    void downButton();

    void confirmButton();
};


#endif //UNTITLED4_CHOOSENUMBER_H
