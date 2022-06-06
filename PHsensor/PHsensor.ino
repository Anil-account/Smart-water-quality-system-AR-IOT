#include <stdlib.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial nodemcu(5,6);  //rx, tx

String value="";
float phval;

const int analogInPin = A0; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;


void setup() {

 Serial.begin(9600);
 nodemcu.begin(9600);
 Serial.println("Progran started");
 
}

void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();

 ph_data();

 data["PhData"] = phval;
 data.printTo(nodemcu);
 jsonBuffer.clear();
 Serial.println(phval);
 
 delay(200);
}



void ph_data(){
   for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 Serial.print("sensor = ");
 phval = phValue;
 value = phValue;
  
 }


 
