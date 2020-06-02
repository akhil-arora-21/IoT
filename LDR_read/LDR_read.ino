void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldr_val= analogRead(A0);

Serial.print(ldr_val);
Serial.println(" is the output value of LDR");
}
