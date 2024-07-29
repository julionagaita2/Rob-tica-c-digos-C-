#include "arduino_secrets.h"

/* Define a intensidade do brilho de um LED usando um pino
PWM. */
int pinoLed = 11; /* Define o pino 11 como pino do LED. */
int pinoLed2 = 9
int pinoLed3 = 10;
int intensidade = 50; /* Defina o brilho do LED (0-255). */
int intensidade2
void setup() {
/* Define o pino do LED como saÃ­da. */
pinMode(pinoLed, OUTPUT);
pinMode(pinoLed2, OUTPUT);
pinMode(pinoLed3, OUTPUT);

}
void loop() {
/* Liga o LED com a intensidade definida. */
analogWrite(pinoLed, intensidade);
}