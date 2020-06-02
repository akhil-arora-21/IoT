int Ledpin=12;
int brightness=0;
int fadeamount=5;

void setup() {
  // put your setup code here, to run once:
pinMode(Ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(Ledpin, brightness);

brightness= brightness + fadeamount;

if(brightness>=255 || brightness<=0)

fadeamount= -fadeamount; // -(-5)= +5

delay(50);

}
