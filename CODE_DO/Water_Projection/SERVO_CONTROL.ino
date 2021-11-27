void Servo_Control() {
  myServo[3].write(50);
  delay(1000);
  myServo[3].write(80);
  delay(1000);
}
void Servo_UpDown(char text) {
  if (text == '1') {
    de += 5;

  }
  if (text == '3') {
    de -= 5;

  }
  //   Serial.println(de);
  if (de < 10) {
    de = 10;
  }
  if (de > 180) {
    de = 180;
  }
  myServo[1].write(de);
  delay(100);
}
