//
// Created by mikoaj on 06.09.2021.
//

#ifndef ARDUINO_CODE_DISPLAY_H
#define ARDUINO_CODE_DISPLAY_H

#include <Arduino.h>
#include "Observer.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Subject.h"
#include "Hyperlapser.h"


class Display : public LiquidCrystal_I2C, public Observer {
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
    Hyperlapser *hyper;
    int **list;
public:
    Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
    Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows,Hyperlapser *hyperlapser);

    void setPointerToHyperlapser(Hyperlapser *hyper);

    void onReceivedDataFromSubject(Subject *subject);

    void initClass();

    void DisplayMenuState();

    int WhatState();

    void DisplayChooseMenuState();
};


#endif //ARDUINO_CODE_DISPLAY_H
