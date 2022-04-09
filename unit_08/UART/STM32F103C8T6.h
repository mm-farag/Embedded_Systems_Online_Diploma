/*
 * stm32f103c8t6.h
 *
 *  Created on: Oct 30, 2021
 *      Author: Muhammad Mustafa
 */

#ifndef STM32F103C8_H_
#define STM32F103C8_H_


//-----------------------------
//Includes
#include<stdlib.h>
#include<stdint.h>
//-----------------------------


#define SET 1
#define RESET 0

#define SET_BIT(REG, BIT)					(REG |=1<<BIT)
#define RESET_BIT(REG, BIT)					(REG &= ~(1<<BIT))
#define SET_REG(REG)						(REG = 0xFF)
#define RESET_REG(REG)						(REG=0x00)
#define GET_BIT(REG, BIT)					((REG & (1<<BIT))>>BIT)
#define GET_REG(REG)						(REG & 0xFF)
#define TOGGLE_REG(REG)						(REG ^= 0xFF)
#define TOGGLE_BIT(REG, BIT)


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE				0X08000000UL //UL unsigned 32 bits
#define SRAM_MEMORY_BASE				0x20000000UL
#define SYSTEM_MEMORY_BASE 				0X1FFFF000UL
#define PERIPHERALS_MEMORY_BASE 		0X40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS 	0xE0000000UL

#define NVIC_BASE						0xE000E100UL






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
//UART1
#define UART1_BASE						0x40013800UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------
#define UART2_BASE						0x40004400UL
#define UART3_BASE						0x40004800UL
#define UART4_BASE
#define UART5_BASE

//===============================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_ISER0 *((volatile uint32_t*)(NVIC_BASE + 0x000))
#define NVIC_ISER1 *((volatile uint32_t*)(NVIC_BASE + 0x004))
#define NVIC_ISER2 *((volatile uint32_t*)(NVIC_BASE + 0x008))
#define NVIC_ICER0 *((volatile uint32_t*)(NVIC_BASE + 0x080))
#define NVIC_ICER1 *((volatile uint32_t*)(NVIC_BASE + 0x084))
#define NVIC_ICER2 *((volatile uint32_t*)(NVIC_BASE + 0x088))
#define NVIC_ISPR0 *((volatile uint32_t*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1 *((volatile uint32_t*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2 *((volatile uint32_t*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0 *((volatile uint32_t*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1 *((volatile uint32_t*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2 *((volatile uint32_t*)(NVIC_BASE + 0x188))
#define NVIC_IABR0 *((volatile uint32_t*)(NVIC_BASE + 0x200))


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
	volatile uint32_t EXTICR[4];
//	volatile uint32_t EXTICR2;
//	volatile uint32_t EXTICR3;
//	volatile uint32_t EXTICR4;
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


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: UART1
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}UART_Typedef;


//===============================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIO_A 	((GPIO_Typedef *)PORT_A_BASE)
#define GPIO_B 	((GPIO_Typedef *)PORT_B_BASE)
#define GPIO_C 	((GPIO_Typedef *)PORT_C_BASE)
#define GPIO_D 	((GPIO_Typedef *)PORT_D_BASE)
#define GPIO_E 	((GPIO_Typedef *)PORT_E_BASE)
#define RCC 	((RCC_Typedef *)RCC_BASE)
#define EXTI	((EXTI_Typedef*)EXTI_BASE)
#define AFIO 	((AFIO_Typedef*)AFIO_BASE)

#define NVIC 	((NVIC_Typedef_t*)NVIC_BASE)

#define UART1  (UART_Typedef *)UART1_BASE
#define UART2  (UART_Typedef *)UART2_BASE
#define UART3  (UART_Typedef *)UART3_BASE
#define UART4
#define UART5

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIO_A_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIO_B_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIO_C_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIO_D_CLK_EN()		(RCC->APB2ENR |= 1<<5)
#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= 1<<0)

#define RCC_UART1_CLK_EN()		(RCC->APB2ENR |= 1<<14)
#define RCC_UART2_CLK_EN()		(RCC->APB1ENR |= 1<<17)
#define RCC_UART3_CLK_EN()		(RCC->APB1ENR |= 1<<18)

//RCC reset mechanism
#define RCC_UART1_RESET()		(RCC->APB2RSTR |= 1<<14)
#define RCC_UART2_RESET()		(RCC->APB1RSTR |= 1<<17)
#define RCC_UART3_RESET()		(RCC->APB1RSTR |= 1<<18)
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Vector Table
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI
#define EXTI_00_IRQ 	6
#define EXTI_01_IRQ 	7
#define EXTI_02_IRQ 	8
#define EXTI_03_IRQ 	9
#define EXTI_04_IRQ 	10
#define EXTI_05_IRQ 	23
#define EXTI_06_IRQ 	23
#define EXTI_07_IRQ 	23
#define EXTI_08_IRQ 	23
#define EXTI_09_IRQ 	23
#define EXTI_10_IRQ 	40
#define EXTI_11_IRQ 	40
#define EXTI_12_IRQ 	40
#define EXTI_13_IRQ 	40
#define EXTI_14_IRQ 	40
#define EXTI_15_IRQ 	40

#define UART1_IRQ		37
#define UART2_IRQ		38
#define UART3_IRQ		39
#define UART4_IRQ		52
#define UART5_IRQ		53



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable/Disable MACROS
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


#define NVIC_IRQ6_EXTI_00_ENABLE      	(NVIC_ISER0|=1<<6)
#define NVIC_IRQ6_EXTI_01_ENABLE      	(NVIC_ISER0|=1<<7)
#define NVIC_IRQ6_EXTI_02_ENABLE      	(NVIC_ISER0|=1<<8)
#define NVIC_IRQ6_EXTI_03_ENABLE      	(NVIC_ISER0|=1<<9)
#define NVIC_IRQ6_EXTI_04_ENABLE      	(NVIC_ISER0|=1<<10)
#define NVIC_IRQ6_EXTI_05_09_ENABLE     (NVIC_ISER0|=1<<23)
#define NVIC_IRQ6_EXTI_10_15_ENABLE     (NVIC_ISER1|=1<<8)  //ISER1

#define NVIC_IRQ37_UART1_ENABLE	 		(NVIC_ISER1|=1<<(	UART1_IRQ - 32	))  //ISER1
#define NVIC_IRQ38_UART2_ENABLE  	    (NVIC_ISER1|=1<<(	UART2_IRQ - 32	))  //ISER1
#define NVIC_IRQ39_UART3_ENABLE       	(NVIC_ISER1|=1<<(	UART3_IRQ - 32	))  //ISER1
#define NVIC_IRQ52_UART3_ENABLE       	(NVIC_ISER1|=1<<(	UART4_IRQ - 32	))  //ISER1
#define NVIC_IRQ53_UART3_ENABLE       	(NVIC_ISER1|=1<<(	UART5_IRQ - 32	))  //ISER1



#define NVIC_IRQ6_EXTI_00_DISABLE      	(NVIC_ICER0|=1<<6)
#define NVIC_IRQ6_EXTI_01_DISABLE      	(NVIC_ICER0|=1<<7)
#define NVIC_IRQ6_EXTI_02_DISABLE      	(NVIC_ICER0|=1<<8)
#define NVIC_IRQ6_EXTI_03_DISABLE      	(NVIC_ICER0|=1<<9)
#define NVIC_IRQ6_EXTI_04_DISABLE      	(NVIC_ICER0|=1<<10)
#define NVIC_IRQ6_EXTI_05_09_DISABLE    (NVIC_ICER0|=1<<23)
#define NVIC_IRQ6_EXTI_10_15_DISABLE    (NVIC_ICER1|=1<<8)  //ICER1

#define NVIC_IRQ37_UART1_DISABLE		(NVIC_ICER1|=1<<(	UART1_IRQ - 32	))  //ICER1
#define NVIC_IRQ38_UART2_DISABLE		(NVIC_ICER1|=1<<(	UART2_IRQ - 32	))  //ICER1
#define NVIC_IRQ39_UART3_DISABLE		(NVIC_ICER1|=1<<(	UART3_IRQ - 32	))  //ICER1
#define NVIC_IRQ52_UART3_DISABLE		(NVIC_ICER1|=1<<(	UART4_IRQ - 32	))  //ICER1
#define NVIC_IRQ53_UART3_DISABLE		(NVIC_ICER1|=1<<(	UART5_IRQ - 32	))  //ICER1




#endif //STM32F103C8_H_
