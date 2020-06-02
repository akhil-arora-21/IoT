int r1=10, r2=11,r3=12,r4=13;
int c1=6,c2=7,c3=8,c4=9;
int colm1,colm2,colm3,colm4;

/*
 * 1, 2 ,3, A
 * 4, 5, 6, B
 * 7, 8, 9, C
 * *, 0, #, D
 */

void setup() {
  // put your setup code here, to run once:
pinMode(r1,OUTPUT); pinMode(r2,OUTPUT);
pinMode(r3,OUTPUT); pinMode(r4,OUTPUT);
pinMode(c1,INPUT); pinMode(c2,INPUT);
pinMode(c3,INPUT); pinMode(c4,INPUT);
Serial.begin(9600);
digitalWrite(c1,HIGH); digitalWrite(c2,HIGH);
digitalWrite(c3,HIGH); digitalWrite(c4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
//Row 1 check
  digitalWrite(r1,LOW); digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH);
  colm1=digitalRead(c1); colm2=digitalRead(c2);
  colm3=digitalRead(c3); colm4=digitalRead(c4);

  if(colm1==LOW || colm2==LOW || colm3==LOW || colm4==LOW)
 {
  if(colm1==LOW){ Serial.println("1"); delay(200); }
  if(colm2==LOW){ Serial.println("2"); delay(200); }
  if(colm3==LOW){ Serial.println("3"); delay(200); }
  if(colm4==LOW){ Serial.println("A"); delay(200); }
 }
delay(30);
//Row 2 check


digitalWrite(r1,HIGH); digitalWrite(r2,LOW);
digitalWrite(r3,HIGH); digitalWrite(r4,HIGH);
colm1=digitalRead(c1); colm2=digitalRead(c2);
colm3=digitalRead(c3); colm4=digitalRead(c4);
if(colm1==LOW){ Serial.println("4"); delay(200); }
if(colm2==LOW){ Serial.println("5"); delay(200); }
if(colm3==LOW){ Serial.println("6"); delay(200); }
if(colm4==LOW){ Serial.println("B"); delay(200); }
delay(30);
//Row 3 check
digitalWrite(r1,HIGH); digitalWrite(r2,HIGH);
digitalWrite(r3,LOW); digitalWrite(r4,HIGH);
colm1=digitalRead(c1); colm2=digitalRead(c2);
colm3=digitalRead(c3); colm4=digitalRead(c4);
if(colm1==LOW){ Serial.println("7"); delay(200); }
if(colm2==LOW){ Serial.println("8"); delay(200); }
if(colm3==LOW){ Serial.println("9"); delay(200); }
if(colm4==LOW){ Serial.println("C"); delay(200); }
delay(30);
//Row 4 check
digitalWrite(r1,HIGH); digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH); digitalWrite(r4,LOW);
colm1=digitalRead(c1); colm2=digitalRead(c2);
colm3=digitalRead(c3); colm4=digitalRead(c4);
if(colm1==LOW){ Serial.println("*"); delay(200); }
if(colm2==LOW){ Serial.println("0"); delay(200); }
if(colm3==LOW){ Serial.println("#"); delay(200); }
if(colm4==LOW){ Serial.println("D"); delay(200); }
delay(30); 

}
