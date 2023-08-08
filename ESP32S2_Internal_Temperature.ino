//This example demonstrates how to receive temperature data from an internal sensor of ESP32S2 (ESP32-C2, ESP32-C3, ESP32-C6, ESP32-H2, ESP32-S2, ESP32-S3)

// Driver for internal temperature sensor
#include "driver/temp_sensor.h"

// Variable for temperature value
float temperature = 0;

// Temperature sensor initialization
void iniTemperatureSensor(){
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
    temp_sensor.dac_offset = TSENS_DAC_L2;  // TSENS_DAC_L2 is default; L4(-40°C ~ 20°C), L2(-10°C ~ 80°C), L1(20°C ~ 100°C), L0(50°C ~ 125°C)
    temp_sensor_set_config(temp_sensor);
    temp_sensor_start();
}

// Initialization
void setup()
{
  // Port initialization
  Serial.begin(9600);

  // Temperature sensor initialization
  iniTemperatureSensor();
}

// Main loop
void loop() {

  Serial.print("Temperature: ");

  // Reading data from a temperature sensor into a variable
  temp_sensor_read_celsius(&temperature);

  // Displaying the temperature value in the terminal
  Serial.print(temperature);

  Serial.println(" °C");
  delay(1000);
}