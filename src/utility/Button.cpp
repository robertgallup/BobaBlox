///////////////////////////////////////////////////////////////
//
//  Button.cpp
//
//  Simple class for switches/buttons
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

#include "button.h"

// Constructor : Button
Button::Button (byte p)
{
  _pin = p;
  pinMode (_pin, INPUT_PULLUP);

  _lastSample = digitalRead(_pin);
  _sampleTime = millis();
  _reading = _lastSample;
}

// Return button state (0=down, 1=up)
int Button::state ()
{
  return (digitalRead(_pin));
}

// Check button down
boolean Button::isDown ()
{
  return (digitalRead(_pin) == LOW);
}

// Check button up
boolean Button::isUp ()
{
  return (digitalRead(_pin) == HIGH);
}

// Check button was pressed
boolean Button::wasPressed ()
{
	// Update edge detection
	_checkEdge();
	
	// Save and reset edge state  (_wasPressed)
	boolean edge = _wasPressed;
	_wasPressed = false;
	
	// Return _wasPressed state
	return edge;
}

// Check button was released
boolean Button::wasReleased ()
{
	// Update edge detection
	_checkEdge();

	// Save and reset edge state (_wasReleased)
	boolean edge = _wasReleased;
	_wasReleased = false;

	// Return edge state
	return edge;
}

void Button::_checkEdge () {

	// Take samples only on debounce intervals
	if ((millis()-_sampleTime) > DEBOUNCE_INTERVAL) {
		// Sample pin
		_thisSample = digitalRead(_pin);
		// If it's the same as the last sample then we have a valid reading
		if (_thisSample == _lastSample) {
			// If there's a change, then set pressed/release states (inverse of each other)
			if (_thisSample != _reading) {
				_wasPressed = (_reading == HIGH) && (_thisSample == LOW);
				_wasReleased = !_wasPressed;
			}
			// Save this sample as a reading
			_reading = _thisSample;
		}
		// Use this sample/time as reference for the next detection
		_lastSample = _thisSample;
		_sampleTime = millis();
	}

}
