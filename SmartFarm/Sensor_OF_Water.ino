int Sensor_Wate() {
  val1 = analogRead(A1);
  val1 = map(val1, 1023, 0, 0, 100);
  return val1;
}
