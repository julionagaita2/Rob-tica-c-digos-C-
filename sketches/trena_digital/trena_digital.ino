#include "arduino_secrets.h"

// Ultrasonic - Version: Latest 
#include <Ultrasonic.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
#define pino_trig A1
#define pino_echo A0

Ultrasonic ultrasonic(pino_trig, pino_echo);
float medida;

void setup(void) {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}
void loop(void){
  medida = ultrasonic.read();
  display.clearDisplay();
  display.setCursor(8, 0);
  display.setTextSize(1);
  display.setTextColor(1);
  display.print("-- TRENA DIGITAL --");
  display.drawRoundRect(0, 12, 128, 40, 10, WHITE);
  display.setCursor(20, 55);
  display.print("Rob");
  display.write(162);
  display.print("tica Paran");
  display.write(160);
  display.setTextSize(2);
  if (medida < 10){
    display.setCursor(25, 25);
    display.print(medida);
    display.setCursor(85, 25);
    display.print("cm");
    }

  

  if (medida >= 10 && medida < 100){
    display.setCursor(13, 25);
    display.print(medida);
    display.setCursor(85, 25);
    display.print("cm");
    
    }
  if(medida >= 100){
    display.setCursor(25, 25);
    display.print(medida / 100);
    display.setCursor(85, 25);
    display.print("m");
    display.display();
    delay(100);
  }
}