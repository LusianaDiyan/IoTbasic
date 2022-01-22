#include <WiFi.h>

const char* ssid =  "InixindoZone";
const char* password = "inix2013surabaya1";

String header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body>";
String tailer = "</body></html>";

WiFiServer server(80);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.disconnect();
  //WiFi.disconnect(true);
  connectWifi();
  server.begin();
}

void loop() {
  client  = server.available();
  Serial.println(".. waiting for client ..");
  if(client){
    Serial.println("~new client~");           
    response("Hello Welcome to This Webpage."); 

    //client.stop();   // Close the connection
    //Serial.println("Client disconnected.");
    Serial.println("");
  }
  else{
    Serial.println("~no client yet~");
  }
  delay(5000);  
}

void connectWifi() {
  WiFi.begin( ssid, password );
  Serial.println("Trying to establish connection to WiFi Router");
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP addr: ");
  Serial.println(WiFi.localIP());
}

void response(String konten){
    Serial.println(header);
    Serial.println(konten);
    Serial.println(tailer);
    client.println(header);
    client.println(konten);
    client.println(tailer);
    client.println(); 
}
