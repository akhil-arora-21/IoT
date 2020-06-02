#include<LiquidCrystal.h>

const int rs=13, e=12, d4=8, d5=9, d6=10, d7=11;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Champs of NIELIT");
  lcd.setCursor(0, 1); // column, row
  lcd.print("CHANDIGARH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(6, 0); // column, row
  lcd.print("IoT");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  //lcd.autoscroll();
  lcd.print("Arduino Uno");
  //lcd.scrollDisplayLeft();
  delay(500);
  
  lcd.setCursor(6, 1); 
  lcd.print(millis()/1000);
  delay(500);
  lcd.clear();
}
