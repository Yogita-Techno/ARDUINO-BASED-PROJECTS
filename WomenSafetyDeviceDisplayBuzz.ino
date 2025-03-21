
#define btnPin 9
#define buzPin 4
#define redLedPin 2
#define greenLedPin 3
#define btRx 8
#define btTx 7
#define gpsRx 5
#define gpsTx 6

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include<SoftwareSerial.h>
SoftwareSerial bluetooth(btRx, btTx);

#include <TinyGPS++.h>
TinyGPSPlus gps;
SoftwareSerial gpsSerial(gpsRx, gpsTx); // RX, TX

String womenStatus;
float lantitude,longitude;


void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  bluetooth.begin(9600);
  lcd.init();
  //  lcd.begin();
  lcd.backlight();
  pinMode(btnPin, INPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  digitalWrite(buzPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);

  lcd.print("Startining...!!");
  lcd.clear();
  lcd.print("Women is Safe.");


}

void loop() {
  checkGps();
//  Serial.println(digitalRead(11));
  if (digitalRead(btnPin) == 1) {
    while (digitalRead(btnPin) == 1) {
      delay(10);
    }
    digitalWrite(buzPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    lcd.clear();
    lcd.print("DANGER");
    bluetooth.println("A"+String(lantitude,6)+"B"+String(longitude,6)+"C1");
  }
}

void checkGps() {
  while (gpsSerial.available() > 0) {
    // Feed the GPS parser
    gps.encode(gpsSerial.read());
  }

  // Check if a valid location is available
  if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    lantitude = gps.location.lat();
    Serial.println(lantitude, 6);      // Latitude with 6 decimal places
    Serial.print("Longitude: ");
    longitude = gps.location.lng();
    Serial.println(longitude, 6);  // Longitude with 6 decimal places
  } else {
    lantitude = 21.1475141;
    longitude = 82.0455323;
    Serial.println("Waiting for GPS signal...");
  }

  delay(1000); // Wait for a second before next reading
}
