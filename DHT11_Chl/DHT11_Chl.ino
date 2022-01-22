#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

int dataheader = 1;
int loaddata = 0;
String datashow = "";

float h, hnew;
float t, tnew;
float f, fnew;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void header() { 
  Serial.println("Kelembaban  Temperatur  Temperatur"); 
  Serial.println("    %       Celcius     Fahrenheit"); 
}

void output(){
  if((h==hnew)&&(t==tnew)&&(f==fnew)){
    loaddata = loaddata+1;
    if(loaddata>20){
      datashow = "";
    }else{
      datashow = datashow + ". ";
    }
    Serial.println(datashow);
  }else{
    loaddata = 0;
    datashow = "";
    Serial.println(String(h)+"       "+String(t)+"       "+String(f));
  }
    hnew = h;
    tnew = t;
    fnew = f;
    dataheader = dataheader+1;
    if(dataheader>=6){
      dataheader = 1;
    }
}

void loop() {
  if(dataheader == 1){
    header();
   }
  delay(5000);

  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);

  output();
}
