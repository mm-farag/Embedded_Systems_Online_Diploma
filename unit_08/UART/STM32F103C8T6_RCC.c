/*
 * STM32F103C8_EXTI.c
 *
 *  Created on: Dec 11, 2021
 *      Author: Muhammad Mustafa
 */

#include "STM32F103C8T6_RCC.h"


//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB low-speed clock
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16


//its 13:11 PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t APB_Prescaler_Table[8] = {0, 0, 0, 0, 1, 2, 3, 4};


//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
const uint8_t AHB_Prescaler_Table[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8};




uint32_t MCAL_RCC_Get_Sys_Freq(void)
{
//	Bits 1:0 SW: System clock switch
//	Set and cleared by software to select SYSCLK source.
//	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
//	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
//	System is enabled).
//	00: HSI selected as system clock
//	01: HSE selected as system clock
//	10: PLL selected as system clock
//	11: not allowed
	switch((RCC->CFGR>>2) & 0b11)
	{
	case 0:
		return HSI_CLOCK;
		break;
	case 1:
		return HSE_CLOCK;
		break;
	case 2:
		return PLL_CLOCK;
		break;
	}
}





uint32_t MCAL_RCC_Get_HCLK_Freq(void)
{
//	Bits 7:4 HPRE[3:0]: AHB prescaler
	return (MCAL_RCC_Get_Sys_Freq() >> AHB_Prescaler_Table[(RCC->CFGR >> 4) & 0xF]);
}


uint32_t MCAL_RCC_Get_PCLK1_Freq(void)
{
//	Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	return (MCAL_RCC_Get_HCLK_Freq() >> APB_Prescaler_Table[(RCC->CFGR >> 8) & 0b111]);
}


uint32_t MCAL_RCC_Get_PCLK2_Freq(void)
{
//	Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	return (MCAL_RCC_Get_HCLK_Freq() >> APB_Prescaler_Table[(RCC->CFGR >> 11) & 0b111]);
}




































