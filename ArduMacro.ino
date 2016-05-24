#include "Keyboard.h"

const int buttonPins[6] = {2, 3, 4, 5, 6, 7};          // input pin for pushbutton
int previousButtonState[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};   // for checking the state of a pushButton
boolean pressed[6] = {false, false, false, false, false, false};
int counter = 0;                  // button push counter
String output[6] = {
  "4545",
  "454545",
  "123456",
  "12345678",
  "LarsErSoed",
  "asdf"
};

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime[6] = {0, 0, 0, 0, 0, 0};  // the last time the output pin was toggled
long debounceDelay = 100;    // the debounce time; increase if the output flickers
int keyboardDelay = 100;
void setup() {
  for (int i = 0; i < 6; i++) {
    // make the pushButton pin an input:
    pinMode(buttonPins[i], INPUT);
  }
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < 6; i++) {
    // read the pushbutton:
    int buttonState = digitalRead(buttonPins[i]);
    
    if (buttonState != previousButtonState[i]) {
      // reset the debouncing timer
      lastDebounceTime[i] = millis();
      pressed[i] = false;
    }
    

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:
      // if the button state has changed,
      if //((buttonState != previousButtonState[i])
      // and it's currently pressed:
      //&& 
      (buttonState == HIGH)//) 
      {
        if (!pressed[i]) {
          for (int j = 0; j < output[i].length(); j++) {
            Keyboard.println(output[i].charAt(j));
            delay(keyboardDelay);
          }
          Keyboard.write(KEY_RETURN);
          pressed[i] = true;
        }
      }
      
    }
    // save the current button state for comparison next time:
    previousButtonState[i] = buttonState;
  }
}
