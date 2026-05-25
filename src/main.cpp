#include <Arduino.h>
#include <HardwareSerial.h>

#define GPIO_RX0 20
#define GPIO_TX0 21

#define GPIO_RX1 3
#define GPIO_TX1 4

#define GPIO_LED 8

#define GPIO_ALWAYS_ON 10

#define GPIO_IN_TEST GPIO_LED

#define RX_PIN GPIO_RX1
#define TX_PIN GPIO_TX1

// Default RX/TX is used by USB-CDC*, cant use it to analyze with logic analyzer (will always be high)

// override HardwareSerial::begin case UART_NUM_1: to match custom RX1/TX1
// in .platformio/packages/framework-arduinoespressif32/cores/esp32/HardwareSerial.cppHardwareSerial.cpp
// void HardwareSerial::begin(unsigned long baud, uint32_t config, int8_t rxPin, int8_t txPin, bool invert, unsigned long timeout_ms, uint8_t rxfifo_full_thrhd)

// https://support.saleae.com/protocol-analyzers/analyzer-user-guides/using-async-serial

HardwareSerial Serial2(1);

void setup()
{
    Serial.begin(115200);
    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_TX1, OUTPUT);

    Serial2.begin(115200);

    delay(5000);                           // delay to start serial monitor
    Serial.println("serial setup done");   // should showup in default uart/serial monitor
    Serial2.println("serial2 setup done"); // should show up in logic analyzer
}

// Blink LED
void pulseLED(int duration)
{
    digitalWrite(GPIO_LED, HIGH);
    delay(duration);
    digitalWrite(GPIO_LED, LOW);
    delay(duration);
}

void loop()
{
    Serial.printf("loop..");   // default uart/serial output
    Serial2.printf("loop2.."); // it should showup in logic analyzer (Async serial / 115200 8-N-1 / ASCII)
    pulseLED(500);
}
