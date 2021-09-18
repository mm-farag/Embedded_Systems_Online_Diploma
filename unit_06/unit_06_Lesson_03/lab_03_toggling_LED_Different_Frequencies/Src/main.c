/*
 * Eng. Mohamed Mustafa Farag
 * phase locked loop(PLL) is used as clock source
 * */

typedef volatile unsigned long vuint32_t;

#define RCC_BASE_ADDRESS		0x40021000
#define GPIO_BASE_ADDRESS		0x40010800
#define GPIO_CRH_REGISTER		*(vuint32_t*)(GPIO_BASE_ADDRESS + 0x04)
#define GPIO_ODR_REGISTER		*(vuint32_t*)(GPIO_BASE_ADDRESS + 0x0C)
#define RCC_APB2ENR_REGISTER	*(vuint32_t*)(RCC_BASE_ADDRESS + 0x18)
#define RCC_CR_REGISTER			*(vuint32_t*)(RCC_BASE_ADDRESS + 0x00)
#define RCC_CFGR_REGISTER		*(vuint32_t*)(RCC_BASE_ADDRESS + 0x04)
int main(void)
{
	vuint32_t i;


	//
	//	Bit 16 PLLSRC: PLL entry clock source
	//	Set and cleared by software to select PLL clock source. This bit can be written only when
	//	PLL is disabled.
	//	0: HSI oscillator clock / 2 selected as PLL input clock
	//	1: HSE oscillator clock selected as PLL input clock
	RCC_CFGR_REGISTER &= ~(1<<16); //PLL source is HSI

	//	Bits 21:18 PLLMUL: PLL multiplication factor
	//	These bits are written by software to define the PLL multiplication factor. These bits can be
	//	written only when PLL is disabled.
	//	Caution: The PLL output frequency must not exceed 72 MHz.
	//	0000: PLL input clock x 2
	//	0001: PLL input clock x 3
	//	0010: PLL input clock x 4
	//	0011: PLL input clock x 5
	//	0100: PLL input clock x 6
	//	0101: PLL input clock x 7
	//	0110: PLL input clock x 8 //
	//	0111: PLL input clock x 9
	//	1000: PLL input clock x 10
	//	1001: PLL input clock x 11
	//	1010: PLL input clock x 12
	//	1011: PLL input clock x 13
	//	1100: PLL input clock x 14
	//	1101: PLL input clock x 15
	//	1110: PLL input clock x 16
	//	1111: PLL input clock x 16
	RCC_CFGR_REGISTER |= 0b0110<<18; // PLL * 8 = 32 MHz

	//	Bits 7:4 HPRE: AHB prescaler
	//	Set and cleared by software to control the division factor of the AHB clock.
	//	0xxx: SYSCLK not divided
	//	1000: SYSCLK divided by 2
	//	1001: SYSCLK divided by 4
	//	1010: SYSCLK divided by 8
	//	1011: SYSCLK divided by 16
	//	1100: SYSCLK divided by 64
	//	1101: SYSCLK divided by 128
	//	1110: SYSCLK divided by 256
	//	1111: SYSCLK divided by 512
	RCC_CFGR_REGISTER &= ~(1<<7); //AHB 32 MHz

	//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB low-speed clock
	//	(PCLK1).
	//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR_REGISTER |= 0b100<<8; //APB1 16 MHz


	//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB high-speed clock
	//	(PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR_REGISTER |=0b110<<11; //APB2 4 MHz


	//	Bit 24 PLLON: PLL enable
	//	Set and cleared by software to enable PLL.
	//	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	//	PLL clock is used as system clock or is selected to become the system clock.
	//	0: PLL OFF
	//	1: PLL ON
	RCC_CR_REGISTER |= 1<<24; //pll is on




	//	Bits 1:0 SW: System clock switch
	//	Set and cleared by software to select SYSCLK source.
	//	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	//	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	//	System is enabled).
	//	00: HSI selected as system clock
	//	01: HSE selected as system clock
	//	10: PLL selected as system clock
	//	11: not allowed
	RCC_CFGR_REGISTER |= 0b10<<0; //PLL is selected







	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled
	RCC_APB2ENR_REGISTER |= 1<<2; //enabling the GPIOA Clock




	GPIO_CRH_REGISTER |= 0b10<<20;//pin 13 is output
	GPIO_CRH_REGISTER |= 0b10<<16;//pin 12 is output

	while(1)
	{
		//making pin set
		GPIO_ODR_REGISTER |= 1<<13;
		GPIO_ODR_REGISTER |= 1<<12;
		for(i = 0; i<100000; i++);
		GPIO_ODR_REGISTER &= ~(1<<13);
		GPIO_ODR_REGISTER &= ~(1<<12);
		for(i = 0; i<100000; i++);
	}
	return 0;
}
