#ifndef PID_H
#define PID_H
#include <PID_v1.h>

void setupPID();


extern double pitchGyroAngle;
extern double pitchPIDOutput;
extern double yawGyroRate;
extern double yawPIDOutput;
extern PID pitchPID;
extern PID yawPID;


#endif // PID_H
