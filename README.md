# 🤖 Self-Balancing Robot

This repository contains the design, implementation, and code for our Self-Balancing Robot project. The robot is a demonstration of dynamic stability using feedback control systems, powered by an ESP32 microcontroller and an MPU6050 sensor for precise tilt detection.

Our work aims to showcase the principles of robotics, PID control, and sensor integration in a compact, functional prototype.

## 📖 Project Overview
**🔧 Objective**

To design and develop a self-balancing robot capable of maintaining an upright position dynamically by processing real-time feedback from sensors and applying corrections via motor controls.

**📊 Key Features**

    Autonomous Balancing: Implements a PID control algorithm for stability.
    Real-Time Feedback: Utilizes the MPU6050 accelerometer and gyroscope for precise orientation and tilt detection.

## 🛠️ How It Works
    Sensor Feedback
        The MPU6050 detects the robot's angular position and rate of change.
        Provides real-time tilt data by combining accelerometer and gyroscope readings.

    PID Control Loop
        The Proportional-Integral-Derivative (PID) algorithm calculates the necessary motor corrections based on the tilt angle and its rate of change.
        Parameters are tuned to achieve optimal balancing performance.

    Motor Actuation
        The ESP32 sends control signals to the motor driver, which adjusts motor speeds to counteract any tilt.

## ✨ Key Specifications
| Component         | Description                                      |  
|--------------------|--------------------------------------------------|  
| **Microcontroller**| ESP32 (240 MHz, Dual Core, WiFi, Bluetooth)      |  
| **Sensors**        | MPU6050 (Accelerometer and Gyroscope)            |  
| **Motor Driver**   | (insert)   |  
| **Motors**         | (insert)     |  
| **Power Supply**   | (insert)         |  
 
## 🔧 Development Process
    Hardware Assembly
        Connected the ESP32, MPU6050, motor driver, and motors as per the provided circuit diagram.
        Verified power supply and component functionality.

    Software Implementation
        Configured the ESP32 environment in Visual Studio Code.
        Developed the PID control logic to process sensor input and adjust motor output.
        Fine-tuned PID parameters through testing and iteration.

    Testing and Validation
        Conducted experiments to measure stability under varying conditions.
        Validated performance by observing response to external disturbances.

## 🚀 Testing Results
During testing, the robot achieved the following:

    Response Time: Balanced itself within --- seconds of being tilted.
    PID Stability: Performed optimally with the following tuned parameters:
        Kp: ---
        Ki: ---
        Kd: ---
    Max Tilt Recovery: Successfully stabilized after tilts of up to ---°.

## 📷 Visual
(insert videos, photos, and GIFs)

## 📝 Conclusion
This project demonstrates the integration of electronics, control theory, and programming to create a functional self-balancing robot. The design serves as a practical application of feedback systems and offers scope for further development, such as obstacle avoidance or remote control.

## 📜 License
This work is licensed under the MIT License.

## 📬 Contact

For questions or further discussion, please contact:

    Dave Daniel V. Cardino: davedaniel.cardino@g.msuiit.edu.ph
    Thaddeus Rosales: thaddeus.rosales@g.msuiit.edu.ph
