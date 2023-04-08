//int number_steps = 512; //= 2048/4
int number_steps = 1280;

void setup()
{
  Serial.begin(9600);
  //  stepperSetup();
  Serial.println("5");
  rfidSetup();
  Serial.println("2");
  servoSetup();
  Serial.println("3");

}
void loop()
{
  rfidLoop();

}
void testStepper() {
  //1 rotation counter clockwise
  stepper(-number_steps);

  //1 rotation clockwise
  delay(5000);
  stepper(-number_steps);

  delay(5000);
  //1 rotation counter clockwise
  stepper(-number_steps);

  //1 rotation clockwise
  delay(5000);
  stepper(-number_steps);

  delay(5000);
  stepper(number_steps);

  //1 rotation clockwise
  delay(5000);
  stepper(number_steps);
  //1 rotation clockwise
  delay(5000);

  stepper(number_steps);

  //1 rotation clockwise
  delay(5000);
  stepper(number_steps);
  //1 rotation clockwise
  delay(5000);


}
