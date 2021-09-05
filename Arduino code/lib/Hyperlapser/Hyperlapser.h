//
// Created by mikoaj on 04.09.2021.
//

#ifndef UNTITLED4_HYPERLAPSER_H
#define UNTITLED4_HYPERLAPSER_H

#include "State.h"
#include "Menu.h"

enum ConstantValues {
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
    const int REMOVE_NUMBER=10;
    const int CONFIRM_NUMBER=11;
};

class Hyperlapser {
private:
    Menu menu ;
    ChooseNumber chooseNumber{};
    TurnServo turnServo{};
    State hyperlapserState{};
    Servo servo;
    int time = TIME;
    int currentMenu = 1;
    int currentNumber = 1;
    int pos = START_POSITION;
    int startPos = START_POSITION;
    int endPos = END_POSITION;
    int timeMultiplier = TIME_MULTIPLIER_MINUTE;
    double interval;
public:
    Hyperlapser();

    double calculateInterval();

    void setHyperlapserState(State newHyperlapserState);

    const State &getHyperlapserState() const;

    void setHyperlapserState(const State &hyperlapserState);

    void attachServo(Servo servo);

    int getTime() const;

    void setTime(int time);

    int getTimeMultiplier() const;

    void setTimeMultiplier(int timeMultiplier);

    int getCurrentMenu() const;

    void setCurrentMenu(int currentMenu);

    int getCurrentNumber() const;

    void setCurrentNumber(int currentNumber);

    int getPos() const;

    void setPos(int pos);

    int getStartPos() const;

    void setStartPos(int startPos);

    int getEndPos() const;

    void setEndPos(int endPos);

    void upButton();

    void downButton();

    void confirmButton();

    State getMenuState();

    State getChooseNumberState();

    State getTurnServoState();

}


#endif //UNTITLED4_HYPERLAPSER_H
