#include "arduino_secrets.h"

/*

*/

void setup() {
    pinMode(9, OUTPUT);
    pinMode(13, INPUT);
}

void loop() {
    digitalWrite(9, HIGH);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
}
