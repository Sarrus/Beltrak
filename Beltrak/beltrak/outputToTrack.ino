/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

void outputToTrack()
{
  
  //set the points


  //apply the PPD to the train
  analogWrite(pinPD, int((PPD / 100) * 255));

  //apply the reverser to the train
  if (reverser)
  {
    digitalWrite(pinDIR, HIGH);
  }
  else
  {
    digitalWrite(pinDIR, LOW);
  }


}
