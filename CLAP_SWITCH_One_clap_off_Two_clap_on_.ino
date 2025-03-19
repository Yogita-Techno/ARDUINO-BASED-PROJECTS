#define SOUND_SENSOR_PIN 2  
#define RELAY_PIN 3         

int clapCount = 0;         // Number of claps detected
unsigned long lastClapTime = 0; // Time of the last clap
unsigned long clapDelay = 500;   // Delay between claps (500ms)

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT);  // Sound sensor pin as input
  pinMode(RELAY_PIN, OUTPUT);        // Relay pin as output
  
  digitalWrite(RELAY_PIN, LOW);  // Initialize relay to OFF
  Serial.begin(9600);            // Start serial communication for debugging
}

void loop() {
  int soundLevel = digitalRead(SOUND_SENSOR_PIN);  // Read the sound sensor

  // If a clap is detected (high signal from the sound sensor)
  if (soundLevel == HIGH) {
    // Debounce the sound detection
    if (millis() - lastClapTime > clapDelay) {
      clapCount++;  
      lastClapTime = millis();  // Record the time of the clap
      Serial.print("Clap detected! Clap count: ");
      Serial.println(clapCount);
    }
  }

  // If 1 clap detected (turn off relay)
  if (clapCount == 1) {
    digitalWrite(RELAY_PIN, LOW);  // Turn off the relay
    Serial.println("Relay OFF (1 clap detected)");
    clapCount = 0;  // Reset clap count
  }

  // If 2 claps detected (turn on relay)
  if (clapCount == 2) {
    digitalWrite(RELAY_PIN, HIGH);  // Turn on the relay
    Serial.println("Relay ON (2 claps detected)");
    clapCount = 0;  // Reset clap count
  }
  
  delay(50);  // Small delay for sensor stability
}
