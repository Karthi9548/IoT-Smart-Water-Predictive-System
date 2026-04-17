# IoT-Smart-Water-Predictive-System
IoT Smart Water Monitor using ESP32 &amp; Wokwi. Features real-time pH/Turbidity tracking &amp; a Predictive Maintenance algorithm to monitor Filter Health %. If sensors detect contamination or 0% filter life, the system triggers a safety lock. Ideal for smart city water management.
Project Overview

This project is an advanced IoT solution for real-time water quality monitoring. Unlike standard systems, it features a synthetic degradation algorithm that tracks filter health based on water turbidity levels, providing predictive maintenance alerts.

Key Features

 Real-time Analysis: Monitors pH and Turbidity levels using ESP32.
 Predictive Maintenance:  Calculates "Filter Health %" based on usage and contamination levels.
 Safety Interlock: Automatically "locks" the system when the filter is depleted or water is unsafe.
 Intuitive Interface: 16x2 I2C LCD provides instant potability status (Safe, Acidic, Dirty, or Locked).

Technical Stack

Microcontroller: ESP32
Simulator: Wokwi
Language: C++/Arduino
Protocols: I2C (LiquidCrystal), ADC (Analog Sensors)

How to Run

1. Open the `Smart_Water_System.ino` in the Arduino IDE or Wokwi.
2. Ensure the `LiquidCrystal_I2C` library is installed.
3. Simulate/Upload to see real-time potability tracking.
