//int number_steps = 512; //= 2048/4


void setup()
{
  Serial.begin(9600);
  stepperSetup();

  //  rfidSetup();

  //  servoSetup();
  btnSetup();
  lcdSetup();
  get_init_floor();
//  stepper(-number_steps); //up
}
void loop()
{
  btnLoop();
  //  rfidLoop();

}
