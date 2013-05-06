  /*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 Programing completed: 06/05/2013 at 17:45
 
 */

/*this function returns an intager value coresponding the the current button (or lack therof) being
pressed, it only works when either 1 or 0 butons are being pressed, the intager values output are
#defined at the begining of the program as rightOut upOut etc.

the sensor board outputs a diferent voltage depending on which buton is pressed, these voltages are
#defined at the begining of the program and are called upADC, downADC etc.

the sensitivity (or hysteresis) is how far out the voltage can be on either side of the defined value,
this allows for the tolerence of the resistors used producing the voltages

the voltage used is stored in buttonVoltage*/

int readSensors(int sensorNumber)
{
  unsigned int buttonVoltage = analogRead(sensorNumber); //this reads the voltage and stores it
  //Serial.println(buttonVoltage);
  if(buttonVoltage < (rightADC + ADCsensitivity)) //the rightADC is 0 so we check that it is beneath 0 +the sensitivity
  {
    return rightOut; //this returns the button pressed
  }

  else if(buttonVoltage >= (upADC - ADCsensitivity) && buttonVoltage <= (upADC + ADCsensitivity)) //this checks the voltage is in range
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
    return noneOut; //if the voltage matches none of these then we return that no button is being pressed
  }
  
  
}

