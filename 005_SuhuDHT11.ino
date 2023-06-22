void setup() {
  Serial.begin(9600);
}

void loop() {
  int bacaAnalog = analogRead(A0);
  float tegangan = bacaAnalog * (5.0 / 1023.0);
  float celcius = (tegangan - 0.5) * 100;
  Serial.println(celcius);
}
