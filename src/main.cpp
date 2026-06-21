#include <Arduino.h>
#include "spi.h"
#include "Inputs/config.h"

// put function declarations here:
void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("hello world");
}

void loop(){
  delay(2000);
  Serial.println("hello world");
}