int button = 12;
int led = 4;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int nilaiButton = digitalRead(button);
  if (nilaiButton == LOW){
    Serial.println("LOW");
    digitalWrite(led,LOW);
  } else{
    // jika tidak, maka
    Serial.println("HIGH");
    digitalWrite(led,HIGH);
  }
}
