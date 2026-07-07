# IoT-Smart-Monitoring-and-health-machine
IoT Smart Machine Health and Energy Monitoring System for Steel Industry

An ESP32-based IoT solution for real-time machine health monitoring and energy analysis using Blynk Cloud, OLED display, and multiple sensors.

Overview

The IoT Smart Machine Health and Energy Monitoring System is designed to continuously monitor the health and operating condition of industrial machines. It collects important parameters such as temperature, humidity, current consumption, and vibration, processes them using an ESP32 microcontroller, and displays the information on both an OLED display and a Blynk IoT Dashboard.

The system also calculates an overall Machine Health Index and classifies the machine status as NORMAL, WARNING, or CRITICAL. This project demonstrates how IoT and Embedded Systems can be used for predictive maintenance, energy monitoring, and Industry 4.0 applications in the steel industry.

Objectives
Monitor machine temperature in real time.
Monitor surrounding humidity.
Simulate motor current monitoring.
Detect abnormal machine vibration.
Calculate Machine Health Index.
Display live data on an OLED display.
Upload sensor data to the Blynk IoT Cloud.
Indicate machine condition using LEDs.
Demonstrate a low-cost predictive maintenance system.
Promote Industry 4.0 concepts for smart manufacturing.
Components Used
Component	Quantity	Purpose
ESP32 Dev Board	1	Main microcontroller with Wi-Fi
DHT22 Sensor	1	Temperature & Humidity sensing
MPU6050	1	Vibration monitoring
Potentiometer	1	Simulates ACS712 current sensor in Wokwi
OLED Display (SSD1306)	1	Local display of sensor data
Green LED	1	Indicates Normal condition
Red LED	1	Indicates Warning/Critical condition
Buzzer	1	Alarm indication
Breadboard & Jumper Wires	As required	Circuit connections
Blynk Cloud	1	IoT Dashboard
Wokwi Simulator	1	Circuit simulation
EasyEDA	1	Schematic design
Working Principle
ESP32 initializes all sensors.
DHT22 measures temperature and humidity.
MPU6050 measures machine vibration.
The potentiometer simulates the output of an ACS712 current sensor.
ESP32 reads all sensor values.
Machine Health Index is calculated based on predefined thresholds.
Machine status is determined as NORMAL, WARNING, or CRITICAL.
Sensor values are displayed on the OLED screen.
Data is transmitted to the Blynk IoT Cloud via Wi-Fi.
LEDs indicate the current machine condition.
The dashboard stores and displays historical trends.
LED Indications
LED	Status	Meaning
🟢 Green LED	ON	Machine operating normally
🔴 Red LED	ON	Warning or Critical condition detected
🔴 + Buzzer	ON	Immediate attention required (if enabled)
Detection Logic

The machine health is calculated using the following parameters:

Temperature
Current Consumption
Vibration

Health starts from 100%.

The health percentage decreases whenever:

Temperature exceeds safe limits.
Current exceeds predefined limits.
Excessive vibration is detected.

Machine Status:

Health (%)	Status
80 – 100	NORMAL
50 – 79	WARNING
0 – 49	CRITICAL
Circuit Connections
DHT22 Sensor
DHT22 Pin	ESP32 Pin
VCC	3.3V
GND	GND
DATA	GPIO 4
MPU6050
MPU6050 Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
OLED Display (SSD1306)
OLED Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
Potentiometer (Current Sensor Simulation)
Potentiometer Pin	ESP32 Pin
VCC	3.3V
GND	GND
Wiper (Signal)	GPIO 34

Note: In the actual hardware implementation, the potentiometer should be replaced with an ACS712 Hall-effect Current Sensor.

LEDs
Component	ESP32 Pin
Green LED	GPIO 18
Red LED	GPIO 19
Buzzer	GPIO 23
Software Used
Arduino IDE
Wokwi Simulator
EasyEDA
Blynk IoT Platform
GitHub
Libraries Used
WiFi.h
BlynkSimpleEsp32.h
Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h
Adafruit_MPU6050.h
Adafruit_Sensor.h
DHT.h
math.h
Dashboard Parameters
Temperature
Humidity
Current
Machine Health
Machine Status
Vibration
Normal LED Indicator
Warning LED Indicator
Historical Trend Chart
Features
Real-time IoT monitoring
Wi-Fi enabled ESP32
OLED display
Cloud dashboard using Blynk
Machine Health Index calculation
Energy monitoring (simulated)
Vibration monitoring
Temperature & humidity monitoring
LED status indication
Expandable architecture
Low-cost Industry 4.0 prototype
Suitable for predictive maintenance research
Project Applications
Steel Industry
Manufacturing Plants
Smart Factories
Motor Health Monitoring
Predictive Maintenance
Industrial IoT (IIoT)
Energy Management
Educational Embedded Systems Projects
Future Improvements
Replace the potentiometer with an ACS712 Current Sensor for real current measurement.
Add an actual energy meter for power and energy consumption analysis.
Integrate with PLC and SCADA systems.
Implement MQTT for industrial communication.
Add AI/ML-based predictive maintenance.
Use TinyML on ESP32 for edge intelligence.
Add SMS/Email notifications for fault alerts.
Store data in a cloud database.
Develop a mobile application.
Monitor multiple industrial machines simultaneously.
Implement Digital Twin technology.
Add Industrial 5G connectivity.
