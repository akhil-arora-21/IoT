int digit[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};  //binary numbers of 0 to 9 on seven segment display from g to a
                //0bgfedcba
int digit_ones, digit_tens;

void setup() {
  // put your setup code here, to run once:
for(int i=2; i<=10;i++)
pinMode(i,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int num=0;num<=99;num++)//43
{
  digit_tens=num/10;    // 43/10= quotient 4

  digit_ones=num%10;    // 43%10= remainder 3

digitalWrite(9,HIGH); digitalWrite(10,LOW);
show(digit_tens);
delay(10);

digitalWrite(9,LOW); digitalWrite(10,HIGH);
show(digit_ones);

delay(10);  
}

}


void show(int number)
{
for (int i=2; i<9;i++)

  digitalWrite(i,bitRead(digit[number],i-2));
  
}
