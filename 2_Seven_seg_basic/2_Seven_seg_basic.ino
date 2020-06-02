int digit[10][7] = {      { 0,0,0,0,0,0,1 },    // 0
                          { 1,0,0,1,1,1,1 },    // 1
                          { 0,0,1,0,0,1,0 },    // 2
                          { 0,0,0,0,1,1,0 },    // 3
                          { 1,0,0,1,1,0,0 },    // 4
                          { 0,1,0,0,1,0,0 },    // 5
                          { 0,1,0,0,0,0,0 },    // 6
                          { 0,0,0,1,1,1,1 },    // 7
                          { 0,0,0,0,0,0,0 },    // 8
                          { 0,0,0,1,1,0,0 }};   // 9
                          // a,b,c,d,e,f,g 

int Seg1_pins[] = { 0 , 1 , 2 , 3  ,4  , 5 , 6} ;  
int Seg2_pins[] = { 7 , 8 , 9 , 10  ,11  , 12 , 13} ;  

void setup() {
  // put your setup code here, to run once
  for(int i=0;i<7;i++)
  {
    pinMode(Seg1_pins[i], OUTPUT);
    pinMode(Seg2_pins[i], OUTPUT);
  }
  

}


int number=0;
int buttonState=0;

void loop() {
  // put your main code here, to run repeatedly:


for(int i=0;i<10;i++)//for tens digit
{

    for (int m=0; m < 7; m++) { //for displaying tens digit
          
          digitalWrite(Seg2_pins[m], digit[i][m]);
      }


for(int j=0;j<10;j++)//for ones digit
{
for (int l=0; l < 7; l++) {  //for displaying ones digit
   digitalWrite(Seg1_pins[l], digit[j][l]);
  }
  delay(1000);  
}

}
}
