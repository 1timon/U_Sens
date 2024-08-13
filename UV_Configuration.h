/** @file UV_Configuration.h
 *  @brief Function declarations for UV Spectroscopy configuration.
 *
 *         This header file provides the declarations for configuring the AFE for UV Spectroscopy.
 *         It includes the necessary external variables and function prototypes.
 *
 *  @version 1.0
 *  @date August 8, 2024
 *
 *  @author Timon Grosch
 */

#ifndef UV_CONFIGURATION_H_
#define UV_CONFIGURATION_H_

#include <stdint.h>

// External variables
extern struct AFE_RegMap dev1;
extern uint32_t errorFlags;

// Function prototype for UV Spectroscopy configuration
void AFE_config_for_UVSpectroscopy();

#endif /* UV_CONFIGURATION_H_ */
