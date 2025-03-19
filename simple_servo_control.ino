#include <Servo.h>

Servo myServo;  

int potPin = A0;  // Pin connected to potentiometer
int potValue = 0;  // Variable to store potentiometer value
int angle = 0;     // Variable to store angle of servo

void setup() {
  myServo.attach(9);  // Attach servo to pin 9
}

void loop() {
  potValue = analogRead(potPin);  // Read potentiometer value (0-1023)
  angle = map(potValue, 0, 1023, 0, 180);  // Map the value to a range of 0-180 degrees
  myServo.write(angle);  // Move the servo to the angle
  delay(15);  // Wait for the servo to reach the position
}
