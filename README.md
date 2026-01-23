# ESP-IDF Arduino Starter

Available language: EN | IDN

This is my boilerplate for starting ESP-IDF by using arduino-esp32 as components. Just clone then build.
There are so many terms, so I tried to make this tutorial as clear as possible for who wanna migrate from an Arduino IDE.

Features:
- LSP and code navigation support by `clangd`
- Code formatting by `clang-format` based on [ESP-IDF Style Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/contribute/style-guide.html).
- Pyhton script for removing gcc '-m*' and '-f*' flags from the `compile_commands.json`.
- EditorConfig configuration for consistency across code editor.

## Requirements

- Installed ESP-IDF, follow this tutorial based on you OS.
- VS Code with clangd extension for code navigation.
- An internet connection.

---

### Get Started

1. Open ESP-IDF terminal environment, then navigate in your favourite folder (eg. `./projects`).
2. Clone this repo then navigate into it.
    ```bash
    git clone
    cd
    ```
3. Set target MCU. Let's say i wanna use `ESP32C3`.
    ```bash
        idf.py set-target esp32c3
    ```
4. Build the firmware.
    ```
    idf.py build
    ```
5. Flash to your esp.
    ```
    idf.py flash
    ```
6. Open serial monitor using esp-idf built in feature.
    ```
    idf.py monitor
    ```
