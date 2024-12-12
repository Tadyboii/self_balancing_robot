#ifndef MPU_H
#define MPU_H
#include <MPU6050_6Axis_MotionApps20.h>
#include <Wire.h>

void setupMPU();
void dmpDataReady();

extern MPU6050 mpu;
extern volatile bool mpuInterrupt;
extern bool dmpReady;
extern uint8_t mpuIntStatus;
extern uint8_t devStatus;
extern uint16_t packetSize;
extern uint16_t fifoCount;
extern uint8_t fifoBuffer[64];
extern Quaternion q;
extern VectorFloat gravity;
extern float ypr[3];
extern VectorInt16 gy;

#endif // MPU_H


