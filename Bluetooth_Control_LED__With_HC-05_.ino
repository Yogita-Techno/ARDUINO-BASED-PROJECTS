
int ledPin = 13;  
char command;    

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication for Bluetooth
}

void loop() {
  if (Serial.available()) {  // Check if Bluetooth data is available
    command = Serial.read();  // Read the command
    if (command == '1') {
      digitalWrite(ledPin, HIGH);  // Turn LED on
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);   // Turn LED off
    }
  }
}
