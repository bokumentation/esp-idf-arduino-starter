# Dokumentasi Teknis (Technical Documentation)

Dokumen ini menjelaskan infrastruktur pengembangan yang digunakan dalam boilerplate ini. Jika Anda terbiasa dengan Arduino IDE, alat-alat di bawah ini adalah yang memberikan fitur "pintar" (seperti auto-complete dan format otomatis) di lingkungan ESP-IDF.

### 1. Clangd (Language Server)

Di Arduino IDE, navigasi kode dilakukan secara otomatis (tekan `ctrl + klik`). Di ESP-IDF, kita menggunakan `Clangd` untuk memberikan fitur serupa.

- Fungsi: Memberikan fitur Auto-complete, Go to Definition, dan peringatan error secara real-time.
- Mengapa ini perlu?: ESP-IDF memiliki ribuan file header. Tanpa Clangd, editor tidak akan tahu di mana letak fungsi seperti initArduino() atau gpio_config().
- Setup: Skrip setup.sh akan secara otomatis menautkan konfigurasi .clangd yang sesuai dengan sistem operasi Anda (Windows, Linux, atau macOS) agar jalur (path) header terdeteksi dengan benar.

### 2. Clang-format

Arduino IDE memiliki fitur "*Auto Format*" (`Ctrl+T`). `Clang-format` adalah versi yang jauh lebih kuat dan profesional dari fitur tersebut.

- Fungsi: Merapikan penulisan kode (spasi, tanda kurung, baris baru) secara otomatis sesuai aturan tertentu.
- Aturan yang Digunakan: Proyek ini dikonfigurasi mengikuti `Espressif Style Guide`.
- Cara Kerja: Setiap kali Anda menyimpan file, editor akan merapikan kode Anda agar selalu terlihat rapi dan konsisten dengan tim pengembang lainnya.

### 3. Pre-commit

Ini adalah "penjaga gerbang" sebelum Anda menyimpan perubahan ke dalam Git (*Version Control*).

- Fungsi: Menjalankan serangkaian pengecekan otomatis (seperti `Clang-format` dan pemeriksaan file `YAML`) sesaat sebelum Anda melakukan `git commit`.

- Mengapa ini penting?: Untuk memastikan tidak ada kode yang "berantakan" atau file yang rusak terunggah ke repositori. Jika ada kesalahan format, `pre-commit` akan membatalkan commit Anda dan meminta Anda merapikannya terlebih dahulu.

- AStyle: Selain `Clang-format`, kita juga menggunakan astyle_py untuk memastikan format tambahan pada file C/C++ sesuai dengan aturan internal Espressif.

### 4. EditorConfig

Perbedaan teks editor (seperti VS Code, Zed, atau Notepad++) seringkali memiliki aturan spasi atau tab yang berbeda.

- Fungsi: Memberitahu editor kode apa pun yang Anda gunakan untuk selalu menggunakan aturan dasar yang sama.

- Konfigurasi Kita:
    - Menggunakan 4 spasi untuk indentasi (bukan tab).
    - Memastikan setiap file berakhir dengan satu baris kosong (standar POSIX).
    - Menggunakan karakter akhir baris LF (Unix *style*) agar tidak terjadi konflik antara pengguna Windows dan Linux.

---

## Alur Kerja Pengembangan (Workflow)

1. **Setup:** Jalankan `./setup.sh` satu kali setelah clone.
1. **Coding:** Tulis kode Anda di `main/main.cpp`. `Clangd` akan membantu Anda menemukan fungsi.
1. **Save:** `EditorConfig` dan `Clang-format` akan menjaga kerapihan kode saat Anda menyimpan file.
1. **Commit:** Saat menjalankan `git commit`, `pre-commit` akan memastikan semuanya sudah sempurna sebelum disimpan ke sejarah Git.

> Tips untuk Pengguna Arduino
>
> Jika Anda melihat banyak garis merah di editor padahal kode bisa di-build, biasanya itu karena Clangd belum selesai memproses indeks. Cobalah jalankan perintah "Clangd: Restart language server" di VS Code setelah melakukan idf.py build.
