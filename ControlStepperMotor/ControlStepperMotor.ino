#include<SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //RX TX
int STEP_PIN = 9;
int DIR_PIN = 8;
int EN_PIN =  10;
int maxPer = 0;
int driec = 3, gl = 3;
int x;
char str = 'N';
void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  driec = 0;
  Direction(driec, 100, 'F');
  Stop();

}

void loop() {
  //  str = 'N';
  Direction(x, 100, 'F');
//  HomeDirection(1,100);
  delay(1000);
  Stop();
  //  Bluettoth();
  //  Button();
  //  if (digitalRead(10)) {
  //    Position();
  //  }

}

void Stop() {
  digitalWrite(EN_PIN, 1);
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(400);
//  Buzzer();
}
int sum = 0;
void Direction(int dri, int Per, char p) {
//  if (p == 'T') {
//    if (maxPer >= 100) maxPer = 110;
//    if (maxPer == 90) maxPer = 110;
//    if (sum < 0) sum = 0;
//    if (sum == 5) sum = 0;
//    if (maxPer > 100) {
//      sum = maxPer;
//      maxPer = 0;
//    }
//    if (sum > 0) {
//      dri = driec;
//      sum = sum - Per - 5;
//    } else {
//      maxPer = maxPer + Per;
//    }
    Serial.println(sum);
    Serial.println(maxPer);
    digitalWrite(EN_PIN, 0);
    digitalWrite(DIR_PIN, dri);
    for (int i = 0; i < (4000 * Per) / 100; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(500);
    }

    delay(500);

//  } else {
//    digitalWrite(EN_PIN, 0);
//    digitalWrite(DIR_PIN, dri);
//    driec = dri;
//    for (int i = 0; i < (4000 * Per) / 100; i++) {
//      digitalWrite(STEP_PIN, HIGH);
//      delayMicroseconds(500);
//      digitalWrite(STEP_PIN, LOW);
//      delayMicroseconds(500);
//    }
//
//    delay(500);
//
//  }
}
void HomeDirection(int dri,int Per) {
  digitalWrite(EN_PIN, 0);
  digitalWrite(DIR_PIN, dri);
  for (int i = 0; i < (3800*Per)/100; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);
  }
  delay(500);
}
