/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */

void initialise()
{
  
  //initialise the lcd screen with rows and columns
  lcd.begin( 16, 2 );

  //print the loading screen
  lcd.setCursor( 0, 0 );
  lcd.print( "Loading..." );

  //initialise global variables
  PPD = 0; //full stop
  reverser = false; //the train will travel forward

  //initialise pins
  pinMode(pinPD, OUTPUT); //instruct the board to output to the PD pin
  pinMode(pinDIR, OUTPUT); //instruct the board to output to the direction pin
  pinMode(pinButtons, INPUT ); //instruct the board to read from the button pin
  digitalWrite(pinButtons, LOW); //make sure that the board doesent pass voltage to the button pin

  pinMode(point1, OUTPUT); //the point pins
  pinMode(point2, OUTPUT);
  
  pinMode(backlightPin, OUTPUT);
  
  backlight = 2;
  
//  pinMode(pointPower, OUTPUT);
  pinMode(pointDir, OUTPUT);
  

  //initialise array positions
  instSet = 7;
  instPos = 0;

  //initialise the timer
  timer = 0;  

  //initialise points
  for(int i=0; i<10; i++)
  {
//    /*these two values are set to differ so that the board is forced to move all the points on the first run, this makes sure
//     that the board knows their positions and reveals any malfunctioning points*/
//    pointState[i] = true;
//    pointSwitch[i] = false;
  }

  //initialise transition boolean
  inTransit = false;

  //initialises the anti-multipress boolean
  /*this is set to true so that if a button is stuck down when the board turns on it is not registered*/
  butonCaptured = true;
  
  //menu positions
  menuPosX = 0;
  menuPosY = 0;
}
