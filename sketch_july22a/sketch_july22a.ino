#include <Servo.h>

//Soap
#define trigPin1 11
#define echoPin1 10

//Water
#define trigPin2 5
#define echoPin2 3

// Soap
long duration1;
int distance1;
int threshold1 = 10;

// Water
long duration2;
int distance2;
int threshold2 = 10;

Servo countServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(7, OUTPUT);
  countServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) * 0.0343;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) * 0.0343;

  Serial.print("jarak1:");
  Serial.println(distance1);
  Serial.print("Jarak2:  ");
  Serial.println(distance2);

  //soap
  if (distance1 < threshold1) {
    countServo.write(180);
  }
  if (distance1 > threshold1) {
    countServo.write(0);
  }

  //water
  if (distance2 < threshold2) {
    countServo.write(0);
    digitalWrite(7, LOW);
    delay(2800);
  }
  if (distance2 > threshold2) {
    countServo.write(0);
    if (distance1 < threshold1) {
      countServo.write(180);
    }
    digitalWrite(7, HIGH);
  }
}
