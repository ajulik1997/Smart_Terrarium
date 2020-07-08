#include "Arduino.h"            // Arduino core
#include "Multiplexer.h"        // Analog multiplexer library
#include "Power.h"              // Corresponding header
#include <Battery.h>            // Battery sense library
#include <VoltageReference.h>   // Library for referencing real value of VCC pin

Power::Power(Multiplexer *amux, byte amux_device) : _driver(3000, 4200, amux->signal_pin){
  // Constructor for power class
  // Multiplexer object is used to select battery sense pin amux_device read from it
  _amux = amux;
  _amux_device = amux_device;
  _driver.begin(VoltageReference().readVcc(), 1, &sigmoidal);   // initialise battery monitoring with respect to real VCC voltage
  _amux->lock_enable();                                         // lock multiplexer in enabled mode, as muliple readings will be made
  
  for (byte i = 0; i < 10; i++) {                               // take 10 battery percentage readings
	  _tmp_percentage += _driver.level();                       // readings are added, so their average can be taken
	  delay(100);												// take readings every 0.1s
  }
  
  level = _tmp_percentage / 10;                                 // obtain and store time-averaged battery percentage
  _amux->unlock_enable();                                       // unlock the multiplexer enable pin, so it can be switched off
}