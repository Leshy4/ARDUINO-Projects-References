// LEDs brighten/dim using Potentiometer && Outputs the value within 0-255.

int LEDpin = 10;    // Hook LED up @ pin 10 (Don't forget the resistor!)
int potPin = A0;    // Potentiometer
int readValue;      // Values from 0-1023
int writeValue = (255./1023.) * readValue;
      // Analog Values = 0-255  // Digital Values = 0-1023
  
void setup() {
  Serial.begin(9600);       // Standard Serial Rate
  pinMode(potPin, INPUT);   // PotPin == Input
  pinMode(LEDpin, OUTPUT);  // LED == Output
  
  Serial.println("This Program reads Analog Values\n");
}

void loop() {  
  readValue = analogRead(potPin);  // Read Values from 0-1023 Potentiometer
  analogWrite(LEDpin, writeValue); // Control LED with Potentiometer
  Serial.print("Analog Value = "); // Uses print && println
  Serial.println(writeValue);      // Prints Values from 0-255
}
