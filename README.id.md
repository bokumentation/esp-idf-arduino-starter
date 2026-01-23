# ESP-IDF Arduino Starter

Bahasa: [EN](README.md) | [ID](README.id.md)

Ini adalah *boilerplate* atau kerangka proyek saya untuk memulai ESP-IDF dengan menggunakan `arduino-esp32`.

Terdapat banyak istilah di repo ini, jadi saya mencoba membuat tutorial ini sejelas mungkin bagi kaum-kaum yang ingin bermigrasi dari Arduino IDE. Proyek ini juga mencerminkan alur kerja (*workflow*) yang saya gunakan.

### Fitur:

- Dukungan LSP: Konfigurasi `clangd` multi-platform (Windows/Linux/macOS).
- Format Otomatis: Penggunaan `clang-format` dan `AStyle` yang dipaksakan melalui `pre-commit hooks`.
- Mengikuti panduan [Espressif Style Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/contribute/style-guide.html) untuk C/C++.
- Konfigurasi `EditorConfig`: Untuk konsistensi antar editor kode.
- Skrip Python: Untuk menghapus flag gcc `-m*` dan `-f*` dari compile_commands.json berdasarkan agar `clangd` bekerja maksimal.

## Syarat

- ESP-IDF Terinstal, ikuti [tutorial ini](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html) dan sesuaikan dengan sistem operasi Anda.
- Editor teks: [**VS Code**](https://code.visualstudio.com/download) dengan ekstensi terinstal:
    - `clangd` untuk navigasi kode.
    - `EditorConfig` untuk konsistensi format editor.
- Koneksi internet.

## Cara Memulai
1. Buka terminal ESP-IDF, lalu navigasikan ke folder favorit Anda menggunakan perintah `cd` (misal: `./projects`).

2. Clone repositori ini kemudian masuk ke dalam foldernya.
    ```bash
    git clone https://github.com/bokumentation/esp-idf-arduino-starter.git
    ```
    ```bash
    cd esp-idf-arduino-starter
    ```

3. Tentukan target MCU, build, lalu flash. Menggunakan ESP32 standar sebagai contoh:
    ```bash
    idf.py set-target esp32
    ```
    ```bash
    idf.py build
    ```
    ```bash
    idf.py -p <PORT> flash
    ```
    > Ganti <PORT> dengan port serial asli ESP32 Anda (contoh: COM3 di Windows atau /dev/ttyUSB0 di Linux). Anda bisa menemukannya di Device Manager.
    >
    > Perintah alternatif: idf.py build flash.

4. Buka serial monitor menggunakan fitur bawaan ESP-IDF. LED bawaan (onboard) akan mulai berkedip.
    ```bash
    idf.py -p <PORT> monitor
    ```
    > Jika PC Anda hanya terhubung ke satu ESP, Anda bisa langsung menggunakan idf.py monitor tanpa menentukan <PORT>.

## Memilih Gaya Pemrograman

Anda dapat menulis kode dalam gaya Arduino yang sudah dikenal atau gaya asli (native) ESP-IDF C++.

### Gaya Arduino IDE

Gaya ini menggunakan fungsi standar `setup()` dan `loop()`. Untuk mengaktifkan ini, kita harus mencentang `Autostart Arduino setup and loop boot` di dalam `idf.py menuconfig` pada bagian `Arduino options`.

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

### Gaya Native ESP-IDF C++

Gaya ini menggunakan fungsi `app_main()` sebagai titik masuk utama (*entry point*). Untuk menggunakan ini, cukup matikan fitur `Autostart Arduino setup and loop boot` di `idf.py menuconfig` atau edit file `sdkconfig.defaults`.

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

Pengaturan LSP:
[docs/TECHNICAL.id.md](docs/TECHNICAL.id.md).
