// define echo and trig for ultrasonic senso
int USecho = 8; 
int UStrig = 7; 

// define duration and distance variables
long duration; 
int distance; 

void setup() {
  // set sonar digital pin mode
  pinMode (UStrig, OUTPUT) ; 
  pinMode (USecho, INPUT); 
  
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
