#include "Keyboard.h"

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState != previousButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed,
    if ((buttonState != previousButtonState)
        // and it's currently pressed:
        && (buttonState == HIGH)) {
      // increment the button counter
      counter++;
      // type out a message
      Keyboard.print("You pressed the button ");
      Keyboard.print(counter);
      Keyboard.println(" times.");
    }
    // save the current button state for comparison next time:
    previousButtonState = buttonState;
  }
}