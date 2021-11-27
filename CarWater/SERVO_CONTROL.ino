void Servo_Control() {

}
void Servo_Rotate(char text){

   if(text=='2'){
    d--;
   }
   if(text=='4'){
    d++;
   }
   Serial.println(d);
   if(d<0){
    d=0;
   }
   if(d>180){
    d=180;
   }
   myServo[2].write(d);
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
