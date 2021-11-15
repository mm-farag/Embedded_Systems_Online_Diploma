/*
 * stm32f103c8t6.h
 *
 *  Created on: Oct 30, 2021
 *      Author: Muhammad Mustafa
 */

#ifndef DEVICE_DRIVER_H_
#define DEVICE_DRIVER_H_


//-----------------------------
//Includes
#include<stdlib.h>
#include<stdint.h>
//-----------------------------

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE				0X08000000UL //UL unsigned 32 bits
#define SRAM_MEMORY_BASE				0x20000000UL
#define SYSTEM_MEMORY_BASE 				0X1FFFF000UL
#define PERIPHERALS_MEMORY_BASE 		0X40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS 	0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE						0x40021000UL
//-----------------------------


//Base addresses for APB2 Peripherals
//POART_A is fully included in LQFP48.
#define PORT_A_BASE						0x40010800UL

//POART_B is fully included in LQFP48.
#define PORT_B_BASE 					0x40010C00UL

//PORT_C is partially included in LQFP48.
#define PORT_C_BASE 					0x40011000UL

//PORT_D is partially included in LQFP48.
#define PORT_D_BASE 					0x40011400UL

//PORT_E is not included in LQFP48.
#define PORT_E_BASE 					0x40011800UL

//EXTI
#define EXTI_BASE 						0x40010400UL

//AFIO
#define AFIO_BASE 						0x40010000UL
//-----------------------------


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------


//===============================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
//note: the table may have a mistake
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED; //0x18 is not concidered, volatile is not necessary
	volatile uint32_t MAPR2;
}AFIO_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SEIER;
	volatile uint32_t PR;
}EXTI_Typedef;
//===============================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIO_A 	((GPIO_Typedef *)PORT_A_BASE)
#define GPIO_B 	((GPIO_Typedef *)PORT_B_BASE)
#define GPIO_C 	((volatile GPIO_Typedef *)PORT_C_BASE)
#define GPIO_D 	((volatile GPIO_Typedef *)PORT_D_BASE)
#define GPIO_E 	((volatile GPIO_Typedef *)PORT_E_BASE)

#define RCC 	((volatile RCC_Typedef *)RCC_BASE)

#define EXTI	((volatile EXTI_Typedef*)EXTI_BASE)

#define AFIO 	((volatile AFIO_Typedef*)AFIO_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIO_A_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIO_B_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIO_C_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIO_D_CLK_EN()		(RCC->APB2ENR |= 1<<5)


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif //DEVICE_DRIVER_H_
