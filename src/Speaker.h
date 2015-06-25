///////////////////////////////////////////////////////////////
//
//  Speaker.h
//
//  Simple class for controlling a speaker using one pin (+ ground) or two pins
//  BobaBlox Library
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2014-2015 Robert Gallup
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

#ifndef BB_SPEAKER_h
#define BB_SPEAKER_h

#include "Arduino.h"

// CLASS
class Speaker
{
  public:
  
    // Constructors
    Speaker (byte)
    Speaker (byte, byte);
    
    // Sound definition and control
    void beep (unsigned int, unsigned int, float color=0.5);
    void tone (unsigned int, float color=0.5);
    void start();
    void stop();

    // Returns current frequency and color
    unsigned int frequency();
    unsigned int color();

  private:
  
    // Physical connection
    byte _pin1;                               // Pin number of first pin
    byte _pin2;                               // Pin number of second pin
    boolean _onePin;                          // True if using only one pin
    
    // Sound definition adn control
    boolean _soundON;                         // True if speaker is currently playing
    unsigned int  _frequency;                 // Tone frequency
    float _color;                             // Tone color (pulse width)
    
    // Waveform definition
    unsigned long _cycleLength[2];            // Lengths for the two halfcycles
    unsigned long _cycleTimer;                // For timing the half cycles
    byte _halfCycle;                          // 0=positive halfcycle, 1=-halfcycle
    
    // Utility methods
    void _calculateWave();                    // Calculates positive/negative halfcycle lengths given current frequency/color
    void _cycleSpeaker(int);                  // Cycles the speaker positive or negative
  	
};

#endif
