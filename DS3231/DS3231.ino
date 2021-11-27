#include <DS3231.h>
#include <LiquidCrystal.h>
DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
void setup() {
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}

  // Initialize the rtc object
  rtc.begin();

  // The following lines can be uncommented to set the date and time
  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(3, 11, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(20, 01, 2021);   // Set the date to January 1st, 2014
  delay(1000);
}
void loop() {
  // lcd.setCursor(0,0);
  // lcd.print("Time:  ");
  // lcd.print(rtc.getTimeStr());
  //
  // lcd.setCursor(0,1);
  // lcd.print("Date: ");
  // lcd.print(rtc.getDateStr());
  Serial.println(rtc.getTimeStr());
  Serial.println(rtc.getDateStr());

  delay(1000);
}
