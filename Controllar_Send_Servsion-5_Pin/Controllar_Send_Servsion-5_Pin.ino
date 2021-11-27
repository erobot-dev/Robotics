
//============= Send==============
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 9); // CE, CSN
const byte address[6] = "00003";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  pinMode(10, INPUT);  //  Serial.println("OK");
  Led();
}
void Led() {
  for (int i = 0; i < 1; i++) {
    digitalWrite(7, 1);
    delay(5);
    digitalWrite(7, 0);
    delay(5);
  }
}
char text = 'N';
uint8_t n = 0;
void loop() {
  if (digitalRead(6) > 0) {
    text = 'S';
  }
  if (digitalRead(2) > 0) {
    text = 'F';
    Led();
  }
  if (digitalRead(3) > 0) {
    text = 'R';
    Led();
  }
  if (digitalRead(4) > 0) {
    text = 'B';
    Led();
  }
  if (digitalRead(5) > 0) {
    text = 'L';
    Led();
  }
  if (digitalRead(10) > 0) {
      text = 'O';
    Led();
  }
  if (digitalRead(A0) > 0) {
    text = '1';
    Led();
  }
  if (digitalRead(A1) > 0) {
    text = '2';
    Led();
  }
  if (digitalRead(A2) > 0) {
    text = '3';
    Led();
  }
  if (digitalRead(A3) > 0) {
    text = '4';
    Led();
  }
  Serial.println(text);
  radio.write(&text, sizeof(text));
  text = 'N';
}
