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

void setup()
{
  
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
    inst[0][0][3] = '1'; //1
    
  //initialise array positions
    instSet = 0;
    instPos = 0;
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


