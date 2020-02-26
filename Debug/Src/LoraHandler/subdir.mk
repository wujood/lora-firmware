################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LoraHandler/CayenneLpp.c \
../Src/LoraHandler/FragDecoder.c \
../Src/LoraHandler/LmHandlerMsgDisplay.c \
../Src/LoraHandler/LmhpClockSync.c \
../Src/LoraHandler/LmhpCompliance.c \
../Src/LoraHandler/LmhpFragmentation.c \
../Src/LoraHandler/LmhpRemoteMcastSetup.c 

OBJS += \
./Src/LoraHandler/CayenneLpp.o \
./Src/LoraHandler/FragDecoder.o \
./Src/LoraHandler/LmHandlerMsgDisplay.o \
./Src/LoraHandler/LmhpClockSync.o \
./Src/LoraHandler/LmhpCompliance.o \
./Src/LoraHandler/LmhpFragmentation.o \
./Src/LoraHandler/LmhpRemoteMcastSetup.o 

C_DEPS += \
./Src/LoraHandler/CayenneLpp.d \
./Src/LoraHandler/FragDecoder.d \
./Src/LoraHandler/LmHandlerMsgDisplay.d \
./Src/LoraHandler/LmhpClockSync.d \
./Src/LoraHandler/LmhpCompliance.d \
./Src/LoraHandler/LmhpFragmentation.d \
./Src/LoraHandler/LmhpRemoteMcastSetup.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LoraHandler/%.o: ../Src/LoraHandler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Src" -I"C:/Users/Matze/workspace/TrashLORA/Src/Board" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoraHandler" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoRaMac" -I"C:/Users/Matze/workspace/TrashLORA/Src/Sensoren" -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


