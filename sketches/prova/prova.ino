#include "arduino_secrets.h"

int pinoLed1 = 6;
int sensorLDR = A0;
int limiarLuz = 200;
int valorLDR = 0;
void setup() {
  pinMode(pinoLed1, OUTPUT);
  pinMode(sensorLDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorLDR = analogRead(sensorLDR);
  if (valorLDR > limiarLuz) {
    digitalWrite(pinoLed1, HIGH);
    
    Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
    Serial.println(valorLDR);
  } else {
    digitalWrite(pinoLed1, LOW);
    Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
    Serial.println(valorLDR);
  }
  delay(100);

}
