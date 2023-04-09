#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
#define Up_Arrow_key 0
#define Down_Arrow_key 1
byte Up_Arrow[8] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
}; //Up-Arrow
byte Down_Arrow[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
}; //Down-Arrow
void lcdSetup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.createChar(Up_Arrow_key , Up_Arrow);
  lcd.createChar(Down_Arrow_key , Down_Arrow);
}

void display(String s1, String s2 , int r)
{
  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print(s1);               // print message at (0, 0)
  lcd.setCursor(0, 1);         // move cursor to   (0, 1)
  lcd.print(s2);               // print message at (0, 1)
  if (r) {
    lcd.print(" ");
    lcd.print(char(r - 1));
  }


}
int getUpArrowkey() {
  return Up_Arrow_key + 1;
}
int getDownArrowkey() {
  return Down_Arrow_key + 1;
}
int getNoArrowkey() {
  return 0;
}
