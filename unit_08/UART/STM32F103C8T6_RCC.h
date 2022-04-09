#ifndef STM32F103C8T6_RCC_H_
#define STM32F103C8T6_RCC_H_


#include "STM32F103C8T6.h"



#define HSI_CLOCK (uint32_t)8000000
#define HSE_CLOCK (uint32_t)16000000//temp value
#define PLL_CLOCK (uint32_t)16000000//temp value


uint32_t MCAL_RCC_Get_Sys_Freq(void);
uint32_t MCAL_RCC_Get_HCLK_Freq(void);
uint32_t MCAL_RCC_Get_PCLK1_Freq(void);
uint32_t MCAL_RCC_Get_PCLK2_Freq(void);

























#endif
