// Gets User Input  //Blinks LEDS: Red i times, then Yellow i times

int redLEDPin = 10;
int yellowLEDPin = 11;
int LEDredON = 500;
int LEDredOFF = 500;
int LEDyellowON = 200;
int LEDyellowOFF = 500;
int redBlinkAmount = 10;
int yellowBlinkAmount = 10;
String greetingMessage = "Blinks 2 LEDS && Outputting on the screen.\n";

void setup() {
  Serial.begin(9600);   // Output to a Computer screen -> BAUD Rate
  Serial.print(greetingMessage);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
}

void loop() {

  Serial.println("Enter a Number for Red LED blinks");
  while (Serial.available() == 0) {}      //Wait for User Input
  redBlinkAmount = Serial.parseInt();     // Gets User Input

  Serial.println("Enter a Number for Yellow LED blinks");
  while (Serial.available() == 0) {}      //Wait for User Input
  yellowBlinkAmount = Serial.parseInt();  // Gets User Input

  Serial.println("Red LED Blinks: ");

  for (int i = 0; i < redBlinkAmount; i++)  //Blinks red LED i times
  {
    Serial.print(i, ", ");  // Outputs 1, 2, ... , i
    digitalWrite(redLEDPin, HIGH);  // Turns LED On
    delay(LEDredON);        // <- Uses Delay of On time
    digitalWrite(redLEDPin, LOW);   // Turns LED Off
    delay(LEDredOFF);
  }

  Serial.println("Yellow LED Blinks: ");
  for (int i = 0; i < yellowBlinkAmount; i++)  //Blinks yellow LED i times
  {
    Serial.print(i);
    Serial.print(" Yellow LED Blinks, ");  // Write to Computer screen for fun
    if (i % 5 == 0) {
      Serial.println(" Yellow LED Blinks");
    }
    digitalWrite(yellowLEDPin, HIGH);
    delay(LEDyellowON);
    digitalWrite(yellowLEDPin, LOW);
    delay(LEDyellowOFF);
  }

}
