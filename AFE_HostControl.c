#include "AFE_HostControl.h"
#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPI_SPEED 4000000 // SPI speed (4 MHz)

// Function prototypes
void readFromAFE(uint8_t registerAddress, uint8_t* data);
void writeToAFE(uint8_t registerAddress, uint32_t value);

// Initialization function
void initSPI() {
    if (!bcm2835_init()) {
        fprintf(stderr, "bcm2835_init failed\n");
        exit(1);
    }

    if (!bcm2835_spi_begin()) {
        fprintf(stderr, "bcm2835_spi_begin failed\n");
        exit(1);
    }

    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // 4 MHz
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // Using CS0
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // Active low
}

// Close SPI function
void closeSPI() {
    bcm2835_spi_end();
    bcm2835_close();
}

// Function to read from AFE register
void readFromAFE(uint8_t registerAddress, uint8_t* data) {
    uint8_t tx_buffer[4] = {0};
    
    // Set the MSB to 1 for read operation
    tx_buffer[0] = registerAddress | 0x80;

    // Activate the chip select, send the address, and receive the data
    bcm2835_spi_transfernb((char *)tx_buffer, (char *)data, 4);

    // The data buffer now contains the 24-bit register data received from the AFE
    // data[0] is D23-D16, data[1] is D15-D8, data[2] is D7-D0, and data[3] is garbage or zero
}

// Function to write to AFE register
void writeToAFE(uint8_t registerAddress, uint32_t value) {
    uint8_t tx_buffer[4];

    // Set the MSB to 0 for write operation
    tx_buffer[0] = registerAddress & 0x7F; // Ensure MSB is 0 for write operation
    tx_buffer[1] = (value >> 16) & 0xFF;   // D23-D16
    tx_buffer[2] = (value >> 8) & 0xFF;    // D15-D8
    tx_buffer[3] = value & 0xFF;           // D7-D0

    // Activate the chip select, and send the address and data
    bcm2835_spi_writenb((char *)tx_buffer, 4);
}

// Updated AFE_readReg function
uint32_t AFE_readReg(uint8_t registerAddress) {
    uint8_t buffer[4] = {0};
    uint32_t afeRegData = 0;

    AFE_writeReg(0x00, 0x000001);  // Specific sequence required by AFE
    readFromAFE(registerAddress, buffer);
    AFE_writeReg(0x00, 0x000000);  // Clear the specific register

    // Reconstruct the 24-bit data from the received buffer
    afeRegData = (buffer[0] << 16) | (buffer[1] << 8) | buffer[2];

    return afeRegData;
}

// Updated AFE_writeReg function
void AFE_writeReg(uint8_t registerAddress, uint32_t value) {
    writeToAFE(registerAddress, value);
}
