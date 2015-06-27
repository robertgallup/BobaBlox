////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Button
//  
//  DECLARATION:
//
//  Button myButton(pin)		// pin = the pin connecting to the button
//
//  METHODS:
//
//  int state ()			// Returns 0 for up, 1 for down
//  boolean isDown ()			// Returns true is button is down, false otherwise
//  boolean isUp ()			// Returns true if button is up, false otherwise
//  boolean wasPressed ()		// Returns true when a button is pressed
//  boolean wasReleased ()		// Returns true when a button is released
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
LED boardLED(1);			// Use on-board LED
Button myButton(2);			// Button is connected between pin #2 and Ground

// Setup runs once
void setup() {                
}

// Loop repeats forever
void loop() {

  if (myButton.isDown()) {
  	boardLED.on();
  } else {
  	boardLED.off();
  }

// To reverse the logic (light is on with up):
// Uncomment the following lines (and comment the lines above)

// if (myButton.isUp()) {
// 	boardLED.on();
// } else {
// 	boardLED.off();
// }

// Blink when button is pressed:

// if (myButton.isDown()) {
// 	boardLED.blink(1, 30, 70);
// }

}
