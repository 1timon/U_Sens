#include "AFE_HostControl.h"
#include "AFE_RegMap.h" // Include the register map header
#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPI_SPEED 4000000 // SPI speed (4 MHz)

// Function prototypes
void readFromAFE(uint8_t registerAddress, uint8_t* data);
void writeToAFE(uint8_t registerAddress, uint32_t value);
void setSPIRegReadMode(struct AFE_RegMap* AFE, bool enable);

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

// Function to write to AFE register
void writeToAFE(uint8_t registerAddress, uint32_t value) {
    AFE_RegMap AFE;  // Assuming AFE_RegMap is defined and initialized properly
    AFE_assignRegMap(&AFE);  // Initialize the register map

    uint8_t tx_buffer[4];

    // Set the MSB to 0 for write operation
    tx_buffer[0] = registerAddress & 0x7F; // Ensure MSB is 0 for write operation
    tx_buffer[1] = (value >> 16) & 0xFF;   // D23-D16
    tx_buffer[2] = (value >> 8) & 0xFF;    // D15-D8
    tx_buffer[3] = value & 0xFF;           // D7-D0

    // Activate the chip select, and send the address and data
    bcm2835_spi_writenb((char *)tx_buffer, 4);
}

// Function to read from AFE register
void readFromAFE(uint8_t registerAddress, uint8_t* data) {
    AFE_RegMap AFE;  // Assuming AFE_RegMap is defined and initialized properly
    AFE_assignRegMap(&AFE);  // Initialize the register map

    uint8_t tx_buffer[4] = {0};

    // Set the MSB to 1 for read operation
    tx_buffer[0] = registerAddress | 0x80;

    // Activate the chip select, send the address, and receive the data
    bcm2835_spi_transfernb((char *)tx_buffer, (char *)data, 4);
}

// AFE_readReg function
uint32_t AFE_readReg(uint8_t registerAddress) {
    uint32_t afeRegData;

    // Set SPI_REG_READ bit to 1 before reading
    AFE_writeReg(0x00, 0x000001);
    readFromAFE(registerAddress, (uint8_t*)&afeRegData);
    // Set SPI_REG_READ bit to 0 after reading
    AFE_writeReg(0x00, 0x000000);

    return afeRegData;
}

// AFE_writeReg function
void AFE_writeReg(uint8_t registerAddress, uint32_t value) {
    writeToAFE(registerAddress, value);
}
