  // Sensing colors with an RBG Sensor
  int redPin = 11;
  int greenPin = 10;
  int bluePin = 6; 
  int S2 = 7;          // Arduino pin 7 for color sensor pin S2
  int S3 = 8;          // Arduino pin 8 for color sensor pin S3
  int outputPin = 4;   // Color Sensor output on Arduino pin 4

  int rColorIntensity;
  int gColorIntensity;
  int bColorIntensity;
  
  unsigned int pulseWidth;
  int delayTime = 400;
  
void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(outputPin, INPUT);
}

void loop() {
      // Read Red value first
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  pulseWidth = pulseIn(outputPin, LOW);
  rColorIntensity = pulseWidth/400. - 1;  // Convert 0-1023 to 0-255
  rColorIntensity = 255- rColorIntensity;

      // Read Green value
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  pulseWidth = pulseIn(outputPin, LOW);
  gColorIntensity = pulseWidth/400. - 1;  // Convert 0-1023 to 0-255
  gColorIntensity = 255- gColorIntensity;

    // Read Blue value
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  pulseWidth = pulseIn(outputPin, LOW);
  bColorIntensity = pulseWidth/400. - 1;  // Convert 0-1023 to 0-255
  bColorIntensity = 255- bColorIntensity;

    // Adjusting color spectrum to a more differentiated value
  if (rColorIntensity > gColorIntensity && gColorIntensity > bColorIntensity)
  {
    rColorIntensity = 255;
    gColorIntensity = gColorIntensity / 2;
    bColorIntensity = 0;    
  }
  if (rColorIntensity > bColorIntensity && bColorIntensity > gColorIntensity)
  {
    rColorIntensity = 255;
    bColorIntensity = bColorIntensity / 2;
    gColorIntensity = 0;    
  }
  if (gColorIntensity > rColorIntensity && rColorIntensity > bColorIntensity)
  {
    gColorIntensity = 255;
    rColorIntensity = rColorIntensity / 2;
    bColorIntensity = 0;    
  }
  if (gColorIntensity > bColorIntensity && bColorIntensity > gColorIntensity)
  {
    gColorIntensity = 255;
    bColorIntensity = bColorIntensity / 2;
    rColorIntensity = 0;    
  }
  if (bColorIntensity > rColorIntensity && rColorIntensity > gColorIntensity)
  {
    bColorIntensity = 255;
    rColorIntensity = rColorIntensity / 2;
    gColorIntensity = 0;    
  }
  if (bColorIntensity > gColorIntensity && gColorIntensity > rColorIntensity)
  {
    bColorIntensity = 255;
    gColorIntensity = gColorIntensity / 2;
    rColorIntensity = 0;    
  }

  bColorIntensity = bColorIntensity / 2;      // Too much Blue
  gColorIntensity = gColorIntensity * 0.75;   // Too much Green
  Serial.print(rColorIntensity);
  Serial.print(" , ");
  Serial.print(bColorIntensity);
  Serial.print(" , ");
  Serial.print(gColorIntensity);
  Serial.println("");
  analogWrite(redPin, rColorIntensity);
  analogWrite(greenPin, gColorIntensity);
  analogWrite(bluePin, bColorIntensity);
  
  delay(delayTime);
}
