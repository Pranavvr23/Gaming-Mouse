#include <Arduino.h>
#include "Comms/spi.h"
#include "Inputs/config.h"
#include "Inputs/sensor.h"

// put function declarations here:
void setup(){
  Serial.begin(115200);
  Serial.println("hello world");
  if(initializeSPI() == 1) Serial.println("spi is setup and working");
  if(initializeSensor() == 1) Serial.println("holy fast debug");
}

void loop(){
  delay(30);
  if(spiRead(MOTION)){
    if(((spiRead(DELTAX) >> 6) & 1) == 1){
      Serial.println(spiRead(DELTAX));
    }
  }
}