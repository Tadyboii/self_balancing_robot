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
| **Motor Driver**   | L298N   |  
| **Motors**         | 2 DC Geared Motors     |  
| **Power Supply**   | 2 3.7V AA Batteries         |  
 
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

### Circuit Diagram
![circuitdia](https://github.com/user-attachments/assets/50c9608c-392b-4af2-bb23-75c2e78f307f)

### Block Diagram
![BCD](https://github.com/user-attachments/assets/a775ab54-ec51-4d9f-8b1e-e1b1df76e3b7)

## 🚀 Testing Results
During testing, the robot achieved the following:

    Response Time: Balanced itself within a decently fast of being tilted.
    PID Stability: Performed optimally with the following tuned parameters:
        Pitch
            Kp: 21
            Ki: 60
            Kd: 0.6
        Yaw
            Kp: 0.5
            Ki: 0.5
            Kd: 0
        
## 📷 Visual
### In Action
![VID20241216120246-ezgif com-optimize](https://github.com/user-attachments/assets/95fc5c23-606c-4563-8965-35550cd9c79b)

### Perspective View
<img src="https://github.com/user-attachments/assets/7f48dc40-040b-4acd-aeb6-4b2cc7a27b79" width=30% height=30%>

### Front View
<img src="https://github.com/user-attachments/assets/285782cf-3b64-4c9e-82d3-6b4dcd4d297a" width=30% height=30%>

### Back View
<img src="https://github.com/user-attachments/assets/cfac928b-d902-4d46-8830-a3c82cc29c90" width=30% height=30%>

### Top View
<img src="https://github.com/user-attachments/assets/662d007a-0043-4da6-acc1-640847cf3b0b" width=30% height=30%>

### Side View
<img src="https://github.com/user-attachments/assets/061405e5-179a-448a-8930-d9ed16d61176" width=30% height=30%>

## 📝 Conclusion
This project demonstrates the integration of electronics, control theory, and programming to create a functional self-balancing robot. The design serves as a practical application of feedback systems and offers scope for further development, such as obstacle avoidance or remote control.

## 📬 Contact
For questions or further discussion, please contact:

    Dave Daniel V. Cardino: davedaniel.cardino@g.msuiit.edu.ph
    Thaddeus Rosales: thaddeus.rosales@g.msuiit.edu.ph
