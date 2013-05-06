/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */
 
 void setBacklight()
 {
   if (backlight == 1)
     digitalWrite (backlightPin, 0); //this switches the backlight off
   
   if (backlight == 2)
     digitalWrite (backlightPin, 255); //this switches it on
 }
