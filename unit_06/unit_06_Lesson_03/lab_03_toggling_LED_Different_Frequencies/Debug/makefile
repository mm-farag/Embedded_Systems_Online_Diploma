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
lab_03_toggling_LED_Different_Frequencies.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab_03_toggling_LED_Different_Frequencies.list \

OBJCOPY_BIN += \
lab_03_toggling_LED_Different_Frequencies.bin \


# All Target
all: lab_03_toggling_LED_Different_Frequencies.axf secondary-outputs

# Tool invocations
lab_03_toggling_LED_Different_Frequencies.axf: $(OBJS) $(USER_OBJS) D:\_KSH\ Embedded\ Systems\_workspaces\_workspace_CubeIDE\lab_03_toggling_LED_Different_Frequencies\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lab_03_toggling_LED_Different_Frequencies.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\_KSH Embedded Systems\_workspaces\_workspace_CubeIDE\lab_03_toggling_LED_Different_Frequencies\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab_03_toggling_LED_Different_Frequencies.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab_03_toggling_LED_Different_Frequencies.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab_03_toggling_LED_Different_Frequencies.list"
	@echo 'Finished building: $@'
	@echo ' '

lab_03_toggling_LED_Different_Frequencies.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab_03_toggling_LED_Different_Frequencies.bin"
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
