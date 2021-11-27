void Servo_Control() {

}
void Servo_Rotate(char text){

   if(text=='2'){
    d--;
   }
   if(text=='4'){
    d++;
   }
//   Serial.println(d);
   if(d<0){
    d=10;
   }
   if(d>180){
    d=170;
   }
   myServo[0].write(d);
}
void Servo_UpDown(char text){
  
   if(text=='1'){
    de--;
   }
   if(text=='3'){
    de++;
   }
//   Serial.println(de);
   if(de<10){
    de=10;
   }
   if(de>180){
    de=180;
   }
   myServo[1].write(de);
   delay(10);
}
void Servo_Shoot(char text){
   if(text=='4'){
   myServo[2].write(180);
   delay(2000);
   myServo[2].write(0);
   delay(2000);
   myServo[2].write(180);
   delay(2000);
   Serial.println("Shooting");
   }
}
