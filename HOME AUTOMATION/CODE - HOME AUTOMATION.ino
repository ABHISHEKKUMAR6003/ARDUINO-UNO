#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);



void setup()
{
  lcd.begin(16,2);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
    
}

long readUltrasonicDistance() 
{ 
pinMode(7, OUTPUT);  
// Clear the trigger 
digitalWrite(7, LOW); 
delayMicroseconds(2); 
// Sets the trigger pin to HIGH state for 10 microseconds 
digitalWrite(7, HIGH); 
delayMicroseconds(10); 
digitalWrite(7, LOW); 
pinMode(7, INPUT); 
// Reads the echo pin, and returns the sound wave travel time in microseconds 
return pulseIn(7, HIGH); 
}

void loop()
{
  
  int level = 0.01723 * readUltrasonicDistance();
  level = map(level,3,336,100,0);
  int ldr = analogRead(A0);
  ldr = map(ldr,49,969,100,0);
  float temp = analogRead(A1);     
  temp = (temp * 0.48828125) - 49;  
  lcd.clear();
  lcd.print("TEMPERATURE:");
  lcd.print(temp);
  delay(200);
  int pir = digitalRead(5);
  
  if (pir==1){
    tone(6,5000);
    delay(15000);
    noTone(6);
  }
  if (ldr<=94){
    digitalWrite(2,HIGH);
    lcd.setCursor(0,1);
    lcd.print("NIGHT");
    delay(200);
  }
  else{
    digitalWrite(2,LOW);
    lcd.setCursor(0,1);
    lcd.print("DAY");
    delay(200);
  }
  if (level>80){
    digitalWrite(3,LOW);
  }
  else{
    digitalWrite(3,HIGH);
  }
  if (temp>28){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
        
  }
  
  
}