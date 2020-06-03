#include<LiquidCrystal.h>
int rs=5 , e=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=10, r2=11, r3=12, r4=13 ;
int c1=6, c2=7, c3=8 ,c4=9 ;
/*
 * 7 8 9 / 
 * 4 5 6 * 
 * 1 2 3 -                  65 + 17=
 * C 0 = +
 */

void setup()
{ 
  lcd.begin(16,2); lcd.print("LCD Keypad ex" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
  lcd.setCursor(0,1);
}

  long int n=0,n1=0,result=0;

  char opr=' ';
  
  void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("7"); n=n*10+7;delay(300);   }    //n=1*10+7=17
  if(digitalRead(c2)==LOW){ lcd.print("8"); n=n*10+8; delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("9"); n=n*10+9;delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("/"); n1=n; n=0;  opr='/'; delay(300);  }
  
  //make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4"); n=n*10+4; delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("5"); n=n*10+5; delay(300);  }    //n=6*10+5=65
  if(digitalRead(c3)==LOW){ lcd.print("6"); n=n*10+6; delay(300);  }      //n=6
  if(digitalRead(c4)==LOW){ lcd.print("*"); n1=n; n=0;  opr='*';  delay(300);  }

  //make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("1"); n=n*10+1; delay(300);  }   //n=1
  if(digitalRead(c2)==LOW){ lcd.print("2"); n=n*10+2; delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("3"); n=n*10+3; delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("-"); n1=n; n=0;opr='-'; delay(300);  }
  
  //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ lcd.clear();n=0;n1=0; delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("0"); n=n*10+ 0; delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("="); delay(300); 
    if (opr=='+')
{
      result=n+n1; lcd.print(result);
}
    if (opr=='-')
{
      result=n1-n; lcd.print(result);
}
    if (opr=='/')
{
      result=n1/n; lcd.print(result);
}
    if (opr=='*')
{
      result=n1*n; lcd.print(result);
}
      }
if(digitalRead(c4)==LOW){ lcd.print("+"); n1=n; n=0; opr='+'; delay(300);  }     //n1=65, n=0
}