void setup()
{
  int throttle = 3; //the speed pin
  int brake = 9; //the brakeing pin
  int forBac = 12; //the direction pin (HIGH forwards, LOW backwards)
  pinMode(throttle, OUTPUT); //Initiates Motor Channel pin
  pinMode(brake, OUTPUT); //Initiates Brake Channel pin
  pinMode(forBac, OUTPUT); //initiates the direction pin
  digitalWrite(brake, LOW); //disengage breaks
  digitalWrite(forBac, HIGH); //sets to forward
  analogWrite(throttle, 255); //sets to max speed
}

void loop()
{
}
