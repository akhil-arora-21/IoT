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

int pins[] = { 11 , 10 , 9 , 8  ,7  , 6 , 5, 4 } ;  


void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  for(int i=0;i<7;i++)
  pinMode(pins[i], OUTPUT);
  digitalWrite(4, HIGH);

}


int number=0;

void loop() {
  // put your main code here, to run repeatedly:

for (number =0 ; number<=9 ; number++) {
  for (int i=0; i < 7; i++) {
   digitalWrite(pins[i], digit[number][i]);
  }
  delay(2000);
 }   
}
