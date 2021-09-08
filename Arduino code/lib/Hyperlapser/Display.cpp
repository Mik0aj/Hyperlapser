//
// Created by mikoaj on 06.09.2021.
//

#include "Display.h"


void Display::onReceivedDataFromSubject(Subject *subject) {
    int **list=subject->getValues();
    Serial.println("display");
    Serial.print(*list[0]);
    Serial.print(*list[1]);
    print(*list[0]);
    print(*list[1]);

}

Display::Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows) : LiquidCrystal_I2C(lcd_Addr, lcd_cols,
                                                                                           lcd_rows) {
}

void Display::initClass() {
    init();
    backlight();
    print("halko");
}


