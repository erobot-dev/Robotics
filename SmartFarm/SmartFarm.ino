// Smart Farm 3/11/2020
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DS3231  rtc(SDA, SCL);

int val, val1;
#define IN1 4
#define IN2 5
#define IN3 7
#define IN4 8
#define ENA 3
#define ENB 6
void setup() {
//  Serial.begin(9600);
  Serial.begin(115200);
   pinMode(13, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  rtc.begin();
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, Erobot!");

  //  rtc.setDOW(WEDNESDAY);
  //  rtc.setTime(4, 49, 0);
  //  rtc.setDate(11, 3, 2020);
}
//int val;
void loop() {

  RealTime();
  val = Sensor_Wate();
  if(val>70){
     Motor_Of_Small('S');
     Serial.println(val);
     digitalWrite(13,1);
     delay(100);
     digitalWrite(13,0);
     delay(100);
  }else{
     Motor_Of_Small('B');
  }
  //    Motor_Of_Big();
   Serial.println(val);
}
