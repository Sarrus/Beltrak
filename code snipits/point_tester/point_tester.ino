void setup()
{
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (12, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(i, HIGH);
    analogWrite (3, 255);
    delay (300);
    digitalWrite(i, LOW);
    
    analogWrite(3, 0);
    delay(1000);
    digitalWrite (12, HIGH);
    
    digitalWrite(i, HIGH);
    analogWrite (3, 255);
    delay (300);
    analogWrite(3, 0);
    digitalWrite(i, LOW);
    
    delay(1000);
    digitalWrite (12, LOW);
    
  }
}
