#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void lcdSetup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void display(String s,int c ,int r)
{
  lcd.clear();                 // clear display
  lcd.setCursor(c, r);         // move cursor to   (0, 0)
  lcd.print(s);        // print message at (0, 0)
  //  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  //  lcd.print("GetStarted.com"); // print message at (2, 1)
  //  delay(2000);                 // display the above for two seconds


}
