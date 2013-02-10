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
          break;
        }

      case 'C':
        {
          pointSwitch[inst[instSet][instPos][3] - 48] = false; //instructs the board to converge the given points
          Serial.println("converge");
          //delay(1000);
          break;
        }

      case 'D':
        {
          pointSwitch[inst[instSet][instPos][3] - 48] = true; //instructs the board to diverge the given points
          Serial.println("diverge");
          //delay(1000);
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
      //instPos++; //this moves to the next instruction set, it is commented out because there is only one instruction so far
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
