// library utama
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); // RX, TX

/*--------Print barcode instruction, including information  “DFR0503”---------*/
char bar_code[24] = {
    0x1b, 0x40,
    0x1d, 0x48, 0x02,                                                            // the 43rd command of the general instruction, select the print address of the information (HRI character)included in the barcode.0×02 means that the printed information should be below the barcode.
    0x1d, 0x68, 0x64,                                                            // set barcode height, range”1~255”, here we set it to “0×64” .
    0x1d, 0x77, 0x03,                                                            // the 45th command of the general instruction, set horizontal width, here we select “0×03”.
    0x1d, 0x6b, 0x49, 0x09, 0x7B, 0x42, 0x44, 0x46, 0x52, 0x7B, 0x43, 0x05, 0x03 // set the information included in barcode. Barcode length “0×09” correspond to ”DFR0503”. “0×44, 0×46, 0×52” are ACILL codes of the three letter D,F,R respectively. “0×05, 0×03” is “0503”.
}; // if the information is “DFR050308”, the barcode length should be”0×0B”, and so on.

/*--------Print QR code instruction, including information”www.dfrobot.com”---------*/
const char QRx[60] = {
    0x1b, 0x40,
    0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x43, 0x05,                                                                                           // Refer to the 1st command of special instruction set.QR code size “0×05”
    0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x45, 0x30,                                                                                           // Set QR code verification level to L.
    0x1d, 0x28, 0x6b, 0x12, 0x00, 0x31, 0x50, 0x30, 0x77, 0x77, 0x77, 0x2E, 0x64, 0x66, 0x72, 0x6F, 0x62, 0x6F, 0x74, 0x2E, 0x63, 0x6F, 0x6D, // “0x12” is the number of the character(15) of the information”www.dfrobot.com” that was included in QR code plus 3.                                                                     //“0x77,0x77,0x77,0x2E,0x64,0x66,0x72,0x6F,0x62,0x6F,0x74,0x2E,0x63,0x6F,0x6D” are the ACILL code of the characters of the website address.
    0x1b, 0x61, 0x01,                                                                                                                         // centre the graphic
    0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x52, 0x30,                                                                                           // Verify the QR code
    0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x51, 0x30                                                                                            // print the QR code
};
void setup()
{
    mySerial.begin(9600);
    Serial.begin(9600);
    while (Serial.read() >= 0)
    {
    }
}
void loop()
{
    mySerial.println();
    mySerial.print("---------------------------------");
    mySerial.println();
    mySerial.write(bar_code, 60); // send “print barcode instruction” to printer
    delay(5);
    mySerial.println();
    mySerial.write(QRx, 60); // send “print QR code instruction” to printer.
    mySerial.println();
    mySerial.print("---------------------------------");
    delay(5000);
}