/*
ERASE - *
SET VALUE - D
*/

#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>
Adafruit_LiquidCrystal lcd_1(0);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','D'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String value="";

void setup(){
  lcd_1.begin(16, 2);
  lcd_1.setCursor(16,0);
  lcd_1.print("KEYPAD CONTROLLED FAN");
  for(int i=0; i<37;i++){
    lcd_1.scrollDisplayLeft();
    delay(100);
  }
  delay(800);
  lcd_1.clear();
  lcd_1.print("FAN SPEED(0-100)");
  lcd_1.setCursor(0,1);
  lcd_1.print("CLICK D TO SET");
}

void loop(){
  
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    
    lcd_1.clear();
    value = value + key;
    Serial.println(value);
    lcd_1.print(value);
    
    if(key=='*')
    {
        lcd_1.clear();
        value="";

    }
    
    if(key=='D')
    {
        
      lcd_1.clear();
      int a=value.toInt();        
      if(a<=100){
        int a1=map(a,0,100,0,255);
        digitalWrite(13,HIGH);
        analogWrite(11,a1);
        value="";
        lcd_1.print(a);
        lcd_1.setCursor(0,1);
        lcd_1.print("VALUE SET :)");
      }
      else{
        lcd_1.clear();
        lcd_1.print("INVALID INPUT :(");
        value="";
      }
    }
    
  }
}
