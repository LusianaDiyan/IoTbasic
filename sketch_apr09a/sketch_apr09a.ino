#include <ESP8266WiFi.h>
 
const char* ssid     = "Infinix"; //nama wifi
const char* password = "12306878"; //password
const char* host = "192.168.43.163"; //IP PC
 
#define pinSensor A0
int sensorValue = 0;
int nilaiMax = 1023;
 
float moisture = 0;
float panjangSensor = 4.0; //tinggi sensor
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  sensorValue = analogRead(pinSensor);
  sensorValue = constrain(sensorValue, 485, 1023);
  moisture= map(sensorValue, 485, 1023, 100, 0);
   Serial.println(moisture);
  Serial.print("connecting to ");
  Serial.println(host);
 
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
 
  // We now create a URI for the request
  String url = "/esp8266/add.php?";
  url += "moisture=";
  url += moisture;
 
  Serial.print("Requesting URL: ");
  Serial.println(url);
 
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
 
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
 
  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    //Serial.print(line);
 
    if (line.indexOf("sukses gaes") != -1) {
      Serial.println();
      Serial.println("Yes, data masuk");
    } else if (line.indexOf("gagal gaes") != -1) {
      Serial.println();
      Serial.println("Maaf, data gagal masuk");
      //digitalWrite(alarmPin, HIGH);
    }
  }
 
  Serial.println();
  Serial.println("closing connection");
  delay(10000);
}
