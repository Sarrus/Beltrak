void outputMenu()
{
  /*this function sets the cursor to the correct position and outputs the required text to the lcd*/
  lcd.setCursor(0,0); //position the cursor
  lcd.print(menu[menuPosX][menuPosY][0]); //output text
  lcd.setCursor(0,1);
  lcd.print(menu[menuPosX][menuPosY][1]);
}
