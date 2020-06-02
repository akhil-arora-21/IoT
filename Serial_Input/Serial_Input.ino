void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c=Serial.read();

  if(c==3)
  {
    digitalWrite(13,HIGH);
    Serial.println("Light is on");
    delay(1000);
  }

  if(c==4)
  {
    digitalWrite(13,LOW);
    Serial.println("Light is off");
    delay(1000);
  }
  
  delay(1000);

}
