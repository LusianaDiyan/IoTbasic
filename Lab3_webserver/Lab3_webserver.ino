#include <WiFi.h>
#define PORT 8080
#define LED_BUILTIN 2
#define IRPIN 27

const char *SSID = "InixindoZone-Portable";
const char *PASSWORD = "inix2013surabaya1";

String header= "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
String tailer= "</body></html>";

WiFiServer server(80);
WiFiClient client;

long randomnumber;
String s;
String cmd;
int isObstacle = HIGH;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IRPIN, INPUT);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.print("Web Server active: ");
  Serial.println( WiFi.localIP() );
  server.begin();
  randomSeed(42);
}

void loop() {
  client= server.available(); //tunggu client
  //Serial.println("waiting for client ");
  isObstacle = digitalRead(IRPIN);
  if(isObstacle == LOW){
    Serial.println("Ada Penghalang");
    digitalWrite(LED_BUILTIN, HIGH);
   }else{
    Serial.println("Tidak Ada Penghalang");
    digitalWrite(LED_BUILTIN,LOW);
   }
  
  if (client) { // dapat client baru
    Serial.println("got a new client");
    while (client.connected() ) {
      if ( client.available()) {
        //Serial.println("Data can be read");
        s = client.readString();
        cmd= getCommand(s);
        if (cmd.equals("")) {
          refresh(0);
        } else if(cmd.equals("refresh?")) {
          refresh(isObstacle); // min max
        } else {
          refresh(0);
          client.stop();
        }
        Serial.println(cmd);
        delay(100);
      }
      else {
        client.stop();
      }
    }
    //client.stop();
  }
  else {
    //Serial.println("No client yet ");
  }
  delay(1000);
}

void refresh (int nilai) {
  client.println(header);
  client.print ("<html><head><title>Sensor</title>");
  client.print ("<meta name='viewport' content='width=device-width,initial-scale=1.0'>");
  client.print ("</head>");
  client.print ("<body><h1>Data Sensor</h1>");
  client.printf("<p>Nilai Data Dari Sensor adalah : %d </p>", nilai);
  client.print ("<p><form action='/refresh'><input type='submit' value='Refresh'></p>");
  client.println(tailer);
}

String getCommand(String s) {
  int i;
  i= s.indexOf(' ',5);
  return (s.substring(5, i));
}
