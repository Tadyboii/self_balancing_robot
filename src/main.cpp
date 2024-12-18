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
  calibrateMPU();
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
    Serial.print(pitchPIDOutput);
    Serial.print(" Yaw PID: ");
    Serial.print(yawPIDOutput);

    rotateMotor(pitchPIDOutput + yawPIDOutput, pitchPIDOutput - yawPIDOutput);
  }
}



//for mpu calibration
// // I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// // for both classes must be in the include path of your project
// #include "I2Cdev.h"

// #include "MPU6050_6Axis_MotionApps20.h"
// // Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// // is used in I2Cdev.h
// #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//     #include "Wire.h"
// #endif

// MPU6050 mppu;
// uint8_t dev_sstatus;      // return status after each device operation (0 = success, !0 = error)

// void setup() {
//     // join I2C bus (I2Cdev library doesn't do this automatically)
//     #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//         Wire.begin();
//         Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
//     #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
//         Fastwire::setup(400, true);
//     #endif

//     // initialize serial communication
//     // (115200 chosen because it is required for Teapot Demo output, but it's
//     // really up to you depending on your project)
//     Serial.begin(115200);
//     while (!Serial); // wait for Leonardo enumeration, others continue immediately

//     // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3V or Arduino
//     // Pro Mini running at 3.3V, cannot handle this baud rate reliably due to
//     // the baud timing being too misaligned with processor ticks. You must use
//     // 38400 or slower in these cases, or use some kind of external separate
//     // crystal solution for the UART timer.

//     // initialize device
//     Serial.println(F("Initializing I2C devices..."));
//     mppu.initialize();

//     // verify connection
//     Serial.println(F("Testing device connections..."));
//     Serial.println(mppu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

//     // wait for ready
//     Serial.println(F("\nSend any character to begin DMP programming and demo: "));
//     while (Serial.available() && Serial.read()); // empty buffer
//     while (!Serial.available());                 // wait for data
//     while (Serial.available() && Serial.read()); // empty buffer again

//     // load and configure the DMP
//     Serial.println(F("Initializing DMP..."));
//     dev_sstatus = mppu.dmpInitialize();

//     // make sure it worked (returns 0 if so)
//     if (dev_sstatus == 0) 
//     {
//         // Calibration Time: generate offsets and calibrate our MPU6050
//         mppu.CalibrateAccel(6);
//         mppu.CalibrateGyro(6);
//         mppu.PrintActiveOffsets();
//     }
// }

// void loop() 
// {
// }