
  #include <Servo.h>
  #define trigPin 12
  #define firePin 8
  #define ledPin 7
  #define ledPin1 6

  #define echoPin 11

  #define max_distance 20

  Servo servo;

  int sound = 250;
  void setup() {

  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);

  servo.attach(10);

  pinMode(firePin,INPUT);

  }

  void loop() {

  long duration, distance; 

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1; if (distance < 80) {

  Serial.print(distance);

  Serial.println(" cm");

  servo.write(90);

  }

  if (distance<50) {

  Serial.print(distance);

  Serial.println(" cm");

  servo.write(90); }

  else {
  servo.write(0);
  Serial.println("The distance is more than 180cm");
  Serial.println();

  }

  delay(500);

  int sensorValue=digitalRead(firePin);

  if(sensorValue==LOW){
    Serial.println("Fire\n");
    digitalWrite(ledPin,HIGH);
    Serial.println();
  }
  else{
    Serial.println("safe\n");
    digitalWrite(ledPin,LOW);
    Serial.println();
  }

  float sensorValue1=analogRead(A0);
  Serial.println(sensorValue1);
  if(sensorValue1<=400){
    Serial.println("Less than 400");
    digitalWrite(ledPin1,HIGH);
  }
  else{
    digitalWrite(ledPin1,LOW);
    Serial.println("Greater Than 400");
  }
  }

