int cm;
int inches;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  cm=0.01723*readTheValue(13,12);  //timing signsls *0.01723= dist
  inches=cm/2.54;
  Serial.print("Centimeters:");
  Serial.println(cm);
  Serial.print("Inches:");
  Serial.println(inches);
  delay(200);
}

long readTheValue(int trig_pin, int echo_pin)
{
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  return pulseIn(echo_pin, HIGH);


}
