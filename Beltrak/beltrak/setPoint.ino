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
   if (point == 4)
     pointPin = point4;
   if (point == 5)
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
   
   digitalWrite(pointDir, LOW);
   
 }
