#include<LiquidCrystal.h>

LiquidCrystal lcd(11,12,2,3,4,5);

const int trigpin=9;
const int echopin=8;
float interval,dist;
int rled=6;
int yled=7;
int gled=13;
  
void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd.begin(16,2);
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled, OUTPUT);
   
}

void loop()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
      
  interval = pulseIn(echopin, HIGH);
  
  dist = (interval*.0343)/2;
  
    
 lcd.setCursor(0,0); 
 lcd.print("Distance");
 lcd.print(dist);
  
  if (dist<100)
  {
    lcd.println("STOP");
    digitalWrite(rled, HIGH);
  }
  
  else 
  {
    digitalWrite(rled, LOW);
  }
  
  if (dist<150)
  {
    lcd.println("SLOW");
    digitalWrite(yled, HIGH);
  }
  
   else 
  {
    digitalWrite(yled, LOW);
  }
  
  if (dist>150)
  {
    lcd.println("PROCEED");
    digitalWrite(gled, HIGH);
  }
  
   else 
  {
    digitalWrite(gled, LOW);
  }
  
   
}
