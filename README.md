# ESP-IDF Arduino Starter

**Language:** [EN](README.md) | [ID](README.id.md)

This is my boilerplate for starting ESP-IDF by using `arduino-esp32` as components. Just clone then build.
There are so many terms, so I tried to make this tutorial as clear as possible for those wanna migrate from an Arduino IDE. Also this is my worksflow.

Features:
- **LSP Support:** Multi-platform `clangd` configuration (Windows/Linux/macOS).
- **Automatic Formatting:** `clang-format` and `AStyle` enforced via pre-commit.
- **Style Compliance:** Follows official [Espressif Style Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/contribute/style-guide.html) for C/C++.
- **EditorConfig** configuration for consistency across code editor.
- **Python script** for removing gcc '-m*' and '-f*' flags from the `compile_commands.json` based on [documentation](https://docs.espressif.com/projects/espressif-ide/en/latest/additionalfeatures/clangd_cdt_support.html).

## Requirements

- **Installed ESP-IDF**, follow this [tutorial](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html) based on you OS.
- Text editor: [**VS Code**](https://code.visualstudio.com/download) with installed extensions:
    - `clangd` for code navigation.
    - `EditorConfig` for consistency across code editor.
- An internet connection.

---

## Get Started

1. Open ESP-IDF terminal environment, then navigate in your favourite folder using `cd` command. (eg. `./projects`).

2. Clone this repo then navigate into it.
    ```bash
    git clone https://github.com/bokumentation/esp-idf-arduino-starter.git
    ```
    ```bash
    cd esp-idf-arduino-starter
    ```

3. Set target MCU, build then flash. Using a standard esp32 as an example.
    ```bash
    idf.py set-target esp32
    ```
    ```bash
    idf.py build
    ```
    ```bash
    idf.py -p <PORT> flash
    ```
    > Replace `<PORT>` with your ESP32's actual serial port (e.g., `COM3` on Windows or `/dev/ttyUSB0` on Linux). You can find this in device manager.
    >
    > Alternative commands: `idf.py build flash`.

4. Open serial monitor using esp-idf built in feature. The onboard LED will begin blinking.
    ```bash
    idf.py -p <PORT> monitor
    ```
    > If your PC just connected to one ESP's, you can use  without set the target `<PORT>`. Eg. `idf.py monitor`.

---

## Choosing Programming Style

You can write your code in either the familiar Arduino style or the native ESP-IDF C++.

### Arduino IDE Style

This style uses the standard `setup()` and `loop()` functions. To enable this, we must enable `Autostart Arduino setup and loop boot` in `idf.py menuconfig` under the `Arduino options` section.

```cpp
// file: main.cpp
#include "Arduino.h"

void setup(){
    Serial.begin(115200);
    while(!Serial){
        ; // Wait for serial port to connect
    }
    Serial.println("Starting up...");
}

void loop(){
    Serial.println("Looping...");
    delay(1000);
}
```

### Native ESP-IDF C++

This style uses the `app_main()` function as the entry point. To use this, simply disable `Autostart Arduino setup and loop boot` in `idf.py menuconfig` or edit the `sdkconfig.defaults`.
```cpp
// file: main.cpp
#include "Arduino.h"

extern "C" void app_main()
{
    initArduino(); // Initialize the Arduino core

    // Arduino-like setup()
    Serial.begin(115200);
    while(!Serial){
        ; // Wait for serial port to connect
    }

    // Arduino-like loop()
    while(true){
        Serial.println("Looping...");
        delay(1000); // Wait for 1 second
    }

    // WARNING: If the program reaches the end of app_main(), the MCU will restart.
}
```

---

LSP Settings:
[docs/TECHNICAL.md](docs/TECHNICAL.md)
