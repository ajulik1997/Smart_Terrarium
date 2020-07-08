#include "Arduino.h"            // Arduino core
#include "Multiplexer.h"        // Analog multiplexer library
#include "Power.h"              // Corresponding header
#include <Battery.h>            // Battery sense library

Power::Power(Multiplexer *amux, byte amux_device) : _driver(3000, 4200, amux->signal_pin){
  // Constructor for power class
  // Multiplexer object is used to select battery sense pin amux_device read from it
  _amux = amux;
  _amux_device = amux_device;
  _driver.begin(4960, 1, &sigmoidal);       // Initialise battery monitoring with respect to 5V (measured as 4.96V at Vin between 10-13V)
  _amux->lock_enable();                     // Lock multiplexer in enabled mode, as muliple readings will be made
  _amux->switch_to_device(_amux_device);    // Switch multiplexer to device representing battery voltage pin
  
  for (byte i = 0; i < 10; i++) {           // Take 10 battery percentage readings
	  _tmp_percentage += _driver.level();   // Readings are added, so their average can be taken
	  delay(100);                           // Take readings every 0.1s
  }
  
  level = _tmp_percentage / 10;             // Obtain and store time-averaged battery percentage
  _amux->unlock_enable();                   // Unlock the multiplexer enable pin, so it can be switched off
}