int moisture = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(7,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  moisture = analogRead(A1);
  Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  //uses RGB LED as indicator
  if (moisture < 200) {
    digitalWrite(12, HIGH);
    digitalWrite(7,HIGH);
  } 
  else if (moisture < 400) {
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7,HIGH);
   } 
  else if (moisture < 600) {
      digitalWrite(10, HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(7,LOW);
   } 
  else if (moisture < 800) {
      
      digitalWrite(11, HIGH);
      digitalWrite(7,LOW);
   } 
  else {
      digitalWrite(10, HIGH);
      digitalWrite(7,LOW);
        }
      
  delay(100); 
  // Wait for 100 milliseconds
}