#include <Arduino.h>

// в зависимости от значений на потенциометре
// светодиод будет плавно менять яркость и цвет

const int BLED = 9;  // Blue LED Cathode on Pin 9
const int GLED = 10; // Green LED Cathode on Pin 10
const int RLED = 11; // Red LED Cathode on Pin 11

const int POT = 0; // Pot on Analog Pin 0
int val = 0;       // Variable to hold the analog reading from the POT

boolean lastButton = LOW;    // Last Button State
boolean currentButton = LOW; // Current Button State
int ledMode = 0;             // Cycle between LED states

void setup()
{
  pinMode(BLED, OUTPUT); // Set Blue LED as Output
  pinMode(GLED, OUTPUT); // Set Green LED as Output
  pinMode(RLED, OUTPUT); // Set Red LED as Output
//  pinMode (BUTTON, INPUT);  // Set button as input (not required)
  Serial.begin(9600);
}

void loop()
{

  val = analogRead(POT); // 0 .. 1023
  Serial.println(val);   // для проверки

  if (val < 255)
  {
    analogWrite(RLED, val);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
  else if (val < 511)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, val - 256);
    analogWrite(BLED, 0);
  }
  else if (val < 767)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, val - 512);
  }
  else
  {
    analogWrite(RLED, val - 768);
    analogWrite(GLED, val - 768);
    analogWrite(BLED, val - 768);
  }

  delay(100);
}