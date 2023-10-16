// ---------------------------------------------------------------- // 
// Tiburones - Motorized Arduino Bot 
// Created by - Team 17
// Using Arduino IDE 2.2.1
// Prototype (Test Code)
// ---------------------------------------------------------------- // 

// define motor control pins
int LMotor = 4; 
int RMotor = 9; 

// define echo and trig for ultrasonic sensor
int tPin = 8; 
int ePin = 7; 

// define duration and distance variables
long duration; 
int distance; 

void setup() {
  
  //initialize motors
  pinMode(LMotor, OUTPUT);
  pinMode(RMotor, OUTPUT);
  
  // set sonar digital pin mode
  pinMode (tPin, OUTPUT); 
  pinMode (ePin, INPUT); 
  
  // start debug communication
  Serial.begin (9600); 
  
}

void loop() {
  
  // receive distance measurement + delays
  digitalWrite (UStrig, LOW); 
  delayMicroseconds (2); 
  digitalWrite (UStrig, HIGH); 
  delayMicroseconds (10); 
  digitalWrite (UStrig, LOW);
  delayMicroseconds (2); 
  
  //receives pulse and duration info to convert to distance
  duration = pulseIn (USecho, HIGH);
  distance = duration * 0.034 / 2; 
  
  }

  delay(10);   

}
