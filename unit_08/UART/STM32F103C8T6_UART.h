#ifndef STM32F103C8T6_UART_H_
#define STM32F103C8T6_UART_H_


#include "STM32F103C8T6.h"
#include "STM32F103C8T6_RCC.h"
#include "STM32F103C8T6_GPIO.h"



/*
 * figure out configurable parameters
 * add USART registers on device header
 * add configuration structure
 * baudrate: clock ode calculations
 * partial implementation on RCC driver
 * IRQ handling support
 * APIs implementaion
 * */



//configuration structure
typedef struct
{
	uint8_t	UART_Mode; 				//specifies Tx/Rx Enable/Disable
									//This parameter must be set based on @ref UART_Mode_Define

	uint32_t baud_Rate;				//this parameter configures the UART comunication baud rate
									//This parameter must be set based on @ref baud_Rate Define

	uint8_t payload_Length;		//this parameter configures the UART word length of frame
									//This parameter must be set based on @ref payload_Length Define

	uint8_t parity;				//this parameter configures the UART frame parity
									//This parameter must be set based on @ref parity define

	uint8_t stop_Bits;				//this parameter configures the UART frame stop bits
									//This parameter must be set based on @ref stop_Bits define

	uint8_t HW_Flow_Control;		//this parameter configures the UART flow control
									//This parameter must be set based on @ref HW_Flow_Control define

	uint8_t IRQ_EN;					//this parameter configures the UART Interrupts
									//This parameter must be set based on @ref IRQ_EN define

	void(*P_callback)(void);
}UART_Config;


//---------------------------------------------------------
//======================Reference Macros===================
//---------------------------------------------------------

//@ref UART_Mode_Define
#define UART_MODE_TX 	(uint32_t)(1<<3)	//Bit 3 TE: Transmitter enable
#define UART_MODE_RX_EN (uint32_t)(1<<2)  //Bit 2 RE: Receiver enable
#define UART_MODE_TX_RX (uint32_t)(1<<2 | 1<<3)

//@ref baud_Rate define
#define UART_BAUD_RATE_2400     2400
#define UART_BAUD_RATE_9600     9600
#define UART_BAUD_RATE_19200    19200
#define UART_BAUD_RATE_57600	57600
#define UART_BAUD_RATE_115200 	115200
#define UART_BAUD_RATE_230769	230769
#define UART_BAUD_RATE_461538	461538
#define UART_BAUD_RATE_923076	923076
#define UART_BAUD_RATE_2250000	2250000
#define UART_BAUD_RATE_4500000 	4500000

//@ref payload_Length define
//Bit 12 M: Word length
//This bit determines the word length. It is set or cleared by software.
//0: 1 Start bit, 8 Data bits, n Stop bit
//1: 1 Start bit, 9 Data bits, n Stop bit
//Note: The M bit must not be modified during a data transfer (both transmission and reception)

#define UART_PAYLOAD_LENGTH_8B 				0
#define UART_PAYLOAD_LENGTH_9B 				(uint32_t)(1<<10)


//@ref parity define
#define UART_PARITY_NON 	0
#define UART_PARITY_EVEN	uint32_t(1<<10)
#define UART_PARITY_ODD		uint32_t(1<<10 | 1<< 9)


//@ref parity define

//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
//The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.

#define UART_STOP_BITS_ONE		(uint32_t)(0)
#define UART_STOP_BITS_HALF		uint32_t(1<<12)
#define UART_STOP_BITS_TWO  	uint32_t(2<<12)
#define UART_STOP_BITS_ONE_HALF	uint32_t(3<<12)


//@ref HW_Flow_Control define
#define UART_CTS_NONE		 (uint32_t)(0)
#define UART_CTS_EN			 uint32_t(1<<9)
#define UART_RTS_EN 		 uint32_t(1<<8)
#define UART_CTS_RTS		 uint32_t(1<<8 | 1<<9)


//@ref IRQ_Enable define
#define UART_IRQ_EN_NONE 		0
#define UART_IRQ_EN_TXEIE		uint32_t(1<<7)
#define UART_IRQ_EN_TCIE 		uint32_t(1<<6)
#define UART_IRQ_EN_RXNEIE		uint32_t(1<<5)
#define UART_IRQ_EN_PEIE		uint32_t(1<<8)

enum polling_Mechanism
{
	enable,
	disable
};

/*Baud Rate Calculations*/
#define USARTDIV(F, BR)                 (uint32_t)(F/(16*BR)) //devisor
#define USARTDIV_100(F, BR)             (uint32_t)((25*F)/(4*BR)) //devisor 100
#define MANTISSA(F, BR)                 (uint32_t)(USARTDIV(F,BR)) //Mantissa
#define MANTISSA_100(F, BR)             (uint32_t)(MANTISSA(F,BR)*100) //Mantissa 100
#define DIV_FRACTION(F,BR)              (uint32_t)(((USARTDIV_100(F,BR)) - (MANTISSA_100(F,BR)))*.16)
#define UART_BRR_REGISTER(F, BR)        ((MANTISSA(F, BR)<<4) | (DIV_FRACTION(F, BR) & 0xF))


//*******************************************************************************
//						APIs supported by MCAL GPIO Driver
//*******************************************************************************

/*
 * Initialization/deinitialization functions
 * */

void MCAL_UART_Init(UART_Typedef* local_UARTx, UART_Config* local_UART_Config);
void MCAL_UART_Deinit(UART_Typedef* local_UARTx);
void MCAL_UART_GPIO_Set_Pins(UART_Typedef* local_UARTx);
void MCAL_UART_Send_Data(UART_Typedef* local_UARTx, uint16_t* P_Tx_Buffer, enum polling_Mechanism polling); //16 bit data due to payload configuratio 8 or 9 bits
void MCAL_UART_Receive_Data(UART_Typedef* local_UARTx, uint16_t* P_Rx_Buffer, enum polling_Mechanism polling); //16 bit data due to payload configuratio 8 or 9 bits
void MCAL_UART_Wait_Tx_Complete(UART_Typedef* local_UARTx); // not that important

//todo void MCAL_UART_LIN_Init();
//todo void MCAL_USART_Init(); /*synch mode*/
//todo void MCAL_UART_DMA_Init();

#endif
