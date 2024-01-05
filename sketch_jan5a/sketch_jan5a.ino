const int Pin1 = 2;
const int Pin2 = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int result1 = digitalRead(Pin1);
  int result2 = digitalRead(Pin2);
  Serial.print("sensor 1:");
  Serial.println(result1);
  Serial.print("sensor 2: ");
  Serial.println(result2);
  delay(50);
}
