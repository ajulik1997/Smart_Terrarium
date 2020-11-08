#include "Arduino.h"            // Arduino core
#include "LCD.h"                // Corresponding header
#include "LCD_bitmaps.h"		// Bitmaps for LCD drawing
#include <Adafruit_GFX.h>       // Graphics library
#include <Adafruit_SSD1306.h>   // LCD control library
#include <Wire.h>               // I2C communication

LCD::LCD(int SCREEN_WIDTH, int SCREEN_HEIGHT, int OLED_RESET) : _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {
  // Constructor for LCD management class
  // SCREEN_WIDTH and SCREEN_HEIGHT define LCD screen dimensions
  // OLED_RESET defines the LCD reset pin (-1 if shared with Arduino)
  if(!_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void LCD::show_splash() {
  // Draws splash screen to LCD
  _display.clearDisplay();
  _display.drawBitmap(0, 0, splash_image, 128, 64, 1);
  _display.display();
}

void LCD::show_main_menu() {
  // Draws main menu screen to LCD
  _display.clearDisplay();
  _display.drawLine(0, 12, 127, 12, WHITE);
  _display.drawLine(0, 53, 127, 53, WHITE);
  _display.drawBitmap(113, 1, battery_full, 15, 10, 1);
  _display.setTextSize(1);
  _display.setTextColor(WHITE);
  _display.setCursor(87, 2);
  _display.print("100%");
  //display.print(battery.level);
  //display.fillRect(0, 53, 51, 63, WHITE);
  //display.setTextColor(BLACK);
  _display.drawLine(46, 53, 46, 63, WHITE);
  _display.drawLine(93, 53, 93, 63, WHITE);
  _display.setCursor(2, 55);
  _display.print("Details");
  _display.setCursor(50, 55);
  _display.print("Control");
  _display.setCursor(97, 55);
  _display.print("Light");
  _display.display(); 
}