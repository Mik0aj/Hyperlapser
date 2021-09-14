////
//// Created by mikoaj on 05.09.2021.
////

#include "ChooseNumber.h"

ChooseNumber::ChooseNumber(Hyperlapser *newOwner) : State(owner) {

}

void ChooseNumber::confirmButton() {
    String newNumber = String(owner->getNumber());
    switch (owner->getCurrentNumber()) {
        case 0:
            newNumber.concat(0);
            break;
        case 1:
            newNumber.concat(1);
            break;
        case 2:
            newNumber.concat(2);
            break;
        case 3:
            newNumber.concat(3);
            break;
        case 4:
            newNumber.concat(4);
            break;
        case 5:
            newNumber.concat(5);
            break;
        case 6:
            newNumber.concat(6);
            break;
        case 7:
            newNumber.concat(7);
            break;
        case 8:
            newNumber.concat(8);
            break;
        case 9:
            newNumber.concat(9);
            break;
        case ConstantValues::REMOVE_NUMBER:
            newNumber.remove(newNumber.length() - 1);
            break;
        case ConstantValues::CONFIRM_NUMBER:
            switch (owner->getCurrentMenu()) {
                case ConstantValues::CHANGE_TIME:
                    owner->setTime(owner->getNumber());
                    break;
                case ConstantValues::SET_START_POSITION:
                    owner->setStartPos(owner->getNumber());
                    break;
                case ConstantValues::SET_END_POSITION:
                    owner->setEndPos(owner->getNumber());
                    break;
            }
            owner->setNumber(0);
            owner->changeStateToMenu();
            owner->setCurrentNumber(0);
            return;
    }
    owner->setNumber(newNumber.toInt());
}

void ChooseNumber::downButton() {
    owner->numberDown();

}

void ChooseNumber::upButton() {
    owner->numberUp();
    Serial.print(owner->getCurrentNumber());
    Serial.println(owner->getCurrentMenu());

}

int ChooseNumber::returnStateId() {
    return ConstantValues::CHOOSE_NUMBER_STATE;
}

