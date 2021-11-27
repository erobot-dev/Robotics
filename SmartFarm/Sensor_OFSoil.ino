int Sensor_Of_Soil() {
  val = analogRead(A1);
  val = map(val, 1023, 200, 0, 100);
  return val;
}
