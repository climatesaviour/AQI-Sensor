#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
const int mq135Pin = A3; // Analog pin connected to the MQ-135 sensor

void setup() {
  lcd.begin(); // Initialize the LCD
  lcd.backlight(); // Turn on the LCD backlight
  lcd.print("Air Quality:"); // Display initial text on the LCD
  Serial.begin(9600); // Initialize the serial communication for debugging
}

void loop() {
  float sensorVoltage = analogRead(mq135Pin) * (5.0 / 1023.0); // Read analog value from the MQ-135 sensor and convert it to voltage
  float airQuality = getAirQuality(sensorVoltage); // Calculate the Air Quality Index

  lcd.setCursor(0, 1); // Set the cursor to the second row
  lcd.print("AQI: "); // Display AQI label
  lcd.print(airQuality); // Display the calculated AQI value

  Serial.print("Sensor Voltage: "); // Debugging information
  Serial.println(sensorVoltage);
  Serial.print("AQI: ");
  Serial.println(airQuality);

  delay(1000); // Delay for a second before taking the next reading
}

float getAirQuality(float sensorVoltage) {
  // Convert the sensor voltage to AQI (adjust this formula according to your sensor calibration)
  float airQuality = (0.2 * sensorVoltage - 0.1) * 1000;
  return airQuality;
}
