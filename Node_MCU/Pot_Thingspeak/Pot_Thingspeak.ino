
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

// set your Router user name and passward
char ssid[] = "NIELIT-SUPER_IoT";          //  your network SSID (name) 
char pass[] = "NIELIT@30";   // your network password

int status = WL_IDLE_STATUS;
WiFiClient  client;

int sensorValue; // variable to save analog reading
int gasValue; // variable to save analog reading

// that you have already remembered from ThingSpeak websie
unsigned long myChannelNumber = 1080431;// Enter your channel number
const char * myWriteAPIKey = "8WDJ5YOU776KT69B"; // Enter the api Key

void setup() {
  WiFi.begin(ssid, pass); 
  ThingSpeak.begin(client);
}

void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  gasValue = analogRead(A0);
  // Write to ThingSpeak. 
  // send your Channel Number
  // write to field 1
  // send sensorValue
  // send your Write API Key
  ThingSpeak.writeField(myChannelNumber, 1, sensorValue, myWriteAPIKey);
  delay(100);
  ThingSpeak.writeField(myChannelNumber, 2, sensorValue, myWriteAPIKey);
  delay(5000); // ThingSpeak will accept updates every 5 seconds.
}
