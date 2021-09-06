////
//// Created by mikoaj on 05.09.2021.
////
//
//
//void ChooseNumber::upButton() {
//    hyperlapser.setCurrentNumber(hyperlapser.getCurrentNumber + 1);
//
//}
//
//void ChooseNumber::downButton() {
//    hyperlapser.setCurrentNumber(hyperlapser.getCurrentNumber -1 );
//}
//
//void ChooseNumber::confirmButton() {
//    currentNumber = hyperlapser.getCurrentNumber();
//    String newNumber = String(number);
//    int number;
//    switch (currentNumber) {
//        case REMOVE_NUMBER:
//            newNumber.remove(newNumber.length() - 1);
//            break;
//        case CONFIRM_NUMBER:
//            number = newNumber.toInt();
//            switch (hyperlapser.getCurrentMenu) {
//                case TIME:
//                    hyperlapser.setTime(number);
//                    break;
//                case SET_START_POSITION:
//                    hyperlapser.setStartPosition(number);
//                    break;
//                case SET_END_POSITION:
//                    hyperlapser.setEndPosition(number);
//                    break;
//            }
//            hyperlapser.setHyperlapserState(hyperlapser.getMenuState());
//            break;
//        case default:
//            newNumber.concat(numberMenu);
//            break;
//    }
//}
//
//ChooseNumber::ChooseNumber(Hyperlapser *newHyperlapser) {
//    hyperlapser = newHyperlapser;
//}
#include "ChooseNumber.h"
#include "Menu.h"

ChooseNumber::ChooseNumber(Hyperlapser* newOwner):State(owner){

}
void ChooseNumber::confirmButton() {
    owner->changeStateToMenu();

}

void ChooseNumber::downButton() {
    Serial.print("downButton ChooseNumber ");

}

void ChooseNumber::upButton() {
    Serial.print("upbutton ChooseNumber ");

}

