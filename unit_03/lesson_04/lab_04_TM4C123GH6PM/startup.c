extern void main(void);
extern unsigned long SYMBOL_E_TEXT;

extern unsigned long SYMBOL_S_DATA;
extern unsigned long SYMBOL_E_DATA;

extern unsigned long SYMBOL_S_BSS;
extern unsigned long SYMBOL_E_BSS;


void reset_Handler(void);
void default_Handler(void);
void NMI_Handler(void)__attribute__((weak, alias("default_Handler")));
void hard_Fault_Handler(void)__attribute__((weak, alias("default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("default_Handler")));


/**************************************************/
static unsigned long g_Arr[256]; // as reference to the stack pointer
void (* const g_p_func_Vectors[])(void) __attribute__((section(".vectors")))= 
{
	(void(*)(void))((unsigned long)g_Arr + sizeof(g_Arr)),
	reset_Handler,
	NMI_Handler,
	hard_Fault_Handler,
	MM_Fault_Handler
};
void default_Handler(void)
{
	reset_Handler();
}
void reset_Handler(void)
{
	unsigned long counter;
	unsigned char *p_Src = (unsigned char*)&SYMBOL_E_TEXT; 
	unsigned char *p_Dist = (unsigned char*)&SYMBOL_S_DATA;
	unsigned long size = (unsigned long)&SYMBOL_E_DATA - (unsigned long)&SYMBOL_S_DATA;
//	unsigned long size = (unsigned char*)&SYMBOL_E_DATA - (unsigned char*)&SYMBOL_S_DATA;
//ml3btsh in the address as a number
	

	//copy .data from flash to sram
	for(counter = 0; counter < size; counter++)
	{
		*(unsigned char*)p_Dist++ = *(unsigned char*)p_Src++;
	}
	
	//initialize .bss by 0;
	size = (unsigned long)&SYMBOL_E_BSS - (unsigned long)&SYMBOL_S_BSS;
	p_Src = (unsigned char *)&SYMBOL_S_BSS;
	for(counter = 0; counter < size; counter++)
	{
		*(unsigned char*)p_Src++ = 0; 
	}
	
	
	//calling the main function which is the last task to the startup
	main();
}





