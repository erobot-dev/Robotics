#include <RC_Car.h>

RC_Car car(9,8,7,6,10,11);
void setup() {
 car.setPIN();
}

void loop() {
  car.setDirection('L',250,200);
}
