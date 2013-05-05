/*

 BELTRAK
 
 V1.0
 
 Hornby trainset automation
 
 By Michael Bell
 
 Programing started: 02/02/2013 at 14:08
 
 */

void respondConditions()
{
  if(checkConditions())
    {
      switch(inst[instSet][instPos][2]) //reads position 2 in the instruction set
      {
      case 'S': //set the PPD to a set value
        {
          switch(inst[instSet][instPos][3]) //reads position 3 which contains the PPD setting
          {
          case '0':
            {
              PPD = 0; //sets the ppd to 0%
              break;
            }

          case '1':
            {
              PPD = 75; //sets the PPD to 50%
              reverser = false; // sets the direction forward
              break;
            }

          case '2':
            {
              PPD = 100; //sets the PPD to 100%
              reverser = false; // sets the direction forward
              break;
            }

          case '3':
            {
              PPD = 75; //sets the PPD to 50%
              reverser = true; // sets the direction backwards
              break;
            }

          case '4':
            {
              PPD = 100; //sets the PPD to 100%
              reverser = true; // sets the direction backwards
              break;
            }
          }
          instPos++;
          break;
        }

      case 'C':
        {
          setPoint(false, (inst[instSet][instPos][3] - 48)); //instructs the board to converge the given points
          Serial.println("converge");
          //delay(1000);
          instPos++;
          break;
          
        }

      case 'D':
        {
          setPoint(true, (inst[instSet][instPos][3] - 48)); //instructs the board to diverge the given points
          Serial.println("diverge");
          //delay(1000);
          instPos++;
          break;
        }

      case 'X':
        {
          PPD = 0; //stop the train
          inTransit = false; //stop following instructions
          break;
        }
      }
      timer = 0; //resets the timer to be used by a diferent call of W
       //this moves to the next instruction set
      //          for(int i = 0; i < 10; i++)
      //          {
      //            Serial.print(i);
      //            Serial.print(":");
      //            Serial.println(pointSwitch[i]);
      //          }
      //          
      //           delay(10000);
          }
  
}
