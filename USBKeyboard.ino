/*
 USB Keyboard
 For the Arduino Leonardo and Micro.
 Sends a defined text string when a button is pressed.
 The circuit: pushbutton attached from pin x to GND
 Copyright (c) 2017 Rok Rodič alias Hacker007 alias GreenEyedExplorer, http://www.rodic.si, The MIT License (MIT)
 See: http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

#include "Keyboard.h"
#include "Bounce2.h"

const int buttonPin1 = 7;
const int buttonPin2 = 5;
const int buttonPin3 = 3;
int previousButtonState1 = HIGH;
int previousButtonState2 = HIGH;
int previousButtonState3 = HIGH;

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  debouncer1.attach(buttonPin1); debouncer1.interval(50);
  debouncer2.attach(buttonPin2); debouncer2.interval(50);
  debouncer3.attach(buttonPin3); debouncer3.interval(50);
  Keyboard.begin();
}

void loop() {
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  //int val1 = debouncer1.read();
  int val2 = debouncer2.read();
  int val3 = debouncer3.read();
  
  if (debouncer1.fell()) { Keyboard.print(" "); } 
  //if (debouncer2.fell()) { Keyboard.press(KEY_UP_ARROW); delay(1); Keyboard.release(KEY_UP_ARROW); }
  //if (debouncer3.fell()) { Keyboard.press(KEY_DOWN_ARROW); delay(1); Keyboard.release(KEY_DOWN_ARROW); }
  if (val2==LOW) { Keyboard.press(KEY_UP_ARROW); delay(10); Keyboard.release(KEY_UP_ARROW); }
  if (val3==LOW) { Keyboard.press(KEY_DOWN_ARROW); delay(10); Keyboard.release(KEY_DOWN_ARROW); }

  delay(25); //25=4rows 35=
}

