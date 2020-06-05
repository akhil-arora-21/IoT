int cm;
int inches;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  cm=0.01723*readTheValue(2,2);  //timing signsls *0.01723= dist
  inches=cm/2.54;
  Serial.print("Centimeters:");
  Serial.println(cm);
  Serial.print("Inches:");
  Serial.println(inches);
  delay(200);
}

long readTheValue(int trig_pin, int echo_pin)
{
  pinMode(trig_pin, OUTPUT);
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  pinMode(trig_pin, INPUT);

  return pulseIn(echo_pin, HIGH);


}
