# AQI-Sensor

We use MQ-135 gas sensor to the detect and report the ambient air quality. The data obtained by the sensor is displayed on a 16x2 LCD display.

Make sure you have installed the "LiquidCrystal_I2C" library for controlling the LCD using I2C. You can install it from the Arduino Library Manager.

In this code, we initialize the LCD using the I2C address 0x27 and the specified number of columns and rows. 
The MQ-135 sensor is connected to analog pin A0. The getAirQuality() function converts the sensor voltage to the AQI based on your calibration. 
The main loop() function reads the sensor voltage, calculates the AQI, and displays it on the LCD. The calculated AQI is also printed to the serial monitor for debugging purposes.

Remember to adjust the formula in the getAirQuality() function to match the calibration of your MQ-135 sensor. 
The calibration process and the mapping of sensor voltage to AQI values can vary depending on your specific sensor and the air quality standards of your region.
