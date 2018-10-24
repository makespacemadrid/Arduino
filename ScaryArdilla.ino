// Scary "Pockets" Chipmunk!
// Circuito 
// Pin D3 - Servo
// Pin D2 - Ojo derecho
// Pin D6 - Ojo izquierdo
// Pin A0 - Light Sensor 

#include <Servo.h>

Servo headServo;

int lightSensorPin = A0;
int rightEyeLedPin = 2;
int leftEyeLedPin = 6;
//int headServoPin = 3; 

void setup() {
  headServo.attach(3);
  pinMode(rightEyeLedPin, OUTPUT);
  pinMode(leftEyeLedPin, OUTPUT);
  //pinMode(headServoPin, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightValue = analogRead(lightSensorPin);

  //Medida inicial del sensor de luz
  Serial.println(lightValue);
  delay(50);

  if(lightValue > 350) {
    digitalWrite(rightEyeLedPin, HIGH);
    digitalWrite(leftEyeLedPin, HIGH);
    headServo.write(180);
    delay(5000); 
  } else {
    digitalWrite(rightEyeLedPin, LOW);
    digitalWrite(leftEyeLedPin, LOW);
    headServo.write(0);
    delay(5000);
  }  
}

