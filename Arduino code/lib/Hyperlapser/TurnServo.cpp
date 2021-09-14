////
//// Created by mikoaj on 05.09.2021.
////

#include "TurnServo.h"

TurnServo::TurnServo(Hyperlapser *newOwner) : State(owner) {

}

void TurnServo::downButton() {
    Serial.print("downButton TurnServo ");
}

void TurnServo::confirmButton() {
    owner->changeStateToChooseNumber();

}

void TurnServo::upButton() {
    Serial.print("upbutton TurnServo ");

}

int TurnServo::returnStateId() {
    return ConstantValues::TURN_SERVO_STATE;
}
