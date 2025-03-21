// Pin Definitions
const int fireSensorPin = A0;  
const int buzzerPin = 8;       
const int relayPin = 9;        

int fireThreshold = 500;      

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int fireLevel = analogRead(fireSensorPin);

  Serial.print("Fire Level: ");
  Serial.println(fireLevel);

  if (fireLevel > fireThreshold) {
    digitalWrite(buzzerPin, HIGH);  
    digitalWrite(relayPin, HIGH);    
  } else {
    digitalWrite(buzzerPin, LOW); 
    digitalWrite(relayPin, LOW);    
  }
  delay(500);
}
