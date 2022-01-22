#define trigPin 27
#define echoPin 26
#define ledHijauSU 32
#define ledMerahSU 33
#define ledHijauBT 12
#define ledMerahBT 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledHijauSU, OUTPUT);
  pinMode(ledMerahSU, OUTPUT);
  pinMode(ledHijauBT, OUTPUT);
  pinMode(ledMerahBT, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  digitalWrite(ledHijauBT, HIGH);
  digitalWrite(ledMerahSU, HIGH);
  
  if (distance <= 15)
    {    
      delay(5000);
      digitalWrite(ledHijauBT, LOW);
      digitalWrite(ledMerahSU, LOW);
      digitalWrite(ledMerahBT,HIGH);
      digitalWrite(ledHijauSU, HIGH);
      delay(6000);
    }
  else
    {
      digitalWrite(ledHijauBT, HIGH);
      digitalWrite(ledMerahSU, HIGH);
      digitalWrite(ledMerahBT, LOW);
      digitalWrite(ledHijauSU, LOW);
    }
}
