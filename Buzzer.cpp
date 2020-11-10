#include "Arduino.h"        // Arduino core
#include "Buzzer.h"         // Corresponding header

Buzzer::Buzzer(byte BUZZ) {
  // Constructor for buzzer class
  // BUZZ is the PWM pin number of the buzzer
  _buzzer_pin = BUZZ;
  pinMode(_buzzer_pin, OUTPUT);
}

void Buzzer::play_startup() {
  // Startup sound used during initialization
  for (int i=2; i<12; i++) {
    tone(_buzzer_pin, (int)(55*pow(2,i/2)), 200);
    delay(200);
  }
}

void Buzzer::play_error_loop() {
  // Infinitely looped error sound, signaling an uncorrectable error
  for (;;) {
    tone(11, 880, 500);
    delay(500);
    tone(11, 440, 500);
    delay(5000);
  }
}

void Buzzer::play_click() {
  // Standard UI click sound as feedback to button press
  tone(_buzzer_pin, 7040, 50);
}

void Buzzer::play_movement() {
  // Standard UI click sound as feedback to UI cursor movement
  tone(_buzzer_pin, 7040, 10);
}

void Buzzer::play_increment() {
  // Input feedback for incrementing UI element
  tone(_buzzer_pin, 14080, 10);
}

void Buzzer::play_decrement() {
  // Input feedback for decrementing UI element
  tone(_buzzer_pin, 3520, 10);
}

void Buzzer::play_warning() {
  // Warning sound signaling action cannot be carried out
  tone(_buzzer_pin, 55, 50);
}