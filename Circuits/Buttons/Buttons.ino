#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int BuzzerPin = 7;

void setup() {
  lcd.begin(16, 2);
  lcd.print("");
  pinMode(13,INPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(BuzzerPin,OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  if(digitalRead(13)==1){
    lcd.print("Food");
    lcd.print("       ");
  }
  else if(digitalRead(10)==1){
    lcd.print("Water");
    lcd.print("       ");
  }
  else if(digitalRead(9)==1){
    lcd.print("Toilet");
    lcd.print("       ");
  }
  else if(digitalRead(8)==1){
    lcd.print("Pain");
    lcd.print("       ");
    digitalWrite(BuzzerPin,HIGH);
  }
  else
  {
    lcd.print("       ");
    digitalWrite(BuzzerPin,LOW);
  }
}
 
