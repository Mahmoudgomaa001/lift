#include <Servo.h>

int servoPin = 6;
Servo servo;
int angle = 0;  // servo position in degrees

void servoSetup() {
  servo.attach(servoPin);
}

void servoOpen() {

  // scan from 0 to 180 degrees
  for (angle = 0; angle < 180; angle++) {
    servo.write(angle);
    delay(15);
  }

}
void servoClose() {
  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle--) {
    servo.write(angle);
    delay(15);
  }
}
