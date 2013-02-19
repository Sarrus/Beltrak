/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

/*this function checks the status of the points and compares them to what they should be, if its diferent it
changes the points to match*/


void checkPoints()
{
  for (int i = 1; i < 11; i++)  //goes through all the points
  {
    if (pointState[i] != pointSwitch[i]) //if the state doesent match what it should be
    {
      setPoint(pointSwitch[i], i); //move the points
      pointState[i] = pointSwitch[i]; //change the state
    }
  }
}
