#include "Adafruit_TinyUSB.h"


#define SCK_PIN 2
#define MISO_PIN 4
#define MOSI_PIN 3
#define CS_PIN 1
#define DELTAX1 0x03 
#define DELTAX2 0x04
#define DELTAY1 0x05
#define DELTAY2 0x06 
#define MOTION 0x02 
#define INITIALIZE_REGISTER 0x3A
#define MOTION_CTRL 0x5C
#define RESOLUTION_X_LOW 0x48
#define RESOLUTION_X_HIGH 0x49
#define SET_RESOLUTION 0x47
#define DEFAULT_DPI 3200