#include "pid.h"
#include <PID_v1.h>

#define PID_MIN_LIMIT -255
#define PID_MAX_LIMIT 255
#define PID_SAMPLE_TIME_IN_MILLI 10

#define SETPOINT_PITCH_ANGLE_OFFSET 4

double setpointPitchAngle = SETPOINT_PITCH_ANGLE_OFFSET;
double pitchGyroAngle = 0;
double pitchPIDOutput = 0;

double setpointYawRate = 0;
double yawGyroRate = 0;
double yawPIDOutput = 0;

#define PID_PITCH_KP 15
#define PID_PITCH_KI 0
#define PID_PITCH_KD 0

#define PID_YAW_KP 0.5
#define PID_YAW_KI 0.5
#define PID_YAW_KD 0

PID pitchPID(&pitchGyroAngle, &pitchPIDOutput, &setpointPitchAngle, PID_PITCH_KP, PID_PITCH_KI, PID_PITCH_KD, DIRECT);
PID yawPID(&yawGyroRate, &yawPIDOutput, &setpointYawRate, PID_YAW_KP, PID_YAW_KI, PID_YAW_KD, DIRECT);

void setupPID()
{
  pitchPID.SetOutputLimits(PID_MIN_LIMIT, PID_MAX_LIMIT);
  pitchPID.SetMode(AUTOMATIC);
  pitchPID.SetSampleTime(PID_SAMPLE_TIME_IN_MILLI);

  yawPID.SetOutputLimits(PID_MIN_LIMIT, PID_MAX_LIMIT);
  yawPID.SetMode(AUTOMATIC);
  yawPID.SetSampleTime(PID_SAMPLE_TIME_IN_MILLI);
}