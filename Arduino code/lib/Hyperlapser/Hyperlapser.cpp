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
    resetPosition();
    calculateAndSetInterval();
    setRunning(true);
    notify();
}

void Hyperlapser::changeStateToMenu() {
    delete currentState;
    currentState = new Menu(this);
    setRunning(false);
    notify();
}

void Hyperlapser::changeStateToChooseNumber() {
    delete currentState;
    currentState = new ChooseNumber(this);
    setRunning(false);
    notify();
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
    if (currentNumber < 0)currentNumber = 11;
    if (currentNumber > ConstantValues::MAX_NUMBER_MENU_VALUE)currentNumber = 0;
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
    notify();
}

int Hyperlapser::getEndPos() const {
    return endPos;
}

void Hyperlapser::setEndPos(int endPos) {
    Hyperlapser::endPos = validatePos(endPos);
    notify();
}

int Hyperlapser::getTimeMultiplier() const {
    return timeMultiplier;
}

void Hyperlapser::setTimeMultiplier(int timeMultiplier) {
    Hyperlapser::timeMultiplier = timeMultiplier;
    notify();
}

void Hyperlapser::moveServo() {
    if (Hyperlapser::startPos > Hyperlapser::endPos) {
        setPos(Hyperlapser::pos - 1);
    } else if (Hyperlapser::startPos < Hyperlapser::endPos) {
        setPos(Hyperlapser::pos + 1);
    }
    servo->write(pos);
    notify();
}

void Hyperlapser::resetPosition() {
    setPos(getStartPos());
    servo->write(pos);
}

float Hyperlapser::getInterval() const {
    return interval;
}

void Hyperlapser::setInterval(long interval) {
    Hyperlapser::interval = interval;
}

int Hyperlapser::validatePos(int pos) {
    if (pos > 180)pos = 180;
    if (pos < 0)pos = 0;
    return pos;
}



void Hyperlapser::switchStartEndValues() {
    int temp = getStartPos();
    setStartPos(getEndPos());
    setEndPos(temp);
    resetPosition();
}

void Hyperlapser::changeTimeMultiplier() {
    switch (Hyperlapser::timeMultiplier) {
        case ConstantValues::TIME_MULTIPLIER_SECOND:
            setTimeMultiplier(ConstantValues::TIME_MULTIPLIER_MINUTE);
            break;
        case ConstantValues::TIME_MULTIPLIER_MINUTE:
            setTimeMultiplier(ConstantValues::TIME_MULTIPLIER_HOUR);
            break;
        case ConstantValues::TIME_MULTIPLIER_HOUR:
            setTimeMultiplier(ConstantValues::TIME_MULTIPLIER_SECOND);
            break;
        default:
            setTimeMultiplier(ConstantValues::TIME_MULTIPLIER_MINUTE);
            break;
    }
}

int Hyperlapser::getNumber() const {
    return number;
}

void Hyperlapser::setNumber(int number) {
    Hyperlapser::number = number;
    notify();
}

bool Hyperlapser::isRunning() const {
    return running;
}

void Hyperlapser::setRunning(bool running) {
    Hyperlapser::running = running;
}

void Hyperlapser::setServo(Servo *servo) {
    Hyperlapser::servo = servo;
}

