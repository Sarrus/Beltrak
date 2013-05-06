/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */
 
 void setBacklight()
 {
   if (backlight == 1)
     digitalWrite (backlightPin, 0);
   
   if (backlight == 2)
     digitalWrite (backlightPin, 255);
 }
