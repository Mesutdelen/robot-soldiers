#include <SD.h> // Sd kart kutuphanesi
#define SD_ChipSelectPin 4 //mega icin cs pini.
#include <TMRpcm.h> // waw okuma kutuphanesi
#include <SPI.h>// seri haberleşme kütüphanesi
#include "Wire.h"
#include <TEA5767Radio.h>
TEA5767Radio radio = TEA5767Radio();
TMRpcm tmrpcm;
String gelenses;
void setup() {
  
pinMode(12,OUTPUT);
{
Wire.begin();
radio.setFrequency(93.0); // pick your own frequency
}
Serial.begin(57600);
pinMode(SD_ChipSelectPin,OUTPUT);
Serial.begin(9600);
tmrpcm.speakerPin = 9;
tmrpcm.volume(100);
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD okuyamadi");
return;
}
tmrpcm.play("1.wav");
}
//-----------------------------------------------------------------------//
void loop() {
//-------------------------------------------------------------------
while (Serial.available()){
  
delay(10);
char c = Serial.read();
if (c == '#') {break;}
gelenses += c;
}
if (gelenses.length() > 0) {
Serial.println(gelenses);
//-----------------------------------------------------------------------//

if(gelenses == "*sen kimsin"){ tmrpcm.play("2.wav");}
if(gelenses == "*Sen abdülhamit'i savundun"){ tmrpcm.play("3.wav");}
if(gelenses == "*Vatanına göz dikeni ez oğlum."){ tmrpcm.play("4.wav");}
if(gelenses == "*atlayamazsın"){ tmrpcm.play("5.wav");}
if(gelenses == "*messi mi ronaldo mu"){ tmrpcm.play("6.wav");}
if(gelenses == "*son bir şarkı istiyorum senden kardeş" || "*ışık"){tmrpcm.play("7.wav");}
if(gelenses == "*damar"){ tmrpcm.play("6.wav");}
else {tmrpcm.play("geri.wav"); }
gelenses="";}
delay(1000); // every second
} //resetleme
//---------------------------------------------------------------------------------------------------------------------------------