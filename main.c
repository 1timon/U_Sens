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

// Function to set up the clock output on GPIO 4
void setup_clock_output(uint32_t freq) {
    // Set GPIO 4 to alternate function 0 (GPCLK0)
    bcm2835_gpio_fsel(GPCLK0_PIN, BCM2835_GPIO_FSEL_ALT0);

    // Disable clock (set clock source to off)
    bcm2835_gpio_write(GPCLK0_PIN, LOW);

    // Set up the clock control register (CM_GP0CTL)
    volatile uint32_t *cm_gp0ctl = bcm2835_peri_ptr(BCM2835_CM_GP0CTL);
    volatile uint32_t *cm_gp0div = bcm2835_peri_ptr(BCM2835_CM_GP0DIV);

    // Stop the clock and disable the oscillator
    bcm2835_peri_write(cm_gp0ctl, 0x5A000000);

    // Set the clock divider (frequency = 19.2 MHz / (divisor + 1))
    uint32_t divisor = (19200000 / freq);
    bcm2835_peri_write(cm_gp0div, 0x5A000000 | (divisor << 12));

    // Set the clock source to oscillator and enable
    bcm2835_peri_write(cm_gp0ctl, 0x5A000016); // 16 for oscillator, enable clock
}

// Function to stop the clock output on GPIO 4
void stop_clock_output() {
    // Set up the clock control register (CM_GP0CTL)
    volatile uint32_t *cm_gp0ctl = bcm2835_peri_ptr(BCM2835_CM_GP0CTL);

    // Stop the clock
    bcm2835_peri_write(cm_gp0ctl, 0x5A000000);

    // Set GPIO 4 back to input mode
    bcm2835_gpio_fsel(GPCLK0_PIN, BCM2835_GPIO_FSEL_INPT);
}

int main() {
    // Initialize the bcm2835 library
    if (!bcm2835_init()) {
        printf("bcm2835_init failed. Are you running as root?\n");
        return 1;
    }

    // Set up the clock output on GPIO 4
    setup_clock_output(32768);  // Set clock to 32.768 kHz

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
