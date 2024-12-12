#include <Arduino.h>
#include "movement.h"
#include "pid.h"
#include "mpu.h"
#include "mpu_calibration.h"

void setup()
{
  Serial.begin(115200);
  setupMotors();   
  setupMPU();
  setupPID();
  //for calibration
  // calibrateMPU();
}

void loop()
{
  if (!dmpReady) return;

  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) 
  {  
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    mpu.dmpGetGyro(&gy, fifoBuffer);

    yawGyroRate = gy.z;                   
    pitchGyroAngle = ypr[2] * 180/M_PI;   

    pitchPID.Compute();
    yawPID.Compute();

    Serial.print("Pitch Angle: ");
    Serial.print(pitchGyroAngle);
    Serial.print(" YaW Rate: ");
    Serial.print(yawGyroRate);
    Serial.print(" Pitch PID: ");
    Serial.println(pitchPIDOutput);

    rotateMotor(pitchPIDOutput + yawPIDOutput, pitchPIDOutput - yawPIDOutput);

    #ifdef PRINT_DEBUG_BUILD
      Serial.println("The gyro  before ");
      Serial.println(pitchGyroAngle);
      Serial.println("The setpoints ");
      Serial.println(setpointPitchAngle);
      Serial.println("The pid output ");
      Serial.println(pitchPIDOutput);
      delay(500);    
    #endif
  }
}