#include <LiquidCrystal.h> //library untuk fungsi lcd LiquidCrystal 
lcd(5, 6, 10, 11, 12, 13); //penginisialam nama dan pin(RS, E, D4, D5, D6, D7) 

int trigpin = 3; //penginisial kaki trigpin masuk pin 3 int echopin = 4; //penginisial kaki echopin masuk pin 4 
int led = 9; 

void setup() { 
  pinMode(trigpin, OUTPUT); //pin trigpin sebagai OUTPUT 
  pinMode(echopin, INPUT); //pin echopin sebagai INPUT 
  lcd.begin(16,2); //menunjukkan bahwa lcd memiliki 16 kolom 2 baris 
  Serial.begin(9600); 
  pinMode(led,OUTPUT); 
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}

void loop() { 
  int bacaAnalog = analogRead(A5); 
  Serial.println(bacaAnalog); 
  float tegangan = bacaAnalog * (5.0/1023.0); 
  lcd.clear(); //bahwa lcd dalam keadaan bersih tanpa tulisan 
  lcd.setCursor(0, 1); 
  lcd.print(tegangan); 
  if(tegangan > 4.0){ 
    digitalWrite(led,HIGH); 
  }else{
    digitalWrite(led,LOW);
  }
  digitalWrite(trigpin, LOW); //membaca pin trigpin low 
  delayMicroseconds(2); 
  digitalWrite(trigpin, HIGH); //pin trigpin mengirim sinyal 
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW); //pin trigpin LOW 
  int duration = pulseIn(echopin, HIGH); //pin echo membaca / menerima sinyal 
  int distance = duration /58; //rumus dalam cm 
  lcd.setCursor(0,0); //text dimulai dari baris 1 dan kolom 1
  lcd.print("Jarak = "); //lcd menampilkan text nilai= 
  lcd.print(distance); //lcd menampilkan data nilai dari sensor 
  lcd.print("cm"); //lcd menampilkan text cm 
  delay(300); 
}
