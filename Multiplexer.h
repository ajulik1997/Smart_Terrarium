#ifndef TERRARIUM_MULTIPLEXER_H_
#define TERRARIUM_MULTIPLEXER_H_

#include "Arduino.h"            // Arduino core
#include <CD74HC4067.h>         // Multiplexer library

class Multiplexer
{
  public:
    Multiplexer(byte SIG, byte S0, byte S1, byte S2, byte S3);  // Default constructor
    int read_device(byte device_id);                            // Reads analog value of device
  private:
    byte _signal_pin;           // Signal pin which receives analog data
    CD74HC4067 _driver;         // Multiplexer driver for switching channels
};

#endif
