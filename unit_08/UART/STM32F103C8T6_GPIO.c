/*
 * stm32f103c8t6_gpio_driver.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Muhammad Mustafa Farag
 */


#include "STM32F103C8T6_GPIO.h"
uint8_t get_CRLH_Position(uint16_t pin_Number)
{
	switch(pin_Number)
	{
	case GPIO_PIN_00:
		return 0;
		break;
	case GPIO_PIN_01:
		return 4;
		break;
	case GPIO_PIN_02:
		return 8;
		break;
	case GPIO_PIN_03:
		return 12;
		break;
	case GPIO_PIN_04:
		return 16;
		break;
	case GPIO_PIN_05:
		return 20;
		break;
	case GPIO_PIN_06:
		return 24;
		break;
	case GPIO_PIN_07:
		return 28;
		break;
	case GPIO_PIN_08:
		return 0;
		break;
	case GPIO_PIN_09:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}







/*================================================================
 *@Fn        	-MCAL_GPIO_Init
 *@brief        -Initializes the GPIOx PINy according to the specified parameters in the pin_Config.
 *@brief         that is by writing values in the CRL or CRH configuration registers.
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..E).
 *@param[in]    -pin_Config: is a pointer to the GPIO_Pin_Config_t structure that
 *			     contains the information for the specified GPIO PIN.
 *@retval		-none
 *@note			-stm32f103c8t6 only has GPIO instants A, B, C, and D.
 */
void MCAL_GPIO_Init(GPIO_Typedef *local_GPIOx, GPIO_Pin_Config_t *local_Pin_Config) //pin_Config is a pointer not to copy the values.
{
	volatile uint32_t *local_Refers_To_CRL_CRH = NULL ;
	uint8_t temp = 0;
	uint32_t bit_Value;
	local_Refers_To_CRL_CRH = (local_Pin_Config->GPIO_Pin_Number < GPIO_PIN_08)? (uint32_t *)&local_GPIOx->CRL  : (uint32_t *)&local_GPIOx->CRH;
	//clear CNF, MODE
	bit_Value = ~(0xF << get_CRLH_Position(local_Pin_Config->GPIO_Pin_Number));
	//	GPIO_A->CRL = 0;
	//	local_GPIOx->CRL = 0;
	//	(*local_Refers_To_CRL_CRH) = 0 ;
	(*local_Refers_To_CRL_CRH) &= bit_Value;
	//if  pin is output
	if((local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_OUTPUT_PP) ||
			(local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_OUTPUT_OD) ||
			(local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_OUTPUT_AF_PP) ||
			(local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_OUTPUT_AF_OD))
	{
		temp = (   (((local_Pin_Config->GPIO_Pin_Mode - 4) << 2) | (local_Pin_Config->GPIO_Output_Speed)) & 0x0F   );
	}
	//if input
	else
	{
		if(local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_INPUT_PD)
		{
			local_GPIOx->ODR &= ~local_Pin_Config->GPIO_Pin_Number;
		}
		else
		{
			local_GPIOx->ODR |= local_Pin_Config->GPIO_Pin_Number;

		}


		if(local_Pin_Config->GPIO_Pin_Mode == GPIO_MODE_INPUT_PD)
		{
			local_Pin_Config->GPIO_Pin_Mode = GPIO_MODE_INPUT_PU;
		}
		temp = ((local_Pin_Config->GPIO_Pin_Mode << 2) | 0x0) & 0xF;
	}
	*local_Refers_To_CRL_CRH |= temp << get_CRLH_Position(local_Pin_Config->GPIO_Pin_Number);

}

/*================================================================
 *@Fn        	-MCAL_GPIO_DeInit
 *@brief        -Deinitializes the GPIOx PINy according to the specified parameters in the pin_Config.
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..E).
 *@retval		-none
 *@note			-
 */
void MCAL_GPIO_DeInit(GPIO_Typedef *local_GPIOx)
{
	/*
	//1st method
	local_GPIOx->CRL = 0x44444444;
	local_GPIOx->CRH = 0x44444444;
//	local_GPIOx->IDR = ; (READ ONLY)
	local_GPIOx->BRR = 0x00000000;
	local_GPIOx->BSRR = 0x00000000;
	local_GPIOx->LCKR = 0x00000000;
	local_GPIOx->ODR = 0x00000000;
	 */

	if(local_GPIOx == GPIO_A)
	{
		RCC->APB2RSTR |= 1<<2;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(local_GPIOx == GPIO_B)
	{
		RCC->APB2RSTR |= 1<<3;
		RCC->APB2RSTR &= ~(1<<3);

	}
	else if(local_GPIOx == GPIO_C)
	{
		RCC->APB2RSTR |= 1<<4;
		RCC->APB2RSTR &= ~(1<<4);

	}
	else if(local_GPIOx == GPIO_D)
	{
		RCC->APB2RSTR |= 1<<5;
		RCC->APB2RSTR &= ~(1<<5);
	}

}

/*================================================================
 *@Fn        	-MCAL_GPIO_Read_Pin
 *@brief        -Reads a specific pin from a specific GPIOx
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..E).
 *@param[in]    pin_Number: sets pin number according to @ref GPIO_PINS_define.
 *@retval		-The input pin value(two values based on @ref GPIO_PIN_STATE_Define)
 *@note			-stm32f103c8t6 only has GPIO instants A, B, C, and D.
 */
uint8_t MCAL_GPIO_Read_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_pin_Number)
{
	uint8_t bit_Status;
	if((local_GPIOx->IDR & local_pin_Number) != 0)
	{
		bit_Status = GPIO_PIN_SET;
	}
	else
	{
		bit_Status = GPIO_PIN_RESET;
	}
	return bit_Status;
}

/*================================================================
 *@Fn        	-MCAL_GPIO_Read_PORT
 *@brief        -Reads a specific GPIOx
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..E).
 *@retval		-The input port value
 *@note			-none
 */
uint16_t MCAL_GPIO_Read_Port(GPIO_Typedef *local_GPIOx)
{
	uint16_t port_Status;
	//	return (local_GPIOx->IDR & 0x0000FFFF);
	port_Status = (uint16_t)local_GPIOx->IDR;// another way
	return port_Status;
}

/*================================================================
 *@Fn        	-MCAL_GPIO_Write_Pin.
 *@brief        -Writes on a specifc pin in a specific GPIO port.
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..D).
 *@param[in]	-pin_Number: where pin can be selected between 0 to 15.
 *@param[in]	-value: pin value 0, 1;
 *@retval		-none
 *@note			-none
 */
void MCAL_GPIO_Write_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number, uint8_t local_Value)
{
	/*
	if(local_Value == GPIO_PIN_SET)
	{
		local_GPIOx->ODR |= local_ Pin_Number;
	}
	else
	{
		local_GPIOx->ODR &= ~local_Pin_Number;
	}*/

	//another method


	if(local_Value != GPIO_PIN_RESET)
	{
		//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit
		local_GPIOx->BSRR = (uint32_t)local_Pin_Number;
	}
	else
	{
		//		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit
		local_GPIOx->BRR = (uint32_t)local_Pin_Number;
	}
}

/*================================================================
 *@Fn        	-MCAL_GPIO_Write_Port.
 *@brief        -Writes on a specific GPIO port.
 *@param[in]    -GPIOx: where x can be used to select between the GPIO peripheral instants(A..D).
 *@param[in]	-value: where value can be 16 bits of zeros or ones
 *@retval		-none
 *@note			-none
 */
void MCAL_GPIO_Write_Port(GPIO_Typedef *local_GPIOx, uint16_t local_Value)
{
	local_GPIOx->ODR = (uint32_t)local_Value;
}

/*================================================================
 *@Fn        	-MCAL_GPIO_Toggle_Pin
 *@brief        -Toggles a specific pin in a specific port
 *@param[in]    -GPIOx: x is used to select between GPIO ports (A..D)
 *@param[in]	-pin_Number: is used to select the pin number.
 *@retval		-none
 *@note			-none
 */
void MCAL_GPIO_Toggle_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number)
{
	local_GPIOx->ODR ^= local_Pin_Number;
}

/*================================================================
 *@Fn        	-MCAL_GPIO_Lock_Pin.
 *@brief        -Locks pin configuration for a specific pin in a specific port.
 *@param[in]    -GPIOx: x is used to select between GPIO ports (A..D).
 *@param[in]	-pin_Number: is used to select the pin number.
 *@retval		-OK if pin config is locked or ERROR if pin is not locked,
 		 	 	 (OK and NOK are defined in @ref_RETURN_LOCK_define).
 *@note			-none.
 */
uint8_t MCAL_GPIO_Lock_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number)
{
	volatile uint32_t temp_Variable = 0;
	uint8_t return_Value = 0;
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked
	local_GPIOx->LCKR |= local_Pin_Number;
	local_GPIOx->LCKR |= 1<<16;//set
	local_GPIOx->LCKR &= ~(1<<16);//reset
	local_GPIOx->LCKR |= 1<<16;//set
	temp_Variable = local_GPIOx->LCKR;//read 1st time
	if(((local_GPIOx->LCKR >> 16) & 1) == 1)
	{
		return_Value =  RETURN_LOCK_OK;
	}
	else
	{
		return_Value = RETURN_LOCK_NOK;
	}
	return return_Value;
}
/*================================================================
 *@Fn        	-STD FN
 *@brief        -
 *@param[in]    -
 *@param[in]	-
 *@retval		-
 *@note			-
 */
