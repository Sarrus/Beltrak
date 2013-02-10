void respondButons()
{
  lcd.setCursor( 0, 0 );
  switch(readButons())
    {
    case rightOut:
      {
        lcd.print("Right           ");
        break;
      }

    case upOut:
      {
        lcd.print("Up              ");
        break;
      }

    case downOut:
      {
        lcd.print("Down            ");
        break;
      }

    case leftOut:
      {
        lcd.print("Left            ");
        break;
      }

    case selectOut:
      {
        lcd.print("Select          ");
        break;
      }

    case noneOut:
      {
        lcd.print("Beltrak 1.0     ");
        break;
      }
    }
}
