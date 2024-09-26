#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
int val1=0;
int val2=0;
int val3=0;
int val4=0;
int val5=0;


void setup()
{
  s1.attach(11);
  s2.attach(10);
  s3.attach(9);
  s4.attach(6);
  s5.attach(5);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop()
{
  val1 = analogRead(A0);
  val2 = analogRead(A1);
  val3 = analogRead(A2);
  val4 = analogRead(A3);
  val5 = analogRead(A4);
  val1 = map(val1,236,634,0,180); //100 kilo ohm resistors are used
  val2 = map(val2,236,634,0,180);
  val3 = map(val3,236,634,0,180);
  val4 = map(val4,236,634,0,180);
  val5 = map(val5,236,634,0,180);
  s1.write(val1);
  s2.write(val2);
  s3.write(val3);
  s4.write(val4);
  s5.write(val5);
  delay(10);
}