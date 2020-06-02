int ledPin = 9;
int inputPin = 2;
int pirState = 0; // Motion previously detected or Not
int val = 0;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(inputPin, INPUT);
Serial.begin(9600);
}

void loop(){

val=digitalRead(inputPin);
if(val==1)
{
          int ldr_val= analogRead(A0);
          
          if(ldr_val<=340)
           {
              digitalWrite(ledPin,HIGH);
            }
          else
          {
            digitalWrite(ledPin,LOW);
          }
        
  
  if (pirState==0)
  Serial.println("Motion Detected");
   
  pirState=1;
 }

 else
 {
    digitalWrite(ledPin, LOW);
    if (pirState==1)
    Serial.println("Motion Ended");
    digitalWrite(ledPin,LOW);
    pirState=0;
 }
 }
