SHELL=C:/Windows/System32/cmd.exe

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = arm-none-eabi
INCS = -I .
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g
project_Name = unit3_Lab4_Cortex_M4

all: $(project_Name).bin
	@echo "========================build id done========================="
%.o: %.c
	$(CC)-gcc -c $(CFLAGS) $(INCS) $< -o $@

$(project_Name).elf: linker_Script.ld $(OBJ)
	$(CC)-ld -T linker_Script.ld $(OBJ) -o $(project_Name).elf -Map=mapfile.map
	cp $(project_Name).elf $(project_Name).axf

$(project_Name).bin: $(project_Name).elf
	$(CC)-objcopy -O binary $(project_Name).elf $(project_Name).bin
clean:
	rm *.o *.elf *.bin *.hex
