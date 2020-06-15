#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char *ssid = "NIELIT-SUPER_IoT"; //Your Network SSID
 
const char *password = "NIELIT@30"; //Your Network Password
 
int val;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
 
 
 
WiFiClient client;
 
unsigned long myChannelNumber = 1080351; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "RQL8ZT7EY5HIA6N2"; //Your Write API Key
 
void setup()
 
{
 
Serial.begin(9600);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
 
 
ThingSpeak.begin(client);
 
}
 
 
 
void loop()
 
{
 
val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.print("The value of LDR is:");
Serial.println(val); //Print on Serial Monitor
 
delay(5000);
 
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 
 
 
delay(10000);
 
}
