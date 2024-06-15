#include <Arduino.h>

#include <Servo.h>

const int soilMoisturePin = A0;
const int pot=A1;
const int pumpPin = 9;
const int led=8;
const int buzzer=7;
const int sleep=2;
Servo servoMotor;

void setup() {
  pinMode(soilMoisturePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pot,INPUT);
  pinMode(sleep,INPUT);
  servoMotor.attach(10);
}

void loop() {
  while(digitalRead(sleep)!=0)
  {
    digitalWrite(pumpPin, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  int soilMoisture = analogRead(soilMoisturePin);
  int pot = analogRead(pot);
  if (soilMoisture < pot) {
    digitalWrite(pumpPin, HIGH);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    servoMotor.write(90);
    delay(5000);           // Watering duration
    digitalWrite(pumpPin, LOW);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    servoMotor.write(0);
  }
  
  delay(1000); // Check soil moisture every second
}
