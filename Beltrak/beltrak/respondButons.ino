void respondButons()
{
 /*in this function the program checks the position of the menu to make sure that when the requested move is made it wont move
 off the edge of the array and that it wont move onto a ~ which is not alowed, it also checks that a buton is not being held
 down by setting button captured to true when a buton is down and setting it to false when a buton is up, it will only respond
 to a press if button captured is false which means that holding down a button does not register multiple presses,
 
 once that has been confirmed it then moves the position in the menu and records the move that was just made for use in the
 hashRespond() function later in the program*/
  switch(readButons())
    {
    case rightOut:
      {
        if(menuPosX < 2 && menu[menuPosX + 1][menuPosY][0] != "~               " && butonCaptured == false) //check conditions
        {
          menuPosX++; //move menu position
          butonCaptured = true; //say that a button is being pressed
          lastMenuMove = rightOut; //record the last move
        }
        break;
      }

    case upOut:
      {
        if(menuPosY > 0 && menu[menuPosX][menuPosY - 1][0] != "~               " && butonCaptured == false)
        {
          menuPosY--;
          butonCaptured = true;
          lastMenuMove = upOut;
        }
        break;
      }

    case downOut:
      {
        if(menuPosY < 4 && menu[menuPosX][menuPosY +1][0] != "~               " && butonCaptured == false)
        {
          menuPosY++;
          butonCaptured = true;
          lastMenuMove = downOut;
        }
        break;
      }

    case leftOut:
      {
        if(menuPosX > 0 && menu[menuPosX - 1][menuPosY][0] != "~               " && butonCaptured == false)
        {
          menuPosX--;
          butonCaptured = true;
          lastMenuMove = leftOut;
        }
        break;
      }

    case selectOut:
      {
        lcd.print("Select          ");
        break;
      }

    case noneOut:
      {
        //lcd.print("Beltrak 1.0     ");
        butonCaptured = false;
        break;
      }
    }
}