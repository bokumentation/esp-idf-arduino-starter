/**
 * @file arduino_style.cpp
 * @brief Main entry point using Arduino-style setup() and loop().
 */

#include "Arduino.h"
#include "my_components.h" // Use our custom library/components
#include "sdkconfig.h"

#ifdef CONFIG_IDF_TARGET_ESP32C3
const int LED_PIN = 8;
#elif defined(CONFIG_IDF_TARGET_ESP32)
const int LED_PIN = 2;
#endif

static const char *pMY_LED_TAG = "LED";

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
    ESP_LOGI(pMY_LED_TAG, "ON");
    Serial.println("LED HIGH");
    delay(1000);

    digitalWrite(LED_PIN, LOW); // Turn off LED
    ESP_LOGI(pMY_LED_TAG, "OFF");
    Serial.println("LED LOW");
    delay(1000);
}
