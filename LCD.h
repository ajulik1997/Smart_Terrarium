#ifndef _TERRARIUM_LCD_H_
#define _TERRARIUM_LCD_H_

#include "Arduino.h"                                                       // Arduino core
#include <Adafruit_SSD1306.h>                                              // LCD control library

class LCD
{
  public:
    LCD(int SCREEN_WIDTH, int SCREEN_HEIGHT, int OLED_RESET);    		   // Default constructor
	void init();														   // Initializes LCD at startup
    void show_splash();													   // Draw splash screen
	void show_main_menu();												   // Draws main menu
  private:
    Adafruit_SSD1306 _display;                                             // Adafruit LCD controller object
};

#endif