/*
 * STM32F103C8_EXTI.c
 *
 *  Created on: Dec 11, 2021
 *      Author: Muhammad Mustafa
 */


#include "STM32F103C8T6_UART.h"
//*******************************************************************************
//						Globale Variable
//*******************************************************************************

UART_Config* GP_UART_Config = NULL;
uint16_t ch_Buffer = 0;






/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_Init(UART_Typedef* local_UARTx, UART_Config* local_UART_Config)
{
	uint32_t pclk = 0;



	/* 1. clock enable
	 * 2. enable the module itself
	 * 3. enable tx/rx
	 * 4. choose the payload
	 * 5. config parity bits
	 * 6. config the stop bits
	 * 7. HW flow control
	 * 8. baud rate
	 * 9. IRQ En
	 * */
	GP_UART_Config = local_UART_Config; //keep it as a backup


	//	1. Enable UART clock
	if(local_UARTx == UART1)
		RCC_UART1_CLK_EN();
	else if(local_UARTx == UART2)
		RCC_UART2_CLK_EN();
	else if(local_UARTx == UART3)
		RCC_UART3_CLK_EN();
	else{}


	//	Bit 13 UE: USART enable
	//	When this bit is cleared the USART prescalers and outputs are stopped and the end of the
	//	current
	//	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	//	0: USART prescaler and outputs disabled
	//	1: USART enabled
	local_UARTx->CR1 |= 1<<13;



	//	Bit 3 TE: Transmitter enable
	//	This bit enables the transmitter. It is set and cleared by software.
	//	0: Transmitter is disabled
	//	1: Transmitter is enabled
	//	Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
	//	(idle line) after the current word, except in Smartcard mode.
	//	2: When TE is set there is a 1 bit-time delay before the transmission starts.
	//	Bit 2 RE: Receiver enable
	//	This bit enables the receiver. It is set and cleared by software.
	//	0: Receiver is disabled
	//	1: Receiver is enabled and begins searching for a start bit
	local_UARTx->CR1 |= local_UART_Config->UART_Mode;


	//	Bit 12 M: Word length
	//	This bit determines the word length. It is set or cleared by software.
	//	0: 1 Start bit, 8 Data bits, n Stop bit
	//	1: 1 Start bit, 9 Data bits, n Stop bit
	//	Note: The M bit must not be modified during a data transfer (both transmission and reception)
	local_UARTx->CR1 |= local_UART_Config->payload_Length;


	//	Bit 9 PS: Parity selection
	//	This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
	//	bit set). It is set and cleared by software. The parity will be selected after the current byte.
	//	0: Even parity
	//	1: Odd parity
	//
	local_UARTx->CR1 |= local_UART_Config->parity;


	//	Bits 13:12 STOP: STOP bits
	//	These bits are used for programming the stop bits.
	//	00: 1 Stop bit
	//	01: 0.5 Stop bit
	//	10: 2 Stop bits
	//	11: 1.5 Stop bit
	//	The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5
	local_UARTx->CR2 |= local_UART_Config->stop_Bits;





	//	Bit 8 RTSE: RTS enable
	//	0: RTS hardware flow control disabled
	//	1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
	//	The transmission of data is expected to cease after the current character has been
	//	transmitted. The RTS output is asserted (tied to 0) when a data can be received.
	//	This bit is not available for UART4 & UART5.
	//
	//	Bit 9 CTSE: CTS enable
	//	0: CTS hardware flow control disabled
	//	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
	//	the CTS input is deasserted while a data is being transmitted, then the transmission is
	//	completed before stopping. If a data is written into the data register while CTS is deasserted,
	//	the transmission is postponed until CTS is asserted.
	//	This bit is not available for UART4 & UART5
	local_UARTx->CR3 |= local_UART_Config->HW_Flow_Control;





	//baud rate calculations
	if(local_UARTx == UART1)
	{
		pclk = MCAL_RCC_Get_PCLK2_Freq();
	}
	else
	{
		pclk = MCAL_RCC_Get_PCLK1_Freq();
	}

	local_UARTx->BRR = UART_BRR_REGISTER(pclk, local_UART_Config->baud_Rate);

	if(local_UART_Config->IRQ_EN != UART_IRQ_EN_NONE)
	{
		local_UARTx->CR1 |= local_UART_Config->IRQ_EN; //enable the local interrupt
		//we have to check the NVIC according to the vector table
		if(local_UARTx == UART1) 			NVIC_IRQ37_UART1_ENABLE;
		else if(local_UARTx == UART2)		NVIC_IRQ38_UART2_ENABLE;
		else if(local_UARTx == UART3)		NVIC_IRQ39_UART3_ENABLE;
		else
		{

		}
	}


	//end of func
}


/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_Deinit(UART_Typedef* local_UARTx)
{
	if(local_UARTx == UART1)
	{
		RCC->APB2RSTR |= 1<<14;
		NVIC_IRQ37_UART1_DISABLE;
	}

	else if(local_UARTx == UART2)
	{
		RCC->APB1RSTR |= 1<<17;

	}
	else if(local_UARTx == UART3)
	{
		RCC->APB1RSTR |= 1<<18;
	}


	//end of function
}


/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_Send_Data(UART_Typedef* local_UARTx, uint16_t* P_Tx_Buffer, enum polling_Mechanism polling)
{

	//wait untill the TXE flag is set
	if(polling == enable)
	{
		while(!(local_UARTx->SR & (1<<7))); //transmitter is sending data
		//check the wordlength
		if(GP_UART_Config->payload_Length == UART_PAYLOAD_LENGTH_9B)
		{
			local_UARTx->DR = (*P_Tx_Buffer & (uint16_t)0x1FF);
		}
		else
		{
			local_UARTx->DR = (*P_Tx_Buffer & (uint16_t)0xFF);
		}
	}

}



/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_Wait_Tx_Complete(UART_Typedef* local_UARTx) //not that important
{
	//	wait till the TC flag is set
	while(!(local_UARTx->SR & 1<<6));
}



/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_Receive_Data(UART_Typedef* local_UARTx, uint16_t* P_Rx_Buffer, enum polling_Mechanism polling) //16 bit data due to payload configuratio 8 or 9 bits
{

	//wait till the RXE flag is set
	if(polling == enable)
	{
		while(!(local_UARTx->SR & (1<<5))); //receiver is receiving data
		//check the wordlength
		if(GP_UART_Config->payload_Length == UART_PAYLOAD_LENGTH_9B)
		{
			if(GP_UART_Config->parity == UART_PARITY_NON)
			{
				*P_Rx_Buffer = local_UARTx->DR;
			}
			else
			{
				*((uint16_t*)P_Rx_Buffer) = local_UARTx->DR & (uint8_t)0xFF;
			}
		}
		else
		{
			if(GP_UART_Config->parity == UART_PARITY_NON)
			{
				*((uint16_t*)P_Rx_Buffer) = (uint8_t)local_UARTx->DR;
			}
			else
			{
				*((uint16_t*)P_Rx_Buffer) = local_UARTx->DR & (uint8_t)0x7F;
			}

		}

	}

}






/*=============================================================
 * @Fn
 * @brief
 * @param
 * @param
 * @retrn_Val
 * Note:
 * */
void MCAL_UART_GPIO_Set_Pins(UART_Typedef* local_UARTx)
{
	GPIO_Pin_Config_t uart_Pin_Config;
	uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
	uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_OUTPUT_AF_PP;
	uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_09;
	MCAL_GPIO_Init(GPIO_A, &uart_Pin_Config);
	//	TX -> AFPP
	//	RX -> I/P pull up or floating

	if(local_UARTx == UART1)
	{
		//	A9 tx
		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_OUTPUT_AF_PP;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_09;
		MCAL_GPIO_Init(GPIO_A, &uart_Pin_Config);


		//	A10 Rx
		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_INPUT_FLO;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIO_A, &uart_Pin_Config);
	}
	else if(local_UARTx == UART2)
	{
		//		tx A2
		//		Rx A3
		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_OUTPUT_AF_PP;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_02;
		MCAL_GPIO_Init(GPIO_A, &uart_Pin_Config);


		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_INPUT_FLO;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_03;
		MCAL_GPIO_Init(GPIO_A, &uart_Pin_Config);

	}
	else if(local_UARTx == UART3)
	{
		//		Tx b10
		//		Rx b11
		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_OUTPUT_AF_PP;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIO_B, &uart_Pin_Config);


		//	A10 Rx
		uart_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		uart_Pin_Config.GPIO_Pin_Mode = GPIO_MODE_INPUT_FLO;
		uart_Pin_Config.GPIO_Pin_Number = GPIO_PIN_11;
		MCAL_GPIO_Init(GPIO_B, &uart_Pin_Config);
	}


}



















