#include<Servo.h>
Servo myServo, myServo2, myServo3;
#define LED1 36
#define LED2 38
#define LED3 40
#define LED4 42
#define LED5 44
#define BUZZER 48

void setup() {
  myServo.attach(12);
  myServo2.attach(11);
  myServo3.attach(10);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, 1);
  delay(100);
  digitalWrite(BUZZER, 0);
  delay(100); digitalWrite(BUZZER, 1);
  delay(100);
  digitalWrite(BUZZER, 0);
  delay(100); digitalWrite(BUZZER, 1);
  delay(100);
  digitalWrite(BUZZER, 0);
  delay(100);

}

void loop() {
  myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);
  myServo2.write(180);
  delay(1000);
  myServo2.write(0);
  delay(1000);
  myServo3.write(180);
  delay(1000);
  myServo3.write(0);
  delay(1000);
  digitalWrite(LED1, 1);
  delay(100);
  digitalWrite(LED1, 0);
  delay(100);
  digitalWrite(LED2, 1);
  delay(100);
  digitalWrite(LED2, 0);
  delay(100);
  digitalWrite(LED3, 1);
  delay(100);
  digitalWrite(LED3, 0);
  delay(100);
  digitalWrite(LED4, 1);
  delay(100);
  digitalWrite(LED4, 0);
  delay(100);
  digitalWrite(LED5, 1);
  delay(100);
  digitalWrite(LED5, 0);
  delay(100);
  digitalWrite(BUZZER, 1);
  delay(100);
  digitalWrite(BUZZER, 0);
  delay(100);

}
