#include "arduino_secrets.h"

/************************************************************/
/* Aula 27 - Sensor LDR */
/* ProgramaÃ§Ã£o: Aciona um LED a partir da leitura do mÃ³dulo */
/* sensor de luminosidade LDR. */
/************************************************************/
/* VariÃ¡vel que armazenarÃ¡ os dados do sensor LDR. */
int Sensor_LDR;
/* Define A0 como porta de entrada do sensor LDR.           */
int Pin_LDR = A0;
/* Define a porta digital 5 para controle do LED.           */
int Pin_LED = 5;
void setup() {
/* Inicia a comunicaÃ§Ã£o serial na velocidade de 9600.     */
Serial.begin(9600);
/* Define a porta de controle do LED como SAÃDA.          */
pinMode(Pin_LED, OUTPUT);
/* Define a porta de controle do LED como SAÃDA.          */
pinMode(Pin_LDR, INPUT);
}
void loop() {
/* A variÃ¡vel Sensor_LDR recebe os dados do sensor LDR. */
Sensor_LDR = digitalRead(Pin_LDR);
/* Imprime o valor lido do sensor LDR (0 a 1023).         */
Serial.print("Valor lido: );
Serial.println(Sensor_LDR);
/* Pequena pausa para realizar a prÃ³xima leitura. */
delay(100);
/* Se o valor lido for menor que 800, faÃ§a...             */
if (Sensor_LDR == 1) {
 /* Ligue o LED. */
 digitalWrite(Pin_LED, HIGH);
 /* SenÃ£o... */
} else {
 /* Desligue o LED. */
 digitalWrite(Pin_LED, LOW);
}
}