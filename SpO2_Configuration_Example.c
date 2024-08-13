/** @file SpO2_Configuration_Example.c
 *  @brief An example configuration for SpO2 based on AFE4432EVM
 *
 *         This example shows how to use the driver to configure the AFE based on given hardware (i.e. AFE4432EVM).
 *         User can take this as a reference and modify based on their requirements such as LED-PD associations, clocking mode and PRF.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#include"AFE_Functions_PPG.h"

extern struct AFE_RegMap dev1;
extern uint32_t errorFlags;

void AFE_configAFE_forSpO2(){

    uint8_t PhaseToConfig;
    enum REG_TWLED LED_ON_AC = LED_ON_117uS;            // Higher LED ON time to capture AC component of PPG, Higher LED time lowers the Noise reduction filter's bandwidth thus increasing the SNR. 
    enum REG_TWLED LED_ON_DC = LED_ON_16uS;             // Lower LED ON time to capture DC component of PPG to lower LED power consumption as SNR requirement is not higher.
    enum RF_TIA rfSelected_AC = RF_250KOhm;             // Higher RF can be used for AC as PPG's DC is automatically cancelled by AFE using LED DC Cancellation loop.
    enum RF_TIA rfSelected_DC = RF_10KOhm;              // Lower RF is used as DC of PPG signal needs to be acquired with saturating the signal chain.

    AFE_config_regMapInit();                            // Mandatory Step1
    AFE_set_SW_RESET();                                 // Mandatory Step2
    AFE_clearPPM();                                     // Mandatory Step3
    AFE_initializeAFE();                                // Mandatory Step4, Recommended to verify configurations in this functions.
    AFE_config_phaseTimingScheme(HIGH_PRF_MODE);        // Phase timing scheme is set to High PRF Mode
    AFE_config_clockMode(CLK_MODE_INT);                 // CLK_MODE_INT is used as clocking for AFE
    AFE_set_PRPCT(2560);                                // PRPCT of 2560 corresponds to 100Hz with CLK_MODE_INT 
    AFE_set_FILTER_BW(LED_ON_AC, LED_ON_DC);            // 2 sets of Noise reduction filter is confired based on two different LED ON times
    AFE_set_REG_SCALE_DRE(rfSelected_AC);               // Since RF for AC component of PPG is higher, it is used to set REG_SCALE_DRE

    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_NUMPHASE, 3);  // 4 phase to be used: 2 for AC component of PPG, 2 for DC component of PPG

    PhaseToConfig = Phase1;         // Red LED for AC component of PPG
    AFE_set_phaseType(              PhaseToConfig, LED_WithPreAMB, TXN1, TXN1);                                 // LED Phase with auto insertion of Pre AMB, TXN3 used for both LED Drivers, TX_SUP connected to Anode of LEDSs (instead of TXP Pins of AFE)    
    AFE_set_REG_TWLED(              PhaseToConfig, LED_ON_AC);                                                  // LED ON time set to 117uS
    AFE_set_ILED_DRVx(              PhaseToConfig, 50, 50);                                                     // LED current of 50 codes 
    AFE_set_FIFO_DATA_CTRL(         PhaseToConfig, LED_AMB);                                                    // FIFO is filled with LED - AMB data   
    AFE_set_NUMAV(                  PhaseToConfig, 2);                                                          // Average of 2 ADC samples.
    AFE_configTIA(                  PhaseToConfig, TIA1, PD2, rfSelected_AC,LED_ON_AC, LED_cancelWithoutDRE);   // RF of 250K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation enabled without DRE
    AFE_config_AMBCancellation(     PhaseToConfig, AMB_estimateAndCancel);                                      // AMB is estimated and cancelled before begining of this Phase.

    PhaseToConfig = Phase2;         // IR LED for AC component of PPG
    AFE_set_phaseType(              PhaseToConfig, LED_WithPreAMB, TXN3, TXN3);                                 // LED Phase with auto insertion of Pre AMB, TXN3 used for both LED Drivers, TX_SUP connected to Anode of LEDSs (instead of TXP Pins of AFE)   
    AFE_set_REG_TWLED(              PhaseToConfig, LED_ON_AC);                                                  // LED ON time set to 117uS
    AFE_set_ILED_DRVx(              PhaseToConfig, 50, 50);                                                     // LED current of 50 codes
    AFE_set_FIFO_DATA_CTRL(         PhaseToConfig, LED_AMB);                                                    // FIFO is filled with LED - AMB data   
    AFE_set_NUMAV(                  PhaseToConfig, 2);                                                          // Average of 2 ADC samples.
    AFE_configTIA(                  PhaseToConfig, TIA1, PD2, rfSelected_AC,LED_ON_AC, LED_cancelWithoutDRE);   // RF of 250K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation enabled without DRE
    AFE_config_AMBCancellation(     PhaseToConfig, AMB_cancel);                                                 // AMB is cancelled based on previous estimate.

    PhaseToConfig = Phase3;         // Red LED for DC component of PPG
    AFE_set_phaseType(              PhaseToConfig, LED_WithPreAMB, TXN1, TXN1);                                 // LED Phase with auto insertion of Pre AMB, TXN3 used for both LED Drivers, TX_SUP connected to Anode of LEDSs (instead of TXP Pins of AFE)   
    AFE_set_REG_TWLED(              PhaseToConfig, LED_ON_DC);                                                  // LED ON time set to 16uS
    AFE_set_ILED_DRVx(              PhaseToConfig, 50, 50);                                                     // LED current of 50 codes
    AFE_set_FIFO_DATA_CTRL(         PhaseToConfig, LED_AMB);                                                    // FIFO is filled with LED - AMB data   
    AFE_set_NUMAV(                  PhaseToConfig, 2);                                                          // Average of 2 ADC samples.
    AFE_configTIA(                  PhaseToConfig, TIA1, PD2, rfSelected_DC,LED_ON_DC, LED_cancelDisabled);     // RF of 10K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation disabled
    AFE_config_AMBCancellation(     PhaseToConfig, AMB_estimateAndCancel);                                      // AMB is estimated and cancelled before begining of this Phase.

    PhaseToConfig = Phase4;         // IR LED for DC component of PPG
    AFE_set_phaseType(              PhaseToConfig, LED_WithPreAMB, TXN3, TXN3);                                 // LED Phase with auto insertion of Pre AMB, TXN3 used for both LED Drivers, TX_SUP connected to Anode of LEDSs (instead of TXP Pins of AFE)   
    AFE_set_REG_TWLED(              PhaseToConfig, LED_ON_DC);                                                  // LED ON time set to 16uS
    AFE_set_ILED_DRVx(              PhaseToConfig, 50, 50);                                                     // LED current of 50 codes
    AFE_set_FIFO_DATA_CTRL(         PhaseToConfig, LED_AMB);                                                    // FIFO is filled with LED - AMB data   
    AFE_set_NUMAV(                  PhaseToConfig, 2);                                                          // Average of 2 ADC samples.
    AFE_configTIA(                  PhaseToConfig, TIA1, PD2, rfSelected_DC,LED_ON_DC, LED_cancelDisabled);     // RF of 10K, LED ON TIME should be same as REG_TWLED, LED DC Cancellation disabled
    AFE_config_AMBCancellation(     PhaseToConfig, AMB_cancel);                                                 // AMB is cancelled based on previous estimate.

    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_WM_FIFO, 39);

    if (errorFlags==0)
        AFE_enableTimingEngine();

}

