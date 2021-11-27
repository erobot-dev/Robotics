void Meterail(int pin, int n){
  for(int i=0;i<n;i++){
    digitalWrite(pin,1);
    delay(100);
    digitalWrite(pin,0);
    delay(100);
  }
}
