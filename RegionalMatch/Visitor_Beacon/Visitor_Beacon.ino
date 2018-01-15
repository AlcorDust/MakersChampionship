// Visitor_Beacon.ino

#include <SoftwareSerial.h>

#define visitor_number 1

#define pwmPin 11   

const int rxPin = 3;  
const int txPin = 2; 
const int STX = 2;
const int ETX = 3;
const long IR_CLOCK_RATE = 38000L;

SoftwareSerial displayPort(rxPin, txPin); 

void setup()  {
  
  displayPort.begin(1200);
  
  TCCR2A = _BV(WGM21) | _BV(COM2A0);
  TCCR2B = _BV(CS20);
  
  OCR2A = (F_CPU/(IR_CLOCK_RATE*2L)-1);
  pinMode(pwmPin, OUTPUT);

}

void sendMessagePacket(char message[]){
  
  int index = 0;
  byte checksum = 0;
  
  displayPort.print((char)STX);
  while (message[index] != NULL)
  {
    displayPort.print(message[index]);
    checksum = checksum + (byte)message[index];
    index++;
  }
  displayPort.print((char)ETX);
  displayPort.print((char)checksum);

}

void loop (){
  
  pinMode(pwmPin, OUTPUT);
  delay(1000);
  char msg[] = visitor_number;
  sendMessagePacket(msg);
  pinMode(pwmPin, INPUT); 
  delay(1000);

}
