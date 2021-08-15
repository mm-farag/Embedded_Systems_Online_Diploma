/*
* linker script for cortex m3
* Eng. Mohamed Mustafa Farag Haggag
*/

MEMORY
{
	flash(RX): ORIGIN = 0x08000000 , LENGTH = 128k
	sram(RWX): ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		SYMBOL_E_TEXT = .;
	}> flash

	.data :
	{
		SYMBOL_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		SYMBOL_E_DATA = .;
	}> sram AT> flash

	.bss :
	{
		SYMBOL_S_BSS = .;
		*(.bss)
		. = ALIGN(4);
		SYMBOL_E_BSS = .;
	}> sram
	. = . + 0x1000;
	SYMBOL_Stack_Top = .;

}
