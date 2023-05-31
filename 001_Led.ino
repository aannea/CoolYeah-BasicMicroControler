void setup(){
  pinMode(9, Output);
}

void loop(){
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
}
