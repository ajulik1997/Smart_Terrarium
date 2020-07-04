#include "Arduino.h"        // Arduino core
#include "Multiplexer.h"    // Analog multiplexer library
#include "Power.h"          // Corresponding header
#include <Battery.h>        // Battery sense library

Power::Power(byte SENSE, Multiplexer *amux) : _driver(3000, 4200, amux->signal_pin){
  // Constructor for power class
  // SENSE pin passed to battery driver for measuring battery percentage
  //_driver.begin(5000, 1, &sigmoidal);
  //_driver(3000, 4200, SENSE)
  _amux = amux;
  _amux->lock_enable();
  for (byte i = 0; i < 10; i++) {
	  _tmp_percentage += analogRead(_amux->signal_pin);
	  delay(100);
  }
  battery_percentage = _tmp_percentage / 10;
}