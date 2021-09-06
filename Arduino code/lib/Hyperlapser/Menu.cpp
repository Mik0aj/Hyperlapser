//
// Created by mikoaj on 04.09.2021.
//

#include "Hyperlapser.h"
#include "Menu.h"
#include "TurnServo.h"

//void Menu::upButton() {
//    hyperlapser.setCurrentMenu(hyperlapser.getCurrentMenu + 1);
//}
//
//void Menu::downButton() {
//    hyperlapser.setCurrentMenu(hyperlapser.getCurrentMenu - 1);
//}
//
//void Menu::confirmButton() {
//    int currentMenu = hyperlapser.getCurrentMenu();
//    switch (currentMenu) {
//        // to know what number to choose i should check current menu value in chooseNumverState
//        case Hyperlapser.h::CHANGE_TIME:
//            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
//            break;
//        case Hyperlapser.h::CHANGE_TIME_MULTIPLIER:
//            switch (hyperlapser.getTimeMultiplier) {
//                case Hyperlapser.h::TIME_MULTIPLIER_SECOND:
//                    hyperlapser.setTimeMultiplier(Hyperlapser.h::TIME_MULTIPLIER_MINUTE);
//                    break;
//                case Hyperlapser.h::TIME_MULTIPLIER_MINUTE:
//                    hyperlapser.setTimeMultiplier(Hyperlapser.h::TIME_MULTIPLIER_HOUR);
//                    break;
//                case Hyperlapser.h::TIME_MULTIPLIER_HOUR:
//                    hyperlapser.setTimeMultiplier(Hyperlapser.h::TIME_MULTIPLIER_SECOND);
//                    break;
//                default:
//                    hyperlapser.setTimeMultiplier(Hyperlapser.h::TIME_MULTIPLIER_HOUR);
//            }
//            break;
//        case Hyperlapser.h::START_PROGRAM:
//            hyperlapser.calculateInterval();
//            hyperlapser.setHyperlapserState(hyperlapser.getTurnServoState());
//            break;
//        case Hyperlapser.h::RESET_POSITION:
//            hyperlapser.setPos(hyperlapser.startPos);
//            break;
//        case Hyperlapser.h::SET_START_POSITION:
//            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
//            break;
//        case Hyperlapser.h::SET_END_POSITION:
//            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
//            break;
//        case Hyperlapser.h::SWITCH_START_END:
//            int start = hyperlapser.getStartPos();
//            int end = hyperlapser.getEndPos();
//            hyperlapser.setEndPos(start);
//            hyperlapser.setStartPos(end);
//            break;
//
//    }
//}
//
//Menu::Menu(Hyperlapser newHyperlapser) {
//    hyperlapser = newHyperlapser;
//}

Menu::Menu(Hyperlapser* newOwner):State(newOwner){
    //nothing here
}
void Menu::downButton() {
    Serial.print("downButton menu ");
}

void Menu::confirmButton() {

    owner->changeStateToTurnServo();
}

void Menu::upButton() {
    Serial.print("upbutton menu ");
}
