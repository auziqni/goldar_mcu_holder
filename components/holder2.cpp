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
    // switch (type)
    // {
    // case 1:
    //   myDFPlayer.play(1); // a+
    //   break;
    // case 2:
    //   myDFPlayer.play(2); // a-
    //   break;
    // case 3:
    //   myDFPlayer.play(3); // b+
    //   break;
    // case 4:
    //   myDFPlayer.play(4); // b-
    //   break;
    // case 5:
    //   myDFPlayer.play(5); // ab+
    //   break;
    // case 6:
    //   myDFPlayer.play(6); // ab-
    //   break;
    // case 7:
    //   myDFPlayer.play(7); // o+
    //   break;
    // case 8:
    //   myDFPlayer.play(8); // o-
    //   break;
    // default:
    //   myDFPlayer.play(8); // o-
    //   break;
    // }

    if (bloodType == "A+")
    {
        myDFPlayer.play(1); // a+
    }
    else if (bloodType == "A-")
    {
        myDFPlayer.play(2); // a-
    }
    else if (bloodType == "B+")
    {
        myDFPlayer.play(3); // b+
    }
    else if (bloodType == "B-")
    {
        myDFPlayer.play(4); // b-
    }
    else if (bloodType == "AB+")
    {
        myDFPlayer.play(5); // ab+
    }
    else if (bloodType == "AB-")
    {
        myDFPlayer.play(6); // ab-
    }
    else if (bloodType == "O+")
    {
        myDFPlayer.play(7); // o+
    }
    else if (bloodType == "O-")
    {
        myDFPlayer.play(8); // o-
    }
    else
    {
        myDFPlayer.play(8); // o-
    }

    // printer.setSize('M');
    // printer.justify('C'); // Menyelaraskan teks ke tengah
    // printer.println("KARTU TEST");
    // printer.println("GOLONGAN DARAH");

    // printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    // printer.justify('M'); // Kembali ke penyelarasan kiri
    // printer.println("NAMA :");
    // printer.println("UMUR :");

    // printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    // printer.justify('C'); // Menyelaraskan teks ke tengah
    // printer.setSize('S');
    // printer.println("HASIL");
    // printer.setSize('L');
    // printer.println(bloodType);

    // printer.feed(3); // Beri jarak 2 baris kosong setelah teks
}
void setup()
{
    Serial.begin(9600);
    initSound();
    initPrinter();
    delay(5000);

    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("ALAT SIAP!");
    printer.feed(2); // Beri jarak 2 baris kosong setelah teks
    Serial.println("ALAT SIAP!");
    delay(5000);
}

void loop()
{
    milis = millis();
    int dif = milis - lastmillis;
    Serial.println(dif);
    if (dif > 15000)
    {
        lastmillis = milis;
        Serial.println("A-");
        tellBloodType("A-", 2);
    }
    // tellBloodType("A+", 1);
    // tellBloodType("A-", 2);
    // tellBloodType("B+", 3);
    // tellBloodType("B-", 4);
    // tellBloodType("AB+", 5);
    // tellBloodType("AB-", 6);
    // tellBloodType("O+", 7);
    // tellBloodType("O-", 8);
    // delay(15000);
}