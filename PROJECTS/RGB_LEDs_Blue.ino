                  // Using RGB LEDs
int redPin = 11;
int greenPin = 10;
int bluePin = 6;
int RbrightnessLED = 0;
int GbrightnessLED = 0;
int BbrightnessLED = 75;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {   //Sets RGB LED to Blue
  analogWrite(redPin, RbrightnessLED);
  analogWrite(greenPin, GbrightnessLED);
  analogWrite(bluePin, BbrightnessLED);
}
