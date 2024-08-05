#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial thermalPrinter(2, 3); // RX, TX

// Tempatkan bitmap 64x128 Anda di sini
const unsigned char bitmap[] PROGMEM = {
  // Ganti dengan data bitmap 64x128 Anda
  // Setiap baris akan memiliki 8 byte (64 pixel / 8 bit per byte)
  // Total akan ada 128 baris, jadi total ukuran array adalah 8 * 128 = 1024 byte
};

void setup() {
  thermalPrinter.begin(9600);
  delay(1000);
  
  // Inisialisasi printer
  thermalPrinter.write(27);
  thermalPrinter.write(64);
  delay(500);

  // Cetak bitmap
  printBitmap(64, 128);
}

void loop() {
  // Tidak ada yang perlu dilakukan di sini
}

void printBitmap(int width, int height) {
  int widthBytes = (width + 7) / 8; // Akan menjadi 8 untuk lebar 64 pixel

  // Kirim perintah untuk mencetak bitmap
  thermalPrinter.write(18);  // DC2
  thermalPrinter.write(42);  // *
  thermalPrinter.write(height & 255); // Tinggi bitmap (byte rendah)
  thermalPrinter.write(height >> 8);  // Tinggi bitmap (byte tinggi)
  thermalPrinter.write(widthBytes);   // Lebar bitmap dalam byte

  // Kirim data bitmap
  for (int i = 0; i < height * widthBytes; i++) {
    thermalPrinter.write(pgm_read_byte(&bitmap[i]));
  }

  // Tambahkan baris kosong setelah bitmap
  thermalPrinter.write(10);

  // Potong kertas
  thermalPrinter.write(29);
  thermalPrinter.write(86);
  thermalPrinter.write(66);
  thermalPrinter.write(3);
}