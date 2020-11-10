#include <Adafruit_BMP280.h>    // Barometric Pressure Sensor

#include "LCD.h"
#include "Encoder.h"
#include "Multiplexer.h"
#include "Power.h"
#include "Soil.h"

/* ===== DEFINE PIN NUMBERS ===== */

/* ===== SETUP GLOBAL VARS ===== */

LCD lcd(128, 64, -1);
Encoder encoder(2, 4, 3);

/* ===== STARTUP INIT ===== */

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  
  
  attachInterrupt(digitalPinToInterrupt(2), interrupt_encoder, CHANGE);
  

  Multiplexer amux(A0, 2, 3, 4, 5, 6);
  Power battery(&amux, 15);
  lcd.show_main_menu();
}

/* ===== RUNTIME LOOP ===== */

void loop() {
}

/* ===== INTERRUPT SERVICE ROUTINES ===== */

void interrupt_encoder() {
	encoder.read_encoder();
}