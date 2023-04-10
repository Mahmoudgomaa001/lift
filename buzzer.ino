const int buzzer = 9; //buzzer to arduino pin 9

void buzzerSetup() {
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}
void dingO()
{
  tone(buzzer, 200);
  delay(350);
  noTone(buzzer);
  delay(110);
  tone(buzzer, 300);
  delay(350);
  tone(buzzer, 400);
  delay(450);
  noTone(buzzer);
}


void dingC()
{
  tone(buzzer, 400);
  delay(450);
  noTone(buzzer);
  delay(110);
  tone(buzzer, 200);
  delay(350);
  noTone(buzzer);
}
