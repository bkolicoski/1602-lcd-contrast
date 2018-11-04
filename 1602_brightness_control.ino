#include <LiquidCrystal.h>

// initialize the LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// output control pins
#define LCD_CONTRAST_PIN 6
#define LCD_BACKLIGHT_PIN 10

void setup() {
  //set some defaults
  analogWrite(LCD_BACKLIGHT_PIN, 255); //set backlight on
  analogWrite(LCD_CONTRAST_PIN, 50); //set some contrast
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(5000);
}

void loop() {
  lcd.clear();
  lcd.print("Contrast:");
  // loop through values for contrast
  for (int i=0; i <= 150; i++){
    analogWrite(LCD_CONTRAST_PIN, i);
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(80);
  }
  
  analogWrite(LCD_CONTRAST_PIN, 50);

  lcd.clear();
  lcd.print("Back light:");
  // loop through values for backlight
  for (int i=0; i <= 255; i+=2){
    analogWrite(LCD_BACKLIGHT_PIN, i);
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(80);
  }
}
