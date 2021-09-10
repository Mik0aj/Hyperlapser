//
// Created by mikoaj on 06.09.2021.
//

#include "Display.h"
#include "Hyperlapser.h"


void Display::onReceivedDataFromSubject(Subject *subject) {
    clear();
    backlight();

    switch (hyper->getCurrentMenu()) {
        case ConstantValues::CHANGE_TIME:
            print("Set time");
            setCursor(0,1);
            print(*list[3]);
            break;
        case ConstantValues::CHANGE_TIME_MULTIPLIER:
            print("Time multiplier");
            setCursor(0,1);
            print(*list[6]);
            break;
        case ConstantValues::START_PROGRAM:
            print("Start program");
            break;
        case ConstantValues::RESET_POSITION:
            print("Reset position");

            break;
        case ConstantValues::SET_START_POSITION:
            print("Start position");
            setCursor(0,1);
            print(*list[4]);
            break;
        case ConstantValues::SET_END_POSITION:
            print("End position");
            setCursor(0,1);
            print(*list[5]);
            break;
        case ConstantValues::SWITCH_START_END:
            print("Switch start end");
            break;
    }
}



Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows) : LiquidCrystal_I2C(lcd_Addr, lcd_cols,
                                                                                           lcd_rows) {
}

void Display::initClass() {
    init();
    backlight();
    print("halko");
}

void Display::setPointerToHyperlapser(Hyperlapser *hyperlapser) {
    hyper = hyperlapser;
}

Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows,Hyperlapser *hyperlapser) : LiquidCrystal_I2C(lcd_Addr, lcd_cols,
                                                                                           lcd_rows) {
    setPointerToHyperlapser(hyperlapser);
}


