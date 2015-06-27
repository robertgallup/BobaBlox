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
//  5V  PIN  GND
//
//
//  DECLARATION:
//
//  Knob myKnob(pin)	// pin is LED pin
//
//  METHOD:
//
//  void value ();	// Returns the current knob value (0-1023)
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED(1);        // Declare an LED on pin #1
Knob myKnob(1);         // Knob is connected to Analog pin #1 (digital pin #2)

int knobValue;          // The knob value
int blinkDelay;		// The blink delay

// Setup runs once
void setup() {                

}

// Loop repeats forever
void loop() {
  
  // Check the knob value
  // Convert the value (0-1023) to a 0-1 second delay (0-1000).
  // Note: see the Map command reference
  knobValue = myKnob.value();
  blinkDelay = map(knobValue, 0, 1023, 0, 1000);
  boardLED.blink(1, blinkDelay);
  
}