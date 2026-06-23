#include "spi.h"
#include "Inputs/config.h"

uint8_t spiRead(uint8_t reg){
    uint8_t output = 0x00;
    SPI.beginTransaction(mySettings);
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(reg);
    delayMicroseconds(SPI_DELAY_READ);
    output = SPI.transfer(dummy);
    digitalWrite(CS_PIN, HIGH);
    SPI.endTransaction();
    delayMicroseconds(SPI_DELAY_READ);
    return output;
}

void spiWrite(uint8_t reg, uint8_t value){
    uint8_t temp = 0x00;
    SPI.beginTransaction(mySettings);
    digitalWrite(CS_PIN, LOW);
    temp = reg | 0x80;
    SPI.transfer(temp);
    SPI.transfer(value);
    digitalWrite(CS_PIN, HIGH);
    SPI.endTransaction();
    delayMicroseconds(SPI_DELAY_WRITE);
}

void toggleCS(void){
    digitalWrite(CS_PIN, HIGH);
    delayMicroseconds(1);
    digitalWrite(CS_PIN, LOW);
}