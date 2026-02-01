/**
 * @file main.cpp
 * @brief Main entry point using Arduino-style setup() and loop().
 */

#include "Arduino.h"
#include "my_components.h"

const int LED_PIN = 2; // Use pin GPIO 2 for OUTPUT
static const char *TAG = "EXAMPLE";

void setup()
{
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect
    }

    pinMode(LED_PIN, OUTPUT); // Initialize Pin as Output

    ESP_LOGI("TAG", "HELLO from ESP_LOG Info!");        // ESP-IDF Log Info
    Serial.println("HELLO from ARDUINO Serial Print!"); // Arduino Serial Print
    hello_log_init();                                   // Call function from "my_components.h"

    delay(3000);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    ESP_LOGI(TAG, "From ESP_LOGI: LED ON");
    Serial.println("From Serial.println: LED ON");
    printf("From printf: LED ON\n");
    delay(1000);

    digitalWrite(LED_PIN, LOW); // Turn off LED
    ESP_LOGI(TAG, "From ESP_LOGI: LED OFF");
    Serial.println("From Serial.println: LED OFF");
    printf("From printf: LED OFF\n");
    delay(1000);
}
