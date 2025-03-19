// Pin definitions for RGB LED
int redPin = 11;
int greenPin = 12;
int bluePin = 13;

void setup() {
  // Initialize the digital pin as an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Red color
  analogWrite(redPin, 255);   // Red full brightness
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 0);    // No blue
  delay(1000);                // Wait for 1 second

  // Green color
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 255); // Green full brightness
  analogWrite(bluePin, 0);    // No blue
  delay(1000);                // Wait for 1 second

  // Blue color
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 255);  // Blue full brightness
  delay(1000);                // Wait for 1 second

  // Yellow color (Red + Green)
  analogWrite(redPin, 255);   // Red full brightness
  analogWrite(greenPin, 255); // Green full brightness
  analogWrite(bluePin, 0);    // No blue
  delay(1000);                // Wait for 1 second

  // Purple color (Red + Blue)
  analogWrite(redPin, 255);   // Red full brightness
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 255);  // Blue full brightness
  delay(1000);                // Wait for 1 second

  // Cyan color (Green + Blue)
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 255); // Green full brightness
  analogWrite(bluePin, 255);  // Blue full brightness
  delay(1000);                // Wait for 1 second
}
