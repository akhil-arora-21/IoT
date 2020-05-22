const int LedPin=13;
const int ButtonPin=2;

int ButtonState=0;

void setup() {
  // put your setup code here, to run once:
pinMode(ButtonPin, INPUT);
pinMode(LedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ButtonState=digitalRead(ButtonPin);

  if(ButtonState==HIGH)
  {
    digitalWrite(LedPin, HIGH);
  }
  else
  {
    digitalWrite(LedPin, LOW);
  }

}
