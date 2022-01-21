# BobaBlox Library Documentation  

```
Version:    2.1.0
Author:	    Robert Gallup
Date: 	    1/11/2022
```



## BobaBlox Overview

BobaBlox is an Arduino library that makes it easier to sketch code for basic hardware components. I've found while teaching Arduino workshops, the repetitiveness of typing multiple commands just to make an LED blink can get in the way of learning overall programming concepts. So, I developed BobaBlox. It should work with all standard Arduino boards, including variants such as the Adafruit Trinket.

Here's an example using BobaBlox in the standard blink example. First, standard blink from Arduino examples:

    void setup() {
        pinMode (13, OUTPUT);            // Define pin 13 as an output pin
    }
    
    void loop() {
        digitalWrite (13, HIGH);         // Turn the LED on
        delay (500);                     // Delay for 500 milliseconds
        digitalWrite (13, LOW);          // Turn the LED off
        delay (500);                     // Delay for 500 milliseconds
    }

When this is written using BobaBlox, it becomes:

	#include <BobaBlox.h>            // Include the BobaBlox library
	
	LED light(13);                   // Define the LED on pin 13
	 
	void setup() {}                  // No extra setup statements required
	void loop () {
	  light.blink();                 // Each time through the loop, blink the LED on/off
	}

Notice that there's no need to type digitalWrite/Delay twice. Also, setup() is empty. The only statement needed, is a "blink" command in loop().

The same pattern holds true for the other elements in BobaBlox: Button, Knob, Photocell, Speaker and Timer. You can find out more in the following documentation. Also, see the example BobaBlox sketches for working samples.

## Installation

The library is installed like other Arduino libraries. You can download a zip of the library and install it using Sketch > Include Library > Add .ZIP Library ... . BobaBlox should also be available in the Arduino Library Manager. Install using the Library Manger by choosing: Sketch > Include Library > Manage Libraries ... . Then, search for and select BobaBlox.


## BobaBlox Object Reference

### LED

LED's are connected between an Arduino pin and ground, typically with a resistor in series.

##### Declaration

    LED led_name(pin);

*led_name* is the name of the LED variable being declared.  
*pin* is the number of the pin being used for the LED.

#### Methods

    void on ();                             // Turns the LED off
    void off ();                            // Turns the LED on
    void set (state);                       // Sets LED on if state is greater than zero
    void toggle();                          // Toggles the LED on and off
    void blink ();                          // Blinks LED once with default 250ms on and off
    void blink (n);                         // Blinks n times with default blink delay
    void blink (n, delay);                  // Blinks n times with specific delay
    void blink (n, delayON, delayOFF);      // Blinks n times with delayON and delayOFF
    void setBrightness (brightness);        // On a PWM  pin, sets LED brightness (0-255)   

- - -
### Button

Buttons are connected between a pin and ground. The internal pull-up resistor is used, so no other external components are required.

#### Declaration

    Button button_name(pin);

*button_name* is name of the button variable being declared.  
*pin* is the number of the pin being used for the button. Its mode will be set to *input_pullup*.

#### Methods

    int state ()                            // Returns 0 for up, 1 for down
    boolean isDown ()                       // Returns true is button is down, false otherwise
    boolean isUp ()                         // Returns true if button is up, false otherwise
    boolean wasPressed ()                   // Returns true when a button is pressed
    boolean wasReleased ()                  // Returns true when a button is released


***Notes:***

The Button methods use basic debouncing, but may have difficulties with "noisy" buttons. Also, *wasPressed()* and *wasReleased()* are more responsive the more frequently they are called. In a simple loop without a lot of *delay()* calls, it should be reasonably responsive.

   

- - -
### Knob

Knobs are potentiometers. This element assumes that the "outside" leads of the Knob are connected to *ground* and *V+*, respectively. The center lead is connected to an analog Input pin.

#### Declaration

    Knob knob_name(pin);

*knob_name* is name of the knob variable being declared.  
*pin* is the number of the analog pin being used to connect to the center lead of the Knob.

#### Methods

    int value ();                               // Returns the current value (0-1023)
    int value (int rangeStart, int rangeEnd)    // Returns value mapped to specified range

***Notes:***

Potentiometers return values from 0 to 1023 on the 10-bit Arduino analog to digital convertor (ADC). However, the range for setting the brightness of an LED, for example, is 0-255. Often, this is change in range is accomplished by using the *map()* function. However *map()* can be a bit complicated to understand. The version of *value()* that allows you to specify the range, does the mapping automatically and is more straightforward.

   

- - -
### Photocell

Photocells are identical to Knobs in implementation. This element assumes that the one lead from the photocell is connected to *V+*. The other lead is connected to *ground* through a series resistor. The point where the photocell and series resistor are joined is connected to an Analog Input pin.

#### Declaration

    Photocell photocell_name(pin);

*photocell_name* is name of the Photocell variable being declared.  
*pin* is the number of the pin being used for the photocell.

#### Methods

    int value ();                               // Returns the current value (0-1023)
    int value (int rangeStart, int rangeEnd)    // Returns value mapped to specified range

***Notes:***
*
The notes from the Knob section apply here.

   

- - -
### Speaker

In standard Arduino, speakers can be controlled using the tone() method. This is not available on the Trinket. So, the Speaker object implements related ways to make sound using one or two pins (see notes, below).

#### Declaration

    Speaker speaker_name(pin);                  // One speaker is pin, the other is ground
    Speaker speaker_name(pin1,pin2);            // Speaker is connected between Pin1 and Pin2

***Notes:***

Often, a speaker is connected between one Arduino pin and ground. However, in the case of a Piezo, this can result in barely-audible audio. One technique to increase volume is to connect the speaker across two pins. This will drive the Piezo both positive and negative (rather than positive, then zero for a one-pin connection). This is handled by BobaBlox and results in double the volume.

#### Methods

    void beep (frequency, length, color);       // Beeps at frequency for length with color
    void tone (frequency, color);               // Continuous tone at frequency and color
    void start ();                              // Starts tone (if it's been stopped)
    void stop ();                               // Stops the tone (if its running)
    void frequency ();                          // Returns the last set frequency
    void color ();                              // Returns the last color

***Notes:***

*frequency* is the pitch of a tone. It is a positive integer.  
*length* is in milliseconds.  
*color* refers to the nature" of the sound. It will change with values from 0.0 - 1.0

*beep()* is just like the tone() Arduino function. It will pause the loop while the sound is playing.
*tone()* plays a tone continuously, monitoring it as the function is called repeatedly in *loop()*. In order for tone() to be effective, it must be called frequently at the top level of *loop()*.

   

- - -
### Timer

Sometimes in programming, you want to have timed actions that do not delay the main loop between actions. This is so you can continue checking a button, or blinking an LED, etc. The simple Timer object helps implement these "non-blocking" actions. 

#### Declaration

    Timer timer_name();                        // Timer preset to 1 second
    Timer timer_name(interval);                // Timer preset to specified interval (milliseconds)

***Notes:***

To use a Timer, you can declare it with an interval, or use the setTime()  or setTimeMicros() methods (below), then you use the start() method to begin the timer. Finally, the isExpired() method can be used to check when the timer has ended.

There are two versions of most routines, the "default" one that uses milliseconds, and a "micros" version that uses microseconds for higher resolution.

#### Methods

    void setTime (time);                        // Sets the time (milliseconds)
    void setTimeMicros (time);                  // Sets the time (microseconds)
    void getTime ();                            // Returns the interval (milliseconds)
    void getTimeMicros ();                      // Returns the interval (microseconds)
    void getTimeRemaining ();                   // Returns the timer's remaining time (milliseconds)
    void getTimeRemainingMicros ();             // Returns the timer's remaining time (microseconds)
    void start ();                              // Starts the timer
    void restart ();                            // Same as start ()
    void isExpired ();                          // Returns true if the timer has expired, false if not

   

   

- - -
Copyright 2015-2022 Robert Gallup
