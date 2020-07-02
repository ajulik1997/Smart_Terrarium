#ifndef TERRARIUM_BATTERY_H_
#define TERRARIUM_BATTERY_H_

#include "Arduino.h"            // Arduino core
#include <Battery.h>            // Battery sense library

class Battery
{
  public:
    Battery(byte SENSE);  // Default constructor
    int read_device(byte device_id);                            // Reads analog value of device
  private:
    byte _signal_pin;           // Signal pin which receives analog data
    CD74HC4067 _driver;         // Multiplexer driver for switching channels
};

#endif
