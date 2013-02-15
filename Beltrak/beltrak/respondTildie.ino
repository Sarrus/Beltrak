/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */
 
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
        menuPosX = 0;
        menuPosY = 0;
      }  
  }
}
