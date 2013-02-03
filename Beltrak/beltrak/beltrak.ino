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

void setup()
{
  
  //initialise global variables
    PPD = 0; //full stop
    reverser = false; //the train will travel forward
    
  //initialise pins
    pinMode(pinPD, OUTPUT);
    pinMode(pinDIR, OUTPUT);
}

void loop()
{
  
/* the "loop" is devided into 3 logical sections,

section 1: the menu position is ascertained and text is output to the screen, variables are ajusted to provide the other sections with user input

section 2: the instruction array is queried and the sensors are checked, variables are ajusted to set the curent instructions for the train

section 3: variables from section 2 are checked and the points are ajusted if necesary, then the speed of the train is set

these three are repeated endlessly untill power off */

//section 1: read user input and output display

//section 2: check position and instructions

//section 3: output to track
  //apply the PPD to the train
    analogWrite(pinPD, int((PPD / 100) * 255));
    
  //delay(1); //protective delay to be used whenever outputing serial information
}


