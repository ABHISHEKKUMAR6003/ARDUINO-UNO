//PASSWORD - 589D
//CLOSING - CD
//RESET - ALARM *
/*motion detector works only if the door is closed and the
slideswitch is ON (slide left to turn on)

This project involves creating a home safety system,
which has a pasword projected door and burglar alarm
system. Two keypads are used - one accessed from outside, 
and another from inside. This project is still under
development.
*/

#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Adafruit_LiquidCrystal lcd_1(0);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";
Servo servo_10;

void setup(){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12,INPUT);
  servo_10.attach(10);
  
  servo_10.write(0);
  lcd_1.begin(16, 2);
}

void loop(){
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    
    lcd_1.clear();
    
    v_passcode = v_passcode + key;
    lcd_1.print(v_passcode);
    
  
    
    if(key=='*') //KEY FOR RESETING ALARM
    {
      digitalWrite(11,LOW);
      lcd_1.print("ALARM RESET :)");
      v_passcode="";

    }
    
    if(key=='#') //KEY FOR CLEARING PASSWORD AND ENTER AGAIN
    {
        Serial.println("Enter Password again ending with D");
        v_passcode="";
      	Serial.println(v_passcode);
        

    }
    
    
    
    
    if(key=='D')//KEY FOR FINISHING PASSWORD
    {
      
      lcd_1.setCursor(0,0);    
      lcd_1.print(v_passcode);
      lcd_1.setCursor(0,1);
          
      if (v_passcode=="589D")//OPENING DOOR
      {
          Serial.println("Access Granted");
            lcd_1.print("ACCESS GRANTED:)");
            servo_10.write(90);
            delay(2000);
            digitalWrite(13,HIGH);
            v_passcode="";
          }
      
      else if(v_passcode=="CD")//CODE FOR CLOSING DOOR
      {
        
        lcd_1.print("DOOR CLOSING");
        servo_10.write(0);
        lcd_1.clear();
        lcd_1.print("DOOR CLOSED");
        
      
      }
      
       
       	 
      else
        {
            
            lcd_1.print("ACCESS DENIED");
             v_passcode="";
        }
      
      
      
    }
    
    
      
    
  }
  if((servo_10.read()<10) && (digitalRead(12)==1))//MOVEMENT DETECTION PROVIDED DOOR IS CLOSED
  {
    lcd_1.clear();
    digitalWrite(11,HIGH);
    lcd_1.print("BURGLAR ALERT");
    delay(1000);
    
         }
  
    
  
 
  
}