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
    
  //the position in the instruction array
    int instSet; //the set of instructions to be folowed, eg. go to hawkhaven, this is set by the user through the menus
    int instPos; //the position in the instructions, when a condition is met and a state is changed this incriments, when instSet changesm, this becomes 0
    boolean met; //set to true of a condition is met, the state is then changed.
    
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
    int butonOut; //the place where these numbers are set
    #define noneOut 0
    #define rightOut 1
    #define upOut 2
    #define downOut 3
    #define leftOut 4
    #define selectOut 5
    
  //anti-multipress boolean
    /*to prevent the board from reading a button as pressed multiple times the board sets this to true when it responds to a press
    it will then not respond again untill this is set to false by the board detecting that no button is pressed*/
    boolean buttonCaptured;
    

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
    pinMode(pinButtons, INPUT ); //instruct the board to read from the button pin
    digitalWrite(pinButtons, LOW); //make sure that the board doesent pass voltage to the button pin
    
  //initialise the switching instructions
    inst[0][0][0] = 'W'; //wait
    inst[0][0][1] = '9'; //900
    inst[0][0][2] = 'X'; //end
    inst[0][0][3] = '9'; //
    
  //initialise array positions
    instSet = 0;
    instPos = 0;
    met = false;
    
  //initialise the timer
    timer = 0;  
    
  //initialise virtual sensors
    VS[4] = true;
    
  //initialise points
    for(int i=0; i<10; i++)
    {
      /*these two values are set to differ so that the board is forced to move all the points on the first run, this makes sure
      that the board knows their positions and reveals any malfunctioning points*/
      pointState[i] = true;
      pointSwitch[i] = false;
    }
    
  //initialise transition boolean
    inTransit = true;
    
  //initialises the anti-multipress boolean
   /*this is set to true so that if a button is stuck down when the board turns on it is not registered*/
   buttonCaptured = true;
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
        
        //section 1.1
        
        unsigned int buttonVoltage = analogRead(pinButtons);
          if(buttonVoltage < (rightADC + ADCsensitivity))
          {
            butonOut = rightOut;
          }
          
          else if(buttonVoltage >= (upADC - ADCsensitivity) && buttonVoltage <= (upADC + ADCsensitivity))
          {
            butonOut = upOut;
          }
          
          else if(buttonVoltage >= (downADC - ADCsensitivity) && buttonVoltage <= (downADC + ADCsensitivity))
          {
            butonOut = downOut;
          }
          
          else if(buttonVoltage >= (leftADC - ADCsensitivity) && buttonVoltage <= (leftADC + ADCsensitivity))
          {
            butonOut = leftOut;
          }
          
          else if(buttonVoltage >= (selectADC - ADCsensitivity) && buttonVoltage <= (selectADC + ADCsensitivity))
          {
            butonOut = selectOut;
          }
          
          else
          {
            butonOut = noneOut;
          }
        
        
        //section 1.2
          lcd.setCursor( 0, 0 );
          
          switch(butonOut)
          {
            case rightOut:
            {
              lcd.print("Right           ");
              break;
            }
            
            case upOut:
            {
              lcd.print("Up              ");
              break;
            }
            
            case downOut:
            {
              lcd.print("Down            ");
              break;
            }
            
            case leftOut:
            {
              lcd.print("Left            ");
              break;
            }
            
            case selectOut:
            {
              lcd.print("Select          ");
              break;
            }
            
            case noneOut:
            {
              lcd.print("Beltrak 1.0     ");
              break;
            }
          }
        
      }

//section 2: check position and instructions
  /* section 2 is devided into two parts, part one checks if the given condition is met, part two carries out an instruction and moves
  to the next condition if it is, when a condition is met, the variable 'met' is set to true, section two is only run if met is true
  it sets met to false once it has been run*/
  if(inTransit)
  {
    //section 2.1
        switch(inst[instSet][instPos][0]) //this reads position 0 of an instruction set, to see what the condition is
        {
          case 'B': //met when sensor x goes HIGH
          {
            Serial.println("state is B!"); //this tells us that the board has read state B
            
            if(VS[(inst[instSet][instPos][1]) - 48] == true) //this reads the virtual sensor dictated by position 1
            {
              Serial.println("sensor high"); //this is run if the sensor is high or the VS is true
              met = true; //the condition is met so this goes true
            }
            
            break;
          }
          case 'W': //wait for x miliseconds then meet
          {
            Serial.println("state is W!"); //this tells us that the board has read state W
            if (timer > ((inst[instSet][instPos][1]) - 48) * 100) //checks if the timer has exceded the stated time in multiples of 100
            {
              met = true; //the condition has been met
            }
            else
            {
              timer++; //incriment timer
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
            
            case 'C':
            {
              pointSwitch[inst[instSet][instPos][3] - 48] = false; //instructs the board to converge the given points
              Serial.println("converge");
              //delay(1000);
              break;
            }
            
            case 'D':
            {
              pointSwitch[inst[instSet][instPos][3] - 48] = true; //instructs the board to diverge the given points
              Serial.println("diverge");
              //delay(1000);
              break;
            }
            
            case 'X':
            {
              PPD = 0; //stop the train
              inTransit = false; //stop following instructions
              break;
            }
          }
          
          timer = 0; //resets the timer to be used by a diferent call of W
          met = false; //this prevents the instruction from being run twice
          //instPos++; //this moves to the next instruction set, it is commented out because there is only one instruction so far
//          for(int i = 0; i < 10; i++)
//          {
//            Serial.print(i);
//            Serial.print(":");
//            Serial.println(pointSwitch[i]);
//          }
//          
//          delay(10000);
        }
  }

//section 3: output to track

  //set the points
  
  
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
    
    
  delay(1); //protective delay to prevent over running the serial buffer and used to time iterations
}


