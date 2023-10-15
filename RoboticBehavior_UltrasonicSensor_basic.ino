// define variables
int USecho = 8; // attach pin D8 of arduino to echo of ultrasonic sensor (HC-SR04)
int UStrig = 7; // attach pin D7 of arduino to trig of ultrasonic sensor 

long duration; // duration of sound wave travel
int distance; // distance measurement

void setup() {
  pinMode (UStrig, OUTPUT) ; // sonar digital pin mode for trig
  pinMode (USecho, INPUT); // sonar digital pin mode for echo

  Serial.begin (9600) ; // begin 9600 baud rate for serial communication
}


void loop() {
  digitalWrite (UStrig, LOW); // starts trig pin low
  delayMicroseconds (2); // delay for 2 ms
  digitalWrite (UStrig, HIGH); // makes trig pin high
  delayMicroseconds (10) ; // continue high UStrig for 10 ms
  digitalWrite (UStrig, LOW); // after 10 ms set UStrig to low
  delayMicroseconds (2); // delay for 2 ms
  
  duration = pulseIn (USecho, HIGH); // recieves pulse and duration info from echo
  distance = duration * 0.034 / 2; // converts statistics of duration to distance to the obejct
  }

  delay(10); //delay for 10 ms
  
}
