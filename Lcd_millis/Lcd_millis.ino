#include<LiquidCrystal.h>


const int rs=13, e=12, d4=8, d5=9, d6=10, d7=11;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

lcd.print("Welcome Champs");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.print(millis()/1000);
  delay(500);
  lcd.clear();
}
