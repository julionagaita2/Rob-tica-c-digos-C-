#include "arduino_secrets.h"

// LedControl - Version: Latest 
#include <LedControl.h>

LedControl lc = LedControl(8, 10, 9, 1);
int tempo = 500;
byte Coracao_Peq[] = {
  B00001110,
  B00011110,
  B00111110,
  B01111100,
  B01111100,
  B00111110,
  B00011110,
  B00001100
  
};
byte Coracao_Gra[] = {
  B00011110,
  B00111111,
  B01111111,
  B11111110,
  B11111110,
  B01111111,
  B00111111,
  B00011110
  
};

void setup() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 10);
    lc.clearDisplay(0);
}

void loop() {
    mostra_coracao_peq();
    delay(tempo);
    mostra_coracao_gra();
    delay(tempo);
    }
void mostra_coracao_peq(){
  for (int i = 0; i < 8; i++){
    lc.setRow(0, i, Coracao_Peq[i]);
    
  }
}
void mostra_coracao_gra(){
  for(int i = 1; i <8; i++){
    lc.setRow(0, i, Coracao_Gra[i]);
  }
}