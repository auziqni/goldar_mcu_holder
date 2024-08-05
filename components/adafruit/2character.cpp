#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

// Pilih pin untuk komunikasi serial
#define TX_PIN 13 // Pin untuk TX ke RX printer
#define RX_PIN 12 // Pin untuk RX dari TX printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX
Adafruit_Thermal printer(&mySerial);
void printHorizontalLine()
{
    printer.setSize('S'); // Kembali ke ukuran font normal untuk garis
    for (int i = 0; i < 32; i++)
    { // Sesuaikan jumlah karakter dengan lebar kertas printer
        printer.print('=');
    }
    printer.println(); // Pindah ke baris berikutnya setelah garis selesai
}

void setup()
{
    mySerial.begin(9600); // Sesuaikan baud rate dengan printer Anda
    printer.begin();      // Memulai printer

    printer.underlineOn();
    printer.println(F("CHARACTER SET EXAMPLE\n"));
    printer.underlineOff();

    printHorizontalLine();
    printHorizontalLine();
    printHorizontalLine();

    printer.setDefault(); // Restore printer to defaults

    printer.feed(3); // Beri jarak 3 baris kosong setelah teks
}

void loop()
{
    // Tidak ada kode di loop
}
