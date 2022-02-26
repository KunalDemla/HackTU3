// C++ code
//
const int pingPin1 = 7;
const int pingPin2 = 6;
const int DrivePin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(DrivePin, OUTPUT);
}

void loop()
{
  long d1, cm1, d2, cm2;
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);

  
  pinMode(pingPin1, INPUT);
  d1 = pulseIn(pingPin1, HIGH);

  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

  
  pinMode(pingPin2, INPUT);
  d2 = pulseIn(pingPin2, HIGH);
  
  cm1 = microsecondsToCentimeters(d1);
  cm2 = microsecondsToCentimeters(d2);

  if((cm1 < 100)||(cm2>10)) {
    digitalWrite(DrivePin, LOW);
  }
  else {
    digitalWrite(DrivePin, HIGH);
  }
  
  delay(10);
}

long microsecondsToCentimeters(long microseconds) {
  
  return microseconds / 29 / 2;
}
