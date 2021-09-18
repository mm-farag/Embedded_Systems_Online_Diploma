typedef volatile unsigned long vuint32_t;
typedef struct

{
	vuint32_t bit_0:1;
	vuint32_t bit_1:1;
	vuint32_t bit_2:1;
	vuint32_t bit_3:1;
	vuint32_t bit_4:1;
	vuint32_t bit_5:1;
	vuint32_t bit_6:1;
	vuint32_t bit_7:1;
	vuint32_t bit_8:1;
	vuint32_t bit_9:1;
	vuint32_t bit_10:1;
	vuint32_t bit_11:1;
	vuint32_t bit_12:1;
	vuint32_t bit_13:1;
	vuint32_t bit_14:1;
	vuint32_t bit_15:1;
	vuint32_t bit_16:1;
	vuint32_t bit_17:1;
	vuint32_t bit_18:1;
	vuint32_t bit_19:1;
	vuint32_t bit_20:1;
	vuint32_t bit_21:1;
	vuint32_t bit_22:1;
	vuint32_t bit_23:1;
	vuint32_t bit_24:1;
	vuint32_t bit_25:1;
	vuint32_t bit_26:1;
	vuint32_t bit_27:1;
	vuint32_t bit_28:1;
	vuint32_t bit_29:1;
	vuint32_t bit_30:1;
	vuint32_t bit_31:1;
}R_general_Register_t;

#define RCC_BASE_ADDRESS		0x40021000
#define GPIO_BASE_ADDRESS		0x40010800
#define GPIO_CRH_ADDRESS		(GPIO_BASE_ADDRESS + 0x04)
#define RCC_APB2ENR_ADDRESS		(RCC_BASE_ADDRESS + 0x18)
#define GPIO_ODR_ADDRESS		(GPIO_BASE_ADDRESS + 0x0C)
int main(void)
{
	unsigned long i;
	volatile R_general_Register_t* RCC_APB2ENR = (volatile R_general_Register_t*)RCC_APB2ENR_ADDRESS;
	volatile R_general_Register_t* GPIO_CRH = (volatile R_general_Register_t*)GPIO_CRH_ADDRESS;
	volatile R_general_Register_t* GPIO_ODR = (volatile R_general_Register_t*)GPIO_ODR_ADDRESS;


	//Bit 2 IOPAEN: I/O port A clock enable
	//Set and cleared by software.
	//0: I/O port A clock disabled
	//1:I/O port A clock enabled
	RCC_APB2ENR -> bit_2 = 1;


//write 0x2 on bit 20;
	GPIO_CRH->bit_20 =0;
	GPIO_CRH->bit_21 =1;
	GPIO_CRH->bit_22 =0;
	GPIO_CRH->bit_23 =0;
	while(1)
	{
		//making pin set
		GPIO_ODR->bit_13 = 1;
		for(i = 0; i<50000; i++);
		GPIO_ODR->bit_13 = 0;
		for(i = 0; i<50000; i++);
	}
	return 0;
}
