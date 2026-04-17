#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PH_PIN 34
#define TURB_PIN 35

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Global Variables for the "Special" logic
float filterHealth = 100.0; 

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("AI-SMART WATER");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM STARTING");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read simulated sensors
  int phRaw = analogRead(PH_PIN);
  int turbRaw = analogRead(TURB_PIN);

  // Convert to realistic values
  float phValue = (phRaw / 4095.0) * 14.0;
  float turbidity = (turbRaw / 4095.0) * 100.0;

  // "Special" Feature: Filter Degradation Logic
  // If water is very dirty (Turbidity > 40), filter health drops faster
  if (turbidity > 40) {
    filterHealth -= 0.5; 
  } else if (turbidity > 15) {
    filterHealth -= 0.1;
  }
  
  if (filterHealth < 0) filterHealth = 0;

  // Display Row 1: pH and Filter Life
  lcd.setCursor(0, 0);
  lcd.print("pH:"); lcd.print(phValue, 1);
  lcd.print(" FLTR:"); lcd.print((int)filterHealth); lcd.print("%");

  // Display Row 2: Potability Logic
  lcd.setCursor(0, 1);
  if (filterHealth <= 0) {
    lcd.print("SYSTEM LOCKED!  "); // Filter is dead
  } else if (phValue < 6.5 || phValue > 8.5) {
    lcd.print("ACIDIC/ALKALINE "); // Chemical imbalance
  } else if (turbidity > 20) {
    lcd.print("DIRTY: CLEANING "); // High turbidity
  } else {
    lcd.print("POTABLE: SAFE   "); // Everything is perfect
  }

  delay(800); // Slightly faster refresh for a "real-time" feel
}