///////////////////////////////////////////////////////////////
//
//  Button.cpp
//
//  Simple class for switches/buttons
//  BobaBlox Library
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2014 Robert W. Gallup
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

#include "Button.h"

#define DEBOUNCE_INTERVAL 14

// Constructor : Button
Button::Button (byte p)
{
  _pin = p;
  pinMode (_pin, INPUT_PULLUP);
  _lastState = digitalRead(_pin);
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

boolean Button::wasPressed ()
{
	return detectEdge (HIGH);
}

boolean Button::wasReleased ()
{
	return detectEdge (LOW);

}

boolean Button::detectEdge (int type) {

	boolean e = false;
	if ((_lastState == type) && (digitalRead(_pin) == !type)) {
		delay (DEBOUNCE_INTERVAL);
		if (digitalRead(_pin) == !type) {
			e = true;
		}
	}

	_lastState = digitalRead(_pin);
	return e;

}
