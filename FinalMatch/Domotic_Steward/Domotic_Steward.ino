// Domotic_Steward.ino
#include <Servo.h>

byte pinBoiler = 4;
byte pinRisc = 5;
byte pinLuci = 6;
byte pinCond = 7;

bool statoBoiler;
bool statoRisc;
bool statoCond;
bool statoLuci;
bool statoTapp;

bool statoBoilerPrev = 0;
bool statoRiscPrev = 0;
bool statoCondPrev = 0;
bool statoLuciPrev = 0;
bool statoTappPrev = 0;

bool manda = 0;

String comando = "";
String comandoStato = "";

byte pinPhoto = A0;
byte pinServo = 10;

bool checkLuce = 0;

Servo tapparellaServo;

void setup() {
  Serial.begin(9600);

  tapparellaServo.attach(pinServo);
  tapparellaServo.write(0);

  pinMode(pinBoiler, INPUT);
  pinMode(pinRisc, INPUT);
  pinMode(pinLuci, INPUT);
  pinMode(pinCond, INPUT);

}

void loop() {

  //------------------------------------luci

  int luminosita = analogRead(pinPhoto);

  if (luminosita >= 500) {

    while(analogRead(pinPhoto)>=500){
      ;
    }
    //Alza servo
    Serial.println("alza");
    tapparellaServo.write(90);
    comando = "4";
    comandoStato = "0";
    
    if (checkLuce == 0) {
      manda = 1;
      checkLuce = 1;
    }else{
      manda = 0;
    }

  } else {
    //Abbassa verso
    Serial.println("abbassa");
    tapparellaServo.write(0);
    comando = "5";
    checkLuce = 0;
    comandoStato = "0";
    manda = 1;
  }

  //----------------------------------------

  statoBoiler = digitalRead(pinBoiler);
  if (statoBoiler != statoBoilerPrev) {
    comando = "0";
    Serial.println(statoBoiler);
    if (statoBoiler == 1) {
      comandoStato = "1";
    } else {
      comandoStato = "0";
    }
    manda = 1;
    statoBoilerPrev = statoBoiler;
    Serial.println("boiler");
  }

  statoRisc = digitalRead(pinRisc);
  if (statoRisc != statoRiscPrev) {
    comando = "1";
    if (statoRisc == 1) {
      comandoStato = "1";
    } else {
      comandoStato = "0";
    }
    manda = 1;
    statoRiscPrev = statoRisc;
    Serial.println("risc");
  }

  statoLuci = digitalRead(pinLuci);
  if (statoLuci != statoLuciPrev) {
    comando = "2";

    if (statoLuci == 1) {
      comandoStato = "1";
    } else {
      comandoStato = "0";
    }
    manda = 1;
    statoLuciPrev = statoLuci;
    Serial.println("luci");
  }

  statoCond = digitalRead(pinCond);
  if (statoCond != statoCondPrev) {
    comando = "3";

    if (statoCond == 1) {
      comandoStato = "1";
    } else {
      comandoStato = "0";
    }
    manda = 1;
    statoCondPrev = statoCond;
    Serial.println("cond");
  }

  if (manda == 1) {
    String payload = "";

    payload += "&,";
    payload += comando;
    payload += ",";
    payload += comandoStato;
    payload += ",";

    Serial.println(payload);
    manda = 0;
  }

}
