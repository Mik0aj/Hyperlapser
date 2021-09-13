//
// Created by mikoaj on 04.09.2021.
//

#include "Hyperlapser.h"
#include "Menu.h"
#include "TurnServo.h"

Menu::Menu(Hyperlapser* newOwner):State(newOwner){
    //nothing here
}
void Menu::downButton() {
    owner->menuUp();
}

void Menu::confirmButton() {
    int currentMenu=owner->getCurrentMenu();
    switch (currentMenu) {
        case ConstantValues::CHANGE_TIME:
            owner->changeStateToChooseNumber();
            break;
        case ConstantValues::CHANGE_TIME_MULTIPLIER:
            owner->changeTimeMultiplier();
            break;
        case ConstantValues::START_PROGRAM:
            owner->changeStateToTurnServo();
        case ConstantValues::RESET_POSITION:
            owner->resetPosition();
        case ConstantValues::START_POSITION:
            owner->changeStateToChooseNumber();
        case ConstantValues::END_POSITION:
            owner->changeStateToChooseNumber();
        case ConstantValues::SWITCH_START_END:
            owner->switchStartEndValues();
    }
}

void Menu::upButton() {
owner->menuDown();
}
