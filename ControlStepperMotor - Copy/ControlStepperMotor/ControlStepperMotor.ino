
int STEP_PIN = 6;
int DIR_PIN = 5;
int EN_PIN =  9;
int maxPer = 0;
int driec = 3, gl = 3;
int x;
char str = 'N';
void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  //  driec = 0;
  //  Direction(driec, 100, 'F');
  //  Stop();
}

void loop() {
  TestIng() ;
}
void TestIng() {
  digitalWrite(EN_PIN, 0);
  digitalWrite(DIR_PIN, 1);
  for (int i = 0; i < 100; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(DIR_PIN, 0);
  for (int i = 100; i > 0; i--) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
}

void Stop() {
  digitalWrite(EN_PIN, 1);
  digitalWrite(STEP_PIN, 0);
  //  delayMicroseconds(400);
  digitalWrite(STEP_PIN, 0);
  delayMicroseconds(400);
}
int sum = 0;
void Direction(int dri, int Per, char p) {
  if (p == 'F') {
    digitalWrite(EN_PIN, 0);
    digitalWrite(DIR_PIN, 0);
    for (int i = 0; i < (4000 * Per) / 100; i += 1) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(500);
    }
    delay(500);
  } else if (p == 'B') {
    digitalWrite(EN_PIN, 0);
    digitalWrite(DIR_PIN, 1);
    for (int i = 0; i < (4000 * Per) / 100; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(500);
    }
    delay(500);
  }
}
void HomeDirection(int dri, int Per) {
  digitalWrite(EN_PIN, 0);
  digitalWrite(DIR_PIN, dri);
  for (int i = 0; i < (3800 * Per) / 100; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);
  }
  delay(500);
}
