#include "movement.h"
#include <Arduino.h>

int enableMotor1 = 13;
int motor1Pin1 = 14;
int motor1Pin2 = 12;

int motor2Pin1 = 27;
int motor2Pin2 = 26;
int enableMotor2 = 25;

#define MIN_ABSOLUTE_SPEED 0

void rotateMotor(int speed1, int speed2)
{
  if (speed1 < 0)
  {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);    
  }
  else
  {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);      
  }

  if (speed2 < 0)
  {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);    
  }
  else
  {
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);      
  }

  speed1 = constrain(abs(speed1) + MIN_ABSOLUTE_SPEED, MIN_ABSOLUTE_SPEED, 220);
  speed2 = constrain(abs(speed2) + MIN_ABSOLUTE_SPEED, MIN_ABSOLUTE_SPEED, 220);
    
  Serial.print(" Speed1: ");
  Serial.print(speed1);
  Serial.print(" Speed2: ");
  Serial.println(speed2);
  analogWrite(enableMotor1, speed1);
  analogWrite(enableMotor2, speed2);    
}

void setupMotors()
{
  pinMode(enableMotor1, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  
  pinMode(enableMotor2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  rotateMotor(0, 0);
}