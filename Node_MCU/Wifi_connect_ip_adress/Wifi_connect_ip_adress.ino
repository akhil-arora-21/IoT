#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

int ledpin=2;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT);
  delay(5000);
  Serial.println();
  Serial.print("Connecting to WiFi ");
  //WiFi.begin("SSID" , "Password");
  WiFi.begin("NIELIT_LAB3" , "NIELIT@54321");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  // For getting the Local IP
  Serial.print("Use this IP Address to connect to NodeMcu:");
  Serial.print("http://");
  
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledpin,HIGH);
Serial.println("LED HIGH");
delay(1000);
digitalWrite(ledpin,LOW);
Serial.println("LED LOW");
delay(1000);

}
