/** @file AFE_RegMap.h
 *  @brief Register map declaration of AFE4432.
 *
 *  	This file contains the declaration for the AFE4432's parameter.
 *  	Each AFE parameter has address, page, msb bit and lsb bit as attributes.
 *
 *  @author Prabin Yadav (yadav@ti.com)
 */

#ifndef AFE_REGMAP_H_
#define AFE_REGMAP_H_


#define Phase1 	32 
#define Phase2 	37 
#define Phase3 	42 
#define Phase4 	47 
#define Phase5 	52 
#define Phase6 	57 
#define Phase7 	62 
#define Phase8 	67 
#define Phase9 	72 
#define Phase10	77 
#define Phase11	82 
#define Phase12	87 


#define Enable  1
#define Disable 0


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "AFE_HostControl.h"

struct sigParameter{
	uint8_t address;
	uint8_t msb;
	uint8_t lsb;
};

typedef struct sigParameter sigParameter;

struct AFE_RegMap{

	struct GLOBAL
	{
		sigParameter SPI_REG_READ;
		sigParameter SW_RESET;
		sigParameter RW_CONT;
		sigParameter PAGE_SEL;
		sigParameter TM_COUNT_RST;
		sigParameter FIFO_EN;
		sigParameter EN_LED_SAT_DET;
		sigParameter MASK_REVERSE;
		sigParameter HIGH_PRF_MODE;
		sigParameter MAX_AMB_REJ;
		sigParameter DIS_POST_AMB_MAX_AMB_REJ;
		sigParameter POL_IOFFDAC_LED;
		sigParameter POL_IOFFDAC_AMB;
		sigParameter SWAP_DAC;
		sigParameter EN_LED_OFFDAC_CHOP;
		sigParameter EN_TIA_RST;
		sigParameter IOFFDAC_PD1;
		sigParameter IOFFDAC_PD2;
		sigParameter REG_NUM_TIA_MAX;
		sigParameter IOFFDAC_PD3;
		sigParameter PD_DISCONNECT_TIA1;
		sigParameter PD_DISCONNECT_TIA2;
		sigParameter INT_MUX_ADC_RDY;
		sigParameter INT_MUX_GPIO2;
		sigParameter INPUT_PRF_RST_ON_GPIO2;
		sigParameter PROG_INT2_STC;
		sigParameter PROG_INT2_ENDC;
		sigParameter SEL1_CLK_TE;
		sigParameter OSCL_DIS;
		sigParameter PDN_OSCL_IN_DEEP_SLEEP;
		sigParameter EN_PRF_RESET;
		sigParameter SEL1_CLK_PRF;
		sigParameter DIV_CLK_EXT;
		sigParameter EN_INT_IN_SINGLE_SHOT;
		sigParameter EN_CLK_MODE_MIX;
		sigParameter SET_OSCH_4M_1;
		sigParameter PRPCT;
		sigParameter REG_NUMPHASE;
		sigParameter PRF_COUNTER_ENABLE;
		sigParameter TIMER_ENABLE;
		sigParameter PDNAFE;
		sigParameter EN_AMB_DAC_LSB;
		sigParameter ILED_FS;
		sigParameter SET_OSCH_4M_3;
		sigParameter SET_OSCH_4M_2;
		sigParameter EN_LED_OFFDAC_TIA1;
		sigParameter EN_LED_OFFDAC_TIA2;
		sigParameter DESIGN_ID;
		sigParameter SDOUT_TRISTATE;
		sigParameter EN_GPIO2_OUT;
		sigParameter EN_GPIO2_INT_ON_ADC_RDY;
		sigParameter EN_GPIO2_IN;
		sigParameter REG_WM_FIFO;
		sigParameter FIFO_OFFSET_TO_FORCE;
		sigParameter FORCE_FIFO_OFFSET;
		sigParameter MASK_FIFO_RDY;
		sigParameter AUTO_MASK_FIFO_RDY;
		sigParameter LED_OFFDAC_MARKER_ON_LSB;
		sigParameter EN_LED_OFFDAC_MARKER;
		sigParameter FRAME_SYNC_ON_LSB;
		sigParameter EN_FRAME_SYNC;
		sigParameter REG_POINTER_DIFF;
		sigParameter FIFO_OVERFLOW;
		sigParameter EN_OSCL_CLKOUT;
		sigParameter SPLIT_CLK_FOR_TE_PRF;
		sigParameter IFS_AMB_OFFDAC_TIA1;
		sigParameter IFS_AMB_OFFDAC_TIA2;
		sigParameter PDN_BG_IN_DEEP_SLEEP;
		sigParameter TX_AMP_ALWAYS_ACTIVE;
		sigParameter DEGLITCH_AMB_DAC_MODE;
		sigParameter FILTER_BW_FINE_SET1;
		sigParameter FILTER_BW_PRE_SET1;
		sigParameter OVERRIDE_BW_PRE;
		sigParameter FILTER_BW_FINE_SET2;
		sigParameter FILTER_BW_PRE_SET2;
		sigParameter LOW_THRESHOLD_CODE1;
		sigParameter HIGH_THRESHOLD_CODE1;
		sigParameter LOW_THRESHOLD_CODE2;
		sigParameter HIGH_THRESHOLD_CODE2;
		sigParameter REG_SAMPLE_DELAY_SET1;
		sigParameter REG_SAMPLE_DELAY_SET2;
		sigParameter REG_SAMPLE_DELAY_SET3;
		sigParameter REG_SAMPLE_DELAY_SET4;
		sigParameter EN_PHASE_INT_GPIO;
		sigParameter REG_TSEP_CONV_START;
		sigParameter REG_TSAMP_SEP;
		sigParameter Always1;
		sigParameter EARLY_SAMP_FALL;
		sigParameter REG_TSEP;
		sigParameter REG_TDEEP_SLEEP_PWRUP;
		sigParameter REG_TACTIVE_PWRUP;
		sigParameter REG_TACTIVE_DATA_RDY;
		sigParameter REG_TW_DATA_RDY;
		sigParameter REG_TACTIVE_PWDN;
		sigParameter REG_TDEEP_SLEEP_PWDN;
		sigParameter REG_STEP_COUNT;
		sigParameter REG_TW_FILTER_PRE;
		sigParameter RF_ANA_AACM_END;
		sigParameter REG_DELAY_ANA_ACQ;
		sigParameter REG_TW_ANA_ACQ;
		sigParameter REG_TSEP_ANA_ACQ_LED;
		sigParameter TW_ANA_ACQ_OVERRIDE;
		sigParameter TSEP_ANA_ACQ_LED_OVERRIDE;
		sigParameter EMBED_ANA_AACM_IN_FIFO;
		sigParameter RF_ANA_AACM_START_TIA1;
		sigParameter RF_ANA_AACM_START_TIA2;
		sigParameter CHANNEL_OFFSET_TIA1;
		sigParameter CHANNEL_OFFSET_TIA2;
		sigParameter REG_RECONV_THR_LED_DC;
		sigParameter IOFFDAC_LED_DC_READ;
		sigParameter POL_LED_DC_READ;
		sigParameter LED_DC_LOOP_NUM_READ;
		sigParameter FREEZE_LED_DC_LOOP0;
		sigParameter FREEZE_LED_DC_LOOP1;
		sigParameter FREEZE_LED_DC_LOOP2;
		sigParameter FREEZE_LED_DC_LOOP3;
		sigParameter FREEZE_LED_DC_LOOP4;
		sigParameter FREEZE_LED_DC_LOOP5;
		sigParameter FREEZE_LED_DC_LOOP6;
		sigParameter FREEZE_LED_DC_LOOP7;
		sigParameter REG_SCALE_DRE;
		sigParameter USE_MSB_FOR_DRE;
		sigParameter GAIN_CALIB_LED_DC_142K;
		sigParameter GAIN_CALIB_LED_DC_166K;
		sigParameter GAIN_CALIB_LED_DC_200K;
		sigParameter GAIN_CALIB_LED_DC_250K;
		sigParameter THR_DET_EN;
		sigParameter THR_SEL_LOGIC;
		sigParameter REG_THR_DET_PHASE;
		sigParameter COMB_THR_DET_EN;
		sigParameter THR_PPG_FLAG;
		sigParameter DIS_DEEP_SLEEP;
		sigParameter EN_ALWAYS_ACTIVE;

	}GLOBAL;

	struct PPM
	{
		sigParameter LED_DRV1_TXN;
		sigParameter LED_DRV2_TXN;
		sigParameter THR_SEL_TIA_NUM;
		sigParameter THR_SEL;
		sigParameter THR_SEL_DATA_CTRL;
		sigParameter PHASE_INT_GPIO2;
		sigParameter ILED_DRV1;
		sigParameter ILED_DRV2;
		sigParameter REG_TWLED;
		sigParameter RF_TIA1;
		sigParameter CF_TIA1;
		sigParameter IOFFDAC_LED_TIA1;
		sigParameter LED_DC_EN_TIA1;
		sigParameter IN_TIA1;
		sigParameter RF_TIA2;
		sigParameter CF_TIA2;
		sigParameter IOFFDAC_LED_TIA2;
		sigParameter LED_DC_EN_TIA2;
		sigParameter IN_TIA2;
		sigParameter UPDATE_BASELINE_AMB;
		sigParameter USE_ANA_AACM;
		sigParameter FILTER_SET_SEL;
		sigParameter REG_NUM_TIA;
		sigParameter AUTO_AMB_INSERT;
		sigParameter ENABLE_DRE;
		sigParameter REG_MASK_FACTOR;
		sigParameter REG_NUMAV;
		sigParameter FIFO_DATA_CTRL;
		sigParameter REG_DEC_FACTOR;
		sigParameter SEL_SAMPLE_DELAY_SET;
	}PPM;
	
	

	

	

};


typedef struct AFE_RegMap AFE_RegMap;

/** @brief Assigns the reggister map to the AFE
 *         
 *  @param None
 *         
 *  @return None.
 */
void AFE_assignRegMap (AFE_RegMap* AFE);

/** @brief Modifies the global registers in Page0.
 *         
 *  @param AFE_Parameter, @param Value
 *         
 *  @return None.
 */
void AFE_modifyRegGlobal(sigParameter *param, uint32_t value);

/** @brief Modifies the per-phase registers in Page1. Registers in 0x20 to 0x9F in Page1
 *         
 *  @param PhaseNo, @param AFE_Parameter, @param Value
 *         
 *  @return None.
 */
void AFE_modifyRegPPM(uint8_t PhaseNo, sigParameter *param, uint32_t value);

/** @brief Switches the Page
 *         
 *  @param PageNo 0: For Page0, 1: For Page1
 *         
 *  @return None.
 */
void AFE_switchPage(int pageNo);



#endif /* AFE_REGMAP_H_ */
