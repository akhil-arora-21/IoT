#include <ESP8266WiFi.h>
int ledPin=2;
WiFiServer server(80);

void setup() {
  pinMode(ledPin,OUTPUT); 
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to WiFi ");
  
  WiFi.begin("NIELIT_LAB3" , "NIELIT@54321");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  server.begin();
  Serial.println("Server started");
}

void loop() {
  digitalWrite(ledPin, LOW);
  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) { //client ==NULL
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request by the client
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) { // we are checking that request is to turn the LED off
    digitalWrite(ledPin, LOW);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){ // we are checking that request is to turn the LED on
    digitalWrite(ledPin, HIGH);
    value = LOW;
  }
 
   // Return the response in form HTML page
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("");
  client.println("");
  client.println("");
  client.println(""); 
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><h1> Welcome to NIELIT </h1><hr><br>");
  
      client.println("Click <a href=\"/LED=ON\">here on</a> turn the LED ON<br>");   // a href tag is used for hyperlink
  
      client.println("Click <a href=\"/LED=OFF\">here Off</a> turn the LED OFF<br>");
      
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
