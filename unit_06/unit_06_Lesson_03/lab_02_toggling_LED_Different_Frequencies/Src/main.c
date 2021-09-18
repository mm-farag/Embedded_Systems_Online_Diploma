/*
 * APB1 -> 4MHz
 * APB2 -> 2MHz
 * AHB ->  8MHz
 * sysClk -> 8 MHz
 * use only internal HSI_RC
 * */

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
#define GPIO_ODR_ADDRESS		(GPIO_BASE_ADDRESS + 0x0C)
#define RCC_APB2ENR_ADDRESS		(RCC_BASE_ADDRESS + 0x18)
#define RCC_CR_ADDRESS			(RCC_BASE_ADDRESS + 0x00)
#define RCC_CFGR_ADDRESS		(RCC_BASE_ADDRESS + 0x04)

int main(void)
{
	unsigned long i;
	volatile R_general_Register_t* RCC_APB2ENR = (volatile R_general_Register_t*)RCC_APB2ENR_ADDRESS;
	volatile R_general_Register_t* GPIO_CRH = (volatile R_general_Register_t*)GPIO_CRH_ADDRESS;
	volatile R_general_Register_t* GPIO_ODR = (volatile R_general_Register_t*)GPIO_ODR_ADDRESS;
	volatile R_general_Register_t* RCC_CR = (volatile R_general_Register_t*)RCC_CR_ADDRESS;
	volatile R_general_Register_t* RCC_CFGR = (volatile R_general_Register_t*)RCC_CFGR_ADDRESS;


	//  Bit 0 HSION: Internal high-speed clock enable
	//  Set and cleared by software.
	//  Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
	//  mode or in case of failure of the external 3-25 MHz oscillator used directly or indirectly as
	//  system clock. This bit can not be cleared if the internal 8 MHz RC is used directly or
	//  indirectly as system clock or is selected to become the system clock.
	//  0: Internal 8 MHz RC oscillator OFF
	//  1: Internal 8 MHz RC oscillator ON
	RCC_CR ->bit_0 = 1; // HSI is enabled
	for(i=0; i<5; i++);

	//  Bits 1:0 SW[1:0]: System clock Switch
	//  Set and cleared by software to select SYSCLK source.
	//  Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
	//  the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
	//  enabled).
	//  00: HSI selected as system clock
	//  01: HSE selected as system clock
	//  10: PLL selected as system clock
	//  11: Not allowed
	RCC_CFGR ->bit_0 = 0;
	RCC_CFGR ->bit_1 = 0; //HSI is selected as system clock


	//  Bits 7:4 HPRE[3:0]: AHB prescaler
	//	Set and cleared by software to control AHB clock division factor.
	//	0xxx: SYSCLK not divided
	//	1000: SYSCLK divided by 2
	//	1001: SYSCLK divided by 4
	//	1010: SYSCLK divided by 8
	//	1011: SYSCLK divided by 16
	//	1100: SYSCLK divided by 64
	//	1101: SYSCLK divided by 128
	//	1110: SYSCLK divided by 256
	//	1111: SYSCLK divided by 512
	RCC_CFGR ->bit_4 = 0;
	RCC_CFGR ->bit_5 = 0;
	RCC_CFGR ->bit_6 = 0;
	RCC_CFGR ->bit_7 = 0; //AHB prescaler is not devided


	//	Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR->bit_8 = 0;
	RCC_CFGR->bit_9 = 0;
	RCC_CFGR->bit_10 = 1;//APB2 prescaler is devided by 2;

	//	Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR->bit_11 = 1;
	RCC_CFGR->bit_12 = 0;
	RCC_CFGR->bit_13 = 1;



	//Bit 2 IOPAEN: I/O port A clock enable
	//Set and cleared by software.
	//0: I/O port A clock disabled
	//1:I/O port A clock enabled
	RCC_APB2ENR -> bit_2 = 1;


	//	Bits 26:24 MCO[3:0]: Microcontroller clock output
	//	Set and cleared by software.
	//	00xx: No clock
	//	0100: System clock (SYSCLK) selected
	//	0101: HSI clock selected
	//	0110: HSE clock selected
	//	0111: PLL clock divided by 2 selected
	//	1000: PLL2 clock selected
	//	1001: PLL3 clock divided by 2 selected
	//	1010: XT1 external 3-25 MHz oscillator clock selected (for Ethernet)
	//	1011: PLL3 clock selected (for Ethernet)
	//	Note: This clock output may have some truncated cycles at startup or during MCO clock source
	//	switching.
	//	The selected clock to output onto the MCO pin must not exceed 50 MHz (the maximum I/O
	//	speed)
	RCC_CFGR->bit_24 = 1;
	RCC_CFGR->bit_25 = 0;
	RCC_CFGR->bit_26 = 1;
	RCC_CFGR->bit_27 = 0; //MCO's output is system clock selected

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
