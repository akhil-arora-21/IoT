#include<LiquidCrystal.h>
int rs=5 , e=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=10, r2=11, r3=12, r4=13 ;
int c1=6, c2=7, c3=8 ;
/*
 * 1 2 3 
 * 4 5 6 
 * 7 8 9                  
 * C 0 Ch
 */

void setup()
{ 
  lcd.begin(16,2); lcd.print("SECURITY SYSTEM" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);   
  
  lcd.setCursor(0,1); lcd.blink();
}

  long int n=0,n1=0,password=222;

  int count=1;
  boolean isUserValid=false;
  
  void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);

  
  if(digitalRead(c1)==LOW){ lcd.print("*"); n=n*10+1;delay(300);   }    
  if(digitalRead(c2)==LOW){ lcd.print("*"); n=n*10+2; delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("*"); n=n*10+3;delay(300);  }
  
  //make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("*"); n=n*10+4; delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("*"); n=n*10+5; delay(300);  }    
  if(digitalRead(c3)==LOW){ lcd.print("*"); n=n*10+6; delay(300);  }    

  //make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("*"); n=n*10+7; delay(300);  }   
  if(digitalRead(c2)==LOW){ lcd.print("*"); n=n*10+8; delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("*"); n=n*10+9; delay(300);  }
  
  //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ lcd.clear();lcd.print("SECURITY SYSTEMS"); lcd.setCursor(0,1); lcd.blink(); n=0; }      //when we press the button clear

  
  if(digitalRead(c2)==LOW){ lcd.print("*"); n=n*10+ 0; delay(300);  }


  
  if(digitalRead(c3)==LOW){  // Validate the password 222
n1=n;

if(n1==password)
{
  lcd.clear();
  lcd.print("Password Correct");
  lcd.setCursor(0,1); lcd.print("Welcome");
  isUserValid=true;
  count=1;
}
else
{
  digitalWrite(4,HIGH);  // buzzer connected to pin 1 goes high
  delay(200);
  digitalWrite(4,LOW); 
  lcd.clear();
  lcd.print("Password Incorrect");
  lcd.setCursor(0,1);
  isUserValid=false;
}
n=0;
delay(300);
if(isUserValid==false)
{
  count++;
  if(count>=6)
{
  lcd.clear();
  lcd.print("SYSTEM LOCKED");
  digitalWrite(4,HIGH);
  while(1);
}
  
}

  }


  }
