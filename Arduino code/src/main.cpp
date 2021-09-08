#include <Arduino.h>
#include <Servo.h>
#include <Hyperlapser.h>
#include "Display.h"

const int BAUD_RATE = 9600;
const int COMMON_PIN = 2;
const int UP_BUTTON = 4;
const int DOWN_BUTTON = 5;
const int CONFIRM_BUTTON = 6;
unsigned long lastFire = 0;
Hyperlapser hyperlapser;
Display display(0x27, 16, 2);

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
    pinMode(CONFIRM_BUTTON, INPUT_PULLUP);
    display.initClass();
    hyperlapser.registerObserver(&display);
}

// the loop function runs over and over again forever
void loop() {
    if (millis() - lastFire > 200) { // Debounce
        if (!digitalRead(UP_BUTTON)) {
            hyperlapser.upButton();
        }
        if (!digitalRead(DOWN_BUTTON)) {
            hyperlapser.downButton();
        }
        if (!digitalRead(CONFIRM_BUTTON)) {
            hyperlapser.confirmButton();
        }
        lastFire = millis();
    }
    delay(3000);
    hyperlapser.notify();
    hyperlapser.setCurrentMenu(1);
}