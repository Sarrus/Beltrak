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
   Serial.println("pointSet called");
   int pointPin;
   
   if (point == 1)
     pointPin = point1;
   if (point == 2)
     pointPin = point2;
     
   if (CorD)
   {
     digitalWrite(pointDir, HIGH);
     Serial.println("director high");
     //delay(500);
   }
   
   //analogWrite(pointPower, 255);
   
   digitalWrite(pointPin, HIGH);
   Serial.println("ground point");
   
   delay(50);
   //analogWrite(pointPower, 0);
   digitalWrite(pointPin, LOW);
   Serial.println("unground point");
   if (CorD)
   {
     delay(50);
     digitalWrite(pointDir, LOW);
     Serial.println("director low");
   }
   
 }
