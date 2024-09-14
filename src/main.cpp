#include <Arduino.h>

#define RX 3
#define TX 1
#define LED 16

void setup() {
  Serial.begin(115200, SERIAL_8N1, RX, TX);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    char cmd = Serial.read();
    if(cmd == 'a') {
      digitalWrite(LED, HIGH);
    } else if(cmd == 'b') {
      digitalWrite(LED, LOW);
    }
  }
}