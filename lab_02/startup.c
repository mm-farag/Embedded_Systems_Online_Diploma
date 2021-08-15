#include "platform_Types.h"

extern void main(void);
extern uint32_t SYMBOL_E_DATA;
extern uint32_t SYMBOL_S_DATA;
extern uint32_t SYMBOL_E_TEXT;
extern uint32_t SYMBOL_S_BSS;
extern uint32_t SYMBOL_E_BSS;
extern uint32_t SYMBOL_Stack_Top;



/*handlers declaration*/
void reset_Handler(void);
void default_Handler(void);
void NMI_Handler(void)			__attribute__((weak, alias("default_Handler")));
void hard_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));
void MMU_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));
void bus_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));
void usage_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));


// /* put vectors in vector section, which put in the first of the flash by the linker script

uint32_t vectors[] __attribute__((section(".vectors")))=
{
	(uint32_t)&SYMBOL_Stack_Top,
	(uint32_t)&reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&hard_Fault_Handler,
	(uint32_t)&MMU_Fault_Handler,
	(uint32_t)&bus_Fault_Handler,
	(uint32_t)&usage_Fault_Handler
};

void default_Handler(void)
{
	reset_Handler();
}
void reset_Handler(void)
{
	uint32_t data_Length = &SYMBOL_E_DATA - &SYMBOL_S_DATA;
	uint32_t i;

	uint8_t *P_src = (uint8_t *)&SYMBOL_E_TEXT; //copying the data to sram
	uint8_t *P_dist = (uint8_t *)&SYMBOL_S_DATA;
	for(i = 0; i < data_Length; i++)
	{
		*(uint8_t *)P_dist++ = *(uint8_t *)P_src++;
	}

	data_Length = &SYMBOL_E_BSS - &SYMBOL_S_BSS; //init the bss
	P_src = (uint8_t *)&SYMBOL_S_BSS;
	for(i = 0; i < data_Length; i++)
	{
		*(uint8_t *)P_src++ = 0;
	}
	main();
}
