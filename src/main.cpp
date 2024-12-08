#include <Arduino.h>
#include "movement.h"
#include "gyroscope.h"
#include "pid.h"

void setup() {
  Serial.begin(115200);
  setupMotors();
  setupGyroscope();
  setupPID(getAngle());
}

void loop() {
  double tilt = getAngle();
  Serial.print(tilt);
  Serial.print(" ");
  double output = updatePID(tilt);
  Serial.println(output);

  double speed = map(output, 0, 255, 0, 255);

  // Serial.print(speed);
  // Serial.print(" ");
  // Serial.println(readGyro());
  if(abs(tilt) > 40 || abs(tilt) < 3){
    stop();
  } else if (tilt < 0) {
    moveForward(speed);
  } else {
    moveBackward(speed);
  }
}
