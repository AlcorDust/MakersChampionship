// Room_Sentinel.ino

#include <AltSoftSerial.h>
#include <SoftwareSerial.h>
#include <Servo.h>

// Room 1 sensor
const int rxPinA = 3;
const int txPinA = 255;

// Room 2 sensor
const int rxPinB = 2;
const int txPinB = 255;

// Set up a softserial port
SoftwareSerial inputPortB =  SoftwareSerial(rxPinB, txPinB, true);
SoftwareSerial inputPortA =  SoftwareSerial(rxPinA, txPinA, true);

AltSoftSerial altSerial;
int visitor_number = 1;
Servo servo1;
Servo servo2;

void setup() {

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  servo1.attach(4);
  servo2.attach(5);

  servo1.write(0);
  servo2.write(0);
  
  // set data rate
  inputPortB.begin(1200);
  inputPortA.begin(1200);
  
  Serial.begin(9600);
  Serial.println("\nStarting to listen...\n");
  delay(200);
  
}

void loop(){
  
  inputPortA.listen();
  if (inputPortA.available())
  {
    while(inputPortA.available()){
    inputPortA.read();
    }
    Serial.print("A");
    Serial.println(visitor_number);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    
  }

  inputPortB.listen();
  if (inputPortB.available())
  {
    while(inputPortB.available()){
    inputPortB.read();
    }
    
    Serial.print("B");
    Serial.println(visitor_number);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    
  }
  
}
