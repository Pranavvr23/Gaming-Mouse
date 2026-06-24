#include "spi.h"
#include "Inputs/config.h"

SPISettings mySettings(10000000, MSBFIRST, SPI_MODE3);

uint8_t spiRead(uint8_t reg){
    uint8_t output = 0x00;
    SPI.beginTransaction(mySettings);
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(reg);
    delayMicroseconds(SPI_DELAY_READ);
    output = SPI.transfer(0x00);
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
    digitalWrite(CS_PIN, LOW);
    delayMicroseconds(1);
    digitalWrite(CS_PIN, HIGH);
}

void burst(uint8_t *motion, int16_t *dx, int16_t *dy){
    uint8_t buffer[12];
    SPI.beginTransaction(mySettings);
    digitalWrite(CS_PIN, LOW);
    SPI.transfer(0x16);
    delayMicroseconds(SPI_DELAY_READ);
    for(int i = 0; i < 12; i++){
        buffer[i] = SPI.transfer(0x00);
    }
    digitalWrite(CS_PIN, HIGH);
    SPI.endTransaction();
    delayMicroseconds(SPI_DELAY_READ);
    *motion = buffer[0];
    *dx = (int16_t) ((buffer[2]) | (buffer[3] << 8)); 
    *dy = (int16_t) ((buffer[4]) | (buffer[5] << 8));
}