////////////////////////////////////////////
//  
//  EZBlox Example Sketch: Button
//  
//  DECLARATION:
//
//  Button myButton(pin);								// pin = the pin connecting to the button
//
//  METHODS:
//
//  int state ()												// Returns 0 for up, 1 for down
//  boolean isDown ()										// Returns true is button is down, false otherwise
//  boolean isUp ()											// Returns true if button is up, false otherwise
//  boolean wasPressed ()								// Returns true when a button is pressed
//  boolean wasReleased ()							// Returns true when a button is released
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED;														// Use on-board LED
Button myButton(2);											// Button is connected between pin #2 and Ground

// Setup runs once
void setup() {                
}

// Loop repeats forever
void loop() {

  // If the button is down, turn LED on
  if (myButton.isDown()) {
  	boardLED.on();
  } else {
  	boardLED.off();
  }
  
}
