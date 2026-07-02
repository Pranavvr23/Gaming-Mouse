#include "spi.h"
#include "config.h"

void configDPI(uint16_t dpi);
void setCPI(uint8_t xLow, uint8_t xHigh);
uint16_t getDeltaY(void);
uint16_t getDeltaX(void);
int initializeSPI(void);
int initializeSensor(void);
int motionPinInterrupt(void);
void bootFailure(void);