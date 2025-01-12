class UltrasonicSensor {
private:
  int trigger;
  int echo;
public:
  UltrasonicSensor(int trigger, int echo): trigger(trigger), echo(echo) {}
  int get_trigger() { return trigger; }
  int get_echo() { return echo; }
};

const int TRIG_PIN = 4;
const int ECHO_PIN = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  UltrasonicSensor(TRIG_PIN, ECHO_PIN) ultrasonic_sensor;
  Serial.println(ultrasonic_sensor.get_trigger());
}
