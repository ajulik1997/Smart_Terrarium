#include "Arduino.h"        // Arduino core
#include "Multiplexer.h"    // Corresponding header
#include <CD74HC4067.h>     // Multiplexer library

Multiplexer::Multiplexer(byte SIG, byte EN, byte S0, byte S1, byte S2, byte S3) : _driver(S0, S1, S2, S3) {
  // Constructor for multiplexer class
  // S0, S1, S2, S3 are "select" pins, passed to the CD74HC4067 driver for channel selection
  // SIG is the "signal" pin to which the selected device is now connected
  // EN is the "enable" pin, which when driven high, disables multiplexer
  signal_pin = SIG;
  enable_pin = EN;
  pinMode(signal_pin, INPUT);
  pinMode(enable_pin, OUTPUT);
  digitalWrite(enable_pin, HIGH);    // Disable multiplexer
}

int Multiplexer::read_device(byte device_id) {
  // Enables multiplexer, selects device represented by device_id, reads its analog value, then disables it again
  if (not _lock) digitalWrite(enable_pin, LOW);
  _driver.channel(device_id);
  _analog_value = analogRead(signal_pin);
  if (not _lock) digitalWrite(enable_pin, HIGH);
  return _analog_value;
}

void Multiplexer::lock_enable() {
  // Locks multiplexer to enabled state
  _lock = true;
  digitalWrite(enable_pin, LOW);
}

void Multiplexer::unlock_enable() {
  // Removes enable lock, allowing multiplexer to be disabled
  _lock = false;
  digitalWrite(enable_pin, HIGH);
}