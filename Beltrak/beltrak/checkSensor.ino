/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */

/*this function takes in the number for a sensor and reads the apropriate sensor set then outputs a boolean
to indicate weather or not the sensor is currently triggered*/


boolean checkSensor(int no) //no is the number of the sensor that we are reading
{
  if (no < 6) //if no is less than 6 then it belongs to the first set of sensors
  {
    int highSensor = readSensors(pinLowSensors); //we find out what the high sensor in this set is
    
    if (highSensor == sensorNone) //if there isnt one we return false
      return false;
      
    else if (highSensor == no) //as this is the first set the number in the set and the overall number are the same
      return true; //if they match we return true
      
    else
      return false;  //in all other cases we return false
    
  }
  
  else if (no < 11) //if no does not belong to the first set and is less than 11 then it belongs to the second set
  {
    int highSensor = readSensors(pinHighSensors); //we find out what the high sensor in this set is
    
    if (highSensor == sensorNone) //if there isnt one we return false
      return false;
      
    else if (highSensor == (no - 5)) //in the second set the sensor number is equal to no - 5
      return true; //if it maches then we return true
      
    else
      return false; //in all other cases we return false
  }
}
