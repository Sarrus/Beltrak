/*
  Example code for the Freetronics LCD & Keypad Shield:
  
    http://www.freetronics.com/products/lcd-keypad-shield
  
  by Marc Alexander, 7 September 2011
  This example code is in the public domain.
  
  ---------------------------------------------------------------------
  
  This program demonstrates button detection, LCD text/number printing,
  and LCD backlight control on the Freetronics LCD & Keypad Shield, connected to an Arduino board.
  
  After powerup, the screen looks like this:
  
       ------------------
       |Freetronics 16x2|
       |Btn:          0 | <- This time value counts up the number of seconds since reset (overflows at 99)
       ------------------
 
  When a button is pressed, a label appears for it:
  
       ------------------
       |Freetronics 16x2|
       |Btn:RIGHT     0 |
       ------------------
       Labels are LEFT, UP, DOWN, RIGHT and SELECT-FLASH.
       SELECT-FLASH makes the LCD backlight flash off and on when held down.  
  
  Pins used by LCD & Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
    D4: LCD bit 4
    D5: LCD bit 5
    D6: LCD bit 6
    D7: LCD bit 7
    D8: LCD RS
    D9: LCD E
    D3: LCD Backlight (high = on, also has pullup high so default is on)
  
  ADC voltages for the 5 buttons on analog input pin A0:
  
    RIGHT:  0.00V :   0 @ 8bit ;   0 @ 10 bit
    UP:     0.71V :  36 @ 8bit ; 145 @ 10 bit
    DOWN:   1.61V :  82 @ 8bit ; 329 @ 10 bit
    LEFT:   2.47V : 126 @ 8bit ; 505 @ 10 bit
    SELECT: 3.62V : 185 @ 8bit ; 741 @ 10 bit
*/
/*--------------------------------------------------------------------------------------
  Includes
--------------------------------------------------------------------------------------*/
#include <LiquidCrystal.h>   // include LCD library
/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/
// Pins in use
#define BUTTON_ADC_PIN           A0  // A0 is the button ADC input
#define LCD_BACKLIGHT_PIN         3  // D3 controls LCD backlight
// ADC readings expected for the 5 buttons on the ADC input
#define RIGHT_10BIT_ADC           0  // right
#define UP_10BIT_ADC            145  // up
#define DOWN_10BIT_ADC          329  // down
#define LEFT_10BIT_ADC          505  // left
#define SELECT_10BIT_ADC        741  // right
#define BUTTONHYSTERESIS         10  // hysteresis for valid button sensing window
//return values for ReadButtons()
#define BUTTON_NONE               0  // 
#define BUTTON_RIGHT              1  // 
#define BUTTON_UP                 2  // 
#define BUTTON_DOWN               3  // 
#define BUTTON_LEFT               4  // 
#define BUTTON_SELECT             5  // 
//some example macros with friendly labels for LCD backlight/pin control, tested and can be swapped into the example code as you like
#define LCD_BACKLIGHT_OFF()     digitalWrite( LCD_BACKLIGHT_PIN, LOW )
#define LCD_BACKLIGHT_ON()      digitalWrite( LCD_BACKLIGHT_PIN, HIGH )
#define LCD_BACKLIGHT(state)    { if( state ){digitalWrite( LCD_BACKLIGHT_PIN, HIGH );}else{digitalWrite( LCD_BACKLIGHT_PIN, LOW );} }
/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
byte buttonJustPressed  = false;         //this will be true after a ReadButtons() call if triggered
byte buttonJustReleased = false;         //this will be true after a ReadButtons() call if triggered
byte buttonWas          = BUTTON_NONE;   //used by ReadButtons() for detection of button events
int state;                               // 1: dissarmed 2:standing by 3: armed 4: counting down 5: detonated
boolean stateHeld;                       // used to indicate that a state change button has been pressed and not yet releaced
int delayTime;
/*--------------------------------------------------------------------------------------
  Init the LCD library with the LCD pins to be used
--------------------------------------------------------------------------------------*/
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );   //Pins for the freetronics 16x2 LCD shield. LCD: ( RS, E, LCD-D4, LCD-D5, LCD-D6, LCD-D7 )
/*--------------------------------------------------------------------------------------
  setup()
  Called by the Arduino framework once, before the main loop begins
--------------------------------------------------------------------------------------*/
void setup()
{
   //button adc input
   pinMode( BUTTON_ADC_PIN, INPUT );         //ensure A0 is an input
   digitalWrite( BUTTON_ADC_PIN, LOW );      //ensure pullup is off on A0
   //lcd backlight control
   digitalWrite( LCD_BACKLIGHT_PIN, HIGH );  //backlight control pin D3 is high (on)
   pinMode( LCD_BACKLIGHT_PIN, OUTPUT );     //D3 is an output
   //set up the LCD number of columns and rows: 
   lcd.begin( 16, 2 );
   //Print some initial text to the LCD.
   lcd.setCursor( 0, 0 );   //top left
   //          1234567890123456
   lcd.print( "SEMTEX detonator" );
   //
   lcd.setCursor( 0, 1 );   //bottom left
   //          1234567890123456
   //lcd.print( "Disarmed" );
   state = 1;
   stateHeld = false;
   delayTime = 900;
}
/*--------------------------------------------------------------------------------------
  loop()
  Arduino main loop
--------------------------------------------------------------------------------------*/
void loop()
{
   byte button;
   
   // the position in counting down
   int countdown;
   byte timestamp;
   
   switch(state)
   {
     case 1:
     {
       lcd.setCursor( 0, 1 );   //bottom left
       lcd.print( "Disarmed        " );
       break;
     }
     case 2:
     {
       lcd.setCursor( 0, 1 );   //bottom left
       lcd.print( "Standing By     " );
       break;
     }
     case 3:
     {
       lcd.setCursor( 0, 1 );   //bottom left
       lcd.print( "      ARMED     " );
               //SELECT is a special case, it pulses the LCD backlight off and on for demo
        digitalWrite( LCD_BACKLIGHT_PIN, LOW );
        delay( 150 );
        digitalWrite( LCD_BACKLIGHT_PIN, HIGH );   //leave the backlight on at exit
        delay( 150 );
        
        /* an example of LCD backlight control via macros with nice labels
        LCD_BACKLIGHT_OFF();
        delay( 150 );
        LCD_BACKLIGHT_ON();   //leave the backlight on at exit
        delay( 150 );
        */
        
        /*
        // an example of LCD backlight control via a macro with nice label, called with a value
        LCD_BACKLIGHT(false);
        delay( 150 );
        LCD_BACKLIGHT(true);   //leave the backlight on at exit
        delay( 150 );
        */
        break;
     }
     case 4:
     {
       for(int i = 10; i>0; i--)
       {
         lcd.setCursor( 0, 1 );   //bottom left
         lcd.print("       ");
         lcd.print(i);
         lcd.print("       ");
         delay(delayTime);
       }
       
       digitalWrite( LCD_BACKLIGHT_PIN, LOW );
       lcd.setCursor( 0, 1 );   //bottom left
       lcd.print("                ");
       delay(6000);
       
       digitalWrite( LCD_BACKLIGHT_PIN, HIGH );
       state = 1;
       
       break;
     }
       
   }
   
   //get the latest button pressed, also the buttonJustPressed, buttonJustReleased flags
   button = ReadButtons();
   //show text label for the button pressed
   
   
   switch( button )
   {
      case BUTTON_NONE:
      {
         stateHeld = false;
      }
      case BUTTON_RIGHT:
      {
         break;
      }
      case BUTTON_UP:
      {
         break;
      }
      case BUTTON_DOWN:
      {
         break;
      }
      case BUTTON_LEFT:
      {
        break;
     }
     case BUTTON_SELECT:
     {
        if (!stateHeld && state < 4)
       {
        state = state + 1;
        stateHeld = true; 
       }
        

        
        break;
      }
      default:
     {
        break;
     }
   }
  
/*  
   //debug/test display of the adc reading for the button input voltage pin.
   lcd.setCursor(12, 0);
   lcd.print( "    " );          //quick hack to blank over default left-justification from lcd.print()
   lcd.setCursor(12, 0);         //note the value will be flickering/faint on the LCD
   lcd.print( analogRead( BUTTON_ADC_PIN ) );
*/
   //clear the buttonJustPressed or buttonJustReleased flags, they've already done their job now.
   if( buttonJustPressed )
      buttonJustPressed = false;
   if( buttonJustReleased )
      buttonJustReleased = false;
}
/*--------------------------------------------------------------------------------------
  ReadButtons()
  Detect the button pressed and return the value
  Uses global values buttonWas, buttonJustPressed, buttonJustReleased.
--------------------------------------------------------------------------------------*/
byte ReadButtons()
{
   unsigned int buttonVoltage;
   byte button = BUTTON_NONE;   // return no button pressed if the below checks don't write to btn
   
   //read the button ADC pin voltage
   buttonVoltage = analogRead( BUTTON_ADC_PIN );
   //sense if the voltage falls within valid voltage windows
   if( buttonVoltage < ( RIGHT_10BIT_ADC + BUTTONHYSTERESIS ) )
   {
      button = BUTTON_RIGHT;
   }
   else if(   buttonVoltage >= ( UP_10BIT_ADC - BUTTONHYSTERESIS )
           && buttonVoltage <= ( UP_10BIT_ADC + BUTTONHYSTERESIS ) )
   {
      button = BUTTON_UP;
   }
   else if(   buttonVoltage >= ( DOWN_10BIT_ADC - BUTTONHYSTERESIS )
           && buttonVoltage <= ( DOWN_10BIT_ADC + BUTTONHYSTERESIS ) )
   {
      button = BUTTON_DOWN;
   }
   else if(   buttonVoltage >= ( LEFT_10BIT_ADC - BUTTONHYSTERESIS )
           && buttonVoltage <= ( LEFT_10BIT_ADC + BUTTONHYSTERESIS ) )
   {
      button = BUTTON_LEFT;
   }
   else if(   buttonVoltage >= ( SELECT_10BIT_ADC - BUTTONHYSTERESIS )
           && buttonVoltage <= ( SELECT_10BIT_ADC + BUTTONHYSTERESIS ) )
   {
      button = BUTTON_SELECT;
   }
   //handle button flags for just pressed and just released events
   if( ( buttonWas == BUTTON_NONE ) && ( button != BUTTON_NONE ) )
   {
      //the button was just pressed, set buttonJustPressed, this can optionally be used to trigger a once-off action for a button press event
      //it's the duty of the receiver to clear these flags if it wants to detect a new button change event
      buttonJustPressed  = true;
      buttonJustReleased = false;
   }
   if( ( buttonWas != BUTTON_NONE ) && ( button == BUTTON_NONE ) )
   {
      buttonJustPressed  = false;
      buttonJustReleased = true;
   }
   
   //save the latest button value, for change event detection next time round
   buttonWas = button;
   
   return( button );
}
