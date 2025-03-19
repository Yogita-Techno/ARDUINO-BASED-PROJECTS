// Define the buzzer pin
const int buzzerPin = 8;

// Define the musical notes in Hz (frequencies)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  466
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784

// Define the note durations (in milliseconds)
#define WHOLE 1000
#define HALF 500
#define QUARTER 250
#define EIGHTH 125

void setup() {

}

void loop() {
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_F4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_G4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_G4, HALF);
  delay(HALF);
  
  tone(buzzerPin, NOTE_F4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  
  tone(buzzerPin, NOTE_E4, HALF);
  delay(HALF);
  
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_F4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_G4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_G4, HALF);
  delay(HALF);
  
  tone(buzzerPin, NOTE_F4, QUARTER);
  delay(QUARTER);
  tone(buzzerPin, NOTE_E4, QUARTER);
  delay(QUARTER);
  
  noTone(buzzerPin); 
  delay(1000);        
}
