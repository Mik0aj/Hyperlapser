//
// Created by mikoaj on 04.09.2021.
//

#include "Menu.h"

void Menu::upButton() {
    hyperlapser.setCurrentMenu(hyperlapser.getCurrentMenu + 1);
}

void Menu::downButton() {
    hyperlapser.setCurrentMenu(hyperlapser.getCurrentMenu - 1);
}

void Menu::confirmButton() {
    currentMenu = hyperlapser.getCurrentMenu();
    switch (currentMenu) {
        // to know what number to choose i should check current menu value in chooseNumverState
        case CHANGE_TIME:
            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
            break;
        case CHANGE_TIME_MULTIPLIER:
            switch (hyperlapser.getTimeMultiplier) {
                case TIME_MULTIPLIER_SECOND:
                    hyperlapser.setTimeMultiplier(TIME_MULTIPLIER_MINUTE);
                    break;
                case TIME_MULTIPLIER_MINUTE:
                    hyperlapser.setTimeMultiplier(TIME_MULTIPLIER_HOUR);
                    break;
                case Hyperlapser.TIME_MULTIPLIER_HOUR:
                    hyperlapser.setTimeMultiplier(TIME_MULTIPLIER_SECOND);
                    break;
                default:
                    hyperlapser.setTimeMultiplier(TIME_MULTIPLIER_HOUR);
            }
            break;
        case START_PROGRAM:
            hyperlapser.calculateInterval();
            hyperlapser.setHyperlapserState(hyperlapser.getTurnServoState());
            break;
        case RESET_POSITION:
            hyperlapser.setPos(hyperlapser.startPos);
            break;
        case SET_START_POSITION:
            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
            break;
        case SET_END_POSITION:
            hyperlapser.setHyperlapserState(hyperlapser.getChooseNumberState());
            break;
        case SWITCH_START_END:
            int start = hyperlapser.getStartPos();
            int end = hyperlapser.getEndPos();
            hyperlapser.setEndPos(start);
            hyperlapser.setStartPos(end);
            break;

    }
}

Menu::Menu(Hyperlapser newHyperlapser) {
    hyperlapser = newHyperlapser;
}
