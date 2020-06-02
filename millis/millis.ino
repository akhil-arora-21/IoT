void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//~0ms
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=millis();//~0ms
  Serial.print(val);//~0ms
  Serial.println(" is the time elapsed after the recent reset of arduino");//1ms
  delay(1000);//1ms*1000=1000
}
