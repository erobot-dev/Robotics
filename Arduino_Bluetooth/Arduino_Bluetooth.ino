#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <IRremote.h>
#define Tx 10
#define Rx 11
#define relay1 9
#define relay2 8
#define relay3 7
SoftwareSerial bluetoothSarial(Tx, Rx);
int RECV_PIN = 12;
int state1, state2, state3;
IRrecv irrecv(RECV_PIN);
decode_results results;
// other variable
boolean state_all_led = false;
boolean state_two_led = false;
int led_array_pin[] = {relay1, relay2, relay3};
int led_index = 0;
void setup() {
  Serial.begin(9600);
  bluetoothSarial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  state1 = EEPROM.read(1);
  state2 = EEPROM.read(2);
  state3 = EEPROM.read(3);
  digitalWrite(relay1, state1);
  digitalWrite(relay2, state2);
  digitalWrite(relay3, state3);
}
void loop() {
  //  BT_CTRL();
  IR_CTRL();
}
void BT_CTRL() {
  if (bluetoothSarial.available())  {
    Serial.println("Enabling Blutooth");
    char val = bluetoothSarial.read(); //1byte
    Serial.println(val);

    if ( val == 'A' ) {
      digitalWrite(relay1, HIGH);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
    }
    if ( val == 'B' ) {
      digitalWrite(relay1, LOW);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
    }
    if ( val == 'C' ) {
      digitalWrite(relay2, HIGH);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
    }
    if (val == 'D' ) {
      digitalWrite(relay2, LOW);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
    }
    if ( val == 'E' ) {
      digitalWrite (relay3, HIGH);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'F' ) {
      digitalWrite (relay3, LOW);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'G' ) {
      digitalWrite (relay1, HIGH);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay2, HIGH);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
    }
    if ( val == 'H' ) {
      digitalWrite (relay1, LOW);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay2, LOW);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
    }
    if ( val == 'I' ) {
      digitalWrite (relay1, HIGH);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay3, HIGH);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'J' ) {
      digitalWrite (relay1, LOW);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay3, LOW);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'K' ) {
      digitalWrite (relay2, HIGH);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
      digitalWrite (relay3, HIGH);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'L' ) {
      digitalWrite (relay2, LOW);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
      digitalWrite (relay3, LOW);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'M' ) {
      digitalWrite (relay1, HIGH);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay2, HIGH);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
      digitalWrite (relay3, HIGH);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    if ( val == 'N' ) {
      digitalWrite (relay1, LOW);
      state1 = digitalRead(relay1);
      EEPROM.write(1, state1);
      digitalWrite (relay2, LOW);
      state2 = digitalRead(relay2);
      EEPROM.write(2, state2);
      digitalWrite (relay3, LOW);
      state3 = digitalRead(relay3);
      EEPROM.write(3, state3);
    }
    delay(50);
  }
}
void IR_CTRL() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {
      case 0xFF30CF://button namber 1
        digitalWrite(relay1, !digitalRead(relay1));
        state1 = digitalRead(relay1);
        EEPROM.write(1, state1);
        delay(100);
        break;
      case 0xFF18E7://button namber 2
        digitalWrite(relay2, !digitalRead(relay2));
        state2 = digitalRead(relay2);
        EEPROM.write(2, state2);
        delay(100);
        break;
      case 0xFF7A85://button namber 3
        digitalWrite(relay3, !digitalRead(relay3));
        state3 = digitalRead(relay3);
        EEPROM.write(3, state3);
        delay(100);
        break;
      case 0xFF10EF://button namber 4
        state_two_led = !state_two_led;
        if (state_two_led) {
          digitalWrite(relay1, HIGH);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay2, HIGH);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          led_index = 1;
        }
        else {
          digitalWrite(relay1, LOW);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay2, LOW);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          led_index = 0;
        }
        delay(100);
        break;
      case 0xFF38C7://button namber 5
        state_two_led = !state_two_led;
        if (state_two_led) {
          digitalWrite(relay1, HIGH);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay3, HIGH);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 2;
        }
        else {
          digitalWrite(relay1, LOW);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay3, LOW);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 0;
        }
        delay(100);
        break;
      case 0xFF5AA5://button namber 6
        state_two_led = !state_two_led;
        if (state_two_led) {
          digitalWrite(relay2, HIGH);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          digitalWrite(relay3, HIGH);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 2;
        }
        else {
          digitalWrite(relay2, LOW);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          digitalWrite(relay3, LOW);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 1;
        }
        delay(100);
        break;
      case 0xFFC23D://stop
        state_all_led = !state_all_led;
        if (state_all_led) {
          digitalWrite(relay1, HIGH);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay2, HIGH);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          digitalWrite(relay3, HIGH);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 2;
        }
        else {
          digitalWrite(relay1, LOW);
          state1 = digitalRead(relay1);
          EEPROM.write(1, state1);
          digitalWrite(relay2, LOW);
          state2 = digitalRead(relay2);
          EEPROM.write(2, state2);
          digitalWrite(relay3, LOW);
          state3 = digitalRead(relay3);
          EEPROM.write(3, state3);
          led_index = 0;
        }
        delay(100);
        break;
      case 0xFF02FD://VOL+
        digitalWrite(led_array_pin[led_index], HIGH);
        state1 = digitalRead(led_array_pin[led_index]);
        EEPROM.write(led_index + 1, state1);
        led_index++;
        if (led_index > 2)led_index = 2;
        delay(100);
        break;
      case 0xFF22DD://VOL-
        digitalWrite(led_array_pin[led_index], LOW);
        state2 = digitalRead(led_array_pin[led_index]);
        EEPROM.write(led_index + 1, state2);
        led_index--;
        if (led_index < 0)led_index = 0;
        delay(100);
        break;
      case 0xFFE21D://button Next
        for (int i = 0; i < 3; i++) {
          digitalWrite(led_array_pin[i], LOW);
          EEPROM.write(1, 0);
          EEPROM.write(2, 0);
          EEPROM.write(3, 0);
        }
        digitalWrite(led_array_pin[led_index], HIGH);
        state3 = digitalRead(led_array_pin[led_index]);

        EEPROM.write(led_index + 1, state3);

        led_index++;
        if (led_index > 2)led_index = 0;
        delay(100);
        Serial.print(EEPROM.read(1));
        Serial.print(EEPROM.read(2));
        Serial.println(EEPROM.read(3));
        break;
    }
    irrecv.resume(); // Receive the next value

  }
  delay(100);
}
