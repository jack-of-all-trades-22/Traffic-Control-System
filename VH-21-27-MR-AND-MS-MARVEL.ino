#include<LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(11,12,2,3,4,5);
Servo servo10;
int breaker=A5;
const int trigpin=9;
const int echopin=8;
float interval,dist;
int rled=6;
int yled=7;
int gled=13;
int c=0;
int spd;  
void setup()
{
  pinMode(10,INPUT);
  pinMode(A5,OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd.begin(16,2);
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled,OUTPUT);
  servo10.attach(breaker);
  servo10.write(0);
  Serial.begin(9600);
}

void loop()
{
  int a = digitalRead(10);
  Serial.println(a);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
      
  interval = pulseIn(echopin, HIGH);
  
  dist = (interval*.0343)/2;
  spd= dist/interval;
  if (dist<100)
  {    
    lcd.println("STOP");
    digitalWrite(rled, HIGH);
    digitalWrite(yled, LOW);
    digitalWrite(gled, LOW);
    servo10.write(0);
    delay(20);
    lcd.clear();
    if( a==1)
    {
      digitalWrite(rled, HIGH);
      lcd.setCursor(0,0);
      lcd.println("Cross the Road");
      delay(2000);
      lcd.clear();
      digitalWrite(gled, HIGH);
      lcd.println("Now Proceed");
      c=c+a;
      Serial.println("Two Wheeler Count:");
      Serial.print(c);
      delay(2000);
    }
      
  }
  else if (dist>100 && dist<200)
  {
    lcd.println("Slow");
      digitalWrite(yled, HIGH);
      digitalWrite(rled, LOW);
      digitalWrite(gled,LOW);
      servo10.write(90);
      delay(2000);
      lcd.clear();
    if( a==1)
    {
      digitalWrite(yled,HIGH);
      lcd.setCursor(0,0);
      c=c+a;
      Serial.println("Two Wheeler Count:");
      Serial.print(c);
      delay(2000);
      lcd.clear();
    }
   }
  else if (dist>200)
  {
  
    lcd.println("PROCEED");
    digitalWrite(gled, HIGH);
    digitalWrite(yled, LOW);
    digitalWrite(rled,LOW);
    delay(20);
    servo10.write(0);
    delay(20);
    lcd.clear();
  }
  
   else 
  {
    digitalWrite(gled, LOW);
  }
  
   
}
