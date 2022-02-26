//Code for Arduino Fall Alarm Sensor 

#define fsrpin A0

int fsrreading;
int count=0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  fsrreading = analogRead(fsrpin);
  if(fsrreading>200)
  {
    count=0;
    digitalWrite(13, LOW);
  }
  else 
  {
    count++;
  }
  if(count>3){
  digitalWrite(13, HIGH);
  }
  delay(1000);
}