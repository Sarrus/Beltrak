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
  inst[0][0][0] = 'W';  inst[0][0][1] = '1';  inst[0][0][2] = 'S';  inst[0][0][3] = '2';
  inst[0][1][0] = 'B';  inst[0][1][1] = '2';  inst[0][1][2] = 'S';  inst[0][1][3] = '4';
  inst[0][2][0] = 'B';  inst[0][2][1] = '7';  inst[0][2][2] = 'S';  inst[0][2][3] = '0';
  inst[0][3][0] = 'W';  inst[0][3][1] = '2';  inst[0][3][2] = 'X';
  
  inst[1][0][0] = 'W';  inst[1][0][1] = '1';  inst[1][0][2] = 'S';  inst[1][0][3] = '2';
  inst[1][1][0] = 'B';  inst[1][1][1] = '6';  inst[1][1][2] = 'S';  inst[1][1][3] = '0';
  inst[1][2][0] = 'W';  inst[1][2][1] = '1';  inst[1][2][2] = 'X';
  
  inst[2][0][0] = 'W';  inst[2][0][1] = '1';  inst[2][0][2] = 'S';  inst[2][0][3] = '2';
  inst[2][1][0] = 'B';  inst[2][1][1] = '2';  inst[2][1][2] = 'S';  inst[2][1][3] = '4';
  inst[2][2][0] = 'B';  inst[2][2][1] = '7';  inst[2][2][2] = 'D';  inst[2][2][3] = '2';
  inst[2][3][0] = 'B';  inst[2][3][1] = '8';  inst[2][3][2] = 'D';  inst[2][3][3] = '2';
  inst[2][4][0] = 'W';  inst[2][4][1] = '1';  inst[2][4][2] = 'S';  inst[2][4][3] = '3';
  inst[2][5][0] = 'W';  inst[2][5][1] = '1';  inst[2][5][2] = 'S';  inst[2][5][3] = '0';
  inst[2][6][0] = 'W';  inst[2][6][1] = '1';  inst[2][6][2] = 'X'; 

  inst[3][0][0] = 'W';  inst[3][0][1] = '1';  inst[3][0][2] = 'S';  inst[3][0][3] = '2';
  inst[3][1][0] = 'B';  inst[3][1][1] = '2';  inst[3][1][2] = 'S';  inst[3][1][3] = '4';
  inst[3][2][0] = 'B';  inst[3][2][1] = '7';  inst[3][2][2] = 'C';  inst[3][2][3] = '2';
  inst[3][3][0] = 'B';  inst[3][3][1] = '8';  inst[3][3][2] = 'C';  inst[3][3][3] = '1';
  inst[3][4][0] = 'B';  inst[3][4][1] = '9';  inst[3][4][2] = 'S';  inst[3][4][3] = '3';
  inst[3][5][0] = 'W';  inst[3][5][1] = '3';  inst[3][5][2] = 'S';  inst[3][5][3] = '0';
  inst[3][6][0] = 'W';  inst[3][6][1] = '1';  inst[3][6][2] = 'X';  
  
  inst[4][0][0] = 'W';  inst[4][0][1] = '1';  inst[4][0][2] = 'S';  inst[4][0][3] = '2';
  inst[4][1][0] = 'B';  inst[4][1][1] = '2';  inst[4][1][2] = 'S';  inst[4][1][3] = '4';
  inst[4][2][0] = 'B';  inst[4][2][1] = '7';  inst[4][2][2] = 'C';  inst[4][2][3] = '2';
  inst[4][3][0] = 'B';  inst[4][3][1] = '8';  inst[4][3][2] = 'D';  inst[4][3][3] = '1';
  inst[4][4][0] = 'B';  inst[4][4][1] = '9';  inst[4][4][2] = 'S';  inst[4][4][3] = '3';
  inst[4][5][0] = 'W';  inst[4][5][1] = '3';  inst[4][5][2] = 'S';  inst[4][5][3] = '0';
  inst[4][6][0] = 'W';  inst[4][6][1] = '1';  inst[4][6][2] = 'X';   
  
  inst[5][0][0] = 'W';  inst[5][0][1] = '1';  inst[5][0][2] = 'S';  inst[5][0][3] = '2';
  inst[5][1][0] = 'B';  inst[5][1][1] = '2';  inst[5][1][2] = 'S';  inst[5][1][3] = '2';
  inst[5][2][0] = 'W';  inst[5][2][1] = '3';  inst[5][2][2] = 'S';  inst[5][2][3] = '4';
  inst[5][3][0] = 'B';  inst[5][3][1] = '3';  inst[5][3][2] = 'S';  inst[5][3][3] = '3';
  inst[5][4][0] = 'W';  inst[5][4][1] = '2';  inst[5][4][2] = 'S';  inst[5][4][3] = '0';
  inst[5][5][0] = 'W';  inst[5][5][1] = '1';  inst[5][5][2] = 'X';   
 
  inst[6][0][0] = 'W';  inst[6][0][1] = '1';  inst[6][0][2] = 'S';  inst[6][0][3] = '2';
  inst[6][1][0] = 'B';  inst[6][1][1] = '1';  inst[6][1][2] = 'S';  inst[6][1][3] = '3';
  inst[6][2][0] = 'W';  inst[6][2][1] = '1';  inst[6][2][2] = 'S';  inst[6][2][3] = '0';
  inst[6][3][0] = 'W';  inst[6][3][1] = '1';  inst[6][3][2] = 'X';   
     
  inst[7][0][0] = 'W';  inst[7][0][1] = '1';  inst[7][0][2] = 'X';  inst[7][0][3] = '1';
}

