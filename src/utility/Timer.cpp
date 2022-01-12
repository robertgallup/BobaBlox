///////////////////////////////////////////////////////////////
//
//  Timer.cpp
//
//  Simple class implementing a software timer
//  BpbaBlox Library
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

#include "Timer.h"

const unsigned long MILLIS_TO_MICROS = 1000UL;

// Constructor : Initialize with default of one second
Timer::Timer ()
{
  _time = MILLIS_TO_MICROS;
}

// Constructor : Initialize with specified interval
Timer::Timer (unsigned long interval)
{
  _time = interval * MILLIS_TO_MICROS;
}

// Set timer interval
void Timer::setTime (unsigned long time) {
  _time = time * MILLIS_TO_MICROS;
}

// Set timer interval in microseconds
void Timer::setTimeMicros (unsigned long time) {
  _time = time;
}

// Get timer interval
unsigned long Timer::getTime () {
  return _time / MILLIS_TO_MICROS;
}

// Get timer interval in microseconds
unsigned long Timer::getTimeMicros () {
  return _time;
}

// Get time remaining on timer
unsigned long Timer::getTimeRemaining () {
  return (micros()-_startTime) / MILLIS_TO_MICROS;
}

// Get time remaining on timer in microseconds
unsigned long Timer::getTimeRemainingMicros () {
  return (micros()-_startTime);
}

// Start a timer
void Timer::start () {
  _expired = false;
  _startTime = micros();
}

// Restart is synomym for start
void Timer::restart () {
  start();
}

// Return true if timer has expired
boolean Timer::isExpired (){
  if (!_expired && (micros() - _startTime) > _time) _expired = true;
  return _expired;
}

