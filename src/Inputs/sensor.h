#include "spi.h"
#include "config.h"


uint16_t getDeltaY(void);
uint16_t getDeltaX(void);
int initializeSPI(void);
int initializeSensor(void);
int motionPinInterrupt(void);
void bootFailure(void);