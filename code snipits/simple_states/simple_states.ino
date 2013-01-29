int out;
int state = 1;
boolean changeing = false;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(1, OUTPUT);
}

void loop()
{
  out = analogRead(A0);
  Serial.println(state);
  delay(25);
  
  
  if(out == 0 && !changeing)
  {
    state++;
    changeing = true;
  }
  else if (out == 0)
  {
    
  }
  else
  {
    changeing = false;
  }
  
  if (state == 9)
    state = 1;
    
//  switch(state)
//  {
//    case 1:
//    {
//      break;
//    }
//    
//  }  
  
  delay(25);
}
