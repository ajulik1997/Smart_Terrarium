#include <Adafruit_BMP280.h>    // Barometric Pressure Sensor

#include "LCD.h"
#include "Multiplexer.h"
#include "Power.h"
#include "Soil.h"

/* ===== DEFINE PIN NUMBERS ===== */

const byte RTENC_CLK = 2;       // ROTARY ENCODER: Clock
const byte RTENC_DT = 3;        // ROTARY ENCODER: Data
const byte RTENC_SW = 4;        // ROTARY ENCODER: Switch

/* ===== SETUP GLOBAL VARS ===== */


static uint8_t prevNextCode = 0;
static uint16_t store=0;

LCD lcd(128, 64, -1);

/* ===== STARTUP INIT ===== */

void setup() {
  Serial.begin(9600);
  lcd.show_splash();
  
  setup_rotary_encoder();

  Multiplexer amux(A0, 2, 3, 4, 5, 6);
  Power battery(&amux, 15);
  lcd.show_main_menu();
}

void setup_rotary_encoder() {
  pinMode(RTENC_CLK, INPUT);
  pinMode(RTENC_CLK, INPUT_PULLUP);
  pinMode(RTENC_DT, INPUT);
  pinMode(RTENC_DT, INPUT_PULLUP);
  
  pinMode(RTENC_SW, INPUT);
}

/* ===== RUNTIME LOOP ===== */

void loop() {
static int8_t c,val;

   if( val=read_rotary() ) {
      c +=val;
      Serial.print(c);Serial.print(" ");

      if ( prevNextCode==0x0b) {
         Serial.print("eleven ");
         Serial.println(store,HEX);
      }

      if ( prevNextCode==0x07) {
         Serial.print("seven ");
         Serial.println(store,HEX);
      }
   }
}

int8_t read_rotary() {
  static bool rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

  prevNextCode <<= 2;
  if (digitalRead(RTENC_DT)) prevNextCode |= 0x02;
  if (digitalRead(RTENC_CLK)) prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

   // If valid then store as 16 bit data.
   if  (rot_enc_table[prevNextCode] ) {
      store <<= 4;
      store |= prevNextCode;
      //if (store==0xd42b) return 1;
      //if (store==0xe817) return -1;
      if ((store&0xff)==0x2b) return -1;
      if ((store&0xff)==0x17) return 1;
   }
   return 0;
}
