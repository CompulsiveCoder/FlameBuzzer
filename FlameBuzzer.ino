#define buzzerPin 11
#define flameSensorPin A0

const int threshold = 2; // Between 1 and 100. The lower the value the more sensitive it is and the longer the range.

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int reading = analogRead(flameSensorPin);

  int flameLevel = map(reading, 1023, 0, 0, 100);

  Serial.println(flameLevel);

  if (flameLevel > 2)
    beep(1000);

  delay(100);
}
void beep(unsigned char delayms) {
  analogWrite(buzzerPin, 20);
  delay(delayms);
  analogWrite(buzzerPin ,0);
  delay(delayms);
  
}
