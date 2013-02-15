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

//track control variables
boolean pointState[10]; //this says the curent state of the points with FALSE for converge and TRUE for diverge
boolean pointSwitch[10]; //this holds the desired state of the points with FALSE for converge and TRUE for diverge

//pin number constants
#define pinPD 3 //the pin number for the Potential Diference output
#define pinDIR 12 //the pin number of the direction pin
#define pinButtons A0 //the button input pin

//the instruction array
char inst[5][5][5]; //array containing the switching instructions

//the menu array
String menu[3][5][2];

//position in the menu
int menuPosX;
int menuPosY;

//the position in the instruction array
int instSet; //the set of instructions to be folowed, eg. go to hawkhaven, this is set by the user through the menus
int instPos; //the position in the instructions, when a condition is met and a state is changed this incriments, when instSet changesm, this becomes 0


//timing variable
/*when condition W is in force this is incrimented every iteration of loop untill it meets the given value at which point it
 is reset and met is set to true*/
int timer;

//virtual sensors
/*these are variables that are used to test the program before sensors are intoduced true means HIGH false means LOW, !remember
 to change these in the code when introducing sensors!*/
boolean VS[5];

//tranition boolean
/*when this is false the train is stationary and the menu is displayed, when it is true, the program executes the given
 instructions and the UI is locked*/
boolean inTransit;

//button voltages
/*these are the ADC readings taken on A0 and the button presses they represent*/
#define rightADC 0
#define upADC 145
#define downADC 329
#define leftADC 505
#define selectADC 741

//button voltage sensitivity  
#define ADCsensitivity 10

//button output numbers
/*to make the output from the buttons easear to understand these are used in place of the numbers representing the button output*/
#define noneOut 0
#define rightOut 1
#define upOut 2
#define downOut 3
#define leftOut 4
#define selectOut 5

//anti-multipress boolean
/*to prevent the board from reading a button as pressed multiple times the board sets this to true when it responds to a press
 it will then not respond again untill this is set to false by the board detecting that no button is pressed*/
boolean butonCaptured;

//last menu move
  int lastMenuMove;


void setup()
{
  initialise();
  initialiseMenu();
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
    if(inTransit)
    {
      lcd.setCursor( 0, 0 );
      lcd.print( "In Transit" );
    }
    else
    {
      /*if the train is not in transit then we execute three consecutive steps, in step one the program reads A0 to see if any butons
       are pressed, and sets the value of buttonOut to match. in step two this value is used to query the menu structure array
       and that is then displayed on the screen, finaly in step 3 we check to see if the enter button has been pressed, if it has we
       execute the instructions apropriate to the currently selected menu option*/
       respondButons();
       respondHashes();
       outputMenu();
    }

  //section 2: check position and instructions
    /* section 2 is devided into two parts, part one checks if the given condition is met, part two carries out an instruction and moves
     to the next condition if it is, when a condition is met, the variable 'met' is set to true, section two is only run if met is true
     it sets met to false once it has been run*/
    if(inTransit)
    {
      respondConditions();
    }
  //section 3: output to track
    outputToTrack();
    
    
    
  delay(1); //protective delay to prevent over running the serial buffer and used to time iterations
}

