#include "Inputs/sensor.h"
#include "Inputs/config.h"
//The purpose of the sensor module is to understand the movement made by the mouse

// motion pin goes low to signal new data ready
// registers hold change in x and change in y


// SPI communication works with 4 standard wires
// Mosi, Miso, Sclk, cs

// Key registers:
// 1. Motion - confirms the data is ready
//  Idles High
// 
// 2. Delta_x - X movement
// 3. Delta_y - y movement
// 4. Cpi regiesters - set sensitivity

// int setMouseCPI(int cpi){
//     // set the register with the mouse cpi to int cpi
// }

// int getMouseCPI(void){
//     //get teh register value for cpi
// }

// int setReportRate(void){
//     // set the report rate of the sensor (?)
// }

// int getChangeX(void){
//     //return the value in deltax register
// }

// int getChangeY(void){
//     //return the value in deltay register
// }

int initializeSPI(void){
    //initialize the spi communication protocol to fit 
    if(SPI.setSCK(SCK_PIN) != 1) return 0;
    if(SPI.setRX(MISO_PIN) != 1) return 0;
    if(SPI.setTX(MOSI_PIN) != 1) return 0;
    pinMode(CS_PIN, OUTPUT);
    digitalWrite(CS_PIN, HIGH);
    SPI.begin();
    return 1;
}

// int initializeSensor(void){
//     //initialize the sensor powerup sequence
// }

int motionPinInterrupt(void){
    //if(MOTION_PIN == true) return 1;
    return 0;
}



