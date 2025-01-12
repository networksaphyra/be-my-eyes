class UltrasonicSensor {
private:
  int trigger;
  int echo;
public:
  UltrasonicSensor(int trigger, int echo): trigger(trigger), echo(echo) {}
  int get_trigger() { return trigger; }
  int get_echo() { return echo; }
};

void setup() {
  Serial.begin(9600);
  UltrasonicSensor(3, 4) ultrasonic_sensor;
  Serial.println(ultrasonic_sensor.get_trigger());
}

void loop() {

}
