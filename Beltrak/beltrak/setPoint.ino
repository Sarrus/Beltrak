/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */

/*this function takes in a point number and a point state, looks up the pin for that point's relay then 
sets the point to the given state.*/
 
 //C false converge A | D true Diverge B
 
 void setPoint(boolean CorD, int point)
 {
   Serial.println("pointSet called"); //used for debuging
   int pointPin;
   
   //These are the two points we use
   if (point == 1)
     pointPin = point1; 
   if (point == 2)
     pointPin = point2;
     
   if (CorD)
   {
     digitalWrite(pointDir, HIGH); //if the points diverge we switch on the direction relay
     Serial.println("director high"); //used for debuging
     //delay(500);
   }
   
   //analogWrite(pointPower, 255);
   
   digitalWrite(pointPin, HIGH); //we ground the points causing them to move
   Serial.println("ground point"); //used for debuging
   
   delay(50); //we give them time to move
   //analogWrite(pointPower, 0);
   digitalWrite(pointPin, LOW); //we unground them so they wont heat up
   Serial.println("unground point"); //used for debuging
   if (CorD)
   {
     delay(50);
     digitalWrite(pointDir, LOW); //if the points diverge we switch off the direction relay
     Serial.println("director low"); //used for debuging
   }
   
 }
