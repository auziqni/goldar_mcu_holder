#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
    Serial.begin(9600);
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
    myDFPlayer.play(1);    // Play the first mp3
    delay(5000);
}

void loop()
{

    myDFPlayer.play(1); //
    delay(5000);
    myDFPlayer.play(2); // Play the first mp3
    delay(5000);
    myDFPlayer.play(3); // Play the first mp3
    delay(5000);
    myDFPlayer.play(4); // Play the first mp3
    delay(5000);
    myDFPlayer.play(5); // Play the first mp3
    delay(5000);
    myDFPlayer.play(6); // Play the first mp3
    delay(5000);
    myDFPlayer.play(7); // Play the first mp3
    delay(5000);
    myDFPlayer.play(8); // Play the first mp3
    delay(15000);
}