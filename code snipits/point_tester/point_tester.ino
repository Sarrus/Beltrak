void setup()
{
  pinMode (3, OUTPUT);
  pinMode (12, OUTPUT);
}

void loop()
{
  analogWrite (3, 255);
  delay (300);
  analogWrite(3, 0);
  delay(1000);
  digitalWrite (12, HIGH);
  
  analogWrite (3, 255);
  delay (300);
  analogWrite(3, 0);
  delay(1000);
  digitalWrite (12, LOW);
}
