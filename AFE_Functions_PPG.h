/** @file AFE_Functions_PPG.h
 *  @brief Function declarations for AFE's signal chain.
 *
 *         This contains the prototypes for the AFE's PPG signal chain
 *         driver and eventually any macros, constants,
 *         or global variables you will need.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#ifndef AFE_FUNCTIONS_PPG_H_
#define AFE_FUNCTIONS_PPG_H_


# include "AFE_RegMap.h"


//extern struct AFE_RegMap dev1;


/*! \enum  */
//enum clockingScheme {};

/*! \enum  */
enum AMB_CancellationScheme {AMB_Disabled, AMB_estimateAndCancel, AMB_cancel};

/*! \enum  */
enum LED_DC_CancellationScheme {LED_cancelDisabled, LED_cancelWithDRE, LED_cancelWithoutDRE};

/*! \enum Defines the Phase type  */
enum phaseType {explicitAMB, explicitLED, LED_WithPreAMB, LED_WithPreAndPostAMB, LED_WithPostAMB};

/*! \enum Defines the Phase timing scheme  */
enum phaseTimingScheme {STAGGER, HIGH_PRF_MODE, MAX_AMB_REJ, DIS_POST_AMB_MAX_AMB_REJ};

/*! \enum Defines the clock modes */
enum clockMode {CLK_MODE_INT, CLK_MODE_EXT, CLK_MODE_SS, CLK_MODE_MIX};

/*! \enum Defines TIA Gain i.e. RF */
enum RF_TIA {RF_3p7KOhm, RF_5KOhm, RF_10KOhm, RF_25KOhm, RF_33p3KOhm, RF_50KOhm, RF_71p5KOhm, RF_100KOhm, RF_142KOhm, RF_166KOhm, RF_200KOhm, RF_250KOhm, RF_500KOhm, RF_1MOhm};

/*! \enum Defines CF for TIA*/
enum CF_TIA {CF_2p5pF, CF_5pF, CF_7p5pF, CF_10pF, CF_17p5pF, CF_20pF, CF_22p5pF, CF_25pF};

/*! \enum Defines fullscale current for LED*/
enum ILED_FS {ILED_FS_25mA = 0, ILED_FS_50mA = 1, ILED_FS_100mA = 2, ILED_FS_125mA = 3, ILED_FS_167mA = 4};

/*! \enum Defines filter BW*/
enum FILTER_BW {FILT_BW_2p5KHz = 5, FILT_BW_5KHz = 6, FILT_BW_7p5KHz = 7, FILT_BW_10KHz = 0, FILT_BW_20KHz = 12, FILT_BW_30KHz = 8, FILT_BW_50KHz = 16, FILT_BW_25KHz = 14,  FILT_BW_32p5KHz = 9,  FILT_BW_15KHz = 2 ,  FILT_BW_35KHz = 10};

/*! \enum Defines LED ON times*/
enum REG_TWLED {LED_ON_16uS = 3, LED_ON_24uS = 5, LED_ON_31uS = 7, LED_ON_39uS = 9, LED_ON_47uS = 11, LED_ON_63uS = 15, LED_ON_70uS = 17, LED_ON_78uS = 19, LED_ON_94uS = 23, LED_ON_102uS = 25,  LED_ON_117uS = 29};

/*! \enum Defines fullscale current for AMB DAC*/
enum IFS_AMB_OFFDAC_TIA {AMB_DAC_FS_16uA = 0, AMB_DAC_FS_32uA = 1, AMB_DAC_FS_64uA = 3, AMB_DAC_FS_128uA = 5, AMB_DAC_FS_255uA = 7};

/*! \enum Defines TXN pin to be used for LED*/
enum LED_DRV_TXN {AMB_PH = 0, TXN1 = 1, TXN2 = 2, TXN3 = 4, TXN4 = 8};

/*! \enum Defines type of automatic AMB insertion for the given Phase*/
enum AUTO_AMB_INSERT {NONE, PRE_AMB, PRE_AND_POST_AMB, POST_AMB };

/*! \enum Defines type of data streaming into FIFO*/
enum FIFO_DATA_CTRL {NO_DATA, DEFINED_PHASE, LED_AMB, LED_AVG_OF_AMBS, PHASE_AND_AUTO_AMB_INSERTS };

/*! \enum Defines the TIA number of a gien Phase*/
enum TIA_NO {TIA1, TIA2};

/*! \enum Defines PD used for the given TIA of a Phase*/
enum IN_TIA {PD_DISCONNECT = 0, PD1 = 1, PD2 = 2, PD3 = 4};

/*! \enum Defines interrupt to be enabled on ADC_RDY pin*/
enum INT_MUX_ADC_RDY {DATA_RDY, THR_DET_RDY, FIFO_RDY, INT_OUT1, PRF_RST};

/*! \enum Defines reconvergence threshold for LED DC Cancellation*/
enum REG_RECONV_THR_LED_DC {RECONV_THR_0p9V = 192, RECONV_THR_0p8V = 171, RECONV_THR_0p7V = 149, RECONV_THR_0p6V = 128, RECONV_THR_0p5V = 107};


/** @brief Initialise AFE's Register Map
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_config_regMapInit();

/** @brief Applies software reset to AFE
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_set_SW_RESET();

/** @brief Does software power down of AFE
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_set_PDNAFE();

/** @brief Configures the Phase Timing Scheme of the AFE
 *         
 *  @param phTmgScheme Available Options: STAGGER, HIGH_PRF_MODE, MAX_AMB_REJ, DIS_POST_AMB_MAX_AMB_REJ
 *         
 *  @return None.
 */
void AFE_config_phaseTimingScheme(enum phaseTimingScheme phTmgScheme);

/** @brief Configures the clocking mode of the AFE
 *         
 *  @param phTmgScheme Available Options: CLK_MODE_INT, CLK_MODE_EXT, CLK_MODE_SS, CLK_MODE_MIX
 *         
 *  @return None.
 */
void AFE_config_clockMode( enum clockMode clkmode);

/** @brief Configures the PRPCT (i.e. sampling frequency) of the AFE
 *         
 *  @param prpcount calculated as fCLK_PRF / PRF
 *         
 *  @return None.
 */
void AFE_set_PRPCT(uint16_t prpcount);

/** @brief Enables the timing engine and PRF counter PRF
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_enableTimingEngine();

/** @brief Disables the timing engine and PRF counter of AFE
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_disableTimingEngine();

/** @brief Sets the full scale of LED current.
 *         
 *  @param FS_Value_inmA Available Options: ILED_FS_25mA, ILED_FS_50mA, ILED_FS_100mA, ILED_FS_125mA, ILED_FS_167mA
 *         
 *  @return None.
 */
void AFE_set_ILED_FS(enum ILED_FS FS_Value_inmA);

/** @brief Sets the bandwidth of noise reduction filter based on LED ON times
 *         Incase of different LED ON times, user need to set the bandwidths based on datasheets's guidlines
 *         
 *  @param ledOnForSet1_inuS First LED ON time of system, Available Options: LED_ON_16uS, LED_ON_24uS, LED_ON_31uS, LED_ON_39uS, LED_ON_47uS, LED_ON_63uS, LED_ON_70uS, LED_ON_78uS, LED_ON_94uS, LED_ON_102uS,  LED_ON_117uS
 *  @param ledOnForSet2_inuS Second LED ON time of system, Available Options: LED_ON_16uS, LED_ON_24uS, LED_ON_31uS, LED_ON_39uS, LED_ON_47uS, LED_ON_63uS, LED_ON_70uS, LED_ON_78uS, LED_ON_94uS, LED_ON_102uS,  LED_ON_117uS
 *         
 *  @return None.
 */
void AFE_set_FILTER_BW(enum REG_TWLED ledOnForSet1_inuS, enum REG_TWLED ledOnForSet2_inuS);

/** @brief Clears the per phase registers.
 *         Recommended to call this function as SW/HW reset
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_clearPPM();

/** @brief Assigns the LED (TXN switches) to be used for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param txnDrv1 TXN Switch connection for LED_DRV1 , Available Options: TXN1, TXN2, ... TXN8
 *  @param txnDrv2 TXN Switch connection for LED_DRV2 , Available Options: TXN1, TXN2, ... TXN8
 *         
 *  @return None.
 */
void AFE_set_LED_DRVx_TXN(uint8_t PhNo, enum LED_DRV_TXN txnDrv1, enum LED_DRV_TXN txnDrv2);

/** @brief Configures the Phase type along with LED to be used if decalred as LED
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param selectedPhaseType Type of Phase , Available Options: explicitAMB, explicitLED, LED_WithPreAMB, LED_WithPreAndPostAMB, LED_WithPostAMB
 *  @param txnDrv1 TXN Switch connection for LED_DRV1 , Available Options: TXN1, TXN2, ... TXN8
 *  @param txnDrv2 TXN Switch connection for LED_DRV2 , Available Options: TXN1, TXN2, ... TXN8
 *         
 *  @return None.
 */
void AFE_set_phaseType(uint8_t PhNo, enum phaseType selectedPhaseType , enum LED_DRV_TXN txnDrv1, enum LED_DRV_TXN txnDrv2 );

/** @brief Configures the LED current for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param iled1 LED current interms of code for LED_DRV1 , Available Options: 0 to 255 codes
 *  @param iled2 LED current interms of code for LED_DRV2 , Available Options: 0 to 255 codes
 *         
 *  @return None.
 */
void AFE_set_ILED_DRVx(uint8_t PhNo, uint8_t iled1, uint8_t iled2);

/** @brief Configures the LED ON time for the given Phase
 *         if different LED ON time needs to be used, configure noise reduction filter, CF of TIA based on datasheet
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param ledOn_inuS LED ON time interms of fCLK_TE , Available Options: LED_ON_16uS, LED_ON_24uS, LED_ON_31uS, LED_ON_39uS, LED_ON_47uS, LED_ON_63uS, LED_ON_70uS, LED_ON_78uS, LED_ON_94uS, LED_ON_102uS,  LED_ON_117uS
 *         
 *  @return None.
 */
void AFE_set_REG_TWLED(uint8_t PhNo,enum REG_TWLED ledOn_inuS);

/** @brief Configures the ADC averaging for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param ADC_samplesToAverage Number of samples to be averaged , Available Options: 1,2,3,4,8
 *         
 *  @return None.
 */
void AFE_set_NUMAV(uint8_t PhNo, uint8_t ADC_samplesToAverage);

/** @brief Configures the automatic insertion of AMB for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param autoAMB Available Options: NONE, PRE_AMB, PRE_AND_POST_AMB, POST_AMB
 *         
 *  @return None.
 */
void AFE_set_AUTO_AMB_INSERT(uint8_t PhNo, enum AUTO_AMB_INSERT autoAMB);

/** @brief Configures the FIFO data control for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param fifoData Available Options: NO_DATA, DEFINED_PHASE, LED_AMB, LED_AVG_OF_AMBS, PHASE_AND_AUTO_AMB_INSERTS
 *         
 *  @return None.
 */
void AFE_set_FIFO_DATA_CTRL(uint8_t PhNo, enum FIFO_DATA_CTRL fifoData);

/** @brief Configures the PD used for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param tiaSelected TIA Number,  Available Options: TIA1, TIA2, , 
 *  @param pd1 Available Options: PD1, PD_DISCONNECT
 *  @param pd2 Available Options: PD2, PD_DISCONNECT
 *  @param pd3 Available Options: PD3, PD_DISCONNECT
 *         
 *  @return None.
 */
void AFE_set_IN_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum IN_TIA pd1, enum IN_TIA pd2, enum IN_TIA pd3);

/** @brief Configures the RF for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param tiaSelected TIA Number,  Available Options: TIA1, TIA2, , 
 *  @param rfSelected RF Value ,  Available Options: RF_3p7KOhm, RF_5KOhm, RF_10KOhm, RF_25KOhm, RF_33p3KOhm, RF_50KOhm, RF_71p5KOhm, RF_100KOhm, RF_142KOhm, RF_166KOhm, RF_200KOhm, RF_250KOhm, RF_500KOhm, RF_1MOhm
 *         
 *  @return None.
 */
void AFE_set_RF_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum RF_TIA rfSelected);

/** @brief Configures the CF for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param tiaSelected TIA Number,  Available Options: TIA1, TIA2, , 
 *  @param cfSelected CF Value ,  Available Options: CF_2p5pF, CF_5pF, CF_7p5pF, CF_10pF, CF_17p5pF, CF_20pF, CF_22p5pF, CF_25pF
 *         
 *  @return None.
 */
void AFE_set_CF_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum CF_TIA cfSelected);

/** @brief Enables or disables LED DC Cancellation for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param tiaSelected TIA Number,  Available Options: TIA1, TIA2, , 
 *  @param state Available Options: true, false
 *         
 *  @return None.
 */
void AFE_set_LED_DC_EN_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, bool state);

/** @brief Enables or disables DRE for the given Phase
 *         LED DC Cancellations needs to be enabled for the DRE
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param state Available Options: true, false
 *         
 *  @return None.
 */
void AFE_set_ENABLE_DRE(uint8_t PhNo, bool state);

/** @brief Configures the TIA for the given Phase based on given arguments
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param tiaSelected TIA Number,  Available Options: TIA1, TIA2, , 
 *  @param pdSelected PDs to be used,  Available Options: PD_DISCONNECT, PD1, PD2, PD3
 *  @param rfSelected RF Value ,  Available Options: RF_3p7KOhm, RF_5KOhm, RF_10KOhm, RF_25KOhm, RF_33p3KOhm, RF_50KOhm, RF_71p5KOhm, RF_100KOhm, RF_142KOhm, RF_166KOhm, RF_200KOhm, RF_250KOhm, RF_500KOhm, RF_1MOhm
 *  @param ledOn_inuS LED ON time interms of fCLK_TE , Available Options: LED_ON_16uS, LED_ON_24uS, LED_ON_31uS, LED_ON_39uS, LED_ON_47uS, LED_ON_63uS, LED_ON_70uS, LED_ON_78uS, LED_ON_94uS, LED_ON_102uS,  LED_ON_117uS
 *  @param LED_DC_cnclSelected Available Options: LED_cancelDisabled, LED_cancelWithDRE, LED_cancelWithoutDRE
 *         
 *  @return None.
 */
void AFE_configTIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum IN_TIA pdSelected, enum RF_TIA rfSelected, enum REG_TWLED ledOn_inuS, enum LED_DC_CancellationScheme LED_DC_cnclSelected);

/** @brief Configures the AMB cancellation scheme for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param AMB_CancellationScheme Available Options: AMB_Disabled, AMB_estimateAndCancel, AMB_cancel
 *         AMB_estimateAndCancel : AFE estimates ambient signal before just before given phase and cancels it
 *         AMB_cancel : Ambient signal is cancelled based on estimates from previous phase
 *         
 *  @return None.
 */
void AFE_config_AMBCancellation(uint8_t PhNo, enum AMB_CancellationScheme);

/** @brief Configures the LED DC Cancellation scheme for the given Phase
 *         
 *  @param PhNo Phase Number , Available Options: Phase1, Phase2, ... Phase16
 *  @param LED_DC_CancellationScheme Available Options: LED_cancelDisabled, LED_cancelWithDRE, LED_cancelWithoutDRE
 *         
 *  @return None.
 */
void AFE_config_LEDCancellation(uint8_t PhNo, enum LED_DC_CancellationScheme);

/** @brief Configures the interrupt on ADC_RDY pin
 *         
 *  @param intOnADC_RDY Interrupt signal , Available Options: DATA_RDY, THR_DET_RDY, FIFO_RDY, INT_OUT1, PRF_RST
 *         
 *  @return None.
 */
void AFE_set_INT_MUX_ADC_RDY(enum INT_MUX_ADC_RDY intOnADC_RDY);

/** @brief Computes the CF based on RF and LED ON time
 *         
 *  @param ledOnForSet1_inuS LED ON time interms of fCLK_TE , Available Options: LED_ON_16uS, LED_ON_24uS, LED_ON_31uS, LED_ON_39uS, LED_ON_47uS, LED_ON_63uS, LED_ON_70uS, LED_ON_78uS, LED_ON_94uS, LED_ON_102uS,  LED_ON_117uS
 *  @param rfSelected RF Value ,  Available Options: RF_3p7KOhm, RF_5KOhm, RF_10KOhm, RF_25KOhm, RF_33p3KOhm, RF_50KOhm, RF_71p5KOhm, RF_100KOhm, RF_142KOhm, RF_166KOhm, RF_200KOhm, RF_250KOhm, RF_500KOhm, RF_1MOhm
 *         
 *  @return None.
 */
int AFE_compute_CF(enum REG_TWLED ledOnForSet1_inuS,enum RF_TIA rfSelected );

/** @brief Initializes the AFE
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_initializeAFE();

/** @brief Configures the scaling factor for the DRE based on given RF
 *         
 *  @param rfSelected RF Value ,  Available Options: RF_3p7KOhm, RF_5KOhm, RF_10KOhm, RF_25KOhm, RF_33p3KOhm, RF_50KOhm, RF_71p5KOhm, RF_100KOhm, RF_142KOhm, RF_166KOhm, RF_200KOhm, RF_250KOhm, RF_500KOhm, RF_1MOhm
 *                    Among all the active TIA and Phases with the DRE enabled, pick the largest value of RF to be used with this function 
 *         
 *  @return None.
 */
void AFE_set_REG_SCALE_DRE(enum RF_TIA rfSelected);

/** @brief Configuration example for HRM (Heart Rate Monitoring)
 *         
 *  @param None
 * 
 *  @return None.
 */
void AFE_configAFE_forHRM();

/** @brief Configuration example for SpO2
 *         
 *  @param None
 * 
 *  @return None.
 */
void AFE_configAFE_forSpO2();



#endif /* AFE_FUNCTIONS_PPG_H_ */
