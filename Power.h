#ifndef _TERRARIUM_POWER_H_
#define _TERRARIUM_POWER_H_

#include "Arduino.h"                        // Arduino core
#include "Multiplexer.h"                    // Analog multiplexer library
#include <Battery.h>                        // Battery sense library

class Power
{
  public:
    Power(byte SENSE, Multiplexer *amux);   // Default constructor
    void update_battery();                  // Update battery percentage
    unsigned int battery_percentage;        // Time-averaged battery percentage
  private:
    Battery _driver;                        // Battery driver
	Multiplexer* _amux;                     // Analog multiplexer controller
    unsigned int _tmp_percentage = 0;       // Rolling battery percentage to be averaged
    byte _poll_count = 0;                   // Number of times battery level has been polled
    unsigned long _last_updated = 0;        // Last time battery status was updated
};

#endif
