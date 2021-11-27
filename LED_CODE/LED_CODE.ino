class LED{
  private:
    int leds1;
    int leds2;
    int leds3;
    int leds4;
    int leds5;
    int leds6;
    int leds7;
    int leds8;
    int leds9;
    int leds10;
    int leds11;
  public:
    LED(int led_1,int led_2,int led_3,int led_4,int led_5,int led_6,int led_7,int led_8,int led_9,int led_10,int led_11){
      leds1=led_1;
      leds2=led_2;
      leds3=led_3;
      leds4=led_4;
      leds5=led_5;
      leds6=led_6;
      leds7=led_7;
      leds8=led_8;
      leds9=led_9;
      leds10=led_10;
      leds11=led_11;
    }
    void setPIN(){
      pinMode(leds1,OUTPUT);
      pinMode(leds2,OUTPUT);
      pinMode(leds3,OUTPUT);
      pinMode(leds4,OUTPUT);
      pinMode(leds5,OUTPUT);
      pinMode(leds6,OUTPUT);
      pinMode(leds7,OUTPUT);
      pinMode(leds8,OUTPUT);
      pinMode(leds9,OUTPUT);
      pinMode(leds10,OUTPUT);
      pinMode(leds11,OUTPUT);
    }
    void showLED(){
    
        digitalWrite(leds1,HIGH);
        delay(100);
        digitalWrite(leds1,LOW);
        delay(100);
        digitalWrite(leds2,HIGH);
        delay(100);
        digitalWrite(leds2,LOW);
        delay(100);
        digitalWrite(leds3,HIGH);
        delay(100);
        digitalWrite(leds3,LOW);
        delay(100);
        digitalWrite(leds4,HIGH);
        delay(100);
        digitalWrite(leds4,LOW);
        delay(100);
        digitalWrite(leds5,HIGH);
        delay(100);
        digitalWrite(leds5,LOW);
        delay(100);
        digitalWrite(leds6,HIGH);
        delay(100);
        digitalWrite(leds6,LOW);
        delay(100);
        digitalWrite(leds7,HIGH);
        delay(100);
        digitalWrite(leds7,LOW);
        delay(100);
        digitalWrite(leds8,HIGH);
        delay(100);
        digitalWrite(leds8,LOW);
        delay(100);
        digitalWrite(leds9,HIGH);
        delay(100);
        digitalWrite(leds9,LOW);
        delay(100);
        digitalWrite(leds10,HIGH);
        delay(100);
        digitalWrite(leds10,LOW);
        delay(100);
        digitalWrite(leds11,HIGH);
        delay(100);
        digitalWrite(leds11,LOW);
        delay(100);
    }
};


LED led(2,3,4,5,6,7,8,9,10,11,12);
void setup() {
  led.setPIN();

}

void loop() {
  led.showLED();

}
