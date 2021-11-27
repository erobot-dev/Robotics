#include<SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENA 5
#define ENB 3

#define LED1 13
#define LED 1
#define Buzzer 12

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

}
char txt = 'N';
void loop() {
  //  Meterail(Buzzer,2);
    if(mySerial.available()){
      txt=mySerial.read();
      Serial.println(txt);
      dir_motor(txt,250);
    }

}
