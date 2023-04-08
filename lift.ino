#define IN1   4
#define IN2   5
#define IN3   7
#define IN4   8
int Steps = 0;
int Direction = 0;
//int number_steps = 512; //= 2048/4
int number_steps = 1024; 
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // delay(1000);
}
void loop()
{
  //1 rotation counter clockwise
  stepper(number_steps);
  delay(1000);
  //1 rotation clockwise
  stepper(-number_steps);
  delay(1000);
  //Keep track of step number
  for (int thisStep = 0; thisStep < number_steps; thisStep++) {
    stepper(1);
  }
  delay(1000);
  for (int thisStep = number_steps; thisStep > 0; thisStep--) {
    stepper(-1);
  }
  delay(1000);
}
