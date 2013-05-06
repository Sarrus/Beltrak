/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */
 
 /*this function is called when enter is pressed it either sets the instruction set to the apropriate station or
 it runs the function for backlight or top speed*/

void respondEnter(int menuX, int menuY) //the function takes in the current menu position
{
  if(menuX == 2 && menuY < 7 && !inTransit) //only options in the third colum do things so we check if the selected option is there
  //this section is for when a station is selected, the first 7 options are stations so we check weather that is in bounds
  //if the train is already in transit then the enter button should not do anything so we check that as well
  {
    instSet = menuY; //the y position of the cursor also corresponds to the relivent instruction set, this is selected when enter is pressed
    instPos = 0; //we then go to the start of the instructions
    
    menuPosX = 0; //the cursor is reset for when transit is complete
    menuPosY = 0;
    
    inTransit = true; //we set the train in transit which starts the instructions and locks the screen
  }
  else
  {
    if(menuPosX < 2 && butonCaptured == false) //check conditions
        {
          menuPosX++; //move menu position
          butonCaptured = true; //say that a button is being pressed
          lastMenuMove = rightOut; //record the last move
        }
  }
  
  if(menuX == 2 && menuY == 8) //this is the backlight position in the menu
  {
    if(backlight == 2)
      backlight = 1; //1 switches the backlight off
    else
      backlight = 2; //2 switches it on
  }
}
