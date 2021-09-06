////
//// Created by mikoaj on 05.09.2021.
////
//
//#include "TurnServo.h"
//
//TurnServo::TurnServo(Hyperlapser newHyperlapser) {
//    hyperlapser = newHyperlapser;
//
//}
//
//void TurnServo::upButton() {
//    hyperlapser.setHyperlapserState(hyperlapser.getMenuState());
//
//}
//
//void TurnServo::downButton() {
//    hyperlapser.setHyperlapserState(hyperlapser.getMenuState());
//
//}
//
//void TurnServo::confirmButton() {
//    hyperlapser.setHyperlapserState(hyperlapser.getMenuState());
//
//}
#include "TurnServo.h"
#include "ChooseNumber.h"

TurnServo::TurnServo(Hyperlapser* newOwner):State(owner){

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
