#define BLYNK_TEMPLATE_ID "TMPL3ZCLBWtvM"
#define BLYNK_TEMPLATE_NAME "IoT Smart Machine Health and energy monitoring"
#define BLYNK_AUTH_TOKEN "2ci8xGwDCAb5PlGMeZ5d-fXQ1MosH-v2"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define GREEN_LED 18
#define RED_LED 19
#define BUZZER 23
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// ================= OLED =================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ================= DHT22 =================

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// ================= MPU6050 =================

Adafruit_MPU6050 mpu;

// ================= Current Sensor =================

#define CURRENT_PIN 34

void setup()
{
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(115200);

  Wire.begin(21,22);

  // OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    Serial.println("OLED NOT FOUND");
    while(1);
  }

  // DHT
  dht.begin();

  // MPU6050
  if(!mpu.begin())
  {
    Serial.println("MPU6050 NOT FOUND");
    while(1);
  }

  pinMode(CURRENT_PIN,INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  display.clearDisplay();

  display.setTextSize(1);

  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("SAIL Internship");

  display.setCursor(0,18);
  display.println("Sensor Test");

  display.setCursor(0,36);
  display.println("Part A");

  display.display();

  Serial.println("--------------------------------------");
  Serial.println("SMART MACHINE MONITOR");
  Serial.println("--------------------------------------");
}

void loop()
{
  Blynk.run();

  //==========================
  // Read DHT22
  //==========================

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  //==========================
  // Read MPU6050
  //==========================

  sensors_event_t accel, gyro, temp;

  mpu.getEvent(&accel, &gyro, &temp);

  float vibration = sqrt(
    accel.acceleration.x * accel.acceleration.x +
    accel.acceleration.y * accel.acceleration.y +
    accel.acceleration.z * accel.acceleration.z);

  //==========================
  // Read Current
  //==========================

  int adc = analogRead(CURRENT_PIN);

  float current = (adc / 4095.0) * 10.0;

  //==========================
  // Machine Health
  //==========================

  int health = 100;

  if(current > 3)
      health -= 20;

  if(current > 6)
      health -= 20;

  if(temperature > 40)
      health -= 20;

  if(temperature > 60)
      health -= 20;

  if(vibration > 12)
      health -= 20;

  if(health < 0)
      health = 0;

  //==========================
  // Machine Status
  //==========================

  String status;

  if(health >= 80)
      status = "NORMAL";

  else if(health >= 50)
      status = "WARNING";

  else
      status = "CRITICAL";
  //==========================
// Send Data to Blynk
//==========================

Blynk.virtualWrite(V0, temperature);

Blynk.virtualWrite(V1, humidity);

Blynk.virtualWrite(V2, current);

Blynk.virtualWrite(V3, vibration);

Blynk.virtualWrite(V4, health);

Blynk.virtualWrite(V5, status);

Serial.println("Data Sent To Blynk");
  //==========================
  // LED & Buzzer
  //==========================

  if(status == "NORMAL")
{
  digitalWrite(GREEN_LED,HIGH);
  digitalWrite(RED_LED,LOW);
  digitalWrite(BUZZER,LOW);
  Blynk.virtualWrite(V6, 1);
  Blynk.virtualWrite(V7, 0);
}
else
{
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(RED_LED,HIGH);
  digitalWrite(BUZZER,HIGH);
  Blynk.virtualWrite(V6, 0);
  Blynk.virtualWrite(V7, 1);
}

  //==========================
  // OLED Dashboard
  //==========================

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("SMART MACHINE");

  display.setCursor(0,12);
  display.print("T:");
  display.print(temperature,1);
  display.print("C");

  display.setCursor(70,12);
  display.print("H:");
  display.print(humidity,0);
  display.print("%");

  display.setCursor(0,25);
  display.print("I:");
  display.print(current,1);
  display.print("A");

  display.setCursor(70,25);
  display.print("V:");
  display.print(vibration,1);

  display.setCursor(0,40);
  display.print("Health:");
  display.print(health);
  display.print("%");

  display.setCursor(0,54);
  display.print(status);

  display.display();

  //==========================
  // Serial Monitor
  //==========================

  Serial.println("-------------------------------");

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity : ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Current : ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Vibration : ");
  Serial.println(vibration);

  Serial.print("Health : ");
  Serial.print(health);
  Serial.println("%");

  Serial.print("Status : ");
  Serial.println(status);

  delay(100);
  Serial.println("----- Sensor Data -----");
  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  Serial.print("Current: ");
  Serial.println(current);

  Serial.print("Vibration: ");
  Serial.println(vibration);

  Serial.print("Health: ");
  Serial.println(health);

  Serial.print("Status: ");
  Serial.println(status);

  Serial.println("-----------------------");
}
