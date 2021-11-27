  void RealTime() {
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(6, 0);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(6,1);
  lcd.print(rtc.getTimeStr());
//  delay (1000);
}
