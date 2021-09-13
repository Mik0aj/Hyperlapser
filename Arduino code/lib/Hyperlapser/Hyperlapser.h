//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_HYPERLAPSER_H
#define UNTITLED4_HYPERLAPSER_H

#include <Servo.h>
#include "Arduino.h"
#include "Subject.h"
#include "Observer.h"

namespace ConstantValues {
    const int MAX_MENU_VALUE = 8;
    const int MAX_NUMBER_MENU_VALUE = 12;
    const int START_POSITION = 0;
    const int END_POSITION = 180;
    const int TIME = 10;
    const int TIME_MULTIPLIER_SECOND = 1;
    const int TIME_MULTIPLIER_MINUTE = 60;
    const int TIME_MULTIPLIER_HOUR = 3600;
    const int CHANGE_TIME = 1;
    const int CHANGE_TIME_MULTIPLIER = 2;
    const int START_PROGRAM = 3;
    const int RESET_POSITION = 4;
    const int SET_END_POSITION = 6;
    const int SET_START_POSITION = 5;
    const int SWITCH_START_END = 7;
    const int REMOVE_NUMBER = 10;
    const int CONFIRM_NUMBER = 11;
};

class State;

class Hyperlapser : public Subject {
private:
    State *currentState;
    int currentMenu = 1;
    int currentNumber = 0;
    int pos = ConstantValues::START_POSITION;
    int startPos = ConstantValues::START_POSITION;
    int endPos = ConstantValues::END_POSITION;
    int time = ConstantValues::TIME;
    int timeMultiplier = ConstantValues::TIME_MULTIPLIER_MINUTE;
    Servo servo;
    float interval;
public:
    Hyperlapser();

    void setCurrentMenu(int currentMenu);

    void menuUp();

    void menuDown();

    void notify();

    void upButton();

    void downButton();

    void confirmButton();

    void changeStateToTurnServo();

    void changeStateToChooseNumber();

    void changeStateToMenu();

    int getCurrentMenu() const;

    int validatePos(int pos);

    int getPos() const;

    int getTime() const;

    void setTime(int time);

    void calculateAndSetInterval();

    State *getCurrentState() const;

    int getCurrentNumber() const;

    void setCurrentNumber(int currentNumber);

    void setPos(int pos);

    int getStartPos() const;

    void setStartPos(int startPos);

    int getEndPos() const;

    void setEndPos(int endPos);

    int getTimeMultiplier() const;

    void setTimeMultiplier(int timeMultiplier);

    void setServo(const Servo &servo);

    float getInterval() const;

    void setInterval(float interval);

    void numberUp();

    void numberDown();

    void moveServo();
};


#endif //UNTITLED4_HYPERLAPSER_H
