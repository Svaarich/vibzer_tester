#include <Arduino.h>

#define VIBRO 9
#define BUZZER 6
#define BUTTON 3

void reset();

void setupPins() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VIBRO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void ring(int state) {
  if (state == HIGH) {
    analogWrite(BUZZER, 80);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    reset();   
  }
}

void vibrate(int state) {
  if (state == HIGH) {
    digitalWrite(VIBRO, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    reset();
  }
}

void reset() {
  digitalWrite(VIBRO, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  setupPins();
}

void loop() {
  vibrate(digitalRead(BUTTON));
  ring(digitalRead(BUTTON));
}

