#include <Arduino.h>
#include <PID_v1.h>
#include "pid.h"
#include <math.h>

double setPoint = 0;
double input = 0 , output = 0;
double Kp=37, Ki=50, Kd=0;
PID myPID(&input, &output, &setPoint, Kp, Ki, Kd, DIRECT);

void setupPID(double initialTilt) {
    input = initialTilt;
    myPID.SetMode(AUTOMATIC);
}

double updatePID(double currentTilt) {
    input = currentTilt;

    if (currentTilt < 0){
        myPID.SetControllerDirection(DIRECT);
    } else {
        myPID.SetControllerDirection(REVERSE);
    }
    myPID.Compute();
    return output;
}


