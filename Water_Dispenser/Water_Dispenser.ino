#define trigPin 2
#define echoPin 3

long duration;
int distance;
int threshold = 20;


void setup() {
// put your setup code here, to run once:
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(7,OUTPUT);
    Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  Serial.println(distance);
  if (distance < threshold) {
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(7, HIGH);
  }
//  delay(1000);
}
