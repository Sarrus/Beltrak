/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */
 
 /*if the program moves onto a hash it moves forward untill it reaches a menu option except when it moves left onto the hash
 in which case it goes up untill it reaches an option*/
 
void respondHashes()
{
  while (menu[menuPosX][menuPosY][0] == "#               ")
  {
    if (lastMenuMove == downOut)
      menuPosY++;
      
    else if (lastMenuMove == upOut)
      menuPosY--;
      
    else if (lastMenuMove == leftOut)
      menuPosY--;
    
    else
      {
        menuPosX = 0; //this is here in case none of these conditions are met, it resets the menu position to break the loop
        menuPosY = 0;
      }  
  }
}
