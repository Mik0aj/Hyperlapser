//
// Created by mikoaj on 04.09.2021.
//
#include <Arduino.h>
#include "InteruptMultiplexer.h"

InteruptMultiplexer::InteruptMultiplexer(int *pinArray,int pinArraySize,int commonPin){
    InteruptMultiplexer::pinArray=pinArray;
    InteruptMultiplexer::pinArraySize=pinArraySize;
    InteruptMultiplexer::commonPin=commonPin;
    attachInterrupt(digitalPinToInterrupt(commonPin), pressInterrupt, FALLING);
}

int *InteruptMultiplexer::givePinArray() {
    return pinArray;
}

void InteruptMultiplexer::press(int i) {
    Serial.println(i);
}

 void InteruptMultiplexer::pressInterrupt() {
    if (millis() - lastFire < 200) { // Debounce
        return;
    }
    lastFire = millis();
    configureDistinct(); // Setup pins for testing individual buttons
    for (int i = 0; i < pinArraySize; i++) { // Test each button for press
        if (!digitalRead(pinArray[i])) {
            press(i);
        }
    }
    configureCommon(); // Return to original state
}

void InteruptMultiplexer::configureCommon() {
    pinMode(commonPin, INPUT_PULLUP);
    for (int i = 0; i < pinArraySize; i++) {
        pinMode(pinArray[i], OUTPUT);
        digitalWrite(pinArray[i], LOW);
    }
}
void InteruptMultiplexer::configureDistinct() {
    pinMode(commonPin, OUTPUT);
    digitalWrite(commonPin, LOW);
    for (int i = 0; i < pinArraySize; i++) {
        pinMode(pinArray[i], INPUT_PULLUP);
    }
}
