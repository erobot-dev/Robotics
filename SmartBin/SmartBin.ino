#include<Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myServo;


const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello EROBOT");
  lcd.setCursor(0, 1);
  lcd.print("This is SmartBin");
  myServo.attach(A1);

  Serial.begin(9600);
}


void loop()
{
//  Servo_Control(0);
    if(Ulstasonic_Sensor()<40){
      Servo_Control(0);
    }else{
      Servo_Control(90);
    }
}
