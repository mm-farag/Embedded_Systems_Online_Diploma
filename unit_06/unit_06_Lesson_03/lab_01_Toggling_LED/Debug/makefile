################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lab_01_Toggling_LED.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab_01_Toggling_LED.list \

OBJCOPY_BIN += \
lab_01_Toggling_LED.bin \


# All Target
all: lab_01_Toggling_LED.elf secondary-outputs

# Tool invocations
lab_01_Toggling_LED.elf: $(OBJS) $(USER_OBJS) D:\_KSH\ Embedded\ Systems\_workspaces\_workspace_CubeIDE\toggling_LED\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lab_01_Toggling_LED.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\_KSH Embedded Systems\_workspaces\_workspace_CubeIDE\toggling_LED\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab_01_Toggling_LED.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab_01_Toggling_LED.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab_01_Toggling_LED.list"
	@echo 'Finished building: $@'
	@echo ' '

lab_01_Toggling_LED.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab_01_Toggling_LED.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
