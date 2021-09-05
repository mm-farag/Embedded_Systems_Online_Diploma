/*
* linker script for cortex m4
* Eng. Mohamed Mustafa Farag Haggag
*/

MEMORY
{
	flash(RWX): ORIGIN = 0x00000000 , LENGTH = 512M
	sram(RWX): ORIGIN = 0x20000000 , LENGTH = 512M
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
}
