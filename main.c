/** @file HRM_Configuration_Example.c
 *  @brief An example configuration for HRM (Heart Rate Monitoring) based on AFE4432EVM
 *
 *         This example shows how to use the driver to configure the AFE based on given hardware (i.e. AFE4432EVM).
 *         User can take this as a reference and modify based on their requirements such as LED-PD associations, clocking mode and PRF.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#include "AFE_Functions_PPG.h"
#include "AFE_HostControl.h"
#include "UV_Configuration.h"
#include <bcm2835.h>
#include <stdio.h>

#define GPCLK0_PIN RPI_V2_GPIO_P1_07  // GPIO 4 (Pin 7 on the Raspberry Pi header)


int main() {
    // Initialize the bcm2835 library
    if (!bcm2835_init()) {
        printf("bcm2835_init failed. Are you running as root?\n");
        return 1;
    }

    // Initialize SPI
    initSPI();

    printf("Starting UV Absorption Spectroscopy\n");
    AFE_config_for_UVSpectroscopy();
    printf("End UV Absorption Spectroscopy\n");

    // Stop the clock output
    stop_clock_output();

    // Close SPI
    closeSPI();

    // Terminate the bcm2835 library
    bcm2835_close();

    return 0;
}
