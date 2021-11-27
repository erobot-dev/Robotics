void BUZZER_SHOW(int delays, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER, 1);
    delay(delays);
    digitalWrite(BUZZER, 0);
    delay(delays);
  }
}
void LED_SHOW() {
  for (int i = 36; i < 45; i += 2) {
    digitalWrite(i, 1);
    delay(500);
    digitalWrite(i, 0);
    delay(500);
  }
}
