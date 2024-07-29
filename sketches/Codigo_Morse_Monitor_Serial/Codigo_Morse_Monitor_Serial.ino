#include "arduino_secrets.h"

/* As trÃªs primeiras linhas definem as constantes para os pinos
   utilizados para o botÃ£o, o buzzer e o LED. Esses valores nÃ£o
   mudarÃ£o durante a execuÃ§Ã£o do programa.
*/
#define buzzer 2
#define botao 3
#define LED 4


/* As duas linhas seguintes definem as variÃ¡veis booleanas para
   o estado atual do botÃ£o e o estado anterior do botÃ£o.
*/
bool estado_atual_botao;
bool estado_anterior_botao;

/*  O tempo em que o botÃ£o foi pressionado e liberado tambÃ©m Ã© mantido em
    variÃ¡veis do tipo unsigned long (Armazena valores positivos de 0 a 4.294.967.295 bilhÃµes).
*/
unsigned long tempo_pressionar_botao;
unsigned long tempo_soltar_botao;
unsigned long duracao_botao;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /* A primeira linha lÃª o estado atual do botÃ£o.
  */
  estado_atual_botao = digitalRead(botao);

  /* As linhas seguintes verificam se houve mudanÃ§a no estado do botÃ£o.
  */
  if (estado_atual_botao != estado_anterior_botao) {
    /* Se sim, elas atualizam o tempo em que o botÃ£o foi pressionado ou
      liberado, dependendo do estado atual do botÃ£o.
    */
    if (estado_atual_botao == LOW) {
      tempo_pressionar_botao = millis();
    }
    /* Se o botÃ£o foi liberado, o tempo entre o pressionamento e a
      liberaÃ§Ã£o do botÃ£o Ã© calculado em milissegundos.
    */
    else {
      tempo_soltar_botao = millis();
      duracao_botao = tempo_soltar_botao - tempo_pressionar_botao;

      /* Se o tempo de duraÃ§Ã£o estiver entre 5 e 200 milissegundos,
        um ponto Ã© enviado para a funÃ§Ã£o imprimir e ativar o LED e buzzer.
      */
      if (duracao_botao >= 5 && duracao_botao < 200) {
        codigo(".");

        /* Se o tempo de duraÃ§Ã£o estiver entre 200 e 800 milissegundos,
          um traÃ§o Ã© enviado para a funÃ§Ã£o imprimir e ativar o LED e buzzer.
        */
      }
      if (duracao_botao >= 200 && duracao_botao < 800) {
        codigo("-");
        /* Se o tempo de duraÃ§Ã£o estiver entre 800 e 1500 milissegundos,
          um espaÃ§o Ã© impresso no monitor serial.
        */
      }
      if (duracao_botao >= 800 && duracao_botao < 1500) {
        Serial.print(" ");
        /* Se o tempo de duraÃ§Ã£o estiver entre 1500 e 2500 milissegundos,
          uma barra Ã© impressa no monitor serial.
        */
      }
      if (duracao_botao >= 1500 && duracao_botao < 2500) {
        Serial.print(" / ");
        /* Se o tempo de duraÃ§Ã£o for maior ou igual que 2500 milissegundos,
          pula linha no monitor serial.
        */
      }
      if (duracao_botao >= 2500) {
        Serial.println(" ");
      }
    }
  }

  /* Por fim, a variÃ¡vel estado_anterior_botao Ã© atualizada
    para refletir o estado atual do botÃ£o
  */
  estado_anterior_botao = estado_atual_botao;
}

void codigo(String simbolo) {
  Serial.print(simbolo);
  digitalWrite(LED, HIGH);
  tone(buzzer, 440, duracao_botao);
  delay(duracao_botao);
  digitalWrite(LED, LOW);
}
