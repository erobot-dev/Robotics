#include<Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myServo[4];
RF24 radio(7, 8); // CE, CSN
int de=0;
const byte address[6] = "00002";
char text='N';
#define LED1 36
#define LED2 38
#define LED3 40
#define LED4 42
#define LED5 44
#define SERVO1 12
#define SERVO2 11
#define SERVO3 10
#define SERVO4 9
#define BUZZER 48

#define IN1 29
#define IN2 27
#define IN3 25
#define IN4 23

#define IN1_2 37
#define IN2_2 35
#define IN3_2 33
#define IN4_2 31

#define IN1_3 45
#define IN2_3 43

#define ENA 4
#define ENB 6

#define ENA_2 3
#define ENB_2 2

#define ENA_3 5



void setup() {
  myServo[0].attach(SERVO1);
  myServo[1].attach(SERVO2);
  myServo[2].attach(SERVO3);
  myServo[3].attach(SERVO4);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  pinMode(ENA_2, OUTPUT);
  pinMode(ENB_2, OUTPUT);

  pinMode(IN1_3, OUTPUT);
  pinMode(IN2_3, OUTPUT);
  pinMode(ENA_3, OUTPUT);


  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.backlight();
  Display("Kosal", "TRTC", 3, 4);
  BUZZER_SHOW(300, 3);
}

void loop() {
  Motor_Control(NRF_Control(), 250);
  if(NRF_Control()=='1'||NRF_Control()=='2'||NRF_Control()=='3'||NRF_Control()=='4'){
    Servo_UpDown(NRF_Control());
    Motor_Water(NRF_Control());
  }
  //LED_SHOW();
  //BUZZER_SHOW(50,4);
}
