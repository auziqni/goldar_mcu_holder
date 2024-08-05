#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include "Adafruit_Thermal.h"

int milis, lastmillis;

// global variale sound
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// global variable printer

#define TX_PIN 13                        // Pin untuk TX ke RX printer
#define RX_PIN 12                        // Pin untuk RX dari TX printer
SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX
Adafruit_Thermal printer(&mySerial);

void initSound()
{
    mySoftwareSerial.begin(9600);

    if (!myDFPlayer.begin(mySoftwareSerial))
    { // Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
            ;
    }
    Serial.println(F("DFPlayer Mini online."));

    myDFPlayer.volume(30); // Set volume value. From 0 to 30
}

void initPrinter()
{
    mySerial.begin(9600); // Sesuaikan baud rate dengan printer Anda
    printer.begin();      // Memulai printer
}

void tellBloodType(String bloodType, int type)
{

    myDFPlayer.play(type); // a+
    delay(2000);

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
    printer.println(bloodType);

    printer.feed(3); // Beri jarak 2 baris kosong setelah teks
}
void setup()
{
    Serial.begin(9600);
    initPrinter();
    initSound();

    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("ALAT SIAP!");
    printer.feed(2); // Beri jarak 2 baris kosong setelah teks
    Serial.println("ALAT SIAP!");
    delay(5000);
}

void loop()
{

    // tellBloodType("A+", 1);
    // tellBloodType("A-", 2);
    // tellBloodType("B+", 3);
    // tellBloodType("B-", 4);
    // tellBloodType("AB+", 5);
    // tellBloodType("AB-", 6);
    // tellBloodType("O+", 7);
    tellBloodType("O-", 8);
    delay(15000);
}