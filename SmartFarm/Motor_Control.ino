void Motor_Of_Big(char text) {

  if (text == 'S') {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    analogWrite(ENA, 250);
  }
  if (text == 'B') {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    analogWrite(ENA, 0);
  }
}
void Motor_Of_Small(char text) {
  if (text == 'S') {
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    analogWrite(ENB, 250);
  }
  if (text == 'B') {
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 1);
    analogWrite(ENB, 0);
  }
}
