#include<SoftwareSerial.h>

SoftwareSerial mySerial(11,12);//TX,RX
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 7
#define ENA 5
#define ENB 6

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
}
char text;
int sp;
void loop() {
  if(mySerial.available()){
    text=mySerial.read();
    Serial.println(text);
    if(text=='1') sp=50;
    if(text=='3') sp=150;
    if(text=='4') sp=200;
    if(text=='8') sp=250;
    if(text=='q') sp=255;
    if(text=='F'){
      Forword(sp);
    }
    if(text=='B'){
      Backword(sp);
    }
    if(text=='L'){
      Left(sp);
    }
    if(text=='R'){
      Right(sp);
    }
    if(text=='S'){
      STOP();
    }
    
  }
}
void Forword(int Speeds){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,Speeds);
  analogWrite(ENB,Speeds);
}
void Backword(int Speeds){
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  analogWrite(ENA,Speeds);
  analogWrite(ENB,Speeds);
}
void Left(int Speeds){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  analogWrite(ENA,Speeds);
  analogWrite(ENB,Speeds);
}
void Right(int Speeds){
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,Speeds);
  analogWrite(ENB,Speeds);
}
void STOP(){
  digitalWrite(IN1,1);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,1);
  analogWrite(ENA,250);
  analogWrite(ENB,250);
}
