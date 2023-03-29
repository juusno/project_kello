#include <uRTCLib.h>
#include <LiquidCrystal.h>

void TimetoLcd();
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko", "Torstai", "Perjantai", "Lauantai"};
const int rs = 12, epin = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
//backlightpin?
LiquidCrystal lcd(rs, epin, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(3000);
  URTCLIB_WIRE.begin();
  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  //(29.3.23 || klo 16.5.00)
  //rtc.set(0, 5, 16, 4, 29, 3, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)

}

void loop()
{
  rtc.refresh();
  DaytoLcd();
}

  void DaytoLcd()
  {
    lcd.setCursor(0,1);
    lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
    lcd.print(" ");
    lcd.print(rtc.day());
    lcd.print('/');
    lcd.print(rtc.month());
    lcd.print('/');
    lcd.print(rtc.year());

    lcd.setCursor(0,0);
    lcd.print("klo: ");
    lcd.print(rtc.hour());
    lcd.print(':');
    lcd.print(rtc.minute());
    lcd.print(':');
    lcd.print(rtc.second());
    lcd.scrollDisplayLeft();
    delay(500);
  };

