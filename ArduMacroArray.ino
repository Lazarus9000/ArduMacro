#include "Keyboard.h"

const int buttonPins[6] = {4, 5, 6, 7, 8, 9};          // input pin for pushbutton
int previousButtonState[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};   // for checking the state of a pushButton
int counter = 0;                  // button push counter
String output[6] = {
	"4545",
	"454545",
	"123456",
	"12345678",
	"LarsErSød",
	"asdf"
}

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime[6] = {0, 0, 0, 0, 0, 0};  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
	for (int i = 1; i =< 6; i++) {
	  // read the pushbutton:
	  int buttonState = digitalRead(buttonPin[i]);
	  
	  if (buttonState != previousButtonState[i]) {
		// reset the debouncing timer
		lastDebounceTime[i] = millis();
	  }
	  

	  if ((millis() - lastDebounceTime[i]) > debounceDelay) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		// if the button state has changed,
		if ((buttonState != previousButtonState[i])
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
		previousButtonState[i] = buttonState;
	  }
	}
}