#include "platform_Types.h"


typedef union //RCC APB2ENR register layout
{
	vuint32_t all_Fields;
	struct
	{
		vuint32_t 		:2;
		vuint32_t IOPAEN:1;
	}bits;
}R_RCC_APB2ENR_t;


typedef union//GPIO_CRH register layout
{
	vuint32_t all_Fields;
	struct
	{
		vuint32_t		:20;
		vuint32_t pin_13_Mode_Bits :4;
	}bits;
	
}R_GPIO_CRH_t;


typedef union//GPIO_ODR register layout
{
	vuint32_t all_Fields;
	struct
	{
		vuint32_t		:13;
		vuint32_t input_Output:1;
	}bits;
	
}R_GPIO_ODR_t;


#define RCC_BASE 			(0x40021000)
#define GPIO_BASE 			(0x40010800)
#define RCC_APB2ENR_OFFSET 	(0x18)
#define GPIO_CRH_OFFSET 	(0x04)
#define GPIO_ODR_OFFSET 	(0x0C)


void main(void)
{
	volatile R_RCC_APB2ENR_t *R_RCC_APB2ENR = (volatile R_RCC_APB2ENR_t *)(RCC_BASE+RCC_APB2ENR_OFFSET);
	volatile R_GPIO_CRH_t *R_GPIO_CRH = (volatile R_GPIO_CRH_t *)(GPIO_BASE+GPIO_CRH_OFFSET);
	volatile R_GPIO_ODR_t *R_GPIO_ODR = (volatile R_GPIO_ODR_t *)(GPIO_BASE+GPIO_ODR_OFFSET);
	int i;

	
	R_RCC_APB2ENR->bits.IOPAEN = 1; //enabling the gpio clock
	R_GPIO_CRH->bits.pin_13_Mode_Bits = 2;	//configuting pin 13 to be output
	while(1)
	{
		R_GPIO_ODR->bits.input_Output = 0; // pin low, led on.
		for(i=0; i<100000; i++);
		R_GPIO_ODR->bits.input_Output = 1; //pin high, led off.
		for(i=0; i<50000; i++);
	}
	
	
}