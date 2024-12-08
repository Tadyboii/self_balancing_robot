#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "gyroscope.h"

Adafruit_MPU6050 mpu;
double rollComp = 0;
unsigned long prevTime = 0;

void setupGyroscope() {
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  prevTime = millis();
}

void readAcceleration(double &y, double &z) {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  y = a.acceleration.y;
  z = a.acceleration.z;
}

void readGyro(double &x) {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  x = g.gyro.x;
}

double getAngle(){
  double accY, gyroX, accZ;
  readAcceleration(accY, accZ);
  readGyro(gyroX);
  double accAngle = atan2(accY, accZ) * 180 / PI;

  unsigned long currentTime = millis();
  double elapsedTime = (currentTime - prevTime) / 1000.0;
  prevTime = currentTime;

  double gyroAngle = gyroX * elapsedTime;
  double compAngle = 0.79* (rollComp + gyroAngle) + 0.21 * accAngle;
  rollComp = compAngle;
  

  return rollComp;
}
