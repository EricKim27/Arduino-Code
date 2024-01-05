const int sensorPin1 = 3;
const int sensorPin2 = 2;
const float height = 0.3;
double gravitationalAcceleration;
unsigned long startTime;
unsigned long endTime;
unsigned long elapsedTime;
bool sense = false;

void setup() {
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);  
  Serial.begin(9600);
  Serial.println("Waiting for sensor 1");
}

void loop() {
  // 여기서 sensorPin1이 LOW가 된다는 건 포토 인터럽터가 물체에 의해 가로막혀 LOW로 입력이 된다는 것을 뜻함.
  int read1 = digitalRead(sensorPin1);
  int read2 = digitalRead(sensorPin2);
  if (read1 == 0 && !sense) {
    startTime = millis();
    sense = true;
    Serial.println("Sensor 1 has been detected");
  }
  if (read2 == 0 && sense) {
    endTime = millis();
    sense = false;
    
    // ms를 초로 변경
    elapsedTime = endTime - startTime;
    float elapsedTimeInSeconds = static_cast<float>(elapsedTime) / 1000.0;

    Serial.print("Sensor 2 detected. Total time: ");
    Serial.print(elapsedTimeInSeconds);
    Serial.println(" seconds");

    gravitationalAcceleration = 2 * height / (elapsedTimeInSeconds * elapsedTimeInSeconds);
    Serial.print("Gravitational Acceleration: ");
    Serial.print(gravitationalAcceleration);
    Serial.println(" m/s^2");
  }
}
