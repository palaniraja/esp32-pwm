#include <Arduino.h>

#define GPIO_TX 21
#define GPIO_LED 8

void setup() {
    Serial.begin(115200);
    Serial.println("Setup done");
}


void loop() {
    Serial.println("loop");
}