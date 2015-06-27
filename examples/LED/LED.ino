////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: LED
//  
//  DECLARATION:
//
//  LED myLED(pin)				// pin is LED pin
//
//  METHODS:
//
//  void on ();
//  void off ();
//  void set (state);				// Sets LED on if state is greater than zero
//  void blink ();				// Blinks LED once with default 250ms on and off
//  void blink (n);				// Blinks n times with default blink delay
//  void blink (n, delay);			// Blinks n times with specific delay
//  void blink (n, delayON, delayOFF);		// Blinks n times with delayON and delayOFF
//  void setBrightness (brightness);		// On an Analog Output (PWM) pin, sets LED brightness (0-255)
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED(1);

// Setup runs once
void setup() {                
}

// Loop repeats forever
void loop() {

  // Blinks LED. Uncomment one of the blinks below
  // Uncomment one of the lines below for it's effect
  boardLED.blink();
  // boardLED.blink(1, 100);
  // boardLED.blink(1, 20, 250);


}
