#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE 11
DHT dht(DHTPIN, DHTTYPE);

//deklarasi variable global
float h=0,t=0,f=0,hif=0,hic=0;
float h_old,t_old,f_old;
int jumlah_titik=0,jumlah_data=0;


void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  header();
  if(jumlah_data<=5){
    jumlah_data++;
  }else{
    header();
    jumlah_data=0;
  }  
  ambilData();
  printData;
  delay(5000);
  
  
  
  /*
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  */

}

void header() {
Serial.println("Kelembaban\tTemperatur\tTemperatur");
Serial.println(" % \t\tCelcius \tFahrenheit");
}

void ambilData(){
  //menggeser data
  h_old=h;
  t_old=t;
  f_old=f;
  //mengambil data baru
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
   // Compute heat index in Fahrenheit (the default)
  hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  hic = dht.computeHeatIndex(t, h, false);
}

void printData(){
  
  if(h_old==h && t_old==t && f_old==f){
     if(jumlah_titik<=20){
        Serial.print(".");
        jumlah_titik++;
      }else{
        jumlah_titik++;
      }
  }else{
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print(f);
  Serial.print(" *F\t");
  jumlah_titik=0;
  }
}
