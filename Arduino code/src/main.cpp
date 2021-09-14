#include <Arduino.h>
#include <Hyperlapser.h>
#include "Display.h"
#include "Servo.h"


const int BAUD_RATE = 9600;
const int UP_BUTTON = 4;
const int DOWN_BUTTON = 5;
const int CONFIRM_BUTTON = 6;
const int BUTTON_ARRAY[] = {UP_BUTTON, DOWN_BUTTON, CONFIRM_BUTTON};
Servo servo;
void (Hyperlapser::*functions[])() ={&Hyperlapser::upButton, &Hyperlapser::downButton, &Hyperlapser::confirmButton};
unsigned long lastButtonClick = 0;
unsigned long lastServoMove = 0;
Hyperlapser hyperlapser;
Display display(0x27, 16, 2, &hyperlapser);

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
    pinMode(CONFIRM_BUTTON, INPUT_PULLUP);
    display.initClass();
    hyperlapser.registerObserver(&display);
    servo.attach(8, 500, 2500);
    hyperlapser.setServo(&servo);
}

// the loop function runs over and over again forever
void loop() {
    if (millis() - lastButtonClick > 200) { // Debounce
        for (int i = 0; i < 3; i++) {
            if (!digitalRead(BUTTON_ARRAY[i])) {
                (hyperlapser.*functions[i])();
            }
        }
        lastButtonClick = millis();
    } else if (millis() - lastServoMove >= hyperlapser.getInterval() * 1000 && hyperlapser.isRunning()) {
        lastServoMove = millis();
        hyperlapser.moveServo();
    }
}
