/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

boolean checkConditions()
{
  switch(inst[instSet][instPos][0]) //this reads position 0 of an instruction set, to see what the condition is
    {
    case 'B': //met when sensor x goes HIGH
      {
        Serial.println((inst[instSet][instPos][1]) - 48); //this tells us that the board has read state B

        if(checkSensor((inst[instSet][instPos][1]) - 48) == true) //this reads the virtual sensor dictated by position 1
        {
          Serial.println("sensor high"); //this is run if the sensor is high or the VS is true
          return true; //the condition is met so this goes true
        }
        
        else
        {
          return false;
        }

        
      }
    case 'W': //wait for x miliseconds then meet
      {
        Serial.println("state is W!"); //this tells us that the board has read state W
        if (timer > ((inst[instSet][instPos][1]) - 48) * 100) //checks if the timer has exceded the stated time in multiples of 100
        {
          return true; //the condition has been met
        }
        else
        {
          timer++; //incriment timer
          return false;
        }
       
      }
    }
}
