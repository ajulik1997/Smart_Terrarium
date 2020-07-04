#ifndef _TERRARIUM_POWER_H_
#define _TERRARIUM_POWER_H_

#include "Arduino.h"				// Arduino core
#include <Battery.h>				// Battery sense library

class Power
{
  public:
    Power(byte SENSE);				// Default constructor
    void update_status();			// Update battery percentage
    void initial_update();			// Initial battery update
    unsigned int percentage;		// Time-averaged battery percentage
  private:
    byte _sense_pin;				// Sense pin connected to battery
    Battery _driver;				// Battery driver
    unsigned int _tmp_percentage;	// Rolling battery percentage to be averaged
    byte _poll_count;				// Number of times battery level has been polled
    unsigned long _last_updated;	// Last time battery status was updated
};

#endif
