// Uses the: HC-SR04 ultrasonic sensor        // <- Uses SONAR by Pinging 
// Speed of Sound = Distance * 2 / PingTime   // <- Roughly / Realistic includes Temperature & other variables

int echoPin = 11;     //Sonar Sensor: LISTEN
int triggerPin = 13;  //Sonar Sensor: FIRE
int SOUND_PRINT_SPEED = 2000;

float pingTime;    //Time for Audio PING to hit and bounce back
float speedOfSound;
float targetDistance = 6;   //6" - Measure with a ruler

    // Units for Time & Distance
float INCHES_per_MILE = 63360;           
float MICROSECOND_per_SECOND = 1000000;  // 1M
float SECONDS_per_HOUR = 3600;           // (60sec*60min=HOUR)

  //Trigger times
int readyingFire = 2500; // 2.5 ms
int pulseTime = 10;    // 0.010 ms 

void printSpeedOfSoundToScreen(){  
  Serial.print("The Speed of Sound is: ");
  Serial.print(speedOfSound);
  Serial.print(" MPH");
  Serial.println("");
  delay(SOUND_PRINT_SPEED);  // Wait 2,000 ms = 2 seconds  // Delay in Miliseconds  
}
  
void setup() {  
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);  //Event
  pinMode(echoPin, INPUT);      //Event Listener
}


void loop() {  
  digitalWrite(triggerPin, LOW);  // Mili || Micro(μ)   //Getting Ready to Fire
  delayMicroseconds(readyingFire);      // 2.5 ms || 2,500 μs
  
  digitalWrite(triggerPin, HIGH); //FIRE Pulse~~~~~~~~~~~~
  delayMicroseconds(pulseTime); // 0.010 ms      
  digitalWrite(triggerPin, LOW);  //Finish Pulse(Ping)~~~~X

               // LISTEN for the PULSE (Sonic Sine Wave)
  pingTime = pulseIn(echoPin, HIGH);  // Measured in Microseconds (Ping travel time)

              // Inches per Microsecond~~~   // (Sonic Wave Round Trip) == (Distance * 2)
  speedOfSound = (targetDistance * 2) / pingTime;

// Inches/μs to MPH~~~( Inch/μs * (1 sec = 1M * μs )   * (60sec*60min=HOUR) ) / (Inches per Mile)*            
  speedOfSound = (speedOfSound * MICROSECOND_per_SECOND * SECONDS_per_HOUR) / INCHES_per_MILE;

 printSpeedOfSoundToScreen(); 
}
