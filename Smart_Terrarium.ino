#include <Adafruit_BMP280.h>    // Barometric Pressure Sensor

#include "Buzzer.h"
#include "Encoder.h"
#include "LCD.h"
#include "Multiplexer.h"
#include "Power.h"
#include "Soil.h"

/* ===== DEFINE PIN NUMBERS ===== */

/* ===== SETUP GLOBAL VARS ===== */

Buzzer buzzer(11);
Encoder encoder(2, 4, 3);
LCD lcd(128, 64, -1);
Multiplexer amux(A0, 2, 3, 4, 5, 6);
Power battery(&amux, 15);

/* ===== STARTUP INIT ===== */

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  
  attachInterrupt(digitalPinToInterrupt(2), interrupt_encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), interrupt_button, FALLING);

  
  lcd.show_main_menu();
}

/* ===== RUNTIME LOOP ===== */

void loop() {
}

/* ===== INTERRUPT SERVICE ROUTINES ===== */

void interrupt_encoder() {
	encoder.read_encoder();
}

void interrupt_button() {
    
}