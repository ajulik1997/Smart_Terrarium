#include "Arduino.h"        // Arduino core
#include "Encoder.h"        // Corresponding header

Encoder::Encoder(byte CLK, byte DT, byte SW) {
  // Constructor for rotary encoder class
  // CLK and DT define the clock and data pins of the rotary encoder
  // SW defines the switch pin of the rotary encoder
  clock_pin = CLK;
  data_pin = DT;
  switch_pin = SW;
  pinMode(clock_pin, INPUT_PULLUP);
  pinMode(data_pin, INPUT_PULLUP);
  pinMode(switch_pin, INPUT_PULLUP);
  value = 0;
  limit = 1;
  previous = 0;
  current = 0;
}

void Encoder::read_encoder() {
	previous <<= 2;
	  if (digitalRead(data_pin)) previous |= 0x02;
	  if (digitalRead(clock_pin)) previous |= 0x01;
	  previous &= 0x0f;

	   // If valid then store as 16 bit data.
	   if  (_allowed_positions[previous] ) {
		  current <<= 4;
		  current |= previous;
		  if ((current&0xff)==0x2b) value = (value - 1) % 2;
		  if ((current&0xff)==0x17) value = (value + 1) % 2;
	   }
}

void Encoder::read_switch() {
}