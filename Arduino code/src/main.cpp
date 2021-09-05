#include <Arduino.h>
#include "../lib/Hyperlapser/Hyperlapser.h"

#define commonPin 2
#define upbutton 4
#define downbutton 5
#define confirmbutton 6
int buttonPins[] = {upbutton, downbutton, confirmbutton};
unsigned long lastFire = 0;
Hyperlapser hyperlapser;
Servo servo;


void configureCommon() {
    pinMode(commonPin, INPUT_PULLUP);

    for (int i = 0; i < sizeof(buttonPins) / sizeof(int); i++) {
        pinMode(buttonPins[i], OUTPUT);
        digitalWrite(buttonPins[i], LOW);
    }
}

void configureDistinct() {
    pinMode(commonPin, OUTPUT);
    digitalWrite(commonPin, LOW);

    for (int i = 0; i < sizeof(buttonPins) / sizeof(int); i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void press(int i) { // Our handler
    if (i==0){
        hyperlapser.upButton();
    }    else if (i==1){
        hyperlapser.downButton();

    } else{
        hyperlapser.confirmButton();

    }}
void pressInterrupt() { // ISR
    if (millis() - lastFire < 200) { // Debounce
        return;
    }
    lastFire = millis();

    configureDistinct(); // Setup pins for testing individual buttons

    for (int i = 0; i < sizeof(buttonPins) / sizeof(int); i++) { // Test each button for press
        if (!digitalRead(buttonPins[i])) {
            press(i);
        }
    }

    configureCommon(); // Return to original state
}

void setup() {
    configureCommon(); // Setup pins for interrupt

}

// the loop function runs over and over again forever
void loop() {

}
