#include <Arduino.h>
#include <StatusLED.h>
#include <ServoMotor.h>
#include <Cycle.h>

unsigned long loop_delay = 20; //ms
boolean timeout(unsigned long previousTime, unsigned long delay);

StatusLED statusLED;
ServoMotor servoMotor;
Cycle cycle;

void setup() {
  Serial.begin(9600);
  statusLED.init();
  servoMotor.init();
  cycle.init();
  
  cycle.addObserver(&statusLED,0);
  cycle.addObserver(&servoMotor,1);
}

void loop() {

 static unsigned long previousEvalTime = 0;

   if (timeout(previousEvalTime, loop_delay)) { 
     cycle.analyze_clock();

     
   }
}

boolean timeout(unsigned long previousTime, unsigned long delay){
  if (millis() - previousTime >= delay) {
    return true;
  } else
    return false;
}