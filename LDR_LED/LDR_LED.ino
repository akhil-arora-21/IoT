void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(9,OUTPUT); 
}
boolean flag= false;

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_val= analogRead(A0);
  
    if(ldr_val<=340)
    {
      digitalWrite(9,HIGH);
      
      if(flag==false)
      {
        Serial.println("LED light is ON");
        Serial.print(ldr_val);
        Serial.println(" is the output value of LDR");
        flag=true;
      }
    }
    else
    {
      digitalWrite(9,LOW);
     if (flag==true)
      {
        Serial.println("LED light is OFF");
        Serial.print(ldr_val);
        Serial.println(" is the output value of LDR");
        flag=false;
      }
    }
} 
