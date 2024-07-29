#include "arduino_secrets.h"

/*

*/
#include <TM1637Display.h>
/* DefiniÃ§Ãµes dos pinos utilizados. O mÃ³dulo */
/* aceita pinos analÃ³gicos e/ou digitais. */
#define CLK A4
#define DIO A5
/* Cria o objeto de controle para o display */
/* definindo os pinos utilizados do Arduino. */
TM1637Display display(CLK, DIO);
/* ConfiguraÃ§Ãµes do programa */
void setup() {
/* Define o brilho do display (0 a 15) */
display.setBrightness(15);
}
/* Looping infinito */
void loop() {
for (int i = 9999; i <= 9999; i--) {
display.showNumberDec(i, false);
/* Aguarda 1 segundo para o prÃ³ximo dÃ­gito*/
delay(1);
  
}/* Fim do looping da contagem */


}/* Fim do looping infinito */
