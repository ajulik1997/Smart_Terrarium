#ifndef _TERRARIUM_ENCODER_H_
#define _TERRARIUM_ENCODER_H_

#include "Arduino.h"                                                       // Arduino core

class Encoder
{
  public:
    Encoder(byte CLK, byte DT, byte SW);                                   // Default constructor
    void read_encoder();                                                   // Reads change in state of rotary encoder
    void read_switch();													   // Reacts to switch by executing relevant function
	byte clock_pin;
	byte data_pin;
	byte switch_pin;
	uint8_t value;
	uint8_t limit;
  private:
    const bool _allowed_positions[16] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
	uint8_t previous;
	uint16_t current;
};

#endif
