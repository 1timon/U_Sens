/** @file AFE_Functions_PPG.c
 *  @brief Function definitions for AFE's signal chain. 
 *
 *         This contains definition low level functions.
 *         User can add/modify these low level function based on their rerquirement.
 *         AFE parameter can be modified using "AFE_modifyRegGlobal" or "AFE_modifyRegPPM" function as shown in following functions.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#include"AFE_Functions_PPG.h"


// * * * * User modifications based on system requirements : START 
uint8_t maxNoTIA = 1;
enum IFS_AMB_OFFDAC_TIA AMB_DAC_FS_selected = AMB_DAC_FS_16uA;


// * * * * User modifications based on system requirements : END 

AFE_RegMap dev1;
char CF_Array1[6] = {CF_20pF, CF_17p5pF, CF_10pF, CF_10pF, CF_5pF, CF_2p5pF};
char CF_Array2[4] = {CF_22p5pF, CF_17p5pF, CF_7p5pF, CF_2p5pF};
char CF_Array3[3] = {CF_20pF, CF_10pF, CF_5pF};
enum REG_TWLED LED_ON_TIME1, LED_ON_TIME2;



enum phaseTimingScheme selectedPhaseTimingScheme = STAGGER;
uint32_t errorFlags = 0;
uint32_t enableBitsDRE = 0;



void AFE_config_regMapInit(){

    AFE_assignRegMap(&dev1);
}

void AFE_set_SW_RESET(){
     AFE_writeReg(0x00,0x000008);
     errorFlags = 0;
     enableBitsDRE = 0;
}

void AFE_set_PDNAFE(){

    AFE_modifyRegGlobal(&dev1.GLOBAL.PDNAFE, 1);
}

void AFE_config_phaseTimingScheme(enum phaseTimingScheme phTmgScheme){

    if( phTmgScheme == HIGH_PRF_MODE){
        AFE_modifyRegGlobal(&dev1.GLOBAL.HIGH_PRF_MODE,             true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.MAX_AMB_REJ,               false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.DIS_POST_AMB_MAX_AMB_REJ,  false);
        selectedPhaseTimingScheme = HIGH_PRF_MODE;
    }

    else if (phTmgScheme == MAX_AMB_REJ)
    {
        AFE_modifyRegGlobal(&dev1.GLOBAL.HIGH_PRF_MODE,             false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.MAX_AMB_REJ,               true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.DIS_POST_AMB_MAX_AMB_REJ,  false);
        selectedPhaseTimingScheme = MAX_AMB_REJ;
    }

    else if (phTmgScheme == DIS_POST_AMB_MAX_AMB_REJ)
    {
        AFE_modifyRegGlobal(&dev1.GLOBAL.HIGH_PRF_MODE,             false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.MAX_AMB_REJ,               false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.DIS_POST_AMB_MAX_AMB_REJ,  true);
        selectedPhaseTimingScheme = DIS_POST_AMB_MAX_AMB_REJ;
    }

    else 
    {
        AFE_modifyRegGlobal(&dev1.GLOBAL.HIGH_PRF_MODE,             false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.MAX_AMB_REJ,               false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.DIS_POST_AMB_MAX_AMB_REJ,  false);
        selectedPhaseTimingScheme = STAGGER;
    }

    
}

void AFE_config_clockMode( enum clockMode clkmode){

    switch (clkmode)
    {
    case CLK_MODE_EXT:
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_TE,           true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.OSCL_DIS,              true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.PDN_OSCL_IN_DEEP_SLEEP,false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_PRF_RESET,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_PRF,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_INT_IN_SINGLE_SHOT, false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_CLK_MODE_MIX,       false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SPLIT_CLK_FOR_TE_PRF,  false);        
        break;
   
    case CLK_MODE_SS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_TE,           false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.OSCL_DIS,              false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.PDN_OSCL_IN_DEEP_SLEEP,true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_PRF_RESET,          true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_PRF,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_INT_IN_SINGLE_SHOT, true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_CLK_MODE_MIX,       false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SPLIT_CLK_FOR_TE_PRF,  true);
        break;

    case CLK_MODE_MIX:
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_TE,           false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.OSCL_DIS,              false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.PDN_OSCL_IN_DEEP_SLEEP,true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_PRF_RESET,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_PRF,          true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_INT_IN_SINGLE_SHOT, false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_CLK_MODE_MIX,       true);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SPLIT_CLK_FOR_TE_PRF,  true);
        break;
    
    default: //  CLK_MODE_INT
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_TE,           false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.OSCL_DIS,              false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.PDN_OSCL_IN_DEEP_SLEEP,false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_PRF_RESET,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SEL1_CLK_PRF,          false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_INT_IN_SINGLE_SHOT, false);       
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_CLK_MODE_MIX,       false);
        AFE_modifyRegGlobal(&dev1.GLOBAL.SPLIT_CLK_FOR_TE_PRF,  false);
        break;

    }

    
}


void AFE_set_PRPCT(uint16_t prpcount){

    AFE_modifyRegGlobal(&dev1.GLOBAL.PRPCT, prpcount);
}

void AFE_enableTimingEngine(){

    AFE_modifyRegGlobal(&dev1.GLOBAL.TIMER_ENABLE,          true);
    AFE_modifyRegGlobal(&dev1.GLOBAL.PRF_COUNTER_ENABLE,    true);

    
}

void AFE_disableTimingEngine(){

    AFE_modifyRegGlobal(&dev1.GLOBAL.TIMER_ENABLE,          false);
    AFE_modifyRegGlobal(&dev1.GLOBAL.PRF_COUNTER_ENABLE,    false);

    
}


void AFE_set_ILED_FS(enum ILED_FS FS_Value_inmA){

    AFE_modifyRegGlobal(&dev1.GLOBAL.ILED_FS,          FS_Value_inmA);


}


void AFE_set_FILTER_BW(enum REG_TWLED ledOnForSet1_inuS, enum REG_TWLED ledOnForSet2_inuS){
    enum REG_TWLED maxLedOnTime;

    LED_ON_TIME1 = ledOnForSet1_inuS;
    LED_ON_TIME2 = ledOnForSet2_inuS;

    if (ledOnForSet2_inuS>ledOnForSet1_inuS)
        maxLedOnTime = ledOnForSet2_inuS;
    else
        maxLedOnTime = ledOnForSet1_inuS;

    switch (ledOnForSet1_inuS)
    {
    case LED_ON_117uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_25KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_2p5KHz);
        break;
    case LED_ON_102uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_94uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_78uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_70uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_63uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_7p5KHz);
        break;
    case LED_ON_47uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_10KHz);
        break;
    case LED_ON_39uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_20KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_15KHz);
        break;
    case LED_ON_31uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_25KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_25KHz);
        break;
    case LED_ON_24uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_35KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_35KHz);
        break;
    case LED_ON_16uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_50KHz);
        break;
    
    default:
        errorFlags = (errorFlags & 0xFFFFFFFE) + (1);
        break;
    }

    switch (ledOnForSet2_inuS)
    {
    case LED_ON_117uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_25KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_2p5KHz);
        break;
    case LED_ON_102uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_94uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_78uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_32p5KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_70uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_5KHz);
        break;
    case LED_ON_63uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_7p5KHz);
        break;
    case LED_ON_47uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_10KHz);
        break;
    case LED_ON_39uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_20KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_15KHz);
        break;
    case LED_ON_31uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_25KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_25KHz);
        break;
    case LED_ON_24uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_35KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_35KHz);
        break;
    case LED_ON_16uS:
        AFE_modifyRegGlobal(&dev1.GLOBAL.OVERRIDE_BW_PRE,            1);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_PRE_SET1,         FILT_BW_50KHz);
        AFE_modifyRegGlobal(&dev1.GLOBAL.FILTER_BW_FINE_SET1,        FILT_BW_50KHz);
        break;
    
    default:
        errorFlags = (errorFlags & 0xFFFFFFFE) + (1);
        break;
    }

    if (maxLedOnTime<8)                                         // LED ON time < 39uS, where pre charge and fine BW are same.
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_TW_FILTER_PRE,        0x80);  
    else if ( (maxLedOnTime > 8) && (maxLedOnTime < 18) )      // LED ON time = 39uS to 70uS, pre charge width = 4 clks (16uS)
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_TW_FILTER_PRE,        0x84);
    else if ( (maxLedOnTime == 29)  )                           // LED ON time = 117uS, pre charge width = 8 clks (32uS)
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_TW_FILTER_PRE,        0x88);
    
    else                                                         // LED ON time = 78uS to 102uS, pre charge width = 6 clks (24uS)
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_TW_FILTER_PRE,        0x86);
    
}


void AFE_clearPPM(){
    uint8_t regNo;
    //AFE_modifyRegGlobal(&dev1.GLOBAL.PAGE_SEL,        1);
    AFE_switchPage(1);
    for (regNo = 32;regNo<160;regNo++)
        AFE_writeReg(regNo,0x000000);
    //AFE_modifyRegGlobal(&dev1.GLOBAL.PAGE_SEL,        0);
    AFE_switchPage(0);
    
}


void AFE_set_LED_DRVx_TXN(uint8_t PhNo, enum LED_DRV_TXN txnDrv1, enum LED_DRV_TXN txnDrv2){
    AFE_modifyRegPPM(PhNo, &dev1.PPM.LED_DRV1_TXN,          txnDrv1);
    AFE_modifyRegPPM(PhNo, &dev1.PPM.LED_DRV2_TXN,          txnDrv2);

}


void AFE_set_ILED_DRVx(uint8_t PhNo, uint8_t iled1, uint8_t iled2){
    //if (iled1<0 || iled1 > 255)
    if (iled1 > 255)
        AFE_modifyRegPPM(PhNo, &dev1.PPM.ILED_DRV1, 0);
    else
        AFE_modifyRegPPM(PhNo, &dev1.PPM.ILED_DRV1, (uint8_t) iled1);

    //if (iled2<0 || iled2 > 255)
    if (iled2 > 255)
        AFE_modifyRegPPM(PhNo, &dev1.PPM.ILED_DRV2, 0);
    else
        AFE_modifyRegPPM(PhNo, &dev1.PPM.ILED_DRV2, (uint8_t) iled2);
}


void AFE_set_REG_TWLED(uint8_t PhNo,enum REG_TWLED ledOn_inuS){
    AFE_modifyRegPPM(PhNo, &dev1.PPM.REG_TWLED, ledOn_inuS);
    if (ledOn_inuS == LED_ON_TIME2)
        AFE_modifyRegPPM(PhNo, &dev1.PPM.FILTER_SET_SEL, 1);
    else
        AFE_modifyRegPPM(PhNo, &dev1.PPM.FILTER_SET_SEL, 0);
}

void AFE_set_NUMAV(uint8_t PhNo, uint8_t ADC_samplesToAverage){
    if(ADC_samplesToAverage>0)
        AFE_modifyRegPPM(PhNo, &dev1.PPM.REG_NUMAV, ADC_samplesToAverage-1);
    else 
        AFE_modifyRegPPM(PhNo, &dev1.PPM.REG_NUMAV, 0);
}

void AFE_set_AUTO_AMB_INSERT(uint8_t PhNo, enum AUTO_AMB_INSERT autoAMB){
    AFE_modifyRegPPM(PhNo, &dev1.PPM.AUTO_AMB_INSERT, autoAMB);
}

void AFE_set_FIFO_DATA_CTRL(uint8_t PhNo, enum FIFO_DATA_CTRL fifoData){
    
    uint8_t phaseIndex = 0;
    uint32_t invMaskPattern = 0;
    phaseIndex = (PhNo - 32)>>3 ;        // Gives 0, 1, 2,.. for Phase1, Phase2, Phase3 respectively. 

    invMaskPattern = (uint32_t)(1<<phaseIndex);

    switch (selectedPhaseTimingScheme)
    {
    case HIGH_PRF_MODE:
        if (fifoData == LED_AVG_OF_AMBS){
            errorFlags = (errorFlags & 0xFFFFFFF7) + (8);
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, NO_DATA);
        }
        else
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
        break;
    case MAX_AMB_REJ:
        
        if ((fifoData == LED_AMB) || (fifoData == DEFINED_PHASE)  ){
            errorFlags = (errorFlags & 0xFFFFFFF7) + (8);
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, NO_DATA);
        }
        else if ((fifoData == LED_AVG_OF_AMBS)){

            if ((enableBitsDRE & ((invMaskPattern))) == invMaskPattern) {       // if DRE is enabled in the given Phase
                errorFlags = (errorFlags & 0xFFFFFFF7) + (8);
                AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, NO_DATA);
            }
            else
                AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
        }
        else
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
        break;
    case DIS_POST_AMB_MAX_AMB_REJ:
        if ((fifoData == LED_AVG_OF_AMBS) || (fifoData == DEFINED_PHASE)){
            errorFlags = (errorFlags & 0xFFFFFFF7) + (8);
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, NO_DATA);
        }
        else if ((fifoData == LED_AMB)){

            if ((enableBitsDRE & ((invMaskPattern))) == invMaskPattern) {       // if DRE is enabled in the given Phase
                errorFlags = (errorFlags & 0xFFFFFFF7) + (8);
                AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, NO_DATA);
            }
            else
                AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
        }
        else
            AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
        break;
    
    default:
        break;
    }



    AFE_modifyRegPPM(PhNo, &dev1.PPM.FIFO_DATA_CTRL, fifoData);
}

void AFE_set_IN_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum IN_TIA pd1, enum IN_TIA pd2, enum IN_TIA pd3 ){
    AFE_modifyRegPPM((uint8_t)PhNo+tiaSelected, &dev1.PPM.IN_TIA1, (pd1+pd2+pd3));
}

void AFE_set_RF_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum RF_TIA rfSelected){
    AFE_modifyRegPPM((uint8_t)PhNo+tiaSelected, &dev1.PPM.RF_TIA1, rfSelected);
}

void AFE_set_CF_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum CF_TIA cfSelected){
    AFE_modifyRegPPM((uint8_t)PhNo+tiaSelected, &dev1.PPM.CF_TIA1, cfSelected);
}

void AFE_set_LED_DC_EN_TIA(uint8_t PhNo, enum TIA_NO tiaSelected, bool state){
    AFE_modifyRegPPM((uint8_t)PhNo+tiaSelected, &dev1.PPM.LED_DC_EN_TIA1, state);
}

void AFE_set_ENABLE_DRE(uint8_t PhNo, bool state){
     AFE_modifyRegPPM(PhNo, &dev1.PPM.ENABLE_DRE, state);
}

void AFE_configTIA(uint8_t PhNo, enum TIA_NO tiaSelected, enum IN_TIA pdSelected, enum RF_TIA rfSelected, enum REG_TWLED ledOn_inuS,  enum LED_DC_CancellationScheme LED_DC_cnclSelected){
   
    uint8_t phaseIndex = 0;
    uint32_t invMaskPattern = 0;
    phaseIndex = (PhNo - 32)>>3 ;        // Gives 0, 1, 2,.. for Phase1, Phase2, Phase3 respectively. 
    invMaskPattern = (uint32_t)(1<<phaseIndex);

    AFE_set_IN_TIA(PhNo, tiaSelected, pdSelected,PD_DISCONNECT,PD_DISCONNECT);
    AFE_set_RF_TIA(PhNo, tiaSelected, rfSelected);
    AFE_set_CF_TIA(PhNo, tiaSelected, AFE_compute_CF(ledOn_inuS,rfSelected));

 
     switch (LED_DC_cnclSelected)
   {
        case LED_cancelWithDRE:
            enableBitsDRE = (enableBitsDRE & (~(invMaskPattern))) + (invMaskPattern); 
            AFE_set_LED_DC_EN_TIA(PhNo, tiaSelected, true);          
            if (selectedPhaseTimingScheme == HIGH_PRF_MODE){
                errorFlags = (errorFlags & 0xFFFFFFFB) + (4);
                AFE_set_ENABLE_DRE(PhNo,  false);
                enableBitsDRE = (enableBitsDRE & (~(invMaskPattern))); 
            }
            else
                AFE_set_ENABLE_DRE(PhNo,  true);
        break;

        case LED_cancelWithoutDRE:
            AFE_set_LED_DC_EN_TIA(PhNo, tiaSelected, true);
            AFE_set_ENABLE_DRE(PhNo,  false);
        break;
    
        default:
            AFE_set_LED_DC_EN_TIA(PhNo, tiaSelected, false);
            AFE_set_ENABLE_DRE(PhNo,  false);
        break;
   }
}


void AFE_config_AMBCancellation(uint8_t PhNo, enum AMB_CancellationScheme aacmType){
    switch (aacmType)
    {
    case AMB_estimateAndCancel:
         AFE_modifyRegPPM(PhNo, &dev1.PPM.UPDATE_BASELINE_AMB, true);
         AFE_modifyRegPPM(PhNo, &dev1.PPM.USE_ANA_AACM, true);  
        break;

    case AMB_cancel:
         AFE_modifyRegPPM(PhNo, &dev1.PPM.UPDATE_BASELINE_AMB, false);
         AFE_modifyRegPPM(PhNo, &dev1.PPM.USE_ANA_AACM, true);  
        break;
    
    default:
        AFE_modifyRegPPM(PhNo, &dev1.PPM.UPDATE_BASELINE_AMB, false);
        AFE_modifyRegPPM(PhNo, &dev1.PPM.USE_ANA_AACM, false);
        break;
    }
   
}

void AFE_set_INT_MUX_ADC_RDY(enum INT_MUX_ADC_RDY intOnADC_RDY){

    AFE_modifyRegGlobal(&dev1.GLOBAL.INT_MUX_ADC_RDY,          intOnADC_RDY);


}

int AFE_compute_CF(enum REG_TWLED ledOn_inuS,enum RF_TIA rfSelected ){

    int rfIndex = (int)rfSelected;
    if ( (ledOn_inuS==LED_ON_16uS) | (ledOn_inuS==LED_ON_39uS) | (ledOn_inuS==LED_ON_47uS) | (ledOn_inuS==LED_ON_63uS) | (ledOn_inuS==LED_ON_70uS) )
        if (rfSelected>7)     
            return CF_Array1[rfIndex - 8];
        else 
            return CF_25pF;

    else if ( (ledOn_inuS==LED_ON_24uS))
        if (rfSelected>9)  
            return CF_Array2[rfIndex - 10];
        else 
            return CF_25pF;

    else if ( (ledOn_inuS==LED_ON_31uS) | (ledOn_inuS==LED_ON_78uS) | (ledOn_inuS==LED_ON_94uS) | (ledOn_inuS==LED_ON_102uS) | (ledOn_inuS==LED_ON_117uS) )
        if (rfSelected>10)  
            return CF_Array3[rfIndex - 11];
        else 
            return CF_25pF;

    else
        return CF_25pF;

}

void AFE_set_phaseType(uint8_t PhNo, enum phaseType selectedPhaseType , enum LED_DRV_TXN txnDrv1, enum LED_DRV_TXN txnDrv2 ){

    switch (selectedPhaseTimingScheme)
    {
    case MAX_AMB_REJ:
        AFE_set_AUTO_AMB_INSERT(PhNo, NONE); // in MAX AMB REJ mode, pre and post AMB are automatically inserted.
        if (selectedPhaseType == explicitLED){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
        }
        else{
            AFE_set_LED_DRVx_TXN(   PhNo, AMB_PH, AMB_PH);
            errorFlags = (errorFlags & 0xFFFFFFFD) + (2);
        }
        break;
    case HIGH_PRF_MODE:
        if (selectedPhaseType == explicitLED){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, NONE);
        }
        else if (selectedPhaseType == LED_WithPreAMB){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, PRE_AMB);
        }
        else if (selectedPhaseType == explicitAMB){         
            AFE_set_LED_DRVx_TXN(   PhNo, AMB_PH, AMB_PH);
            AFE_set_AUTO_AMB_INSERT(PhNo, NONE);
        }
        else{
            errorFlags = (errorFlags & 0xFFFFFFFD) + (2);
            AFE_set_LED_DRVx_TXN(   PhNo, AMB_PH, AMB_PH);
            AFE_set_AUTO_AMB_INSERT(PhNo, NONE);
        }
        break;
    
    default: // Stagger mode
        if (selectedPhaseType == explicitLED){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, NONE);
        }
        else if (selectedPhaseType == LED_WithPreAMB){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, PRE_AMB);
        }
        else if (selectedPhaseType == LED_WithPreAndPostAMB){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, PRE_AND_POST_AMB);
        }
        else if (selectedPhaseType == LED_WithPostAMB){
            AFE_set_LED_DRVx_TXN(   PhNo, txnDrv1, txnDrv2);
            AFE_set_AUTO_AMB_INSERT(PhNo, POST_AMB);
        }
        else{
            AFE_set_LED_DRVx_TXN(   PhNo, AMB_PH, AMB_PH);
            AFE_set_AUTO_AMB_INSERT(PhNo, NONE);
        }
        break;
    }
}

void AFE_initializeAFE(){
    // For test set to 25 mA
    AFE_set_ILED_FS(ILED_FS_25mA);
    // AFE_set_ILED_FS(ILED_FS_167mA);
    AFE_modifyRegGlobal(&dev1.GLOBAL.REG_RECONV_THR_LED_DC, RECONV_THR_0p8V);
    AFE_modifyRegGlobal(&dev1.GLOBAL.EN_TIA_RST, true);
    AFE_modifyRegGlobal(&dev1.GLOBAL.POL_IOFFDAC_AMB, true);
    AFE_modifyRegGlobal(&dev1.GLOBAL.POL_IOFFDAC_LED, true);
    AFE_modifyRegGlobal(&dev1.GLOBAL.FIFO_EN, true);
    AFE_set_INT_MUX_ADC_RDY(FIFO_RDY);
    AFE_modifyRegGlobal(&dev1.GLOBAL.EN_LED_OFFDAC_TIA1, true);
    AFE_modifyRegGlobal(&dev1.GLOBAL.SET_OSCH_4M_1, true);      // Must write 1
    AFE_modifyRegGlobal(&dev1.GLOBAL.SET_OSCH_4M_2, true);      // Must write 1
    AFE_modifyRegGlobal(&dev1.GLOBAL.SET_OSCH_4M_3, true);      // Must write 1
    AFE_modifyRegGlobal(&dev1.GLOBAL.Always1, true);      // Must write 1
    if (maxNoTIA>1)
        AFE_modifyRegGlobal(&dev1.GLOBAL.EN_LED_OFFDAC_TIA2, true);
        
    AFE_modifyRegGlobal(&dev1.GLOBAL.IFS_AMB_OFFDAC_TIA1, AMB_DAC_FS_selected);
    AFE_modifyRegGlobal(&dev1.GLOBAL.IFS_AMB_OFFDAC_TIA2, AMB_DAC_FS_selected);
    
    if (AMB_DAC_FS_selected>2){ // For 4X, 8X and 16X modes
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_START_TIA1, 0);
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_START_TIA2, 0);
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_END, 5);
    }
    else{   // For 1X and 2X modes
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_START_TIA1, 6);
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_START_TIA2, 6);
        AFE_modifyRegGlobal(&dev1.GLOBAL.RF_ANA_AACM_END, 10);
    }

}

void AFE_set_REG_SCALE_DRE(enum RF_TIA rfSelected){
    if (rfSelected>11) // For RF = 500K and 1M
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_SCALE_DRE, 6);
    else if (rfSelected>7) // For RF = 142K to 250K
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_SCALE_DRE, 5);
    else if (rfSelected>5) // For RF = 71.5K to 100K
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_SCALE_DRE, 4);
    else if (rfSelected>3) // For RF = 33.3K to 50K
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_SCALE_DRE, 3);
    else
        AFE_modifyRegGlobal(&dev1.GLOBAL.REG_SCALE_DRE, 2);
}






/*

void AFE_set_(bool state){

    AFE_modifyRegGlobal(&dev1.GLOBAL., state);
}

void AFE_config_(){

    switch (expression)
    {
    case :
        
        break;
    
    default:
        break;
    }
    
}


*/


//end

