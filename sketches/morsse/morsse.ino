#include "arduino_secrets.h"

#define buzzer  2
#define botao 3
#define LED 4

void setup() {
  /* Configura as portas do LED e buzzer como saÃ­da.*/
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  /* Configura a porta do botÃ£o como entrada e ativa*/
  /* o resistor interno da placa.                   */
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  /* Se presionar o botÃ£o, ligue o LED e emita som. */
  if (digitalRead(botao) == LOW) {
    digitalWrite(LED, HIGH);
    tone(buzzer, 800);
  }
  /* SenÃ£o, desligue o LED e pare o som.           */
  else {
    digitalWrite(LED, LOW);
    noTone(buzzer);
  }
}