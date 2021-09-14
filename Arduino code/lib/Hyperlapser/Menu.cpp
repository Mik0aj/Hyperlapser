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
    switch (owner->getCurrentMenu()) {
        case ConstantValues::CHANGE_TIME:
            owner->changeStateToChooseNumber();
            break;
        case ConstantValues::CHANGE_TIME_MULTIPLIER:
            owner->changeTimeMultiplier();
            break;
        case ConstantValues::START_PROGRAM:
            owner->changeStateToTurnServo();
            break;
        case ConstantValues::RESET_POSITION:
            owner->resetPosition();
            break;
        case ConstantValues::SET_START_POSITION:
            owner->changeStateToChooseNumber();
            break;
        case ConstantValues::SET_END_POSITION:
            owner->changeStateToChooseNumber();
            break;
        case ConstantValues::SWITCH_START_END:
            owner->switchStartEndValues();
            break;
    }
}

void Menu::upButton() {
owner->menuDown();
}
int Menu::returnStateId(){
    return ConstantValues::MENU_STATE;
}
