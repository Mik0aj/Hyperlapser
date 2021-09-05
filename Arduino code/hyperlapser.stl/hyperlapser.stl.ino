#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos = 0;
int newPos = 0;
int upButton = 10;
int downButton = 11;
int selectButton = 12;
int menu = 1;
int numberMenu = 1;
int time = 360;
int mode = 1;
Servo servo;
bool running = false;
float  interval;
unsigned long previousMillis = 0;
int startPos = 150;
int finishPos = 180;
void setup() {
  lcd.begin();
  lcd.backlight();
  servo.attach(8, 500, 2500);
  servo.write(pos);
  updateMenu();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
}
void calculateMovement() {
  if (pos == finishPos) {
    running = false;
  }
  else if (startPos > finishPos) {
    pos -= 1;
  }
  else if (startPos < finishPos) {
    pos += 1;
  }
  servo.write(pos);
}

void loop() {
  unsigned long currentMillis = millis();
  if (running) {
    if (currentMillis - previousMillis >= interval * 1000) {
      previousMillis = currentMillis;
      calculateMovement();
      lcd.clear();
      lcd.print("current pos ");
      lcd.print(pos);
      lcd.setCursor(0, 1);
      lcd.print("at interval ");
      lcd.print(interval);
    }
  }
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    while (!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)) {
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
    case 4:
      action4();
      break;
    case 5:
      action5();
      break;
    case 6:
      action6();
      break;
    case 7:
      action7();
      break;
  }
}

int chooseNumber(int number) {
  String newNumber = String(number);
  updateNumberMenu(newNumber);
  while (true) {
    if (!digitalRead(downButton)) {
      numberMenu--;
      updateNumberMenu(newNumber);
      while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton)) {
      numberMenu++;
      updateNumberMenu(newNumber);
      while (!digitalRead(upButton));
    }
    if (!digitalRead(selectButton)) {

      // if time menu == 11 break while loop

      if (numberMenu == 11) {
        break;
      }    // if time menu == 10 delete last number don't concat anything

      else if (numberMenu == 10) {
        newNumber.remove(newNumber.length() - 1);
        updateNumberMenu(newNumber);
      }
      else {
        newNumber.concat(numberMenu);
        updateNumberMenu(newNumber);
      }

      while (!digitalRead(selectButton));
    }
  }
  number = newNumber.toInt();
  return number;
}

void action1() {
  time = chooseNumber(time);
}
void action2() {
  if (mode == 0) {
    mode = 1;
  }
  else {
    mode = 0;
  }

}
void action3() {
  lcd.clear();
  lcd.print(">Starting");
  running = !running;
  int timeMultiplier;
  if (mode == 0) {
    timeMultiplier = 1;
  }
  else {
    timeMultiplier = 60;
  }
  resetPos();
  interval = time * timeMultiplier / abs(finishPos - startPos); // absolute value in case when finish is larger than start
  lcd.setCursor(0, 1);
  lcd.print("interval ");
  lcd.print(interval);
}

void action4() {
  resetPos();
}
void action5() {
  startPos = chooseNumber(startPos);
  verifyPos();
}
void action6() {
  finishPos = chooseNumber(finishPos);
  verifyPos();
}
void action7() {
  int temp = startPos;
  startPos = finishPos;
  finishPos = temp;
  resetPos();
}

void resetPos() {
  servo.write(startPos);
  lcd.clear();
  lcd.print("Reseting pos");
  lcd.setCursor(0, 1);
  pos = startPos;
  delay(1000); // no way of reading servo's position so i just delay

}
String whatMode() {
  if (mode == 0) {
    return "sec";
  }
  else {
    return "min";
  }

}
void verifyPos() {
  if (startPos < 0) {
    startPos = 0;
  }
  else if (startPos > 180) {
    startPos = 180;
  }
  else if (finishPos < 0) {
    finishPos = 180;
  }
  else if (finishPos > 180) {
    finishPos = 180;
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
      lcd.print("Reset ");
      break;
    case 4:
      lcd.clear();
      lcd.print(">Reset");
      lcd.setCursor(0, 1);
      lcd.print("Start pos ");
      lcd.print(startPos);
      break;
    case 5:
      lcd.clear();
      lcd.print(">Start pos ");
      lcd.print(startPos);
      lcd.setCursor(0, 1);
      lcd.print("Finish pos ");
      lcd.print(finishPos);
      break;
    case 6:
      lcd.clear();
      lcd.print(">Finish pos ");
      lcd.print(finishPos);
      lcd.setCursor(0, 1);
      lcd.print("Switch positions");
      break;
    case 7:
      lcd.clear();
      lcd.print("Finish pos ");
      lcd.print(finishPos);
      lcd.setCursor(0, 1);
      lcd.print(">Switch positions");
      break;
    case 8:
      menu = 7;
  }
}
void updateNumberMenu(String current) {
  lcd.clear();
  lcd.print("Choose number");
  lcd.setCursor(0, 1);
  lcd.print(current);
  lcd.print(">");
  switch (numberMenu) {
    case -1:
      numberMenu = 11;
      lcd.print("confirm");
      break;
    case 10:
      lcd.print("remove");
      break;
    case 11:
      lcd.print("confirm");
      break;
    case 12:
      numberMenu = 0;
      lcd.print(numberMenu);
      break;
    default:
      lcd.print(numberMenu);
      break;
  }

}
