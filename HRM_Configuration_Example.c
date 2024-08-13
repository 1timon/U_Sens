/** @file HRM_Configuration_Example.c
 *  @brief An example configuration for HRM (Heart Rate Monitoring) based on AFE4432EVM
 *
 *         This example shows how to use the driver to configure the AFE based on given hardware (i.e. AFE4432EVM).
 *         User can take this as a reference and modify based on their requirements such as LED-PD associations, clocking mode and PRF.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#include"AFE_Functions_PPG.h"


extern struct AFE_RegMap dev1;

extern uint32_t errorFlags;


void AFE_configAFE_forHRM(){

    uint8_t PhaseToConfig;

    // Initialization and default function calls.
    AFE_config_regMapInit();                            // Mandatory Step1
    AFE_set_SW_RESET();                                 // Mandatory Step2
    AFE_clearPPM();                                     // Mandatory Step3
    AFE_initializeAFE();                                // Mandatory Step4, Recommended to verify configurations in this functions.
    AFE_config_phaseTimingScheme(STAGGER);              // Phase timing scheme is set to Stagger Mode
    AFE_config_clockMode(CLK_MODE_INT);                 // CLK_MODE_INT is used as clocking for AFE
    AFE_set_PRPCT(10240);                               // PRPCT of 10240 corresponds to 25Hz with CLK_MODE_INT 
    AFE_set_FILTER_BW(LED_ON_117uS, LED_ON_117uS);      // Both set of Noise reduction filters are configured to support LED ON time of 117uS.
    AFE_set_REG_SCALE_DRE(RF_250KOhm);                  // Max value of Rf used among the phases where DRE is enabled

    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_NUMPHASE, 0);  // Only 1 phase to be used

    PhaseToConfig = Phase1;
    AFE_set_phaseType(              PhaseToConfig, LED_WithPreAMB, TXN4, TXN4);                     // LED Phase with auto insertion of Pre AMB, TXN8 used for both LED Drivers, TX_SUP connected to Anode of LEDSs (instead of TXP Pins of AFE)               
    AFE_set_REG_TWLED(              PhaseToConfig, LED_ON_117uS);                                           // LED ON time set to 117uS
    AFE_set_ILED_DRVx(              PhaseToConfig, 50, 50);                                                 // LED current of 50 codes 
    AFE_set_FIFO_DATA_CTRL(         PhaseToConfig, LED_AMB);                                                // FIFO is filled with LED - AMB data
    AFE_set_NUMAV(                  PhaseToConfig, 2);                                                      // Average of 2 ADC samples. 
    AFE_configTIA(                  PhaseToConfig, TIA1, PD1, RF_250KOhm,LED_ON_117uS, LED_cancelWithDRE);  // RF of 250K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation enabled with DRE
    AFE_config_AMBCancellation(     PhaseToConfig, AMB_estimateAndCancel);                                  // AMB is estimated and cancelled before begining of this Phase.

    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_WM_FIFO, 0);

    if (errorFlags==0)
        AFE_enableTimingEngine();

}
