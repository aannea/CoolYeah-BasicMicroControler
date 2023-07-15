#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "OPPOA17";
const char* password = "q873am9p";
unsigned long myChannelNumber = 2212704; // Ganti dengan Channel
Number Anda di ThingSpeak
const char * myWriteAPIKey = "CO2CSJLTI4M85F46"; // API Key dari ThingSpeak Anda

// Definisikan pin temp sensor
int tempPin = A0; // Ganti ini dengan pin yang Anda gunakan untukLM35

// Inisialisasi objek WiFiClient
WiFiClient client;

// Membaca suhu dari sensor LM35
float bacaSuhuDariSensor() {
  float reading = analogRead(tempPin);
  // Konversi nilai bacaan menjadi derajat Celsius
  float suhu = (reading * 5.0 / 1023.0) / 0.01;
  return suhu;
}

void setup() {
  Serial.begin(115200);
  delay(10);
  // Hubungkan ke WiFi
  Serial.println();
  Serial.println();
  Serial.print("Menghubungkan ke ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi terhubung");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

// Mengirim data suhu ke ThingSpeak
void loop() {
  // Membaca suhu dari sensor LM35
  float suhu = bacaSuhuDariSensor();
  Serial.println(suhu);
  ThingSpeak.writeField(myChannelNumber, 1, suhu, myWriteAPIKey);
  delay(1000); // Tunggu 20 detik untuk mengirim data berikutnya
}
