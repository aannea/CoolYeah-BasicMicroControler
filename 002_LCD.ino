#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Cia, Puspita, Farhan");
  lcd.setCursor(4,1);
  lcd.print("IF-09-M");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(500);
}
