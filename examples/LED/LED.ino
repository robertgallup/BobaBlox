////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: LED
//  
//  LED Type:
//
//  LED myLED(pin)			// pin is LED pin
//
//  LED Methods:
//
//  void on ();
//  void off ();
//  void set (state);					// Sets LED on if state is greater than zero
//  void blink ();						// Blinks LED once with default 250ms on and off
//  void blink (n);						// Blinks n times with default blink delay
//  void blink (n, delay);				// Blinks n times with specific delay
//  void blink (n, delayON, delayOFF);	// Blinks n times with delayON and delayOFF
//  void setBrightness (brightness);	// On a PWM pin, sets brightness of LED (0-255)
//
////////////////////////////////////////////

// Include libraries
#include <BobaBlox.h>

// Declarations
LED boardLED(1);

// Setup runs once at the beginning
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
