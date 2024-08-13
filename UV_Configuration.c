#include "AFE_Functions_PPG.h"
#include <bcm2835.h>

extern struct AFE_RegMap dev1;
extern uint32_t errorFlags;

#define GPIO_PIN RPI_GPIO_P1_08 // GPIO 14 corresponds to pin 8 on the Raspberry Pi header

void AFE_config_for_UVSpectroscopy() {
    uint8_t PhaseToConfig;

    // Initialization and default function calls.
    AFE_config_regMapInit();  // Mandatory Step1
    AFE_set_SW_RESET();  // Mandatory Step2
    AFE_clearPPM();  // Mandatory Step3
    AFE_initializeAFE();  // Mandatory Step4, Recommended to verify configurations in this functions

    // // Check if GPIO 14 is high
    // if (!bcm2835_init()) {
    //     fprintf(stderr, "bcm2835_init failed\n");
    //     exit(1);
    // }

    // bcm2835_gpio_fsel(GPIO_PIN, BCM2835_GPIO_FSEL_INPT);  // Set GPIO 14 as input

    // if (bcm2835_gpio_lev(GPIO_PIN) == HIGH) {
    //     printf("ADC is ready\n");
    // } else {
    //     printf("ADC is NOT ready\n");
    // }

    // Continue with the configuration
    AFE_config_phaseTimingScheme(STAGGER);  // Phase timing scheme is set to Stagger Mode
    AFE_config_clockMode(CLK_MODE_INT);  // CLK_MODE_INT is used as clocking for AFE
    AFE_set_PRPCT(10240);  // PRPCT of 10240 corresponds to 25Hz with CLK_MODE_INT
    AFE_set_FILTER_BW(LED_ON_117uS, LED_ON_117uS);  // Both set of Noise reduction filters are configured to support LED ON time of 117uS.
    AFE_set_REG_SCALE_DRE(RF_250KOhm);  // Max value of Rf used among the phases where DRE is enabled

    // Test with one phase
    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_NUMPHASE, 0);  // 1 phase

    PhaseToConfig = Phase1;
    AFE_set_phaseType(PhaseToConfig, LED_WithPreAMB, TXN1, TXN1);  // LED Phase with auto insertion of Pre AMB
    AFE_set_REG_TWLED(PhaseToConfig, LED_ON_117uS);  // LED ON time set to 117uS
    AFE_set_ILED_DRVx(PhaseToConfig, 255, 255);  // LED current of 255 codes
    AFE_set_FIFO_DATA_CTRL(PhaseToConfig, LED_AMB);  // FIFO is filled with LED - AMB data
    AFE_set_NUMAV(PhaseToConfig, 2);  // Average of 2 ADC samples.
    AFE_configTIA(PhaseToConfig, TIA1, PD1, RF_250KOhm, LED_ON_117uS, LED_cancelWithDRE);  // RF of 250K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation enabled with DRE
    AFE_config_AMBCancellation(PhaseToConfig, AMB_estimateAndCancel);  // AMB is estimated and cancelled before beginning of this Phase.

    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_WM_FIFO, 0);

    if (errorFlags == 0)
        AFE_enableTimingEngine();
}
