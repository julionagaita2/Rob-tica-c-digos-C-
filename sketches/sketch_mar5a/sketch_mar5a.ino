#include "arduino_secrets.h"

/***************************************************/
/* Aula 5  - SemÃ¡foro completo com display         */
/* ProgramaÃ§Ã£o de um semÃ¡foro completo com botÃ£o e */
/* display com quatro dÃ­gitos contador de tempo de */
/* travessia restante para pedestres.              */
/***************************************************/
/* Baixe a biblioteca atravÃ©s do link abaixo       */
/*                                                 */
/* http://librarymanager/All#TM1637#I2C-Like       */
/*                                                 */
/***************************************************/

/* Inclui a biblioteca de controle do display.     */
#include <TM1637Display.h>

/* Cria a variÃ¡vel para armazenar a contagem.      */
int contador;

/* DefiniÃ§Ãµes dos pinos utilizados. O mÃ³dulo aceita*/
/* pinos analÃ³gicos e digitais.                    */
#define CLK A4
#define DIO A5

/* DefiniÃ§Ã£o dos pinos de controle dos LEDs do    */
/* semÃ¡foro.                                       */
#define Verde_Carros 2
#define Amarelo_Carros 3
#define Vermelho_Carros 4
#define Verde_Pedestres5
#define Vermelho_Pedestres 6

/* DefiniÃ§Ã£o do pino de controle do botÃ£o.        */
#define botao 1

/* Cria o objeto de controle para o display        */
/* mencionando os pinos utilizados do Arduino.     */
TM1637Display display(CLK, DIO);

/* InÃ­cio das configuraÃ§Ãµes.                       */
void setup() {
  /* Define o brilho do display (0 a 15).          */
  display.setBrightness(15);
  /* Garantimos que o display inicie desligado.    */
  display.clear();
  /* Definimos o pino do botÃ£o como entrada.       */
  pinMode(botao, INPUT);
  /* Definimos os pinos dos LEDs como saÃ­das.      */
  pinMode(Verde_Carros, OUTPUT);
  pinMode(Amarelo_Carros, OUTPUT);
  pinMode(Vermelho_Carros, OUTPUT);
  pinMode(Verde_Pedestres, OUTPUT);
  pinMode(Vermelho_Pedestres, OUTPUT);
}/* Fim das configuraÃ§Ãµes.                         */

/* Inicio do looping infinito.                     */
void loop() {
  /* Se o botÃ£o for pressionado, faÃ§a...           */
  if (digitalRead(botao) == 0) {
    /* Aguarda 2 segundos.                         */
    delay(2000);
    /* Desliga o LED Verde dos carros.             */
    digitalWrite(Verde_Carros, 0);
    /* Liga o LED Amarelo dos carros.              */
    digitalWrite(Amarelo_Carros, 1);
    /* Aguarda 5 segundos.                         */
    delay(5000);
    /* Inicia o contador em 15 segundos.           */
    contador = 15;
    /* Inicia a contagem atÃ© 15.                   */
    for (int count = 0; count < 16; count++) {
      /* Se o contador for maior que 5, faÃ§a...    */
      if (contador > 5) {
        /* Desliga o LED Amarelo dos carros.       */
        digitalWrite(Amarelo_Carros, 0);
        /* Liga o LED Vermelho dos carros.         */
        digitalWrite(Vermelho_Carros, 1);
        /* Liga o LED Verde dos pedestres.         */
        digitalWrite(Verde_Pedestres, 1);
        /* Desliga o LED Vermelho dos Ppedestres.  */
        digitalWrite(Vermelho_Pedestres, 0);
        /* Se o contador nÃ£o for maior que 5, entÃ£o*/
        /* inicia a sequÃªncia que faz o LED        */
        /* Vermelho dos pedestres piscar, indicando*/
        /* o fim do tempo de travessia.            */
      } else {
        /* Desliga o LED Verde dos pedestres.      */
        digitalWrite(Verde_Pedestres, 0);
        if (fmod(contador, 2) == 0) {
          /* Desliga o LED Vermelho dos pedestres. */
          digitalWrite(Vermelho_Pedestres, 0);
        } else {
          /* Liga o LED Vermelho dos pedestres.    */
          digitalWrite(Vermelho_Pedestres, 1);
        }
      }
      /* Mostra no display o tempo restante de     */
      /* travessia, sem os zeros Ã  esquerda do     */
      /* nÃºmero.                                   */
      display.showNumberDec(contador, false);
      /* ApÃ³s, decrementa 1 do tempo restante.     */
      contador += -1;
      /* Espera 1 segundo para atualizar o contador*/
      delay(1000);
    }
    /* Limpa o display.                            */
    display.clear();
    /* Se o botÃ£o nÃ£o for pressionado, mantenha os */
    /* LEDs da seguinte forma:                     */
  } else {
    /* Liga o LED Verde dos carros.                */
    digitalWrite(Verde_Carros, 1);
    /* Desliga o LED Amarelo dos carros.           */
    digitalWrite(Amarelo_Carros, 0);
    /* Desliga o LED Vermelho dos carros.          */
    digitalWrite(Vermelho_Carros, 0);
    /* Desliga o LED Verde dos pedestres.          */
    digitalWrite(Verde_Pedestres, 0);
    /* Liga o LED Vermelho dos pedestres.          */
    digitalWrite(Vermelho_Pedestres, 1);
  }
}/* Fim do looping infinito.                       */
