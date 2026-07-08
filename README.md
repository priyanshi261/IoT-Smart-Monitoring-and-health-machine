
# IoT based Smart Machine

An ESP32-based IoT solution for real-time machine health monitoring and energy analysis using Blynk Cloud, OLED display, and multiple sensors.

<img width="857" height="652" alt="image" src="https://github.com/user-attachments/assets/54979675-5bfb-45c5-b627-c235f8c7451b" />


## OVERVIEW
The IoT Smart Machine Health and Energy Monitoring System is designed to continuously monitor the health and operating condition of industrial machines. It collects important parameters such as temperature, humidity, current consumption, and vibration, processes them using an ESP32 microcontroller, and displays the information on both an OLED display and a Blynk IoT Dashboard.

The system also calculates an overall Machine Health Index and classifies the machine status as NORMAL, WARNING, or CRITICAL. This project demonstrates how IoT and Embedded Systems can be used for predictive maintenance, energy monitoring, and Industry 4.0 applications in the steel industry.
## OBJECTIVES
1. Monitor machine temperature in real time.
2. Monitor surrounding humidity.
3. Simulate motor current monitoring.
4. Detect abnormal machine vibration.
5. Calculate Machine Health Index.
6. Display live data on an OLED display.
7. Upload sensor data to the Blynk IoT Cloud.
8. Indicate machine condition using LEDs.
9. Demonstrate a low-cost predictive maintenance system.
10. Promote Industry 4.0 concepts for smart manufacturing.
## COMPONENTS USED
| Component                 | Quantity    | Purpose                                  |
| ------------------------- | ----------- | ---------------------------------------- |
| ESP32 Dev Board           | 1           | Main microcontroller with Wi-Fi          |
| DHT22 Sensor              | 1           | Temperature & Humidity sensing           |
| MPU6050                   | 1           | Vibration monitoring                     |
| Potentiometer             | 1           | Simulates ACS712 current sensor in Wokwi |
| OLED Display (SSD1306)    | 1           | Local display of sensor data             |
| Green LED                 | 1           | Indicates Normal condition               |
| Red LED                   | 1           | Indicates Warning/Critical condition     |
| Buzzer                    | 1           | Alarm indication                         |
| Breadboard & Jumper Wires | As required | Circuit connections                      |
| Blynk Cloud               | 1           | IoT Dashboard                            |
| Wokwi Simulator           | 1           | Circuit simulation                       |
| EasyEDA                   | 1           | Schematic design                         |

## WORKING PRINCIPLE
1. ESP32 initializes all sensors.
2. DHT22 measures temperature and humidity.
3. MPU6050 measures machine vibration.
4. The potentiometer simulates the output of an ACS712 current sensor.
5. ESP32 reads all sensor values.
6. Machine Health Index is calculated based on predefined thresholds.
7. Machine status is determined as NORMAL, WARNING, or CRITICAL.
8. Sensor values are displayed on the OLED screen.
9. Data is transmitted to the Blynk IoT Cloud via Wi-Fi.
10. LEDs indicate the current machine condition.
11. The dashboard stores and displays historical trends.
## LEDs INDICATION
| LED          | Status | Meaning                                   |
| ------------ | ------ | ----------------------------------------- |
| 🟢 Green LED | ON     | Machine operating normally                |
| 🔴 Red LED   | ON     | Warning or Critical condition detected    |
| 🔴 + Buzzer  | ON     | Immediate attention required (if enabled) |

## DETECTION LOGIC
The machine health is calculated using the following parameters:
1. Temperature
2. Current Consumption
3. Vibration
4. Health starts from 100%.

The health percentage decreases whenever:
1. Temperature exceeds safe limits.
2. Current exceeds predefined limits.
3. Excessive vibration is detected.

Machine Status:
| Health (%) | Status   |
| ---------- | -------- |
| 80 – 100   | NORMAL   |
| 50 – 79    | WARNING  |
| 0 – 49     | CRITICAL |

## CIRCUIT CONNECTIONS
DHT22 Sensor
| DHT22 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 4    |

MPU6050
| MPU6050 Pin | ESP32 Pin |
| ----------- | --------- |
| VCC         | 3.3V      |
| GND         | GND       |
| SDA         | GPIO 21   |
| SCL         | GPIO 22   |

OLED Display (SSD1306)
| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

Potentiometer (Current Sensor Simulation)
| Potentiometer Pin | ESP32 Pin |
| ----------------- | --------- |
| VCC               | 3.3V      |
| GND               | GND       |
| Wiper (Signal)    | GPIO 34   |

LEDs
| Component | ESP32 Pin |
| --------- | --------- |
| Green LED | GPIO 18   |
| Red LED   | GPIO 19   |
| Buzzer    | GPIO 23   |

## SOFTWARE USED
* Arduino IDE
* Wokwi Simulator
* EasyEDA
* Blynk IoT Platform
* GitHub

## LIBRARIES USED
* WiFi.h
* BlynkSimpleEsp32.h
* Wire.h
* Adafruit_GFX.h
* Adafruit_SSD1306.h
* Adafruit_MPU6050.h
* Adafruit_Sensor.h
* DHT.h
* math.h

## DASHBOARD PARAMETERS 
* Temperature
* Humidity
* Current
* Machine Health
* Machine Status
* Vibration
* Normal LED Indicator
* Warning LED Indicator
* Historical Trend Chart

  <img width="1392" height="632" alt="Screenshot 2026-07-06 232912" src="https://github.com/user-attachments/assets/4d2edc78-a384-48f2-ae5d-95c17fe33237" />
  <img width="1312" height="525" alt="Screenshot 2026-07-06 232659" src="https://github.com/user-attachments/assets/d41c24f2-0c6c-4479-b556-b2b69aabe0af" />


## FEATURES
* Real-time IoT monitoring
* Wi-Fi enabled ESP32
* OLED display
* Cloud dashboard using Blynk
* Machine Health Index calculation
* Energy monitoring (simulated)
* Vibration monitoring
* Temperature & humidity monitoring
* LED status indication
* Expandable architecture
* Low-cost Industry 4.0 prototype
* Suitable for predictive maintenance research

## FUTURE IMPROVEMENTS 
* Replace the potentiometer with an ACS712 Current Sensor for real current measurement.
* Add an actual energy meter for power and energy consumption analysis.
* Integrate with PLC and SCADA systems.
* Implement MQTT for industrial communication.
* Add AI/ML-based predictive maintenance.
* Use TinyML on ESP32 for edge intelligence.
* Add SMS/Email notifications for fault alerts.
* Store data in a cloud database.
* Develop a mobile application.
* Monitor multiple industrial machines simultaneously.
* Implement Digital Twin technology.
* Add Industrial 5G connectivity.
  
## AUTHOR 
Priyanshi Singh

Electronics & Communication Engineering Student
Bharati Vidyapeeth's College of Engineering, Delhi
