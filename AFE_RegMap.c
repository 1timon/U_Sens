/** @file AFE_RegMap.c
 *  @brief Register map definitaion of AFE4432
 *
 *         This file contains the definition for the AFE4432's parameter.
 *         Each AFE parameter's attributes ( address, page, msb bit and lsb bit) is defined here.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#include"AFE_RegMap.h"
#include<stdio.h>


volatile uint16_t lastRegAddress;
volatile uint32_t lastRegValue;

void AFE_assignRegMap (AFE_RegMap* AFE){

    lastRegAddress = 0;
    lastRegValue = 0;

    AFE->GLOBAL.SPI_REG_READ.address = 0; 
    AFE->GLOBAL.SPI_REG_READ.msb = 0; 
    AFE->GLOBAL.SPI_REG_READ.lsb = 0; 
    AFE->GLOBAL.SW_RESET.address = 0; 
    AFE->GLOBAL.SW_RESET.msb = 3; 
    AFE->GLOBAL.SW_RESET.lsb = 3; 
    AFE->GLOBAL.RW_CONT.address = 0; 
    AFE->GLOBAL.RW_CONT.msb = 4; 
    AFE->GLOBAL.RW_CONT.lsb = 4; 
    AFE->GLOBAL.PAGE_SEL.address = 1; 
    AFE->GLOBAL.PAGE_SEL.msb = 0; 
    AFE->GLOBAL.PAGE_SEL.lsb = 0; 
    AFE->GLOBAL.TM_COUNT_RST.address = 1; 
    AFE->GLOBAL.TM_COUNT_RST.msb = 1; 
    AFE->GLOBAL.TM_COUNT_RST.lsb = 1; 
    AFE->GLOBAL.FIFO_EN.address = 1; 
    AFE->GLOBAL.FIFO_EN.msb = 6; 
    AFE->GLOBAL.FIFO_EN.lsb = 6; 
    AFE->GLOBAL.EN_LED_SAT_DET.address = 1; 
    AFE->GLOBAL.EN_LED_SAT_DET.msb = 7; 
    AFE->GLOBAL.EN_LED_SAT_DET.lsb = 7; 
    AFE->GLOBAL.MASK_REVERSE.address = 1; 
    AFE->GLOBAL.MASK_REVERSE.msb = 9; 
    AFE->GLOBAL.MASK_REVERSE.lsb = 9; 
    AFE->GLOBAL.HIGH_PRF_MODE.address = 1; 
    AFE->GLOBAL.HIGH_PRF_MODE.msb = 10; 
    AFE->GLOBAL.HIGH_PRF_MODE.lsb = 10; 
    AFE->GLOBAL.MAX_AMB_REJ.address = 1; 
    AFE->GLOBAL.MAX_AMB_REJ.msb = 11; 
    AFE->GLOBAL.MAX_AMB_REJ.lsb = 11; 
    AFE->GLOBAL.DIS_POST_AMB_MAX_AMB_REJ.address = 1; 
    AFE->GLOBAL.DIS_POST_AMB_MAX_AMB_REJ.msb = 13; 
    AFE->GLOBAL.DIS_POST_AMB_MAX_AMB_REJ.lsb = 13; 
    AFE->GLOBAL.POL_IOFFDAC_LED.address = 5; 
    AFE->GLOBAL.POL_IOFFDAC_LED.msb = 0; 
    AFE->GLOBAL.POL_IOFFDAC_LED.lsb = 0; 
    AFE->GLOBAL.POL_IOFFDAC_AMB.address = 5; 
    AFE->GLOBAL.POL_IOFFDAC_AMB.msb = 1; 
    AFE->GLOBAL.POL_IOFFDAC_AMB.lsb = 1; 
    AFE->GLOBAL.SWAP_DAC.address = 5; 
    AFE->GLOBAL.SWAP_DAC.msb = 2; 
    AFE->GLOBAL.SWAP_DAC.lsb = 2; 
    AFE->GLOBAL.EN_LED_OFFDAC_CHOP.address = 5; 
    AFE->GLOBAL.EN_LED_OFFDAC_CHOP.msb = 3; 
    AFE->GLOBAL.EN_LED_OFFDAC_CHOP.lsb = 3; 
    AFE->GLOBAL.EN_TIA_RST.address = 5; 
    AFE->GLOBAL.EN_TIA_RST.msb = 16; 
    AFE->GLOBAL.EN_TIA_RST.lsb = 16; 
    AFE->GLOBAL.IOFFDAC_PD1.address = 6; 
    AFE->GLOBAL.IOFFDAC_PD1.msb = 8; 
    AFE->GLOBAL.IOFFDAC_PD1.lsb = 0; 
    AFE->GLOBAL.IOFFDAC_PD2.address = 6; 
    AFE->GLOBAL.IOFFDAC_PD2.msb = 17; 
    AFE->GLOBAL.IOFFDAC_PD2.lsb = 9; 
    AFE->GLOBAL.REG_NUM_TIA_MAX.address = 6; 
    AFE->GLOBAL.REG_NUM_TIA_MAX.msb = 22; 
    AFE->GLOBAL.REG_NUM_TIA_MAX.lsb = 22; 
    AFE->GLOBAL.IOFFDAC_PD3.address = 7; 
    AFE->GLOBAL.IOFFDAC_PD3.msb = 8; 
    AFE->GLOBAL.IOFFDAC_PD3.lsb = 0; 
    AFE->GLOBAL.PD_DISCONNECT_TIA1.address = 7; 
    AFE->GLOBAL.PD_DISCONNECT_TIA1.msb = 20; 
    AFE->GLOBAL.PD_DISCONNECT_TIA1.lsb = 20; 
    AFE->GLOBAL.PD_DISCONNECT_TIA2.address = 7; 
    AFE->GLOBAL.PD_DISCONNECT_TIA2.msb = 21; 
    AFE->GLOBAL.PD_DISCONNECT_TIA2.lsb = 21; 
    AFE->GLOBAL.INT_MUX_ADC_RDY.address = 10; 
    AFE->GLOBAL.INT_MUX_ADC_RDY.msb = 2; 
    AFE->GLOBAL.INT_MUX_ADC_RDY.lsb = 0; 
    AFE->GLOBAL.INT_MUX_GPIO2.address = 10; 
    AFE->GLOBAL.INT_MUX_GPIO2.msb = 10; 
    AFE->GLOBAL.INT_MUX_GPIO2.lsb = 8; 
    AFE->GLOBAL.INPUT_PRF_RST_ON_GPIO2.address = 11; 
    AFE->GLOBAL.INPUT_PRF_RST_ON_GPIO2.msb = 14; 
    AFE->GLOBAL.INPUT_PRF_RST_ON_GPIO2.lsb = 14; 
    AFE->GLOBAL.PROG_INT2_STC.address = 14; 
    AFE->GLOBAL.PROG_INT2_STC.msb = 15; 
    AFE->GLOBAL.PROG_INT2_STC.lsb = 0; 
    AFE->GLOBAL.PROG_INT2_ENDC.address = 15; 
    AFE->GLOBAL.PROG_INT2_ENDC.msb = 15; 
    AFE->GLOBAL.PROG_INT2_ENDC.lsb = 0; 
    AFE->GLOBAL.SEL1_CLK_TE.address = 28; 
    AFE->GLOBAL.SEL1_CLK_TE.msb = 0; 
    AFE->GLOBAL.SEL1_CLK_TE.lsb = 0; 
    AFE->GLOBAL.OSCL_DIS.address = 28; 
    AFE->GLOBAL.OSCL_DIS.msb = 1; 
    AFE->GLOBAL.OSCL_DIS.lsb = 1; 
    AFE->GLOBAL.PDN_OSCL_IN_DEEP_SLEEP.address = 28; 
    AFE->GLOBAL.PDN_OSCL_IN_DEEP_SLEEP.msb = 2; 
    AFE->GLOBAL.PDN_OSCL_IN_DEEP_SLEEP.lsb = 2; 
    AFE->GLOBAL.EN_PRF_RESET.address = 28; 
    AFE->GLOBAL.EN_PRF_RESET.msb = 3; 
    AFE->GLOBAL.EN_PRF_RESET.lsb = 3; 
    AFE->GLOBAL.SEL1_CLK_PRF.address = 28; 
    AFE->GLOBAL.SEL1_CLK_PRF.msb = 4; 
    AFE->GLOBAL.SEL1_CLK_PRF.lsb = 4; 
    AFE->GLOBAL.DIV_CLK_EXT.address = 28; 
    AFE->GLOBAL.DIV_CLK_EXT.msb = 7; 
    AFE->GLOBAL.DIV_CLK_EXT.lsb = 5; 
    AFE->GLOBAL.EN_INT_IN_SINGLE_SHOT.address = 28; 
    AFE->GLOBAL.EN_INT_IN_SINGLE_SHOT.msb = 10; 
    AFE->GLOBAL.EN_INT_IN_SINGLE_SHOT.lsb = 10; 
    AFE->GLOBAL.EN_CLK_MODE_MIX.address = 28; 
    AFE->GLOBAL.EN_CLK_MODE_MIX.msb = 11; 
    AFE->GLOBAL.EN_CLK_MODE_MIX.lsb = 11; 
    AFE->GLOBAL.SET_OSCH_4M_1.address = 28; 
    AFE->GLOBAL.SET_OSCH_4M_1.msb = 15; 
    AFE->GLOBAL.SET_OSCH_4M_1.lsb = 15; 
    AFE->GLOBAL.PRPCT.address = 29; 
    AFE->GLOBAL.PRPCT.msb = 16; 
    AFE->GLOBAL.PRPCT.lsb = 0; 
    AFE->GLOBAL.REG_NUMPHASE.address = 29; 
    AFE->GLOBAL.REG_NUMPHASE.msb = 20; 
    AFE->GLOBAL.REG_NUMPHASE.lsb = 17; 
    AFE->GLOBAL.PRF_COUNTER_ENABLE.address = 29; 
    AFE->GLOBAL.PRF_COUNTER_ENABLE.msb = 22; 
    AFE->GLOBAL.PRF_COUNTER_ENABLE.lsb = 22; 
    AFE->GLOBAL.TIMER_ENABLE.address = 29; 
    AFE->GLOBAL.TIMER_ENABLE.msb = 23; 
    AFE->GLOBAL.TIMER_ENABLE.lsb = 23; 
    AFE->GLOBAL.PDNAFE.address = 35; 
    AFE->GLOBAL.PDNAFE.msb = 0; 
    AFE->GLOBAL.PDNAFE.lsb = 0; 
    AFE->GLOBAL.EN_AMB_DAC_LSB.address = 35; 
    AFE->GLOBAL.EN_AMB_DAC_LSB.msb = 15; 
    AFE->GLOBAL.EN_AMB_DAC_LSB.lsb = 15; 
    AFE->GLOBAL.ILED_FS.address = 35; 
    AFE->GLOBAL.ILED_FS.msb = 18; 
    AFE->GLOBAL.ILED_FS.lsb = 16; 
    AFE->GLOBAL.SET_OSCH_4M_3.address = 36; 
    AFE->GLOBAL.SET_OSCH_4M_3.msb = 7; 
    AFE->GLOBAL.SET_OSCH_4M_3.lsb = 7; 
    AFE->GLOBAL.SET_OSCH_4M_2.address = 36; 
    AFE->GLOBAL.SET_OSCH_4M_2.msb = 9; 
    AFE->GLOBAL.SET_OSCH_4M_2.lsb = 9; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA1.address = 36; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA1.msb = 13; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA1.lsb = 13; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA2.address = 36; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA2.msb = 14; 
    AFE->GLOBAL.EN_LED_OFFDAC_TIA2.lsb = 14; 
    AFE->GLOBAL.DESIGN_ID.address = 40; 
    AFE->GLOBAL.DESIGN_ID.msb = 19; 
    AFE->GLOBAL.DESIGN_ID.lsb = 0; 
    AFE->GLOBAL.SDOUT_TRISTATE.address = 41; 
    AFE->GLOBAL.SDOUT_TRISTATE.msb = 10; 
    AFE->GLOBAL.SDOUT_TRISTATE.lsb = 10; 
    AFE->GLOBAL.EN_GPIO2_OUT.address = 41; 
    AFE->GLOBAL.EN_GPIO2_OUT.msb = 19; 
    AFE->GLOBAL.EN_GPIO2_OUT.lsb = 19; 
    AFE->GLOBAL.EN_GPIO2_INT_ON_ADC_RDY.address = 41; 
    AFE->GLOBAL.EN_GPIO2_INT_ON_ADC_RDY.msb = 23; 
    AFE->GLOBAL.EN_GPIO2_INT_ON_ADC_RDY.lsb = 23; 
    AFE->GLOBAL.EN_GPIO2_IN.address = 49; 
    AFE->GLOBAL.EN_GPIO2_IN.msb = 14; 
    AFE->GLOBAL.EN_GPIO2_IN.lsb = 14; 
    AFE->GLOBAL.REG_WM_FIFO.address = 66; 
    AFE->GLOBAL.REG_WM_FIFO.msb = 7; 
    AFE->GLOBAL.REG_WM_FIFO.lsb = 0; 
    AFE->GLOBAL.FIFO_OFFSET_TO_FORCE.address = 66; 
    AFE->GLOBAL.FIFO_OFFSET_TO_FORCE.msb = 20; 
    AFE->GLOBAL.FIFO_OFFSET_TO_FORCE.lsb = 13; 
    AFE->GLOBAL.FORCE_FIFO_OFFSET.address = 66; 
    AFE->GLOBAL.FORCE_FIFO_OFFSET.msb = 21; 
    AFE->GLOBAL.FORCE_FIFO_OFFSET.lsb = 21; 
    AFE->GLOBAL.MASK_FIFO_RDY.address = 66; 
    AFE->GLOBAL.MASK_FIFO_RDY.msb = 22; 
    AFE->GLOBAL.MASK_FIFO_RDY.lsb = 22; 
    AFE->GLOBAL.AUTO_MASK_FIFO_RDY.address = 66; 
    AFE->GLOBAL.AUTO_MASK_FIFO_RDY.msb = 23; 
    AFE->GLOBAL.AUTO_MASK_FIFO_RDY.lsb = 23; 
    AFE->GLOBAL.LED_OFFDAC_MARKER_ON_LSB.address = 67; 
    AFE->GLOBAL.LED_OFFDAC_MARKER_ON_LSB.msb = 0; 
    AFE->GLOBAL.LED_OFFDAC_MARKER_ON_LSB.lsb = 0; 
    AFE->GLOBAL.EN_LED_OFFDAC_MARKER.address = 67; 
    AFE->GLOBAL.EN_LED_OFFDAC_MARKER.msb = 1; 
    AFE->GLOBAL.EN_LED_OFFDAC_MARKER.lsb = 1; 
    AFE->GLOBAL.FRAME_SYNC_ON_LSB.address = 67; 
    AFE->GLOBAL.FRAME_SYNC_ON_LSB.msb = 2; 
    AFE->GLOBAL.FRAME_SYNC_ON_LSB.lsb = 2; 
    AFE->GLOBAL.EN_FRAME_SYNC.address = 67; 
    AFE->GLOBAL.EN_FRAME_SYNC.msb = 3; 
    AFE->GLOBAL.EN_FRAME_SYNC.lsb = 3; 
    AFE->GLOBAL.REG_POINTER_DIFF.address = 68; 
    AFE->GLOBAL.REG_POINTER_DIFF.msb = 7; 
    AFE->GLOBAL.REG_POINTER_DIFF.lsb = 0; 
    AFE->GLOBAL.FIFO_OVERFLOW.address = 68; 
    AFE->GLOBAL.FIFO_OVERFLOW.msb = 10; 
    AFE->GLOBAL.FIFO_OVERFLOW.lsb = 10; 
    AFE->GLOBAL.EN_OSCL_CLKOUT.address = 75; 
    AFE->GLOBAL.EN_OSCL_CLKOUT.msb = 22; 
    AFE->GLOBAL.EN_OSCL_CLKOUT.lsb = 22; 
    AFE->GLOBAL.SPLIT_CLK_FOR_TE_PRF.address = 80; 
    AFE->GLOBAL.SPLIT_CLK_FOR_TE_PRF.msb = 16; 
    AFE->GLOBAL.SPLIT_CLK_FOR_TE_PRF.lsb = 16; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA1.address = 115; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA1.msb = 4; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA1.lsb = 2; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA2.address = 115; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA2.msb = 7; 
    AFE->GLOBAL.IFS_AMB_OFFDAC_TIA2.lsb = 5; 
    AFE->GLOBAL.PDN_BG_IN_DEEP_SLEEP.address = 116; 
    AFE->GLOBAL.PDN_BG_IN_DEEP_SLEEP.msb = 1; 
    AFE->GLOBAL.PDN_BG_IN_DEEP_SLEEP.lsb = 1; 
    AFE->GLOBAL.TX_AMP_ALWAYS_ACTIVE.address = 116; 
    AFE->GLOBAL.TX_AMP_ALWAYS_ACTIVE.msb = 5; 
    AFE->GLOBAL.TX_AMP_ALWAYS_ACTIVE.lsb = 5; 
    AFE->GLOBAL.DEGLITCH_AMB_DAC_MODE.address = 116; 
    AFE->GLOBAL.DEGLITCH_AMB_DAC_MODE.msb = 9; 
    AFE->GLOBAL.DEGLITCH_AMB_DAC_MODE.lsb = 9; 
    AFE->GLOBAL.FILTER_BW_FINE_SET1.address = 120; 
    AFE->GLOBAL.FILTER_BW_FINE_SET1.msb = 5; 
    AFE->GLOBAL.FILTER_BW_FINE_SET1.lsb = 0; 
    AFE->GLOBAL.FILTER_BW_PRE_SET1.address = 120; 
    AFE->GLOBAL.FILTER_BW_PRE_SET1.msb = 13; 
    AFE->GLOBAL.FILTER_BW_PRE_SET1.lsb = 8; 
    AFE->GLOBAL.OVERRIDE_BW_PRE.address = 120; 
    AFE->GLOBAL.OVERRIDE_BW_PRE.msb = 23; 
    AFE->GLOBAL.OVERRIDE_BW_PRE.lsb = 23; 
    AFE->GLOBAL.FILTER_BW_FINE_SET2.address = 121; 
    AFE->GLOBAL.FILTER_BW_FINE_SET2.msb = 5; 
    AFE->GLOBAL.FILTER_BW_FINE_SET2.lsb = 0; 
    AFE->GLOBAL.FILTER_BW_PRE_SET2.address = 121; 
    AFE->GLOBAL.FILTER_BW_PRE_SET2.msb = 13; 
    AFE->GLOBAL.FILTER_BW_PRE_SET2.lsb = 8; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE1.address = 128; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE1.msb = 11; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE1.lsb = 0; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE1.address = 128; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE1.msb = 23; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE1.lsb = 12; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE2.address = 129; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE2.msb = 11; 
    AFE->GLOBAL.LOW_THRESHOLD_CODE2.lsb = 0; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE2.address = 129; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE2.msb = 23; 
    AFE->GLOBAL.HIGH_THRESHOLD_CODE2.lsb = 12; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET1.address = 131; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET1.msb = 11; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET1.lsb = 0; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET2.address = 131; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET2.msb = 23; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET2.lsb = 12; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET3.address = 132; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET3.msb = 11; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET3.lsb = 0; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET4.address = 132; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET4.msb = 23; 
    AFE->GLOBAL.REG_SAMPLE_DELAY_SET4.lsb = 12; 
    AFE->GLOBAL.EN_PHASE_INT_GPIO.address = 136; 
    AFE->GLOBAL.EN_PHASE_INT_GPIO.msb = 8; 
    AFE->GLOBAL.EN_PHASE_INT_GPIO.lsb = 8; 
    AFE->GLOBAL.REG_TSEP_CONV_START.address = 137; 
    AFE->GLOBAL.REG_TSEP_CONV_START.msb = 2; 
    AFE->GLOBAL.REG_TSEP_CONV_START.lsb = 0; 
    AFE->GLOBAL.REG_TSAMP_SEP.address = 137; 
    AFE->GLOBAL.REG_TSAMP_SEP.msb = 6; 
    AFE->GLOBAL.REG_TSAMP_SEP.lsb = 4; 
    AFE->GLOBAL.Always1.address = 137; 
    AFE->GLOBAL.Always1.msb = 8; 
    AFE->GLOBAL.Always1.lsb = 8; 
    AFE->GLOBAL.EARLY_SAMP_FALL.address = 137; 
    AFE->GLOBAL.EARLY_SAMP_FALL.msb = 18; 
    AFE->GLOBAL.EARLY_SAMP_FALL.lsb = 18; 
    AFE->GLOBAL.REG_TSEP.address = 137; 
    AFE->GLOBAL.REG_TSEP.msb = 21; 
    AFE->GLOBAL.REG_TSEP.lsb = 19; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWRUP.address = 138; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWRUP.msb = 9; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWRUP.lsb = 0; 
    AFE->GLOBAL.REG_TACTIVE_PWRUP.address = 138; 
    AFE->GLOBAL.REG_TACTIVE_PWRUP.msb = 21; 
    AFE->GLOBAL.REG_TACTIVE_PWRUP.lsb = 12; 
    AFE->GLOBAL.REG_TACTIVE_DATA_RDY.address = 141; 
    AFE->GLOBAL.REG_TACTIVE_DATA_RDY.msb = 7; 
    AFE->GLOBAL.REG_TACTIVE_DATA_RDY.lsb = 0; 
    AFE->GLOBAL.REG_TW_DATA_RDY.address = 141; 
    AFE->GLOBAL.REG_TW_DATA_RDY.msb = 19; 
    AFE->GLOBAL.REG_TW_DATA_RDY.lsb = 16; 
    AFE->GLOBAL.REG_TACTIVE_PWDN.address = 142; 
    AFE->GLOBAL.REG_TACTIVE_PWDN.msb = 8; 
    AFE->GLOBAL.REG_TACTIVE_PWDN.lsb = 0; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWDN.address = 142; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWDN.msb = 20; 
    AFE->GLOBAL.REG_TDEEP_SLEEP_PWDN.lsb = 12; 
    AFE->GLOBAL.REG_STEP_COUNT.address = 146; 
    AFE->GLOBAL.REG_STEP_COUNT.msb = 18; 
    AFE->GLOBAL.REG_STEP_COUNT.lsb = 12; 
    AFE->GLOBAL.REG_TW_FILTER_PRE.address = 148; 
    AFE->GLOBAL.REG_TW_FILTER_PRE.msb = 7; 
    AFE->GLOBAL.REG_TW_FILTER_PRE.lsb = 0; 
    AFE->GLOBAL.RF_ANA_AACM_END.address = 149; 
    AFE->GLOBAL.RF_ANA_AACM_END.msb = 7; 
    AFE->GLOBAL.RF_ANA_AACM_END.lsb = 4; 
    AFE->GLOBAL.REG_DELAY_ANA_ACQ.address = 149; 
    AFE->GLOBAL.REG_DELAY_ANA_ACQ.msb = 11; 
    AFE->GLOBAL.REG_DELAY_ANA_ACQ.lsb = 8; 
    AFE->GLOBAL.REG_TW_ANA_ACQ.address = 149; 
    AFE->GLOBAL.REG_TW_ANA_ACQ.msb = 15; 
    AFE->GLOBAL.REG_TW_ANA_ACQ.lsb = 12; 
    AFE->GLOBAL.REG_TSEP_ANA_ACQ_LED.address = 149; 
    AFE->GLOBAL.REG_TSEP_ANA_ACQ_LED.msb = 19; 
    AFE->GLOBAL.REG_TSEP_ANA_ACQ_LED.lsb = 16; 
    AFE->GLOBAL.TW_ANA_ACQ_OVERRIDE.address = 149; 
    AFE->GLOBAL.TW_ANA_ACQ_OVERRIDE.msb = 20; 
    AFE->GLOBAL.TW_ANA_ACQ_OVERRIDE.lsb = 20; 
    AFE->GLOBAL.TSEP_ANA_ACQ_LED_OVERRIDE.address = 149; 
    AFE->GLOBAL.TSEP_ANA_ACQ_LED_OVERRIDE.msb = 21; 
    AFE->GLOBAL.TSEP_ANA_ACQ_LED_OVERRIDE.lsb = 21; 
    AFE->GLOBAL.EMBED_ANA_AACM_IN_FIFO.address = 149; 
    AFE->GLOBAL.EMBED_ANA_AACM_IN_FIFO.msb = 23; 
    AFE->GLOBAL.EMBED_ANA_AACM_IN_FIFO.lsb = 23; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA1.address = 150; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA1.msb = 3; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA1.lsb = 0; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA2.address = 150; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA2.msb = 7; 
    AFE->GLOBAL.RF_ANA_AACM_START_TIA2.lsb = 4; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA1.address = 151; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA1.msb = 11; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA1.lsb = 0; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA2.address = 151; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA2.msb = 23; 
    AFE->GLOBAL.CHANNEL_OFFSET_TIA2.lsb = 12; 
    AFE->GLOBAL.REG_RECONV_THR_LED_DC.address = 154; 
    AFE->GLOBAL.REG_RECONV_THR_LED_DC.msb = 7; 
    AFE->GLOBAL.REG_RECONV_THR_LED_DC.lsb = 0; 
    AFE->GLOBAL.IOFFDAC_LED_DC_READ.address = 155; 
    AFE->GLOBAL.IOFFDAC_LED_DC_READ.msb = 8; 
    AFE->GLOBAL.IOFFDAC_LED_DC_READ.lsb = 0; 
    AFE->GLOBAL.POL_LED_DC_READ.address = 155; 
    AFE->GLOBAL.POL_LED_DC_READ.msb = 9; 
    AFE->GLOBAL.POL_LED_DC_READ.lsb = 9; 
    AFE->GLOBAL.LED_DC_LOOP_NUM_READ.address = 155; 
    AFE->GLOBAL.LED_DC_LOOP_NUM_READ.msb = 12; 
    AFE->GLOBAL.LED_DC_LOOP_NUM_READ.lsb = 10; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP0.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP0.msb = 0; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP0.lsb = 0; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP1.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP1.msb = 1; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP1.lsb = 1; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP2.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP2.msb = 2; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP2.lsb = 2; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP3.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP3.msb = 3; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP3.lsb = 3; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP4.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP4.msb = 4; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP4.lsb = 4; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP5.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP5.msb = 5; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP5.lsb = 5; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP6.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP6.msb = 6; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP6.lsb = 6; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP7.address = 156; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP7.msb = 7; 
    AFE->GLOBAL.FREEZE_LED_DC_LOOP7.lsb = 7; 
    AFE->GLOBAL.REG_SCALE_DRE.address = 158; 
    AFE->GLOBAL.REG_SCALE_DRE.msb = 2; 
    AFE->GLOBAL.REG_SCALE_DRE.lsb = 0; 
    AFE->GLOBAL.USE_MSB_FOR_DRE.address = 158; 
    AFE->GLOBAL.USE_MSB_FOR_DRE.msb = 3; 
    AFE->GLOBAL.USE_MSB_FOR_DRE.lsb = 3; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_142K.address = 159; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_142K.msb = 10; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_142K.lsb = 0; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_166K.address = 160; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_166K.msb = 10; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_166K.lsb = 0; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_200K.address = 161; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_200K.msb = 10; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_200K.lsb = 0; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_250K.address = 162; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_250K.msb = 10; 
    AFE->GLOBAL.GAIN_CALIB_LED_DC_250K.lsb = 0; 
    AFE->GLOBAL.THR_DET_EN.address = 180; 
    AFE->GLOBAL.THR_DET_EN.msb = 0; 
    AFE->GLOBAL.THR_DET_EN.lsb = 0; 
    AFE->GLOBAL.THR_SEL_LOGIC.address = 180; 
    AFE->GLOBAL.THR_SEL_LOGIC.msb = 2; 
    AFE->GLOBAL.THR_SEL_LOGIC.lsb = 1; 
    AFE->GLOBAL.REG_THR_DET_PHASE.address = 180; 
    AFE->GLOBAL.REG_THR_DET_PHASE.msb = 8; 
    AFE->GLOBAL.REG_THR_DET_PHASE.lsb = 4; 
    AFE->GLOBAL.COMB_THR_DET_EN.address = 180; 
    AFE->GLOBAL.COMB_THR_DET_EN.msb = 23; 
    AFE->GLOBAL.COMB_THR_DET_EN.lsb = 23; 
    AFE->GLOBAL.THR_PPG_FLAG.address = 181; 
    AFE->GLOBAL.THR_PPG_FLAG.msb = 11; 
    AFE->GLOBAL.THR_PPG_FLAG.lsb = 0; 
    AFE->GLOBAL.DIS_DEEP_SLEEP.address = 202; 
    AFE->GLOBAL.DIS_DEEP_SLEEP.msb = 13; 
    AFE->GLOBAL.DIS_DEEP_SLEEP.lsb = 13; 
    AFE->GLOBAL.EN_ALWAYS_ACTIVE.address = 202; 
    AFE->GLOBAL.EN_ALWAYS_ACTIVE.msb = 14; 
    AFE->GLOBAL.EN_ALWAYS_ACTIVE.lsb = 14; 


    AFE->PPM.LED_DRV1_TXN.address = 0; 
    AFE->PPM.LED_DRV1_TXN.msb = 3; 
    AFE->PPM.LED_DRV1_TXN.lsb = 0; 
    AFE->PPM.LED_DRV2_TXN.address = 0; 
    AFE->PPM.LED_DRV2_TXN.msb = 11; 
    AFE->PPM.LED_DRV2_TXN.lsb = 8; 
    AFE->PPM.THR_SEL_TIA_NUM.address = 0; 
    AFE->PPM.THR_SEL_TIA_NUM.msb = 17; 
    AFE->PPM.THR_SEL_TIA_NUM.lsb = 17; 
    AFE->PPM.THR_SEL.address = 0; 
    AFE->PPM.THR_SEL.msb = 19; 
    AFE->PPM.THR_SEL.lsb = 19; 
    AFE->PPM.THR_SEL_DATA_CTRL.address = 0; 
    AFE->PPM.THR_SEL_DATA_CTRL.msb = 21; 
    AFE->PPM.THR_SEL_DATA_CTRL.lsb = 20; 
    AFE->PPM.PHASE_INT_GPIO2.address = 0; 
    AFE->PPM.PHASE_INT_GPIO2.msb = 23; 
    AFE->PPM.PHASE_INT_GPIO2.lsb = 23; 
    AFE->PPM.ILED_DRV1.address = 1; 
    AFE->PPM.ILED_DRV1.msb = 7; 
    AFE->PPM.ILED_DRV1.lsb = 0; 
    AFE->PPM.ILED_DRV2.address = 1; 
    AFE->PPM.ILED_DRV2.msb = 15; 
    AFE->PPM.ILED_DRV2.lsb = 8; 
    AFE->PPM.REG_TWLED.address = 1; 
    AFE->PPM.REG_TWLED.msb = 23; 
    AFE->PPM.REG_TWLED.lsb = 16; 
    AFE->PPM.RF_TIA1.address = 2; 
    AFE->PPM.RF_TIA1.msb = 3; 
    AFE->PPM.RF_TIA1.lsb = 0; 
    AFE->PPM.CF_TIA1.address = 2; 
    AFE->PPM.CF_TIA1.msb = 6; 
    AFE->PPM.CF_TIA1.lsb = 4; 
    AFE->PPM.IOFFDAC_LED_TIA1.address = 2; 
    AFE->PPM.IOFFDAC_LED_TIA1.msb = 15; 
    AFE->PPM.IOFFDAC_LED_TIA1.lsb = 7; 
    AFE->PPM.LED_DC_EN_TIA1.address = 2; 
    AFE->PPM.LED_DC_EN_TIA1.msb = 16; 
    AFE->PPM.LED_DC_EN_TIA1.lsb = 16; 
    AFE->PPM.IN_TIA1.address = 2; 
    AFE->PPM.IN_TIA1.msb = 19; 
    AFE->PPM.IN_TIA1.lsb = 17; 
    AFE->PPM.RF_TIA2.address = 3; 
    AFE->PPM.RF_TIA2.msb = 3; 
    AFE->PPM.RF_TIA2.lsb = 0; 
    AFE->PPM.CF_TIA2.address = 3; 
    AFE->PPM.CF_TIA2.msb = 6; 
    AFE->PPM.CF_TIA2.lsb = 4; 
    AFE->PPM.IOFFDAC_LED_TIA2.address = 3; 
    AFE->PPM.IOFFDAC_LED_TIA2.msb = 15; 
    AFE->PPM.IOFFDAC_LED_TIA2.lsb = 7; 
    AFE->PPM.LED_DC_EN_TIA2.address = 3; 
    AFE->PPM.LED_DC_EN_TIA2.msb = 16; 
    AFE->PPM.LED_DC_EN_TIA2.lsb = 16; 
    AFE->PPM.IN_TIA2.address = 3; 
    AFE->PPM.IN_TIA2.msb = 19; 
    AFE->PPM.IN_TIA2.lsb = 17; 
    AFE->PPM.UPDATE_BASELINE_AMB.address = 4; 
    AFE->PPM.UPDATE_BASELINE_AMB.msb = 0; 
    AFE->PPM.UPDATE_BASELINE_AMB.lsb = 0; 
    AFE->PPM.USE_ANA_AACM.address = 4; 
    AFE->PPM.USE_ANA_AACM.msb = 1; 
    AFE->PPM.USE_ANA_AACM.lsb = 1; 
    AFE->PPM.FILTER_SET_SEL.address = 4; 
    AFE->PPM.FILTER_SET_SEL.msb = 2; 
    AFE->PPM.FILTER_SET_SEL.lsb = 2; 
    AFE->PPM.REG_NUM_TIA.address = 4; 
    AFE->PPM.REG_NUM_TIA.msb = 3; 
    AFE->PPM.REG_NUM_TIA.lsb = 3; 
    AFE->PPM.AUTO_AMB_INSERT.address = 4; 
    AFE->PPM.AUTO_AMB_INSERT.msb = 6; 
    AFE->PPM.AUTO_AMB_INSERT.lsb = 5; 
    AFE->PPM.ENABLE_DRE.address = 4; 
    AFE->PPM.ENABLE_DRE.msb = 7; 
    AFE->PPM.ENABLE_DRE.lsb = 7; 
    AFE->PPM.REG_MASK_FACTOR.address = 4; 
    AFE->PPM.REG_MASK_FACTOR.msb = 11; 
    AFE->PPM.REG_MASK_FACTOR.lsb = 8; 
    AFE->PPM.REG_NUMAV.address = 4; 
    AFE->PPM.REG_NUMAV.msb = 15; 
    AFE->PPM.REG_NUMAV.lsb = 12; 
    AFE->PPM.FIFO_DATA_CTRL.address = 4; 
    AFE->PPM.FIFO_DATA_CTRL.msb = 18; 
    AFE->PPM.FIFO_DATA_CTRL.lsb = 16; 
    AFE->PPM.REG_DEC_FACTOR.address = 4; 
    AFE->PPM.REG_DEC_FACTOR.msb = 21; 
    AFE->PPM.REG_DEC_FACTOR.lsb = 19; 
    AFE->PPM.SEL_SAMPLE_DELAY_SET.address = 4; 
    AFE->PPM.SEL_SAMPLE_DELAY_SET.msb = 23; 
    AFE->PPM.SEL_SAMPLE_DELAY_SET.lsb = 22;  
    

}


void AFE_modifyRegGlobal(sigParameter *param, uint32_t value){

    uint32_t mask;
	uint32_t readValue;
	uint32_t writeValue;
	uint32_t regmask;
	uint8_t size;
	/// <b>Algorithm of the method is as follows</b>
	//value=(uint16_t) value; /// * Converts the input value to uint16_t

    if ((lastRegAddress & 0x300) == 0x300)  // i.e. last register written was in Page 1 and this function call is as part of AFE_modifyRegPPM
        {
            lastRegAddress = lastRegAddress & 0x1FF; // reset the D9 bit but do not chnage the page
        }
    else if ((lastRegAddress & 0x300) == 0x100)  // i.e. last register written was in Page 1 
        {
            lastRegAddress = 0;                 // as page is switched
            AFE_switchPage(0) ;                 // switch to Page 0
            
        }

    if ((lastRegAddress & 0xFF) == param->address)
        readValue   =   lastRegValue; 
    else
	    readValue   =   AFE_readReg(param->address);
	size        =   param->msb+1-param->lsb;
	mask        =   ~(((uint32_t) -1)<<(size));
	writeValue  =   value&mask;
	value       =   value>>size;
	regmask     =   (~((((uint32_t) -1)<<(param->msb+1))^(((uint32_t) -1)<<param->lsb)))&0xFFFFFFFF; /// * Masks the bits for the new value to be written
	writeValue  =   (writeValue<<param->lsb)|(readValue&regmask);/// * Creates a new register value to be written to h/w based on created mask and data to be written
	if(readValue!=writeValue)
		AFE_writeReg(param->address,writeValue); /// * Initiates I2C write to device
    
    lastRegAddress = (lastRegAddress & 0x300) + param->address;
    lastRegValue = writeValue;
    
}

void AFE_modifyRegPPM(uint8_t PhaseNo, sigParameter *param, uint32_t value){

    uint8_t absoluteAddress;
    sigParameter dummyParameter;

    absoluteAddress = PhaseNo + param->address;

    dummyParameter.address = absoluteAddress;
    dummyParameter.msb = param->msb;
    dummyParameter.lsb = param->lsb;
    
    if ((lastRegAddress & 0x100) != 0x100)  // i.e. last register written was in Page 0
    {   
         lastRegAddress = 0;                 // as page is switched     
        AFE_switchPage(1) ;                 // switch to Page 1
       
    }

    lastRegAddress = (lastRegAddress & 0xFF) + 0x300 ;
    AFE_modifyRegGlobal(&dummyParameter, value);



}


void AFE_switchPage(int pageNo){
    sigParameter dummyParameter_page_sel;

    dummyParameter_page_sel.address = 1;
    dummyParameter_page_sel.msb = 0;
    dummyParameter_page_sel.lsb = 0;

    AFE_modifyRegGlobal(&dummyParameter_page_sel, pageNo);
    

}


