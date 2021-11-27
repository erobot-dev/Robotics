#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 20, 4);

char Time[]     = "TIME:  :  :  ";
char Calendar[] = "DATE:  /  /20  ";
byte i, second, minute, hour, date, month, year;


#define BTN_Pre 5
#define BTN_Set 6
#define relay1 9
#define relay2 8
#define relay3 7
#define Buzzer 4
#define BTN_Start_Time 3
#define BTN_END_Time 2
int Start_TIME;
int END_Time;


void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  rtc.begin();
  rtc.setDOW(WEDNESDAY);
  pinMode(BTN_Pre, INPUT_PULLUP);
  pinMode(BTN_Set, INPUT_PULLUP);
  pinMode(BTN_Start_Time, INPUT_PULLUP);
  pinMode(BTN_END_Time, INPUT_PULLUP);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  //  rtc.setTime(4, 49, 0);
  //  rtc.setDate(29, 2, 2020);
  //  Start_TIME = EEPROM.read(1);
  //  EEPROM.read(2);
  digitalWrite(Buzzer, 1);
  delay(1000);
  digitalWrite(Buzzer, 0);
  delay(1000);
  Serial.begin(115200);
}

void loop() {
  // lcd.setCursor(0,0);
  // lcd.print("Time:  ");
  // lcd.print(rtc.getTimeStr());
  //
  // lcd.setCursor(0,1);
  // lcd.print("Date: ");
  // lcd.print(rtc.getDateStr());
  //
  // delay(1000);
  //*************************************************

  if (!digitalRead(BTN_Pre)) {
    Serial.println("I'm Edting..");
    i = 0;
    hour   = edit(5, 0, hour);
    minute = edit(8, 0, minute);
    date   = edit(5, 1, date);
    month  = edit(8, 1, month);
    year   = edit(13, 1, year);
    minute = ((minute / 10) << 4) + (minute % 10);
    hour = ((hour / 10) << 4) + (hour % 10);
    date = ((date / 10) << 4) + (date % 10);
    month = ((month / 10) << 4) + (month % 10);
    year = ((year / 10) << 4) + (year % 10);
    Wire.beginTransmission(0x68);
    Wire.write(0);
    Wire.write(0);
    Wire.write(minute);
    Wire.write(hour);
    Wire.write(1);
    Wire.write(date);
    Wire.write(month);
    Wire.write(year);
    Wire.endTransmission();
    delay(200);
  }
  Serial.println("Hello I'm Edting..");
  if (!digitalRead(BTN_Start_Time)) {
    EEPROM.write(1, hour);
    EEPROM.write(3, minute);
    Serial.println( EEPROM.read(1));
    Serial.println( EEPROM.read(3));
  }
  if (!digitalRead(BTN_END_Time)) {
    EEPROM.write(2, hour);
    EEPROM.write(4, minute);
    Serial.println( EEPROM.read(2));
    Serial.println( EEPROM.read(4));
  }
  Wire.beginTransmission(0x68);
  Wire.write(0);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 7);
  second = Wire.read();
  minute = Wire.read();
  hour   = Wire.read();
  Wire.read();
  date   = Wire.read();
  month  = Wire.read();
  year   = Wire.read();
  DS3231_display();
  delay(50);
}
void DS3231_display() {
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour   = (hour >> 4)   * 10 + (hour & 0x0F);
  date   = (date >> 4)   * 10 + (date & 0x0F);
  month  = (month >> 4)  * 10 + (month & 0x0F);
  year   = (year >> 4)   * 10 + (year & 0x0F);
  // End conversion
  Time[12]     = second % 10 + 48;
  Time[11]     = second / 10 + 48;
  Time[9]      = minute % 10 + 48;
  Time[8]      = minute / 10 + 48;
  Time[6]      = hour   % 10 + 48;
  Time[5]      = hour   / 10 + 48;
  Calendar[14] = year   % 10 + 48;
  Calendar[13] = year   / 10 + 48;
  Calendar[9]  = month  % 10 + 48;
  Calendar[8]  = month  / 10 + 48;
  Calendar[6]  = date   % 10 + 48;
  Calendar[5]  = date   / 10 + 48;
  if (hour == EEPROM.read(1) && minute >= EEPROM.read(3) &&  minute < EEPROM.read(4)) {
    digitalWrite(Buzzer, 1);
    digitalWrite(relay1, 1);
    digitalWrite(relay2, 1);
    digitalWrite(relay3, 1);
    Serial.println("Buzzer On");
  }
  if (hour == EEPROM.read(2) && minute  >= EEPROM.read(4)) {
    digitalWrite(Buzzer, 0);
    digitalWrite(relay1, 0);
    digitalWrite(relay2, 0);
    digitalWrite(relay3, 0);
    Serial.println("Buzzer OFF");
  }
  lcd.setCursor(0, 0);
  lcd.print(Time);
  lcd.setCursor(0, 1);
  lcd.print(Calendar);
}
void blink_parameter() {
  byte j = 0;
  while (j < 10 && digitalRead(BTN_Pre) && digitalRead(BTN_Set)) {
    j++;
    delay(25);
  }
}
byte edit(byte x, byte y, byte parameter) {
  char text[3];

  while (!digitalRead(BTN_Pre));
  while (true) {
    while (!digitalRead(BTN_Set)) {
      parameter++;
      if (i == 0 && parameter > 23)
        parameter = 0;
      if (i == 1 && parameter > 59)
        parameter = 0;
      if (i == 2 && parameter > 31)
        parameter = 1;
      if (i == 3 && parameter > 12)
        parameter = 1;
      if (i == 4 && parameter > 99)
        parameter = 0;
      sprintf(text, "%02u", parameter);
      lcd.setCursor(x, y);
      lcd.print(text);
      delay(200);
    }
    lcd.setCursor(x, y);
    lcd.print("  ");
    blink_parameter();
    sprintf(text, "%02u", parameter);
    lcd.setCursor(x, y);
    lcd.print(text);
    blink_parameter();
    if (!digitalRead(BTN_Pre)) {
      i++;
      return parameter;
    }
  }
}
