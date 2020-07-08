#ifndef _TERRARIUM_MULTIPLEXER_H_
#define _TERRARIUM_MULTIPLEXER_H_

#include "Arduino.h"                                                       // Arduino core
#include <CD74HC4067.h>                                                    // Multiplexer library

class Multiplexer
{
  public:
    Multiplexer(byte SIG, byte EN, byte S0, byte S1, byte S2, byte S3);    // Default constructor
    int read_device(byte device_id);                                       // Reads analog value of device
	void lock_enable();                                                    // Locks multiplexer in enabled mode
	void unlock_enable();                                                  // Removes enable lock, allowing multiplexer to be disabled
	void switch_to_device(byte device_id);                                 // Switches to device without reading from it
	byte signal_pin;                                                       // Signal pin which receives analog data
	byte enable_pin;                                                       // Enable pin, when driven high, disables multiplexer
  private:
    CD74HC4067 _driver;                                                    // Multiplexer driver for switching channels
	int _analog_value = 0;                                                 // Stores analog input value of _signal_pin
	bool _lock = false;                                                    // If lock is true, multiplexer cannot be disabled
};

#endif
