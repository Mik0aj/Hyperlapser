//
// Created by mikoaj on 06.09.2021.
//

#ifndef ARDUINO_CODE_DISPLAY_H
#define ARDUINO_CODE_DISPLAY_H

#include <Arduino.h>
#include "Observer.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Display : public LiquidCrystal_I2C, Observer {
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
public:
    Display(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);;

    void onReceivedDataFromSubject(const Subject *);

    void initClass();
};


#endif //ARDUINO_CODE_DISPLAY_H
