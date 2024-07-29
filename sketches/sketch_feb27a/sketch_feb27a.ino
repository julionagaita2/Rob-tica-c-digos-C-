#include "arduino_secrets.h"

/*

*/
#define PIN_SENSOR 2
#define PIN_LED_VERDE_CAR 13
#define PIN_LED_AMARELO_CAR 12
#define PIN_LED_VERMELHO_CAR 11
#define PIN_LED_VERDE_PED 10
#define PIN_LED_VERMELHO_PED 9
int modo = 0;
void setup(){
    pinMode(PIN_SENSOR, INPUT);
    for(int i =9; i<=13 ; i++) {
    pinMode(i, OUTPUT);
    }
    attachInterrupt(digitalPinToInterrupt(PIN_SENSOR),sensorAcionado, FALLING);
    
    }


void loop() {
    switch (modo){
      case 0:
      modocarros();
      break;
    }
}
void sensorAcionado(){
 modo = 1;
 
 
}
void travessia(){
  delay(1000);
  digitalWrite(PIN_LED_VERDE_CAR, LOW);
  digitalWrite(PIN_LED_AMARELO_CAR, HIGH);
  delay(3000);
  digitalWrite(PIN_LED_VERDE_PED, HIGH);
  digitalWrite(PIN_LED_VERMELHO_PED, LOW);
  digitalWrite(PIN_LED_AMARELO_CAR, LOW);
  digitalWrite(PIN_LED_VERMELHO_CAR, HIGH);
  delay(5000);
  digitalWrite(PIN_LED_VERMELHO_PED, LOW);
  for (int i = 0; i <= 5; i++) {
    digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
    delay(300);
    digitalWrite(PIN_LED_VERMELHO_PED, LOW);
    delay(300);
  }
  modo = 0;
}
void modocarros(){
  digitalWrite(PIN_LED_VERDE_PED, LOW);
  digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
  digitalWrite(PIN_LED_VERDE_CAR, LOW);
  digitalWrite(PIN_LED_AMARELO_CAR, LOW);
  digitalWrite(PIN_LED_VERMELHO_CAR, LOW);
  
}

    

