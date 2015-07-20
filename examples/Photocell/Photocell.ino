////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Photocell
//
//	CIRCUIT:
//
//  [Photocell] [10K OHMS]
//
//       //
//  o---[==]---o---/\/\/---o
//  |          |           |
//  |          |           |
//
//  5V        PIN         GND
//
//  Note: Resistor value depends on your Photocell
//
//  DECLARATION:
//
//  Photocell cell(pin)		// Middle pin in above circuit
//
//  METHOD:
//
//  int value ();				  // Returns the current value (0-1023)
//  int value (int rangeStart, int rangeEnd)	// Returns the current value mapped to range specified
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED(1);        	// Declare an LED on pin #1
Photocell cell(1);      	// Knob is connected to Analog pin #1 (digital pin #2)

int cellValue;          	// This will hold the knob value
int blinkDelay;         	// This will hold the blink delay

// Setup runs once
void setup() {                

}

// Loop repeats forever
void loop() {
  
  // Check the photocell value
  // Convert the value (0-1023) to a 0-1 second delay (0-1000).
  // Note: see the Map command reference
  cellValue = cell.value();
  blinkDelay = map(cellValue, 0, 1023, 0, 1000);
  boardLED.blink(1, blinkDelay);
  
}