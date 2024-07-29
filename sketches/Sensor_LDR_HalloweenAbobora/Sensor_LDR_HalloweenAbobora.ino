#include "arduino_secrets.h"

int pinoLed1 = 6;
int pinoLed2 = 5;
int sensorLDR = A0;
int limiarLuz = 200;
int valorLDR = 0;
void setup() {
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(sensorLDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorLDR = analogRead(sensorLDR);
  if (valorLDR > limiarLuz) {
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
    Serial.println(valorLDR);
  } else {
    digitalWrite(pinoLed1, LOW);
    digitalWrite(pinoLed2, LOW);
    Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
    Serial.println(valorLDR);
  }
  delay(100);

}
