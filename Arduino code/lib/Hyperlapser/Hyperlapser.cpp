//
// Created by mikoaj on 04.09.2021.
//

#include "Hyperlapser.h"
#include "Menu.h"
#include "TurnServo.h"
#include "ChooseNumber.h"


//Hyperlapser::Hyperlapser() {
//    Menu menu(this);
//    ChooseNumber chooseNumber(this);
//    TurnServo turnServo;
//    State hyperlapserState = menu;
//}
//
//void Hyperlapser::upButton() {
//    hyperlapserState.upButton();
//}
//
//
//void Hyperlapser::downButton() {
//    hyperlapserState.downButton();
//}
//
//void Hyperlapser::confirmButton() {
//    hyperlapserState.confirmButton();
//}
//
//State Hyperlapser::getMenuState() {
//    return menu;
//}
//
//State Hyperlapser::getChooseNumberState() {
//    return chooseNumber;
//}
//
//State Hyperlapser::getTurnServoState() {
//    return turnServo;
//}
//
//int Hyperlapser::getCurrentMenu() const {
//    return currentMenu;
//}
//
//void Hyperlapser::setCurrentMenu(int currentMenu) {
//    if (Hyperlapser::currentMenu == 0) {
//        Hyperlapser::currentMenu = 1;
//    } else if (Hyperlapser::currentMenu == MAX_MENU_VALUE) {
//        Hyperlapser::currentMenu = 7;
//    } else {
//        Hyperlapser::currentMenu = currentMenu;
//    }
//}
//
//int Hyperlapser::getCurrentNumber() const {
//    return currentNumber;
//}
//
//void Hyperlapser::setCurrentNumber(int currentNumber) {
//    if (Hyperlapser::currentNumber == 0) {
//        Hyperlapser::currentNumber = 1;
//    } else if (Hyperlapser::currentNumber == MAX_NUMBER_MENU_VALUE) {
//        Hyperlapser::currentNumber = 7;
//    } else {
//        Hyperlapser::currentNumber = currentNumber;
//    }
//}
//
//int Hyperlapser::getPos() const {
//    return pos;
//}
//
//void Hyperlapser::setPos(int pos) {
//    if (Hyperlapser::pos == startPos) {
//        Hyperlapser::pos = startPos;
//    } else if (Hyperlapser::pos == endPos) {
//        Hyperlapser::pos = endPos;
//    } else {
//        Hyperlapser::pos = pos;
//    }
//    servo.write(pos)
//}
//
//int Hyperlapser::getStartPos() const {
//    return startPos;
//}
//
//void Hyperlapser::setStartPos(int startPos) {
//    Hyperlapser::startPos = startPos;
//}
//
//int Hyperlapser::getEndPos() const {
//    return endPos;
//}
//
//void Hyperlapser::setEndPos(int endPos) {
//    Hyperlapser::endPos = endPos;
//}
//
//const State &Hyperlapser::getHyperlapserState() const {
//    return hyperlapserState;
//}
//
//int Hyperlapser::getTime() const {
//    return time;
//}
//
//void Hyperlapser::setTime(int time) {
//    Hyperlapser::time = time;
//}
//
//int Hyperlapser::getTimeMultiplier() const {
//    return timeMultiplier;
//}
//
//void Hyperlapser::setTimeMultiplier(int timeMultiplier) {
//    Hyperlapser::timeMultiplier = timeMultiplier;
//}
//
//void Hyperlapser::calculateInterval() {
//    Hyperlapser::interval = time * timeMultiplier / abs(endPos - startPos);
//}
//
//void Hyperlapser::setHyperlapserState(State newHyperlapserState) {
//    hyperlapserState=newHyperlapserState;
//}
//
//
//void Hyperlapser::setHyperlapserState(const State &hyperlapserState) {
//    Hyperlapser::hyperlapserState = hyperlapserState;
//}
//
//
//
//void Hyperlapser::attachServo(Servo servo) {
//    Hyperlapser::servo=servo;
//}
//
void Hyperlapser::upButton() {
    currentState->upButton();
}

void Hyperlapser::downButton() {
    currentState->downButton();
}

void Hyperlapser::confirmButton() {
    currentState->confirmButton();
}

Hyperlapser::Hyperlapser()
        : currentState(new Menu(this)) {
}

void Hyperlapser::changeStateToTurnServo() {
    delete currentState;
    currentState=new TurnServo(this);
}
void Hyperlapser::changeStateToMenu() {
    delete currentState;
    currentState=new Menu(this);
}
void Hyperlapser::changeStateToChooseNumber() {
    delete currentState;
    currentState=new ChooseNumber(this);
}


void Hyperlapser::notify() {
    if (observer != nullptr) {
        observer->onReceivedDataFromSubject(this);
    }
}
