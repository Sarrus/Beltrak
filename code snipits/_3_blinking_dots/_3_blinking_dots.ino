//Michael Bell for Beltrac
//this scetch produces a series of dots in the corner of the screen to show that the device is thinking.


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// choose the locations of the first dot
int firstDotX = 7;
int firstDotY = 0;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(1, 2);
  // Print a message to the LCD.
  lcd.print("Loading");
}

void loop() {
  // set the cursor to the location of the first dot
  lcd.setCursor(firstDotX, firstDotY);
  // clear all dots
  lcd.print("   ");
  // wait
  delay(500);
  // reposition the cursor
  lcd.setCursor(firstDotX, firstDotY);
  // print the first dot
  lcd.print(".");
  //wait
  delay(500);
  // print the second dot
  lcd.print(".");
  //wait
  delay(500);
  // print the third dot
  lcd.print(".");
  //wait
  delay(500);
}
  
  
