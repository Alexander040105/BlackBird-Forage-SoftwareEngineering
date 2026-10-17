/**
  Basic NTC Thermistor demo
  https://wokwi.com/arduino/projects/299330254810382858

  Assumes a 10K@25℃ NTC thermistor connected in series with a 10K resistor.

  Copyright (C) 2021, Uri Shaked
*/

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
const int GREEN_LED_PIN = 9;
const int YELLOW_LED_PIN = 8;
const int RED_LED_PIN = 10;
void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  delay(1000);

  if (celsius < 30) {
      digitalWrite(GREEN_LED_PIN, HIGH);   
  } else if (celsius < 30 || celsius <= 80){
      digitalWrite(YELLOW_LED_PIN, HIGH);
  } else {
      digitalWrite(RED_LED_PIN, HIGH);   
  }


}
