#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define RXPin 12  // Connect GPS TX to Arduino D12
#define TXPin 13  // Connect GPS RX to Arduino D13
#define GPSBaud 9600  // GPS module baud rate

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);
  Serial.println("GPS Module is initializing...");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());

    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(", Longitude: ");
      Serial.println(gps.location.lng(), 6);
    }
  }
}
