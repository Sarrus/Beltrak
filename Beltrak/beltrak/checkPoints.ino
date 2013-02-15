/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

void checkPoints()
{
  for (int i = 1; i < 11; i++)
  {
    if (pointState[i] != pointSwitch[i])
    {
      setPoint(pointSwitch[i], i);
      pointState[i] = pointSwitch[i];
    }
  }
}
