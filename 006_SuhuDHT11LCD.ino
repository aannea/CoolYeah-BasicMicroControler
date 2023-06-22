#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();

  Serial.print("Suhu Celsius = ");
  Serial.print(suhu);
  Serial.print(", Kelembaban = ");
  Serial.println(kelembaban);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu C: ");
  lcd.print(suhu);
  lcd.setCursor(0, 1);
  lcd.print("Kelembaban: ");
  lcd.print(kelembaban);

  delay(2000);
}
