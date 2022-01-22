
#include <WiFi.h>
const char* ssid =  "InixindoZone-Portable";
const char* password = "inix2013surabaya1";

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.disconnect();
  //WiFi.disconnect(true);
  connectToHotSpot();
}

void connectToHotSpot() {

  WiFi.begin( ssid, password );
  Serial.println("Trying to establish connection to WiFi Router");
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP addr: ");
  Serial.println(WiFi.localIP());
  Serial.print("Mac Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // nothing here
}
