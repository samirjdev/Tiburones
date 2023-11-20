// ---------------------------------------------------------------- // 
// Tiburones - Motorized Arduino Bot 
// Created by - Team 17
// Using Arduino IDE 2.2.1
// Prototype (Test Code)
// ---------------------------------------------------------------- // 

// for LCD display
#include <LiquidCrystal_I2C.h>

//initializes LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
  digitalWrite (tPin, LOW); 
  delayMicroseconds (2); 
  digitalWrite (tPin, HIGH); 
  delayMicroseconds (10); 
  digitalWrite (tPin, LOW);
  delayMicroseconds (2); 
  
  //receives pulse and duration info to convert to distance
  duration = pulseIn (ePin, HIGH);
  distance = duration * 0.034 / 2; 

  // displays the distance
  Serial.print ("Distance: ");
  Serial.print (distance);
  Serial.println(" cm");
  
  if (distance <= 30) {
    LCDcurr = 1;

digitalWrite(LMotor, LOW);
digitalWrite(RMotor, HIGH);
digitalWrite(ledpin, HIGH);

if (LCDprev != LCDcurr) {
  lcd.setCursor(0, 1);
  lcd.print(array3);
  delay(10);
}

} else if (distance <= 50) {
  LCDcurr = 2;

  digitalWrite(LMotor, LOW);
  digitalWrite(RMotor, LOW);
  digitalWrite(ledpin, LOW);

  if (LCDprev != LCDcurr) {
    lcd.setCursor(0, 1);
    lcd.print(array2);
    delay(10);
  }

} else if (distance <= 60) {
  LCDcurr = 3;

  digitalWrite(LMotor, HIGH);
  digitalWrite(RMotor, LOW);
  digitalWrite(ledpin, HIGH);

  if (LCDprev != LCDcurr) {
    lcd.setCursor(0, 1);
    lcd.print(array4);
    delay(10);
  }

} else {
  LCDcurr = 4;

  digitalWrite(LMotor, LOW);
  digitalWrite(RMotor, HIGH);
  delay(1000);
  digitalWrite(ledpin, LOW);

  if (LCDprev != LCDcurr) {
    lcd.setCursor(0, 1);
    lcd.print(array5);
    delay(10);
  }

}
delay(10);
