//int number_steps = 512; //= 2048/4


void setup()
{
  Serial.begin(9600);
  stepperSetup();
  rfidSetup();
  delay(5000);
  servoSetup();
  delay(5000);
  btnSetup();
  lcdSetup();
  get_init_floor();
}
void loop()
{
  btnLoop();
  rfidLoop();
  handler();
}
