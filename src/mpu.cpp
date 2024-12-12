#include "mpu.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;

#define INTERRUPT_PIN 2

bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

Quaternion q;
VectorFloat gravity;
float ypr[3];
VectorInt16 gy;

volatile bool mpuInterrupt = false;
void dmpDataReady() {
    mpuInterrupt = true;
}

void setupMPU()
{
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      Wire.begin();
      Wire.setClock(400000);
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
      Fastwire::setup(400, true);
  #endif
  
  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);
  devStatus = mpu.dmpInitialize();

  mpu.setXAccelOffset(-528); 
  mpu.setYAccelOffset(-467); 
  mpu.setZAccelOffset(1112);   
  mpu.setXGyroOffset(116);
  mpu.setYGyroOffset(20);
  mpu.setZGyroOffset(2);

  if (devStatus == 0) 
  {
      mpu.setDMPEnabled(true);
      mpuIntStatus = mpu.getIntStatus();
      dmpReady = true;
      packetSize = mpu.dmpGetFIFOPacketSize();
      attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
  } 
  else 
  {
      // Handle Error
  }
}