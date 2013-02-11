/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

int readButons()
{
  unsigned int buttonVoltage = analogRead(pinButtons);
  if(buttonVoltage < (rightADC + ADCsensitivity))
  {
    return rightOut;
  }

  else if(buttonVoltage >= (upADC - ADCsensitivity) && buttonVoltage <= (upADC + ADCsensitivity))
  {
    return upOut;
  }

  else if(buttonVoltage >= (downADC - ADCsensitivity) && buttonVoltage <= (downADC + ADCsensitivity))
  {
    return downOut;
  }

  else if(buttonVoltage >= (leftADC - ADCsensitivity) && buttonVoltage <= (leftADC + ADCsensitivity))
  {
    return leftOut;
  }

  else if(buttonVoltage >= (selectADC - ADCsensitivity) && buttonVoltage <= (selectADC + ADCsensitivity))
  {
    return selectOut;
  }

  else
  {
    return noneOut;
  }
}

