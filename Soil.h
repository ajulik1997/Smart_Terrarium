#ifndef Soil_h
#define Soil_h

#include "Arduino.h"

class Soil
{
  public:
    Soil(byte top_left, byte top_right, byte bottom_left, byte bottom_right);
    unsigned int moisture[4];
  private:
    byte _sensors[4];
};

#endif
