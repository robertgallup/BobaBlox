///////////////////////////////////////////////////////////////
//
//  LED.cpp
//
//  Simple class for LEDs
//  BobaBlox Library
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2014-2022 Robert Gallup
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
///////////////////////////////////////////////////////////////

#include "LED.h"

#define DEFAULT_DURATION 250
#define _initPin(p) pinMode(p,OUTPUT);digitalWrite(p, LOW)

// Constructor: Built-in LED
LED::LED ()
{
  _pin = LED_BUILTIN;
  _initPin(_pin);
}

// Constructor: Specify LED pin
// LED::LED (byte p, boolean analog)
// {
//   _pin = p;
//   if (!analog) _initPin(_pin);
// }
LED::LED (byte p)
{
  _pin = p;
  _initPin(_pin);
}

// Set LED to ON 
void LED::on ()
{
  digitalWrite (_pin, HIGH);
}

// Set LED to OFF
void LED::off ()
{
  digitalWrite (_pin, LOW);
}

// Set LED to ON for even, OFF for odd number
void LED::set (int ledState)
{
  digitalWrite (_pin, ledState & 1);
}

// Toggle LED
void LED::toggle()
{
  digitalWrite(_pin, !digitalRead(_pin));
}

// A single default blink
void LED::blink () {
  _blink (DEFAULT_DURATION, DEFAULT_DURATION);
}

// Blink a number of default blinks
void LED::blink (int times) {
  for (int i=0; i<times; i++) {
    blink();
  }
}

// Blink a number of times with symetrical on/off durations
void LED::blink (int times, int duration) {
  for (int i=0; i<times; i++) {
    _blink (duration, duration);
  }
}

// Blink a number of times with variable on/off durations
void LED::blink (int times, int onDuration, int offDuration) {
  for (int i=0; i<times; i++) {
    _blink (onDuration, offDuration);
  }
}

// Set the brightness for the LED
void LED::setBrightness (int value) {
  analogWrite (_pin, value);
}

// Blinks a pin on/off with variable durations
void LED::_blink (int onDuration, int offDuration) {
  digitalWrite (_pin, HIGH);
  delay (onDuration);
  digitalWrite (_pin, LOW);
  delay (offDuration);
}
