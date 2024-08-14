/** @file main.c
 *  @brief Configuration for UV absorption spectroscopy using AFE4432
 *
 *         This is a main to interface the AFE4432 device with the Raspberry Pi using SPI interface.
 *         The AFE4432 device is configured for UV absorption spectroscopy.
 *
 *  @author Timon Grosch
 */

#include "AFE_Functions_PPG.h"
#include "AFE_HostControl.h"
#include "UV_Configuration.h"
#include <bcm2835.h>
#include <stdio.h>


// Function to check if the AFE4432 device is alive
int check_device_alive() {
    uint32_t device_id = AFE_readReg(0x28);  // Read the Device ID register
    if (device_id == 0x121) {  // Expected Device ID
        printf("Device is alive. Device ID: 0x%x\n", device_id);
        return 1;  // Device is alive
    } else {
        printf("Device not responding correctly. Read ID: 0x%x\n", device_id);
        return 0;  // Device is not responding
    }
}

int main() {
    // Initialize the SPI interface
    initSPI();

    // Check if the device is alive
    if (check_device_alive()) {
        // Device is alive, proceed with further operations
        printf("Starting UV Absorption Spectroscopy\n");
        for (int i = 0; i < 10; i++) {
            AFE_config_for_UVSpectroscopy();
        }
        printf("End UV Absorption Spectroscopy\n");
    } else {
        printf("Device did not respond correctly. Exiting...\n");
    }

    // Close the SPI interface
    closeSPI();

    // Terminate the bcm2835 library
    bcm2835_close();

    return 0;
}
