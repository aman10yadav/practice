#include <LiquidCrystal.h>
#define trigPin 9
#define echoPin 13
#define buzzer 10
//int pow 10


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pow,OUTPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344 ;
  int pow =10;
  if (distance >=4000 || distance <= 20){
      lcd.print(distance);
    lcd.print(" cm");
   digitalWrite(pow,1000);
    delay(1000);
    lcd.clear();
    digitalWrite(pow,LOW);
   
  }
  else {
    lcd.print("Out of the range please be in a range between 20cm to 0cm") ;
    noTone(buzzer);
    //digitalWrite(pow,500);
  }
  delay(500);
  lcd.clear();
}
