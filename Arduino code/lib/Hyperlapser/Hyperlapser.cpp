//
// Created by mikoaj on 04.09.2021.
//

#include "Hyperlapser.h"
#include "Menu.h"
#include "TurnServo.h"
#include "ChooseNumber.h"

int Hyperlapser::getCurrentMenu() const {
    return currentMenu;
}

int Hyperlapser::getPos() const {
    return pos;
}

int Hyperlapser::getTime() const {
    return time;
}

void Hyperlapser::setTime(int time) {
    Hyperlapser::time = time;
}

void Hyperlapser::calculateAndSetInterval() {
    Hyperlapser::setInterval(time * timeMultiplier / abs(endPos - startPos));
}

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
    currentState = new TurnServo(this);
}

void Hyperlapser::changeStateToMenu() {
    delete currentState;
    currentState = new Menu(this);
}

void Hyperlapser::changeStateToChooseNumber() {
    delete currentState;
    currentState = new ChooseNumber(this);
}


void Hyperlapser::notify() {
    if (observer != nullptr) {
        observer->onReceivedDataFromSubject(this);
    }
}


void Hyperlapser::setCurrentMenu(int currentMenu) {
    if (currentMenu == 0)currentMenu = 7;
    if (currentMenu == ConstantValues::MAX_MENU_VALUE)currentMenu = 1;
    Hyperlapser::currentMenu = currentMenu;
    notify();
}

void Hyperlapser::menuUp() {
    setCurrentMenu(currentMenu + 1);
}

void Hyperlapser::menuDown() {
    setCurrentMenu(currentMenu - 1);
}

void Hyperlapser::numberUp() {
    setCurrentNumber(currentNumber + 1);
}

void Hyperlapser::numberDown() {
    setCurrentNumber(currentNumber - 1);
}

State *Hyperlapser::getCurrentState() const {
    return currentState;
}

int Hyperlapser::getCurrentNumber() const {
    return currentNumber;
}

void Hyperlapser::setCurrentNumber(int currentNumber) {
    if (currentMenu == 0)currentMenu = 11;
    if (currentMenu == ConstantValues::MAX_NUMBER_MENU_VALUE)currentMenu = 0;
    Hyperlapser::currentNumber = currentNumber;
    notify();
}

void Hyperlapser::setPos(int pos) {
    Hyperlapser::pos = validatePos(pos);
}

int Hyperlapser::getStartPos() const {
    return startPos;
}

void Hyperlapser::setStartPos(int startPos) {
    Hyperlapser::startPos = validatePos(startPos);
}

int Hyperlapser::getEndPos() const {
    return endPos;
}

void Hyperlapser::setEndPos(int endPos) {
    Hyperlapser::endPos = validatePos(endPos);
}

int Hyperlapser::getTimeMultiplier() const {
    return timeMultiplier;
}

void Hyperlapser::setTimeMultiplier(int timeMultiplier) {
    Hyperlapser::timeMultiplier = timeMultiplier;
}

void Hyperlapser::moveServo() {
    if (Hyperlapser::startPos > Hyperlapser::endPos) {
        setPos(Hyperlapser::pos - 1);
    } else if (Hyperlapser::startPos < Hyperlapser::endPos) {
        setPos(Hyperlapser::pos + 1);
    }
}

void Hyperlapser::setServo(const Servo &servo) {
    Hyperlapser::servo = servo;
}

float Hyperlapser::getInterval() const {
    return interval;
}

void Hyperlapser::setInterval(float interval) {
    Hyperlapser::interval = interval;
}

int Hyperlapser::validatePos(int pos) {
    if (pos > 180)pos = 180;
    if (pos < 0)pos = 0;
    return pos;
}

