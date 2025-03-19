#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define relayPin 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(relayPin, OUTPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float temp = dht.readTemperature();
  
  if (temp > 30) {  // If temperature is above 30°C
    digitalWrite(relayPin, HIGH);  // Turn on the fan
    Serial.println("Fan ON");
  } else {
    digitalWrite(relayPin, LOW);  // Turn off the fan
    Serial.println("Fan OFF");
  }

  delay(2000);
}
