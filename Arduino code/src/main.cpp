#include <Arduino.h>
#include <Servo.h>
#include <Hyperlapser.h>
#include "Display.h"


const int BAUD_RATE = 9600;
const int COMMON_PIN = 2;
const int UP_BUTTON = 4;
const int DOWN_BUTTON = 5;
const int CONFIRM_BUTTON = 6;
const int BUTTON_ARRAY[]={UP_BUTTON,DOWN_BUTTON,CONFIRM_BUTTON};
void (Hyperlapser::*functions[])()={&Hyperlapser::upButton,&Hyperlapser::downButton,&Hyperlapser::confirmButton};
unsigned long lastFire = 0;
int test=1;
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
    if(test==5)test=1;
    if (millis() - lastFire > 200) { // Debounce
        for(int i=0;i<3;i++){
            if (!digitalRead(BUTTON_ARRAY[i])) {
                (hyperlapser.*functions[i])();
            }
        }
        lastFire = millis();
    }
}