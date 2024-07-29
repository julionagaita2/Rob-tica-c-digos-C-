#include "arduino_secrets.h"

char modelo[] = "Ãnodo Comum";

int Poten = A0;

int pinoLedVermelho = 2;
int pinoLedVerde = 3;
int pinoLedAzul = 4;
int ligar;
int desligar;

void setup() {

 pinMode(pinoLedVermelho, OUTPUT);
 pinMode(pinoLedVerde, OUTPUT);
 pinMode(pinoLedAzul, OUTPUT);
  if (modelo[0] != "C") {
 ligar = 0;
 desligar = 1;
 } else {
 ligar = 1;
 desligar = 0;
 }

 /* Inicia com os LEDs desligados. */
 digitalWrite(pinoLedVermelho, desligar);
 digitalWrite(pinoLedVerde, desligar);
 digitalWrite(pinoLedAzul, desligar);
}

void loop() {
int PotenValor = analogRead(Poten);
    if(PotenValor >= 0 && PotenValor < 341){
      digitalWrite(pinoLedVermelho, HIGH);
    }else{
      digitalWrite(pinoLedVermelho, LOW);
    }if(PotenValor >= 341 && PotenValor < 682){
      digitalWrite(pinoLedVerde, HIGH);
    }else{
      digitalWrite(pinoLedVerde, LOW);
    }if(PotenValor >= 682 && PotenValor < 1024){
      digitalWrite(pinoLedAzul, HIGH);
    }else{
      digitalWrite(pinoLedAzul, LOW);
    }
}
