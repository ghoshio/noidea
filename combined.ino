// DHT sensor library - Version: Latest 
#include <DHT.h>
#include <DHT_U.h>
int sensorValue;

// DHT sensor library - Version: Latest 

#define DHT_SENSOR_PIN  21 // ESP32 pin GPIO21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT22

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


const int relay = 26;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  dht_sensor.begin();
}

void loop()
 {
 
  float humi  = dht_sensor.readHumidity();
  // read temperature in Celsius
  float tempC = dht_sensor.readTemperature();
  // read temperature in Fahrenheit
  float tempF = dht_sensor.readTemperature(true);
  sensorValue = analogRead(A0); 
   Serial.println(sensorValue);
  if(sensorValue>1900)
  {
    digitalWrite(relay, LOW);
    Serial.println("Current Flowing");
  }else
 {
  digitalWrite(relay, HIGH);
  Serial.println("Current not Flowing");
 }
  
   



}








