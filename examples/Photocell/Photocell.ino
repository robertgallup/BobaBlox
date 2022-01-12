////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Photocell
//
//	CIRCUIT:
//
//  [Photocell] [10K OHMS]
//
//       //
//  o---[==]---o---[~~~]---o
//  |          |           |
//  |          |           |
//
//  Vcc       PIN         GND
//
//  Note: Resistor value depends on your Photocell
//
//  DECLARATION:
//
//  Photocell cell(pin);							// Middle pin in above circuit
//
//  METHODS:
//
//  int value ();				  						// Returns the current value (0-1023)
//  int value (rangeStart, rangeEnd);	// Returns the current value mapped to the specified range
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED;													// Use the builtin LED
Photocell cell(1);      							// Photocell "pin" is connected to Analog pin #1

int blinkDelay;         							// This will hold the blink delay

// Setup runs once
void setup() {                
}

// Loop repeats forever
void loop() {
  
  // Check the photocell value (converted to 0-1000) and use it for the blink delay
  blinkDelay = cell.value(0, 1000);
  boardLED.blink(1, blinkDelay);
  
}
