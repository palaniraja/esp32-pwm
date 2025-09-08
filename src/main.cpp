#include <Arduino.h>

#define GPIO_TX 21
#define GPIO_LED 8


#define GPIO_ALWAYS_ON 10
#define GPIO_IN_TEST GPIO_LED
#define GPIO_IN_TEST_MIRROR 3

#define DUTY_CYCLE 255

void setup() {
    Serial.begin(115200);
    delay(3000);
    Serial.println("Setup done");

    pinMode(GPIO_IN_TEST, OUTPUT);
    pinMode(GPIO_IN_TEST_MIRROR, OUTPUT);    
    pinMode(GPIO_ALWAYS_ON, OUTPUT);
    
    digitalWrite(GPIO_ALWAYS_ON, HIGH);
}


void loop() {
    Serial.print("loop...");
    // increase the LED brightness
    for (int dutyCycle = 0; dutyCycle <= DUTY_CYCLE; dutyCycle++)
    {
        // changing the LED brightness with PWM
        analogWrite(GPIO_IN_TEST, dutyCycle);
        analogWrite(GPIO_IN_TEST_MIRROR, dutyCycle);
        delay(15);
    }

    // decrease the LED brightness
    for (int dutyCycle = DUTY_CYCLE; dutyCycle >= 0; dutyCycle--)
    {
        // changing the LED brightness with PWM
        analogWrite(GPIO_IN_TEST, dutyCycle);
        analogWrite(GPIO_IN_TEST_MIRROR, dutyCycle);
        delay(15);
    }
}