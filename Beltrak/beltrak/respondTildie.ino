/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */

/*if the program reaches a tildie this is run, when the program moves onto a ~ it moves back one step except when it moved left
onto a tildie in which case it goes up untill it reaches a menu option*/
 
void respondTildie()
{
  while (menu[menuPosX][menuPosY][0] == "~               ")
  {
    if (lastMenuMove == downOut)
      menuPosY--;
      
    else if (lastMenuMove == upOut)
      menuPosY++;
      
    else if (lastMenuMove == leftOut)
      menuPosY--;
      
    else if (lastMenuMove == rightOut)
      menuPosX--;
    
    else
      {
        menuPosX = 0; //this is here in case none of these conditions are met, it resets the menu position to break the loop
        menuPosY = 0;
      }  
  }
}
