////
//// Created by mikoaj on 05.09.2021.
////

#include "TurnServo.h"

TurnServo::TurnServo(Hyperlapser *newOwner) : State(owner) {

}

void TurnServo::downButton() {
    //nothing
}

void TurnServo::confirmButton() {
    owner->changeStateToMenu();
}

void TurnServo::upButton() {
    //nothing
}

int TurnServo::returnStateId() {
    return ConstantValues::TURN_SERVO_STATE;
}
