#ifndef MOVEMENT_H
#define MOVEMENT_H

extern const int ENA;
extern const int ENB;
extern const int LEFT_MOTOR_PIN1;
extern const int LEFT_MOTOR_PIN2;
extern const int RIGHT_MOTOR_PIN1;
extern const int RIGHT_MOTOR_PIN2;

void setupMotors();
void moveForward(int speed);
void moveBackward(int speed);
void turnLeft();
void turnRight();
void stop();


#endif