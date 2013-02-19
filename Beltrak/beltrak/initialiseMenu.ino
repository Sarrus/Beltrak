/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

/*this function initialises the menu display array, the first number is the X position, the second number is the 
Y position and the third number is the line number, 0 is line 1 and 1 is line 2

~ are used to fill the bottom of columbs as well as blocking the cursor from moveing between options which are on
different sub menus

# are used to bridge the gap between menu options that should apear to be next to eachoter on the Y axis but actualy
arent*/

void initialiseMenu()
{
  menu[0][0][0] = "Welcome to      ";        menu[1][0][0] = "Destinations    ";  menu[2][0][0] = "Hawkhaven       ";
  menu[0][0][1] = "Beltrak!        ";        menu[1][0][1] = "                ";  menu[2][0][1] = "                ";
  
  menu[0][1][0] = "~               ";        menu[1][1][0] = "#               ";  menu[2][1][0] = "Remilo          ";
  menu[0][1][1] = "                ";        menu[1][1][1] = "                ";  menu[2][1][1] = "                ";
  
  menu[0][2][0] = "~               ";        menu[1][2][0] = "#               ";  menu[2][2][0] = "~               ";
  menu[0][2][1] = "                ";        menu[1][2][1] = "                ";  menu[2][2][1] = "                ";
  
  menu[0][3][0] = "~               ";        menu[1][3][0] = "Settings        ";  menu[2][3][0] = "Backlight       ";
  menu[0][3][1] = "                ";        menu[1][3][1] = "                ";  menu[2][3][1] = "                ";
  
  menu[0][4][0] = "~               ";        menu[1][4][0] = "~               ";  menu[2][4][0] = "Top Speed       ";
  menu[0][4][1] = "                ";        menu[1][4][1] = "                ";  menu[2][4][1] = "                ";
}
