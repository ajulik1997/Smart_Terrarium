#include "Arduino.h"            // Arduino core
#include "Multiplexer.h"        // Corresponding header
#include <CD74HC4067.h>         // Multiplexer library

Multiplexer::Multiplexer(byte SIG, byte S0, byte S1, byte S2, byte S3) : _driver(S0, S1, S2, S3) {
  // Constructor for multiplexer class
  // S0, S1, S2, S3 are "select" pins, passed to the CD74HC4067 driver for channel selection
  // SIG is the "signal" pin to which the selected device is now connected
  _signal_pin = SIG;
}

int Multiplexer::read_device(byte device_id) {
  // Selects device represented by device_id and reads its analog value
  _driver.channel(device_id);
  return analogRead(_signal_pin);
}
