/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */
 
 //C false converge A | D true Diverge B
 
 void setPoint(boolean CorD, int point)
 {
   digitalWrite(point, HIGH);
   
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
   digitalWrite(point, LOW);
 }
