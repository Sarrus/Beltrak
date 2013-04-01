/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

/*this function initialises the complete instruction set for the board, these instructions
are followed by the train when it travels to a given destination.

the first number is the instruction set, this is generaly a set of instructions to get to a
destination but can be something like "clean the track" or "return to siding"

the second number is the position in the instruction set

the third number is the part of the instruction 0 is a condition, 1 is the value of the condition
2 is the instruction to execute if the condition is met and 3 is the value of that instruction


in part 0 W means wait with part 1 being the time, B means when sensor is triggered with part 1 being 
the sensor number.

in part 2 C and D stand for converge and diverge with part 3 being the point number to set to
converge or diverge, S sets the speed with part 3 being the speed setting and X stops the train and 
ends the instruction set, all sets end in X, no value is required


the speed settings are: 0 stops the train, 1 travels at roughly half speed forwards, 2 is full
speed forwards, 3 is roughly half speed backwards and 4 is full speed backwards*/



void initialiseInstructions()
{
  inst[0][0][0] = 'W';  inst[0][0][1] = '1';  inst[0][0][2] = 'X';  
  
  inst[1][0][0] = 'B';  inst[1][0][1] = '2';  inst[1][0][2] = 'S';  inst[1][0][3] = '2';
  inst[1][1][0] = 'B';  inst[1][1][1] = '9';  inst[1][1][2] = 'S';  inst[1][1][3] = '1';
  inst[1][2][0] = 'W';  inst[1][2][1] = '3';  inst[1][2][2] = 'S';  inst[1][2][3] = '2';
  inst[1][3][0] = 'B';  inst[1][3][1] = '1';  inst[1][3][2] = 'S';  inst[1][3][3] = '1';
  inst[1][4][0] = 'B';  inst[1][4][1] = '2';  inst[1][4][2] = 'X';  
  
  inst[2][0][0] = 'W';  inst[2][0][1] = '1';  inst[2][0][2] = 'D';  inst[2][0][3] = '1';
  inst[2][1][0] = 'W';  inst[2][1][1] = '5';  inst[2][1][2] = 'C';  inst[2][1][3] = '1';
  inst[2][2][0] = 'W';  inst[2][2][1] = '9';  inst[2][2][2] = 'D';  inst[2][2][3] = '2';
  inst[2][3][0] = 'W';  inst[2][3][1] = '5';  inst[2][3][2] = 'C';  inst[2][3][3] = '2';
  inst[2][4][0] = 'B';  inst[2][4][1] = '1';  inst[2][4][2] = 'X';  
  
  
}

