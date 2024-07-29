#include "arduino_secrets.h"

/* Acionamento de LED atravÃ©s da leitura do Sensor Infravermelho IR */
int pinoSensor = 2; /* Pino digital utilizado pelo sensor. */
int Pin_LED = 4;/*Define o pino 4 como pino do LED. */
int Sensor_IR = 0; /* VariÃ¡vel que armazena o estado do sensor (0 ou 1). 
*/
void setup() {
pinMode(pinoSensor, INPUT); /*Define o pino do sensor como ENTRADA. */
pinMode(Pin_LED, INPUT); /* Define o pino do LED como SAÃDA. */
Serial.begin(9600); /* Inicializa a comunicaÃ§Ã£o serial */
}
void loop() {
int Sensor_IR = digitalRead(pinoSensor); /* Realiza a leitura do sensor e 
registra na variÃ¡vel */
Serial.println(Sensor_IR); /* Imprime o valor registrado na 
variÃ¡vel */
 /* (0: com obstÃ¡culo ou 1: sem 
obstÃ¡culo) */
 if(Sensor_IR == 0) { /* Se a leitura no sensor for igual a 0 
*/
 digitalWrite(Pin_LED, true); /* Ligue o LED */
}else{
digitalWrite(Pin_LED, false);
  
}
}