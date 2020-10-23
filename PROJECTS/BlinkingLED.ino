    //  Port -> COM11
int LEDPin = 10;
int delayTimeON = 1000;  // 1000 ms = 1 Second
int delayTimeOFF = 750;  // 1000 ms = 1 Second

void setup() { 
  pinMode(LEDPin, OUTPUT);
}

void loop() { 
  digitalWrite(LEDPin, HIGH);
  delay(delayTimeON);
  digitalWrite(LEDPin, LOW);
  delay(delayTimeOFF);
}
