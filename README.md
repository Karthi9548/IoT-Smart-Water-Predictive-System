#### **Project Overview**

### 

This project is an advanced IoT solution for real-time water quality monitoring. Unlike standard systems, it features a synthetic degradation algorithm that tracks filter health based on water turbidity levels, providing predictive maintenance alerts.



#### **Key Features**



1. &#x20;Real-time Analysis: Monitors pH and Turbidity levels using ESP32.
2. &#x20;Predictive Maintenance:  Calculates "Filter Health %" based on usage and contamination levels.
3. &#x20;Safety Interlock: Automatically "locks" the system when the filter is depleted or water is unsafe.
4. &#x20;Intuitive Interface: 16x2 I2C LCD provides instant potability status (Safe, Acidic, Dirty, or Locked).

#### 

#### **Technical Stack**



1. Microcontroller: ESP32
2. Simulator: Wokwi
3. Language: C++/Arduino
4. Protocols: I2C (LiquidCrystal), ADC (Analog Sensors)

#### 

#### **How to Run**



1\. Open the `Smart\_Water\_System.ino` in the Arduino IDE or Wokwi.

2\. Ensure the `LiquidCrystal\_I2C` library is installed.

3\. Simulate/Upload to see real-time potability tracking.

