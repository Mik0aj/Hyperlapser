//
// Created by mikoaj on 06.09.2021.
//

#include "Display.h"


void Display::onReceivedDataFromSubject(Subject *subject) {
    hyperlapser=subject;
    this->print(subject->getValues());
}

Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows) : LiquidCrystal_I2C(lcd_Addr, lcd_cols,
                                                                                           lcd_rows) {
}

void Display::initClass() {
    this->init();
    this->backlight();
    this->print("halko");
}


