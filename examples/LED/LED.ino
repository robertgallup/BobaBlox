////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: LED
//  
//  DECLARATION:
//
//  LED myLED;																// Uses LED_BUILTIN pin
//  LED myLED(pin);														// Set LED on specific pin
//
//  METHODS:
//
//  void on ();
//  void off ();
//  void set (state);													// Sets LED on if state is greater than zero
//  void blink ();														// Blinks LED once with default 250ms on and off
//  void blink (n);														// Blinks n times with default blink interval
//  void blink (n, time);											// Blinks n times with specific interval
//  void blink (n, timeON, timeOFF);					// Blinks n times with intervalON and intervalOFF
//  void setBrightness (brightness);					// On an Analog Output (PWM) pin, sets LED brightness (0-255)
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED;																	// Use the builtin LED

// Setup runs once
void setup() {
}

// Loop repeats forever
void loop() {

	// Blink the LED on/off
	boardLED.blink();

}
