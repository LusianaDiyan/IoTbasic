/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
const int LED_MERAH = 26;
const int LED_KUNING = 27;
const int LED_HIJAU = 25;

const int LED_MERAH2 = 32;
const int LED_KUNING2 = 35;
const int LED_HIJAU2 = 34;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode (LED_HIJAU, OUTPUT);

  pinMode(LED_MERAH2, OUTPUT);
  pinMode(LED_KUNING2, OUTPUT);
  pinMode (LED_HIJAU2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_MERAH, HIGH); 
  digitalWrite(LED_MERAH2, LOW);   
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_HIJAU2, HIGH);
  delay(2000);                      
  digitalWrite(LED_MERAH, HIGH);
  digitalWrite(LED_MERAH2, LOW);
  digitalWrite(LED_KUNING2, HIGH);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAU, LOW); 
  digitalWrite(LED_HIJAU2, HIGH);   
  delay(1000);
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_MERAH2, HIGH);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_KUNING2, LOW);
  digitalWrite(LED_HIJAU, HIGH);
  digitalWrite(LED_HIJAU2, LOW);
  delay(2000);
}
