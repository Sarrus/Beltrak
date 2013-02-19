/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

/*this function takes in a point number and a point state, looks up the pin for that point's relay then 
sets the point to the given state.*/
 
 //C false converge A | D true Diverge B
 
 void setPoint(boolean CorD, int point)
 {
   int pointPin;
   
   if (point == 1)
     pointPin = point1;
   if (point == 2)
     pointPin = point2;
   if (point == 3)
     pointPin = point3;
  
     
   
   
   digitalWrite(pointPin, HIGH);
   
   if (CorD)
   {
     digitalWrite(pointDir, HIGH);
   }
   else
   {
     digitalWrite(pointDir, LOW);
   }
   
   analogWrite(pointPower, 255);
   delay(200);
   analogWrite(pointPower, 0);
   digitalWrite(pointPin, LOW);
 }
