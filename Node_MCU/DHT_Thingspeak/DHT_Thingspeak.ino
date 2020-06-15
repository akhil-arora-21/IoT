#include <DHT.h>  // Including library for dht
 
#include <ESP8266WiFi.h>
 
String apiKey = "E0TKCG5NPBZO2YMO";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "NIELIT-SUPER_IoT";     // replace with your wifi ssid and wpa2 key
const char *password =  "NIELIT@30";
const char* server = "api.thingspeak.com";
 
#define DHTPIN 0          //pin where the dht11 is connected
 
DHT dht(DHTPIN, DHT11);
 
WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
       dht.begin();
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, password);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
  
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
              if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }
 
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;    // postStr=E0TKCG5NPBZO2YMO
                             postStr +="&field1=";       // postStr=E0TKCG5NPBZO2YMO&field1=
                             postStr += String(t);       // postStr=E0TKCG5NPBZO2YMO&field1=27.00
                             postStr +="&field2=";       // postStr=E0TKCG5NPBZO2YMO&field1=27.00&field2=
                             postStr += String(h);       // postStr=E0TKCG5NPBZO2YMO&field1=27.00&field2=32
                             postStr += "\r\n\r\n";      // postStr= "E0TKCG5NPBZO2YMO&field1=27.00&field2=32\r\n\r\n"
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print("*C, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  delay(5000);
}
