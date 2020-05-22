const int LedPin1=13;
const int LedPin2=12;
const int LedPin3=11;
const int LedPin4=10;
const int ButtonPin=2;

int ButtonState=0;
int count=0;

void setup() {
  // put your setup code here, to run once:
pinMode(ButtonPin, INPUT);
pinMode(LedPin1, OUTPUT);
pinMode(LedPin2, OUTPUT);
pinMode(LedPin3, OUTPUT);
pinMode(LedPin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ButtonState=digitalRead(ButtonPin);
  
  while(digitalRead(ButtonPin)==LOW);
 
  if(ButtonState==HIGH)
  {
    count++;
    while(digitalRead(ButtonPin)==HIGH);
  }
  
  
  if(count==1)
   { 
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, HIGH);
    digitalWrite(LedPin4, HIGH);
    delay(1000);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    digitalWrite(LedPin4, LOW);
    delay(1000);
    }

  if(count==2)
   { 
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, LOW);
    digitalWrite(LedPin4, LOW);
    delay(1000);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, HIGH);
    digitalWrite(LedPin4, HIGH);
    delay(1000);
    }
      if(count==3)
   { 
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    digitalWrite(LedPin4, HIGH);
    delay(1000);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, HIGH);
    digitalWrite(LedPin4, LOW);
        delay(1000);
    }
    
      if(count==4)
   { 
    digitalWrite(LedPin1, HIGH);
    delay(1000);
    digitalWrite(LedPin1, LOW);
    delay(1000);
    digitalWrite(LedPin2, HIGH);
    delay(1000);
    digitalWrite(LedPin2, LOW);
    delay(1000);
    digitalWrite(LedPin3, HIGH);
    delay(1000);
    digitalWrite(LedPin3, LOW);
    delay(1000);
    digitalWrite(LedPin4, HIGH);
    delay(1000);
    digitalWrite(LedPin4, LOW);
    delay(1000);
    count=0;
    }
   

    
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    digitalWrite(LedPin4, LOW);
    delay(1000);
}
