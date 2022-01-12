////////////////////////////////////////////
//  
//  BobaBlox Example Sketch: Timer
//  
//  DECLARATIONS:
//
//  Timer ()						// Timer with default time (1000ms)
//  Timer (time)				// Timer with time in milliseconds
//
//  METHODS:
//
//  void setTime (unsigned long);							// Sets timer interval (and, stops running timer)
//  void setTimeMicros (unsigned long);				// Sets timer interval (microseconds)
//  unsigned long getTime();									// Gets timer interval
//  unsigned long getTimeMicros();						// Gets timer interval (microseconds)
//  unsigned long getTimeRemaining();					// Gets time remaining
//  unsigned long getTimeRemainingMicros();		// Gets time remaining (microseconds)
//  void start ();														// Starts timer
//  void restart ();													// Restarts timer
//  boolean isExpired ();											// True if timer is expired
//
////////////////////////////////////////////

#include <BobaBlox.h>

// Constants
unsigned long timerInterval = 500UL;					// Blink interval

// Declarations
LED onboardLED(LED_BUILTIN);									// Built-in LED
Timer timer(timerInterval);										// Timer with 1/2 second time					

// Setup runs once
void setup() {
  // Start the timer
  timer.start();
}

// Loop repeats forever
void loop() {
  
	// When the timer expires, toggle the LED and restart the timer
  if (timer.isExpired()) {
    onboardLED.toggle();
    timer.restart();
  }

}
