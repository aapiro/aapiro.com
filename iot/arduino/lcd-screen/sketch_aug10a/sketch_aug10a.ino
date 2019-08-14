// Giuseppe Caccavale
// www.giuseppecaccavale.it

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()
{
  lcd.begin(16, 2);
  lcd.backlight();
}


void loop()
{
  lcd.setCursor(2, 0);
  lcd.print("Te Amo <3");
  lcd.setCursor(6, 1);
  lcd.print("Esposa <3");
}
