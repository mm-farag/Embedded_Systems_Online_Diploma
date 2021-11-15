/*
 * stm32f103c8t6_gpio_driver.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Muhammad Mustafa
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


//includes
#include"device_Driver.h"
//======================================

//config. structure
typedef struct
{
	uint16_t GPIO_Pin_Number; 	//specifies the GPIO pins to be configured
	//this parameter can be a value of @ref GPIO_PINS_Define.

	uint8_t GPIO_Pin_Mode;      //specifies the GPIO pins to be configured
	//this parameter can be a value of @ref GPIO_MODE_Define.

	uint8_t GPIO_Output_Speed;  //specifies the GPIO pins to be configured
	//this parameter can be a value of @ref GPIO_SPEED_Define.

}GPIO_Pin_Config_t;


//GPIO_PIN_STATE_define
#define GPIO_PIN_SET	 	1
#define GPIO_PIN_RESET	 	0

//@ref_RETURN_LOCK_define

#define RETURN_LOCK_OK 		1
#define RETURN_LOCK_NOK 	0

//===============================
//Macros Configuration References
//===============================

//@ref GPIO_PINS_Define.
#define GPIO_PIN_00 		((uint16_t)0x0001)
#define GPIO_PIN_01 		((uint16_t)0x0002)
#define GPIO_PIN_02 		((uint16_t)0x0004)
#define GPIO_PIN_03 		((uint16_t)0x0008)
#define GPIO_PIN_04 		((uint16_t)0x0010)
#define GPIO_PIN_05 		((uint16_t)0x0020)
#define GPIO_PIN_06 		((uint16_t)0x0040)
#define GPIO_PIN_07 		((uint16_t)0x0080)
#define GPIO_PIN_08 		((uint16_t)0x0100)
#define GPIO_PIN_09 		((uint16_t)0x0200)
#define GPIO_PIN_10 		((uint16_t)0x0400)
#define GPIO_PIN_11 		((uint16_t)0x0800)
#define GPIO_PIN_12 		((uint16_t)0x1000)
#define GPIO_PIN_13 		((uint16_t)0x2000)
#define GPIO_PIN_14		 	((uint16_t)0x4000)
#define GPIO_PIN_15 		((uint16_t)0x8000)
#define GPIO_PIN_ALL		((uint16_t)0xFFFF)
#define GPIO_PIN_MASK		0x0000FFFFU



//@ref GPIO_MODE_Define.
//0: Analog mode
//1: Input floating (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input, which is floating input also

#define GPIO_MODE_ANALOG 		0x00000000U
#define GPIO_MODE_INPUT_FLO 	0x00000001U
#define GPIO_MODE_INPUT_PU 		0x00000002U
#define GPIO_MODE_INPUT_PD		0x00000003U
#define GPIO_MODE_OUTPUT_PP		0x00000004U
#define GPIO_MODE_OUTPUT_OD		0x00000005U
#define GPIO_MODE_OUTPUT_AF_PP 	0x00000006U
#define GPIO_MODE_OUTPUT_AF_OD	0x00000007U
#define GPIO_MODE_INPUT_AF		0x00000008U


//@ref GPIO_SPEED_Define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz
#define GPIO_SPEED_10M  		0x00000001U
#define GPIO_SPEED_2M	  		0x00000002U
#define GPIO_SPEED_50M  		0x00000003U


/*
 *	========================================================
 * 	APIs Supported by "MCAL GPIO Driver"
 * 	========================================================
 */

void MCAL_GPIO_Init(GPIO_Typedef *local_GPIOx, GPIO_Pin_Config_t *local_Pin_Config); //pin_Config is a pointer not to copy the values.
void MCAL_GPIO_DeInit(GPIO_Typedef *local_GPIOx);
uint8_t MCAL_GPIO_Read_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_pin_Number);
uint16_t MCAL_GPIO_Read_Port(GPIO_Typedef *local_GPIOx);
void MCAL_GPIO_Write_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number, uint8_t local_Value);
void MCAL_GPIO_Write_Port(GPIO_Typedef *local_GPIOx, uint16_t local_Value);
void MCAL_GPIO_Toggle_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number);
uint8_t MCAL_GPIO_Lock_Pin(GPIO_Typedef *local_GPIOx, uint16_t local_Pin_Number);


#endif //GPIO_DRIVER_H_
