//
// Created by mikoaj on 06.09.2021.
//

#include "Display.h"
#include "Hyperlapser.h"
#include "State.h"


void Display::onReceivedDataFromSubject(Subject *subject) {
    clear();
    backlight();
    switch (hyper->getCurrentState()->returnStateId()) {
        case ConstantValues::MENU_STATE:
            DisplayMenuState();
            break;
        case ConstantValues::CHOOSE_NUMBER_STATE:
            DisplayChooseMenuState();
            break;
        case ConstantValues::TURN_SERVO_STATE:
            break;

    }
}

void Display::DisplayChooseMenuState() {
    switch (hyper->getCurrentMenu()) {
        case ConstantValues::CHANGE_TIME:
            print("Setting time");
            break;
        case ConstantValues::SET_START_POSITION:
            print("Setting start pos");
            break;
        case ConstantValues::SET_END_POSITION:
            print("Setting end pos");
            break;
    }
    setCursor(0, 1);
    print(hyper->getNumber());
    switch (hyper->getCurrentNumber()) {
        case 0:
            print(0);
            break;
        case 1:
            print(1);
            break;
        case 2:
            print(2);
            break;
        case 3:
            print(3);
            break;
        case 4:
            print(4);
            break;
        case 5:
            print(5);
            break;
        case 6:
            print(6);
            break;
        case 7:
            print(7);
            break;
        case 8:
            print(8);
            break;
        case 9:
            print(9);
            break;
        case ConstantValues::REMOVE_NUMBER:
            print("remove");
            break;
        case ConstantValues::CONFIRM_NUMBER:
            print("confirm");
            break;
    }
}

void Display::DisplayMenuState() {
    switch (hyper->getCurrentMenu()) {
        case ConstantValues::CHANGE_TIME:
            print("Set time");
            setCursor(0, 1);
            print(hyper->getTime());
            break;
        case ConstantValues::CHANGE_TIME_MULTIPLIER:
            print("Time multiplier");
            setCursor(0, 1);
            print(hyper->getTimeMultiplier());
            break;
        case ConstantValues::START_PROGRAM:
            print("Start program");
            break;
        case ConstantValues::RESET_POSITION:
            print("Reset position");
            break;
        case ConstantValues::SET_START_POSITION:
            print("Start position");
            setCursor(0, 1);
            print(hyper->getStartPos());
            break;
        case ConstantValues::SET_END_POSITION:
            print("End position");
            setCursor(0, 1);
            print(hyper->getEndPos());
            break;
        case ConstantValues::SWITCH_START_END:
            print("Switch start end");
            break;
    }
}

void Display::initClass() {
    init();
    backlight();
    print("  Hyperlapser");
    delay(750);
    clear();
    backlight();
    DisplayMenuState();
}

void Display::setPointerToHyperlapser(Hyperlapser *hyperlapser) {
    hyper = hyperlapser;
}

Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows, Hyperlapser *hyperlapser) : LiquidCrystal_I2C(
        lcd_Addr, lcd_cols,
        lcd_rows) {
    setPointerToHyperlapser(hyperlapser);
}

Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows) : LiquidCrystal_I2C(lcd_Addr, lcd_cols,
                                                                                           lcd_rows) {
}



