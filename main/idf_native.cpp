/**
 * @file idf_native.cpp
 * @brief Main entry point using ESP-IDF native style.
 */

#include "Arduino.h"
#include "my_components.h" // Include our custom components/library

const int YOUR_LED_PIN = 2;
static const char *pMY_LED_TAG = "LED";

extern "C" void app_main()
{
    initArduino(); // Initialize the Arduino core

    // Arduino-like setup()
    Serial.begin(115200);
    while (!Serial) {
        ; // Wait for serial port to connect
    }

    pinMode(YOUR_LED_PIN, OUTPUT); // Initialize Pin as Output

    ESP_LOGI("TAG", "HELLO from ESP_LOG Info!");        // ESP-IDF Log Info
    Serial.println("HELLO from ARDUINO Serial Print!"); // Arduino Serial Print
    hello_log_init();                                   // Call function from "my_components"

    delay(3000);

    // Arduino-like loop()
    while (true) {
        digitalWrite(YOUR_LED_PIN, HIGH); // Turn on LED
        ESP_LOGI(pMY_LED_TAG, "ON");
        Serial.println("LED HIGH");
        delay(1000);

        digitalWrite(YOUR_LED_PIN, LOW); // Turn off LED
        ESP_LOGI(pMY_LED_TAG, "OFF");
        Serial.println("LED LOW");
        delay(1000);
    }

    // WARNING: If the program reaches the end of app_main(), the MCU will restart.
}
