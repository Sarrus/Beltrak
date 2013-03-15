boolean checkSensor(int no)
{
  if (no < 6)
  {
    int highSensor = readSensors(pinLowSensors);
    
    if (highSensor == sensorNone)
      return false;
      
    else if (highSensor == no)
      return true;
      
    else
      return false;  
    
  }
  
  else if (no < 11)
  {
    
  }
}
