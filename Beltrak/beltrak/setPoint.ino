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
   else if (point == 2)
     pointPin = point2;
   else if (point == 3)
     pointPin = point3;
   else if (point == 4)
     pointPin = point4;
   else if (point == 5)
     pointPin = point5;
   

     
   
   
   
   
   if (CorD)
   {
     digitalWrite(pointDir, HIGH);
     //delay(500);
   }
   else
   {
     digitalWrite(pointDir, LOW);
     //delay(500);
   }
   
   //analogWrite(pointPower, 255);
   
   digitalWrite(pointPin, HIGH);
   
   delay(50);
   //analogWrite(pointPower, 0);
   digitalWrite(pointPin, LOW);
   
 }
