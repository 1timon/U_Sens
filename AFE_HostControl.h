/** @file AFE_HostControl.h
 *  @brief Function declaration for AFE register access
 *
 *          This contains the declaration for AFE's register read/write functions. 
 *          User needs to update the definition of these functions in "AFE_HostControl.c" file 
 *          with appropriate function calls for I2C/SPI Read/Write functions based on their platform
 *  @version 1.0
 *  @date August 8, 2024
 *
 *  @autor Prabin Yadav (yadav@ti.com)
 */

#ifndef AFE_HOSTCONTROL_H_
#define AFE_HOSTCONTROL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Function declarations for SPI operations
void initSPI();
void closeSPI();
uint32_t AFE_readReg(uint8_t registerAddress);
void AFE_writeReg(uint8_t registerAddress, uint32_t value);



#endif /* AFE_HOSTCONTROL_H_ */
