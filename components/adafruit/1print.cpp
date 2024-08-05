#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

// Pilih pin untuk komunikasi serial
#define TX_PIN 13 // Pin untuk TX ke RX printer
#define RX_PIN 12 // Pin untuk RX dari TX printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX
Adafruit_Thermal printer(&mySerial);

void setup()
{
    mySerial.begin(9600); // Sesuaikan baud rate dengan printer Anda
    printer.begin();      // Memulai printer

    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("KARTU TEST");
    printer.println("GOLONGAN DARAH");

    printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    printer.justify('M'); // Kembali ke penyelarasan kiri
    printer.println("NAMA :");
    printer.println("UMUR :");

    printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.setSize('S');
    printer.println("HASIL");
    printer.setSize('L');
    printer.println("AB+");

    printer.feed(3); // Beri jarak 2 baris kosong setelah teks
}

void loop()
{
    // Tidak ada kode di loop
}
