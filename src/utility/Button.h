///////////////////////////////////////////////////////////////
//
//  Button.h
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

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#define DEBOUNCE_INTERVAL 14

// CLASS
class Button
{
  public:
  
    Button (byte);
    int state ();
    boolean isDown ();
    boolean isUp ();
    boolean wasPressed ();
    boolean wasReleased ();

  private:
  
    // Button Pin
    byte _pin;

    // Checks for press/release event
    void _checkEdge();

    // Associated with _checkEdge();
    unsigned long _sampleTime;
    int  _lastSample;
    int  _thisSample;
    int  _reading;
    boolean _wasPressed  = false;
    boolean _wasReleased = false;

};

#endif
