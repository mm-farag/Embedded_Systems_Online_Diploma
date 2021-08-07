/*ARM Cortex-M3 startup.c*/
/*Eng. Mohamed Mustaf Farag*/
/*August, 8 2021*/

#define NULL 0

/*type definiton*/
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

/*externed symbols from linker script.ld and main.c*/
extern void main(void);
extern uint32_t SYMBOL_S_DATA;
extern uint32_t SYMBOL_E_DATA;
extern uint32_t SYMBOL_E_TEXT;
extern uint32_t SYMBOL_S_BSS;
extern uint32_t SYMBOL_E_BSS;
extern uint32_t SYMBOL_Stack_Top;


/*handlers declaration*/
void reset_Handler(void) ;
void default_Handler(void);
void NMI_Handler(void)    			__attribute__((weak, alias("default_Handler")));
void hard_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));
void MM_Fault_Handler(void)			__attribute__((weak, alias("default_Handler")));
void bus_Faulf_Handler(void)		__attribute__((weak, alias("default_Handler")));
void usage_Fault_Handler(void)		__attribute__((weak, alias("default_Handler")));


/*vactors arrangment according to the vector table*/
uint32_t vectors[] __attribute__((section(".vectors"))) =
{
  (uint32_t)&SYMBOL_Stack_Top,
  (uint32_t)&reset_Handler,
  (uint32_t)&NMI_Handler,
  (uint32_t)&hard_Fault_Handler,
  (uint32_t)&MM_Fault_Handler,
  (uint32_t)&bus_Faulf_Handler,
  (uint32_t)&usage_Fault_Handler,
};

/*default handler definition*/
void default_Handler(void)
{
	reset_Handler(); //calling the reset handler
}

/*reset handler definition*/
void reset_Handler(void)
{	
	uint32_t counter;
	// copy the .data from the flash memory to the sram
	uint32_t data_Size = (uint8_t*)&SYMBOL_E_DATA - (uint8_t*)&SYMBOL_S_DATA;
	uint8_t *P_src =  (uint8_t *)&SYMBOL_E_TEXT;  // refers to data int flash
	uint8_t *P_dist = (uint8_t *)&SYMBOL_S_DATA;  //start of the data in the sram
	for(counter = NULL; counter < data_Size; counter++)
	{
		*((uint8_t*)P_dist++)=*((uint8_t*)P_src++);
	}

	
	/*reserving the .bss in the sram and initialize it by zeros*/
	uint32_t bss_Size = (uint8_t*)&SYMBOL_E_BSS - (uint8_t *)&SYMBOL_S_BSS;
	P_dist = (uint8_t *)&SYMBOL_S_BSS;
	for(counter = NULL;counter < bss_Size; counter++) //reserving the .bss byte by byte
	{
		*((uint8_t*)P_dist++)=(uint8_t)NULL;
	}

	
	//jumping to the  main function
	main();
}