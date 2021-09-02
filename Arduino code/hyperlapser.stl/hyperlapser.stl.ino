#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos = 0;
int newPos=0;
int upButton = 10;
int downButton = 11;
int selectButton = 12;
int menu = 1;
int timeMenu=1;
int time=3;
int mode =1;
Servo servo;
bool running=false;
float  interval;
unsigned long previousMillis = 0;        // will store last time LED was updated

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin();
  lcd.backlight();
  servo.attach(8, 500, 2500);
    servo.write(pos);  
  updateMenu();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  Serial.begin(9600); // open the serial port at 9600 bps:

}

void loop() {
  unsigned long currentMillis = millis();

  if(running){
 
  if (currentMillis - previousMillis >= interval*1000) {


    // save the last time you blinked the LED
    previousMillis = currentMillis;
    pos+=1;
  servo.write(pos);  
     lcd.clear();
  lcd.print("current pos ");
    lcd.print(pos);
  }
 
  }

  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    while (!digitalRead(selectButton));
  } 
}
void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
  }
}

int chooseNumber(){
  switch (menu) {
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 11;
      break;
  }
}


void action1() {
  String newTime=String(time);
  updateTimeMenu(newTime);
  while(true){
   if (!digitalRead(downButton)){
    timeMenu--;
    updateTimeMenu(newTime);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    timeMenu++;
    updateTimeMenu(newTime);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
        // if time menu == 11 break while loop

    if(timeMenu==11){
      break;
    }    // if time menu == 10 delete last number don't concat anything

    else if(timeMenu==10){
      newTime.remove(newTime.length()-1);
        updateTimeMenu(newTime);
    }
    else{
       newTime.concat(timeMenu);
    updateTimeMenu(newTime);
    }
 
    while (!digitalRead(selectButton));
  } 
  }
  time=newTime.toInt();
}
void action2() {
    if (mode==0){
    mode=1;
  }
  else{
    mode=0;
  }
  
}
void action3() {
  lcd.clear();
  lcd.print(">Starting");
  running=!running;
   int timeMultiplier;
        if (mode==0){
    timeMultiplier=1;
  }
  else{
    timeMultiplier=60;
  }
  interval=time*timeMultiplier/180;
 lcd.setCursor(0, 1);
  lcd.print("interval ");
  lcd.print(interval);

delay(500);
}

String whatMode(){
  if (mode==0){
    return "sec";
  }
  else{
    return "min";
  }
  
}


void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Time = ");
      lcd.print(time);
      lcd.setCursor(0, 1);
      lcd.print("Set mode ");
      lcd.print(whatMode());
      break;
    case 2:
      lcd.clear();
      lcd.print(">Set mode ");
      lcd.print(whatMode());
      lcd.setCursor(0, 1);
      lcd.print("Start program");
      break;
    case 3:
      lcd.clear();
      lcd.print(">Start program");
      lcd.setCursor(0, 1);
      lcd.print("Stop");
      break;
    case 4:
      menu = 3;
      break;
  }
}
void updateTimeMenu(String current) {
  lcd.clear();
  lcd.print("Setting time");
  lcd.setCursor(0, 1);
  lcd.print(current);
  lcd.print(">");
  switch(timeMenu){
    case -1:
    timeMenu=11;
    lcd.print("confirm");
    break;
    case 10:
    lcd.print("remove");
    break;
    case 11:
    lcd.print("confirm");
    break;
    case 12:
    timeMenu=0;
    lcd.print(timeMenu);
    break;
    default:
    lcd.print(timeMenu);
    break;
  }

}
 
