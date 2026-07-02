#include <Arduino.h>
#include "Comms/spi.h"
#include "Comms/usb.h"
#include "Inputs/config.h"
#include "Inputs/sensor.h"

#include <class/hid/hid.h>

int16_t dx = 0;
int16_t dy = 0;
uint8_t motion = 0;
uint8_t const desc_hid_report[] = { TUD_HID_REPORT_DESC_MOUSE() };
Adafruit_USBD_HID mouse;
volatile bool motionFlag = false;
bool type = false;
int debug = 0;
int totalX = 0;
int totalY = 0;
int usb_hid_poll_interval = 1;
uint8_t bitmap = 0x00;

void motionISR();
// put function declarations here:
void setup(){
  Serial.begin(115200);
  Serial.println("hello world");
  if(initializeMouse(mouse, desc_hid_report, sizeof(desc_hid_report)) != 1) bitmap |= (1 << 2);
  if(initializeSPI() != 1) bitmap |= (1 << 0);
  if(initializeSensor() != 1); bitmap |= (1 << 1);
  //attachInterrupt(digitalPinToInterrupt(26), motionISR, LOW);
}

void loop(){
  // delay(30);
  //  if(motionFlag){
      burst(&motion, &dx, &dy);
     if((motion >> 7) == 1) mouse.mouseMove(0x00 , (int8_t)dx, (int8_t)dy);
      // if((motion >> 7) == 1){
      // // motionFlag = false;
      // // noInterrupts();
      // // interrupts();
      // totalX += dx;
      // totalY += dy;
      // debug ++;
      // //Serial.println(debug);
      // if((debug % 100) == 0){
      //   Serial.print("Total dx");
      //   Serial.println(totalX);
      // }
      // }
  //  }
}

void motionISR(void){
  motionFlag = true;
}