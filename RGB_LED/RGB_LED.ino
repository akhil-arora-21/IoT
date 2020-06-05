int Red_Pin=8;
int Green_Pin=10;
int Blue_Pin=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
RGB_color(255,0,0); // Red
delay(1000);
RGB_color(0,255,0); // Green
delay(1000);
RGB_color(0,0,255); // Blue
delay(1000);
RGB_color(255,255,125); // Raspberry
delay(1000);
RGB_color(0,255,255); // Cyan
delay(1000);
RGB_color(255,0,255); // Magenta
delay(1000);
RGB_color(255,255,0); // Yellow
delay(1000);
RGB_color(255,255,255); // White
delay(1000);
}

void RGB_color(int r, int g, int b)
{
analogWrite(Red_Pin,r);
analogWrite(Green_Pin,g);
analogWrite(Blue_Pin,b);
}
