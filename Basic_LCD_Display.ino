#include <LiquidCrystal.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);   // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Hello, World!");  // Display a message
}

void loop() {
  // Nothing to do here
}
