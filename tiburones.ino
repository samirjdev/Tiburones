// ---------------------------------------------------------------- // 
// Tiburones - Motorized Arduino Bot 
// Created by - Team 17
// Using Arduino IDE 2.2.1
// Prototype (Test Code) v2
// ---------------------------------------------------------------- // 

// for LCD display
#include <LiquidCrystal_I2C.h> 

// initalization for display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// define variables for lcd display
char array1[] = "Robot State:    ";
char array2[] = "STOPPED         ";
char array3[] = "BACKWARD        ";
char array4[] = "FORWARD         ";
char array5[] = "OUT OF RANGE    ";

// define echo and trig for ultrasonic sensor
int ePin = 8; 
int tPin = 7; 

// define motor control pins
int rMotor = 4; 
int lMotor = 5; 
// SWITCH AS NECESSARY

// define variables to update LCD tracks
int LCDprev = 99; 
int LCDcurr = 100; 

// define duration and distance variables
long duration;
int distance; 

void setup() {

  // initialize LCD and backlight
  lcd.init(); 
  lcd.backlight(); 

  // set sonar digital pin mode
  pinMode (tPin, OUTPUT); 
  pinMode (ePin, INPUT); 
  
  // initialize motors
  pinMode (rMotor, OUTPUT); // all L298N digital pins are outputs
  pinMode (lMotor, OUTPUT); // all L298N digital pins are outputs

  // start debug communication
  Serial.begin (9600);

  // set initial cursor and print "Robot State:"
  lcd.setCursor(0, 0);
  lcd.print (array1);
  
}


void loop() {
  
/*  
  NOTE: it is important only to update the LCD screen when a change of state has occured
  Otherwise, the program become inefficient. We only want to write to the LCD when 
  there is a change in what the robot is doing. The LCDprey and LCDcurr variables 
   help us to do this
*/
  LCDprev = LCDcurr;

  // receive distance measurement + delays, clears trig condition
  digitalWrite (tPin, LOW);
  delayMicroseconds (2); 
  digitalWrite (tPin, HIGH); 
  delayMicroseconds (10) ; 
  digitalWrite (tPin, LOW);

  //receives pulse and duration info to convert to distance
  duration = pulseIn (ePin, HIGH); 
  distance = duration * 0.034 / 2; 

  // displays the distance
  Serial.print ("Distance: ");
  Serial.print (distance);
  Serial.println(" cm");
  
  if (distance <= 25) {
    LCDcurr = 1;

    digitalWrite(rMotor, LOW);
    digitalWrite(lMotor, HIGH);

    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array3);
      delay(10);
    }
    
  } else if (distance <= 50) {
    LCDcurr = 2;

    // Turn left 90 degrees
    digitalWrite(rMotor, LOW);
    digitalWrite(lMotor, LOW);
    delay(500);  // Adjust the delay based on the time it takes for the robot to turn 90 degrees
    digitalWrite(rMotor, LOW);
    digitalWrite(lMotor, LOW);

    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array2);
      delay(10);
    }
    
  } else if (distance <= 75) {
    LCDcurr = 3;

    digitalWrite(rMotor, HIGH);
    digitalWrite(lMotor, LOW);

    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array4);
      delay(10);
    }
    
  } else {
    LCDcurr = 4;

    digitalWrite(rMotor, LOW);
    digitalWrite(lMotor, LOW);

    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array5);
      delay(10);
    }
    
  }
  delay(10);
  
}
