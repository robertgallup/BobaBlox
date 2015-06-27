////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Speaker
//  
//  DECLARATIONS:
//
//  Speaker mySpeaker(pin)				// One speaker is pin, the other is ground
//  Speaker mySpeaker(pin1,pin2)			// Speaker is connected between Pin1 and Pin2 (doubles the volume)
//
//  METHODS:
//
//  void beep (frequency, length, color);		// Beeps speaker at frequency (positive int) for length (millis). Color is 0.0 - 1.0
//  void tone (frequency, color);			// Runs tone continuously at frequency and color (must be called at top level of loop)
//  void start ();					// Starts tone (if it's been stopped)
//  void stop ();					// Stops the tone
//  void frequency ();					// Returns the last set frequency
//  void color ();					// Returns the last color
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Declarations
Speaker piezo(2);       // Declare a speaker using digital pin #2

// Setup runs once
void setup() {                
}

// Loop repeats forever
void loop() {
  
  // Sweep frequency from 50 to 6000 in steps of 50Hz
  int freq;
  for (freq=50; freq<=6000; freq=freq+50) {
    piezo.beep(freq, 200);
    delay (100);
  }
  
}
