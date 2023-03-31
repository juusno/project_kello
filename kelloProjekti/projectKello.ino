#include <uRTCLib.h>
#include <LiquidCrystal.h>

void TimetoLcd();
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int Contrast = 70;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  analogWrite(7, Contrast); // Connect the LCD screen's contrast to digital pin 7
  lcd.begin(16, 2);
  URTCLIB_WIRE.begin();
  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  //(30.3.23 || klo 11.59.00)
  //rtc.set(0, 59, 11, 5, 30, 3, 23);
  //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
  // set day of week (1=Sunday, 7=Saturday)
}

void loop() {
  rtc.refresh();
  DaytoLcd();
}

void DaytoLcd()
  {
    lcd.setCursor(0,1);
    lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
    lcd.print(" ");
    if (rtc.day() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.day());
    lcd.print('/');
    if (rtc.month() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.month());
    lcd.print('/');
    if (rtc.year() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.year());

    lcd.setCursor(0,0);
    if (rtc.hour() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.hour());
    lcd.print(':');
    if (rtc.minute() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.minute());
    lcd.print(':');
    if (rtc.second() < 10) {
      lcd.print(0);
    }
    lcd.print(rtc.second());  
  };
  
