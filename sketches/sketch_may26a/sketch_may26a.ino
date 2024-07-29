#include "arduino_secrets.h"


int pinoLed = 9;/* Define como pino do LED. */ 
int pinoLed2 = 10;
int pinoLed3 = 11;
int incremento =  1; /* Incremento do brilho do LED. */
 int brilho = 0; /* VariÃ¡vel do brilho do LED. */
 void setup() { 
pinMode(pinoLed, OUTPUT);
pinMode(pinoLed2, OUTPUT);
pinMode(pinoLed3, OUTPUT);/* Define o pino do LED como saÃ­da. */ 
} void loop() {
 /*Incrementa o brilho do LED de 0 a 255. */ 
for (brilho; brilho <= 256; brilho += incremento) 
{ 
/* Ajusta a intensidade do brilho a cada incremento. */ 
digitalWrite(pinoLed, brilho); 
digitalWrite(pinoLed2, brilho); 
digitalWrite(pinoLed3, brilho); 
delay(100);
}
 }
