/*
file main.cpp
Autor: Atanasij Hristovski
Date: 27.09.25
Version:        1.0
Licence:         MIT
*/
#include <Arduino.h>
#define LED_PIN 5
#define Poti_Pin A0

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(Poti_Pin, INPUT);
}

void loop()
{
  static unsigned long time_old = 0;
  static unsigned long time_new = 0;
  static bool led_state = LOW; 
  int poti_value = 0;
  int delay_time = 0;
 
  poti_value = analogRead(Poti_Pin);
  delay_time = map(poti_value, 0, 1023, 50, 1000);
  Serial.println(delay_time); 
  
  time_new = millis();
 
  if((time_new - time_old) >= delay_time/2)
  {
    time_old = time_new;
    led_state = !led_state;
  }
  
   digitalWrite(LED_PIN,led_state);
}