#ifndef _TERRARIUM_BUZZER_H_
#define _TERRARIUM_BUZZER_H_

#include "Arduino.h"                                                       // Arduino core

class Buzzer
{
  public:
    Buzzer(byte BUZZ);         											   // Default constructor
	void play_startup();												   // Startup sound (used during initialization)
	void play_error_loop();												   // Looped error sound in case of uncorrectable error
	void play_click();													   // Click sound used in UI button press
	void play_movement();												   // Click sound used in normal UI movement
	void play_increment();												   // Click sound used in UI value increment
	void play_decrement();												   // Click sound used in UI value decrement
	void play_warning();												   // Longer click sound used as an action-not-allowed sound
  private:
    byte _buzzer_pin														   // Buzzer PWM pin number
};

#endif
