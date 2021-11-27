void dir_motor(char t,int st){
    if(txt=='L'){
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      analogWrite(ENA,240);
      analogWrite(ENB,240);
//      Meterail(Buzzer,2);
    }
  if(txt=='R'){
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      analogWrite(ENA,240);
      analogWrite(ENB,240);
    }
    if(txt=='B'){
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      analogWrite(ENA,240);
      analogWrite(ENB,240);
    }
    if(txt=='T'){
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      analogWrite(ENA,240);
      analogWrite(ENB,240);
//      Meterail(LED1,2);
    }
    if(txt=='S'){
      digitalWrite(IN1,1);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,1);
      analogWrite(ENA,240);
      analogWrite(ENB,240);
//      Meterail(LED,2);
    }
}
