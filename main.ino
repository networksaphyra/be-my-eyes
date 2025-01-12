class UltrasonicSensor {
private:
    int trigger;
    int echo;
public:
    UltrasonicSensor(int trigger, int echo): trigger(trigger), echo(echo) {}
    int get_trigger() { return trigger; }
    int get_echo() { return echo; }

    float measure_distance() {
        digitalWrite(trigger, LOW);
        delayMicroseconds(2);
        digitalWrite(trigger, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger, LOW);

        float duration = pulseIn(echo, HIGH);
        float distance = duration * 0.034/2;
        return distance;
    }
};

const int TRIG_PIN = 4;
const int ECHO_PIN = 3;
const int BUZZER_SIG = 9;
const int BUTTON_READ = A0;

const float MIN_DISTANCE = 1.0;
const float MAX_DISTANCE = 200.0;
const int MAX_BUZZER = 255;

void communicate_phone() {
    Serial.println("TRIGGER_CAMERA");
    delay(800);
}

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_SIG, OUTPUT);
    pinMode(BUTTON_READ, INPUT);
}

void loop() {
    UltrasonicSensor ultrasonic_sensor(TRIG_PIN, ECHO_PIN);

    int button_read = analogRead(BUTTON_READ);
    if (button_read > 500) {
        communicate_phone();
    }

    float distance = ultrasonic_sensor.measure_distance();

    Serial.print("Distance: ");
    Serial.println(distance);

    int buzzer_intensity = 0;
    if (distance > 0 && distance < MAX_DISTANCE) {
        if (distance < MIN_DISTANCE) {
            buzzer_intensity = MAX_BUZZER;
        } else {
            // Inverse relationship between distance and intensity
            buzzer_intensity = map(
                (int)(distance * 10),
                MIN_DISTANCE * 10,
                MAX_DISTANCE * 10,
                MAX_BUZZER,
                0
            );
        }
    }

    analogWrite(BUZZER_SIG, buzzer_intensity);

    delay(50);
}
