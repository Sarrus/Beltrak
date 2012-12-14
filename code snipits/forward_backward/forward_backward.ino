//by Michael Bell

// to use this, attacch the motor sheild to the arduino board then
// upload the code and put a 9 or 12 volt suply over the vin on the 
// motor sheild

int throttle = 3; //the speed pin
int brake = 9; //the brakeing pin
int forBac = 12; //the direction pin (HIGH forwards, LOW backwards)
int maxSpeed = 255; //the top speed
int speedIs = 0; //the current speed
float pPD; // the % Potential Difference
float speedIsFl; //the float of the speed

//1- acelerating forward
//2- decelerating forward
//3- acelerating backward
//4- decelerating backward
int state = 1;

//the inclludes and defines for the lcd
#include <LiquidCrystal.h>   // include LCD library

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 ); //define the lcd pins

void setup() {
  
  //Setup Channel A
  pinMode(throttle, OUTPUT); //Initiates Motor Channel pin
  pinMode(brake, OUTPUT); //Initiates Brake Channel pin
  pinMode(forBac, OUTPUT); //initiates the direction pin
  digitalWrite(brake, LOW); //disengage breaks
  
  lcd.begin( 16, 2 ); //set the grid
  
  lcd.setCursor( 0, 1 );   //bottom left
  lcd.print( "P.D.:" ); //provide a placeholder for the %PD
  lcd.setCursor( 0, 0 );   //top left
  lcd.print( "Going Forward   " );
}

void loop()
{
  if(speedIs == maxSpeed && state == 1)
  {
    state = 2;
    digitalWrite(forBac, HIGH); //sets to forward
    lcd.setCursor( 0, 0 );   //top left
    lcd.print( "Going Forward   " );
  }
  
  else if (speedIs == 0 && state == 2)
  {
    state = 3;
    digitalWrite(forBac, LOW); //sets to backwards
    lcd.setCursor( 0, 0 );   //top left
    lcd.print( "Going Backwards " );
  }
  
  else if (speedIs == maxSpeed && state == 3)
  {
    state = 4;
    digitalWrite(forBac, LOW); //sets to backwards
    lcd.setCursor( 0, 0 );   //top left
    lcd.print( "Going Backwards " );
  }
  
  else if (speedIs == 0 && state == 4)
  {
    state = 1;
    digitalWrite(forBac, HIGH); //sets to forward
    lcd.setCursor( 0, 0 );   //top left
    lcd.print( "Going Forward   " );
  }
  
  switch(state)
  {
    case 1: //acelerating forward
    {
      
      speedIs = speedIs + 1; //increments speed
      break;
    }
    
    case 2: //decelerating forward
    {
      
      speedIs = speedIs - 1; //decriments speed
      break;
    }
    
    case 3: //acelerating backwards
    {
      
      speedIs = speedIs + 1; //increments speed
      break;
    }
    
    case 4: //decelrating backwards
    {
      
      speedIs = speedIs - 1; //decriments speed
      break;
    }
  }
  analogWrite(throttle, speedIs); 
  
  speedIsFl = speedIs;
  pPD = (speedIsFl/255)*100;
  
  lcd.setCursor( 6, 1 );   //left, one space after P.D.:
  lcd.print( pPD ); //the percentage of the maximum P.D.
  lcd.print( "%   " ); //print a % sign
  delay(25);
}
