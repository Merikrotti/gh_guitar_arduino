#include <Joystick.h>


Joystick_ Joystick;

/* Pin layout

Keys [5-9]:
  Orange 5
  Blue 6
  Yellow 7
  Red 8
  Green 9

Menu [2-4]:
  Home 4
  Start 3
  Select 2

DPAD:
  Left 15
  Right 14

Strum
  Up 10
  Down 16

Whammy A3

*/

//Whammy settings
int whammyOffset = 0;
int whammyTolerance = 15;
int whammyStart = -100;

//Keys
const int orange = 5;
const int blue = 6;
const int yellow = 7;
const int red = 8;
const int green = 9;

//Whammy, strum
const int whammy = A3;
const int up = 10;
const int down = 16;

//Menu
const int home = 4;
const int start = 3;
const int select = 2;
const int left = 15;
const int right = 14;


int buttonStates[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int buttonMapping[12] = {green, red, yellow, blue, orange, up, down, home, start, select, left, right};

void setup() {
  pinMode(green, INPUT_PULLUP);
  pinMode(red, INPUT_PULLUP);
  pinMode(yellow, INPUT_PULLUP);
  pinMode(blue, INPUT_PULLUP);
  pinMode(orange, INPUT_PULLUP);

  pinMode(home, INPUT_PULLUP);
  pinMode(start, INPUT_PULLUP);
  pinMode(select, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);

  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  
  Joystick.setYAxisRange(-100, 100);
  Joystick.begin();
  Serial.begin(9600);
}

void loop() {
  
  int currentWhammyValue = analogRead(whammy);
  float mappedValue = map(currentWhammyValue + whammyOffset, 0, 1023, -100, 100);
  
  if(mappedValue >= whammyStart + whammyTolerance) {
    Joystick.setYAxis(mappedValue);
    Serial.println(mappedValue);
  } else {
    Joystick.setYAxis(whammyStart);
  }

  for(int i = 0; i<12;i++) {

    int currentState = !digitalRead(buttonMapping[i]);
    if (buttonStates[i] != currentState) {
      switch(i) {
        case 0:
          Joystick.setButton(1, currentState);
          break;
        case 1:
          Joystick.setButton(2, currentState);
          break;
        case 2:
          Joystick.setButton(3, currentState);
          break;
        case 3:
          Joystick.setButton(4, currentState);
          break;
        case 4:
          Joystick.setButton(5, currentState);
          break;
        case 5:
          Joystick.setButton(6, currentState);
          break;
        case 6:
          Joystick.setButton(7, currentState);
          break;
        case 7:
          Joystick.setButton(8, currentState);
          break;
        case 8:
          Joystick.setButton(9, currentState);
          break;
        case 9:
          Joystick.setButton(10, currentState);
          break;
        case 10:
          Joystick.setButton(11, currentState);
          break;
        case 11:
          Joystick.setButton(12, currentState);
          break;
      }
    }
    buttonStates[i] = currentState;
  }
}
