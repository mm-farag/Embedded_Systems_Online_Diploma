ENTRY(reset)

MEMORY
{
	MEM(rwx): ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x00010000;

	.startup . :
	{
		startup.o(.text)
	}> MEM

	.text :
	{
		*(.text)
	}> MEM

	.data :
	{
		*(.data)
	}> MEM

	.rodata :
	{
		*(.rodata)
	}> MEM

	.bss :
	{
		*(.bss)
	}> MEM
	. = . + 1000;
	stack_Top = .;

}