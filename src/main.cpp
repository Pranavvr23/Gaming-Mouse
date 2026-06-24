#include <Arduino.h>
#include "Comms/spi.h"
#include "Inputs/config.h"
#include "Inputs/sensor.h"

int16_t dx = 0;
int16_t dy = 0;
uint8_t motion = 0;
volatile bool motionFlag = false;

void motionISR();
// put function declarations here:
void setup(){
  Serial.begin(115200);
  Serial.println("hello world");
  if(initializeSPI() != 1) Serial.println("suhhhhhh");
  if(initializeSensor() != 1) Serial.println("uhhh");
  pinMode(26, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(26), motionISR, FALLING);
}

void loop(){
  // delay(30);
   if(motionFlag){
    burst( &motion, &dx, &dy);
    if((motion >> 7) == 1){
      Serial.println(dx);
      Serial.println(dy);
      motionFlag = false;
    }
   }
}

void motionISR(void){
  motionFlag = true;
}