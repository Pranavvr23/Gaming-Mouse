#include "stdint.h"
#include <Arduino.h>
#include <SPI.h>

#define SPI_DELAY_READ 2
#define SPI_DELAY_WRITE 5

SPISettings mySettings(10000000, MSBFIRST, SPI_MODE3);

uint8_t dummy = 0x00;

uint8_t spiRead(uint8_t reg);
void spiWrite(uint8_t reg, uint8_t value);

