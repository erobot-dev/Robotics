#include <LED_K1.h>
LED_K1 led(2,3,4,5,6,7,8,9,10,11,12);
void setup() {
  led.setPIN();

}

void loop() {
  led.showLED();

}
