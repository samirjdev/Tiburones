// ---------------------------------------------------------------- // 
// Tiburones - Motorized Arduino Bot 
// Created by - Team 17
// Software Lead - Samir Jihadi
// Using Arduino IDE 2.2.1
// Prototype (Test Code)
// ---------------------------------------------------------------- // 

// Defining motor control pins
int LMotor = 4; 
int RMotor = 9; 

// Defining light sensor pin\
int LSensor = A0;

// Potential definition for LED pins
// int ledpin1 =
// int ledpin2 =             

void setup() {
  //initialize motors
  pinMode(LMotor, OUTPUT);
  pinMode(RMotor, OUTPUT);
  //inititalize ultrasonic sensor
  pinMode(tPin, OUTPUT);
  pinMode(ePin, INPUT);
  //starts debug
  Serial.begin (9600);
}

void loop() {
  // Read light sensor value
  int LValue = analogRead(LSensor);

  // Calculate value for motor speed based on the light sensor reading
  // 0 - 1023, min and max values for analog range
  // 0 - 255, min and max values for target range
  int moveSpeed = map(LValue, 0, 1023, 0, 255);

  // Print the light sensor reading on debug
  Serial.print("Light Sensor: ");
  Serial.println(LValue);

  // Set motor speeds
  digitalWrite(LMotor, HIGH);
  digitalWrite(RMotor, HIGH);

  // Adjust motor speeds based on the light sensor reading
  analogWrite(LMotor, 255 - moveSpeed);
  analogWrite(RMotor, 255 - moveSpeed);
}
