/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

void outputMenu()
{
  /*this function sets the cursor to the correct position and outputs the required text to the lcd*/
  lcd.setCursor(0,0); //position the cursor
  lcd.print(menu[menuPosX][menuPosY][0]); //output text
  Serial.println(menu[menuPosX][menuPosY][0]); //this prints what the screen is showing (used for testing)
  lcd.setCursor(0,1);
  lcd.print(menu[menuPosX][menuPosY][1]);
  Serial.println(menu[menuPosX][menuPosY][1]);
}
