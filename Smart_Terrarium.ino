#include <Adafruit_BMP280.h>    // Barometric Pressure Sensor
#include <Adafruit_GFX.h>       // Graphics Library
#include <Adafruit_SSD1306.h>   // LCD

#include <CD74HC4067.h>         // Analog Multiplexer
#include <Wire.h>               // I2C Communication
#include <Battery.h> 
#include "lcd.h"
#include "Multiplexer.h"
#include "Soil.h"

/* ===== DEFINE PIN NUMBERS ===== */

const byte RTENC_CLK = 2;       // ROTARY ENCODER: Clock
const byte RTENC_DT = 3;        // ROTARY ENCODER: Data
const byte RTENC_SW = 4;        // ROTARY ENCODER: Switch

/* ===== SETUP GLOBAL VARS ===== */


static uint8_t prevNextCode = 0;
static uint16_t store=0;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

/* ===== STARTUP INIT ===== */

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.drawBitmap(0, 0, splash_image, 128, 64, 1);
  display.display();
  
  setup_rotary_encoder();

  Multiplexer amux(A0, 3, 4, 5, 6);
  Serial.println(amux.read_device(0));
  Battery batt = Battery(3000, 4200, A1);
  batt.begin(3300, 1.47, &sigmoidal);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(batt.level());
  display.display(); 
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
