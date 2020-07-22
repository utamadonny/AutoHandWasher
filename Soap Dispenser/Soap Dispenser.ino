#include <Servo.h>
#define trigPin 7
#define echoPin 8

long duration;
int distance;
int threshold = 10;
Servo countServo;

void setup() {
// put your setup code here, to run once:
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    countServo.attach(6); 
    Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  Serial.println(distance);
  if (distance < threshold) {
  countServo.write(180);
  countServo.write(0);
  countServo.write(180);
  }
}
