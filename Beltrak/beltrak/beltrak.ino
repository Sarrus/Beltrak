/*

BELTRAK

V1.0

Hornby trainset automation

By Michael Bell

Programing started: 02/02/2013 at 14:08

*/

//declarations of librarys
  #include <LiquidCrystal.h>
  
//initialise librarys
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  
//declare global variables
  
  //train control variables
    float PPD; //Percentage Potential Difference -- what the board multiplies the maximum voltage by, this controls the speed of the train with 100 as the maximum and 0 for stop (PPD does not control direction)
    boolean reverser; //controls the direction of the train, when TRUE the train is reversed
 
  //pin number constants
    #define pinPD 3 //the pin number for the Potential Diference output
    #define pinDIR 12 //the pin number of the direction pin
    
  //the instruction array
    char inst[5][5][5]; //array containing the switching instructions
    
  //the position in the instruction array
    int instSet; //the set of instructions to be folowed, eg. go to hawkhaven, this is set by the user through the menus
    int instPos; //the position in the instructions, when a condition is met and a state is changed this incriments, when instSet changesm, this becomes 0
    boolean met; //set to true of a condition is met, the state is then changed.
    
  //virtual sensors
    /*these are variables that are used to test the program before sensors are intoduced true means HIGH false means LOW, !remember
    to change these in the code when introducing sensors!*/
    boolean VS[5];
    

void setup()
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
    
  //initialise the switching instructions
    inst[0][0][0] = 'B'; //in block
    inst[0][0][1] = '4'; //4
    inst[0][0][2] = 'S'; //set speed to
    inst[0][0][3] = '2'; //1
    
  //initialise array positions
    instSet = 0;
    instPos = 0;
    met = false;
    
  //initialise virtual sensors
    VS[4] = true;
}

void loop()
{
  
/* the "loop" is devided into 3 logical sections,

section 1: the menu position is ascertained and text is output to the screen, variables are ajusted to provide the other sections with user input

section 2: the instruction array is queried and the sensors are checked, variables are ajusted to set the curent instructions for the train

section 3: variables from section 2 are checked and the points are ajusted if necesary, then the speed of the train is set

these three are repeated endlessly untill power off */

//section 1: read user input and output display
    //print a welcome message
      lcd.setCursor( 0, 0 );
      lcd.print( "Beltrak 1.0" );

//section 2: check position and instructions
  /* section 2 is devided into two parts, part one checks if the given condition is met, part two carries out an instruction and moves
  to the next condition if it is, when a condition is met, the variable 'met' is set to true, section two is only run if met is true
  it sets met to false once it has been run*/
  
    //section 2.1
      switch(inst[instSet][instPos][0]) //this reads position 0 of an instruction set, to see what the condition is
      {
        case 'B':
        {
          Serial.println("state is B!"); //this tells us that the board has red state B
          
          if(VS[(inst[instSet][instPos][1]) - 48] == true) //this reads the virtual sensor dictated by position 1
          {
            Serial.println("sensor high"); //this is run if the sensor is high or the VS is true
            met = true; //the condition is met so this goes true
          }
          
          break;
        }
      }
      
    //section 2.2
      if(met)
      {
        switch(inst[instSet][instPos][2]) //reads position 2 in the instruction set
        {
          case 'S': //set the PPD to a set value
          {
            switch(inst[instSet][instPos][3]) //reads position 3 which contains the PPD setting
            {
              case '0':
              {
                PPD = 0; //sets the ppd to 0%
                break;
              }
              
              case '1':
              {
                PPD = 50; //sets the PPD to 50%
                reverser = false; // sets the direction forward
                break;
              }
              
              case '2':
              {
                PPD = 100; //sets the PPD to 100%
                reverser = false; // sets the direction forward
                break;
              }
              
              case '3':
              {
                PPD = 50; //sets the PPD to 50%
                reverser = true; // sets the direction backwards
                break;
              }
              
              case '4':
              {
                PPD = 100; //sets the PPD to 100%
                reverser = true; // sets the direction backwards
                break;
              }
            }
            break;
          }
        }
        
        
        met = false; //this prevents the instruction from being run twice
        //instPos++; //this moves to the next instruction set, it is commented out because there is only one instruction so far
      }

//section 3: output to track
  //apply the PPD to the train
    analogWrite(pinPD, int((PPD / 100) * 255));
    
  //apply the reverser to the train
    if (reverser)
    {
      digitalWrite(pinDIR, HIGH);
    }
    else
    {
      digitalWrite(pinDIR, LOW);
    }
    
  delay(1); //protective delay to be used whenever outputing serial information
}


