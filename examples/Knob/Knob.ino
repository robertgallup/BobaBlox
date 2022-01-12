////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Knob
//  
//	CIRCUIT:
//      ___
//     |   |
//     |   |
//     |___|
//  .---------.
//  |         |
//  o----o----o
//  |    |    |
//  |    |    |
//
//  Vcc PIN  GND
//
//
//  DECLARATION:
//
//  Knob myKnob(pin);									// pin is LED pin
//
//  METHODS:
//
//  int value ();											// Returns the current value (0-1023)
//  int value (rangeStart, rangeEnd);	// Returns the current value mapped to the specified range
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED;													// Use the builtin LED
Knob myKnob(1);         							// Knob is connected to Analog pin #1

int blinkDelay;												// The blink delay

// Setup runs once
void setup() {                

}

// Loop repeats forever
void loop() {
  
  // Check the knob value (converted to 0-1000) and use it for the blink delay
  blinkDelay = myKnob.value(0, 1000);
  boardLED.blink(1, blinkDelay);
  
}
