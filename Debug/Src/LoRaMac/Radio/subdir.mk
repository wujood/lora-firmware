################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LoRaMac/Radio/dragino14-board.c \
../Src/LoRaMac/Radio/sx1276.c 

OBJS += \
./Src/LoRaMac/Radio/dragino14-board.o \
./Src/LoRaMac/Radio/sx1276.o 

C_DEPS += \
./Src/LoRaMac/Radio/dragino14-board.d \
./Src/LoRaMac/Radio/sx1276.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LoRaMac/Radio/%.o: ../Src/LoRaMac/Radio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Src" -I"C:/Users/Matze/workspace/TrashLORA/Src/Board" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoraHandler" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoRaMac" -I"C:/Users/Matze/workspace/TrashLORA/Src/Sensoren" -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


