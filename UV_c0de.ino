int sensorValue;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A0); // Use the correct analog input pin
  Serial.print("The voltage value:");
  Serial.print(sensorValue * 3300 / 4095.0); // Adjust for ESP32's 12-bit ADC
  Serial.println("mV");
  delay(1000);
  Serial.print("\n");
}
