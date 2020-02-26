################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LoRaMac/LoRaMac.c \
../Src/LoRaMac/LoRaMacAdr.c \
../Src/LoRaMac/LoRaMacClassB.c \
../Src/LoRaMac/LoRaMacCommands.c \
../Src/LoRaMac/LoRaMacConfirmQueue.c \
../Src/LoRaMac/LoRaMacCrypto.c \
../Src/LoRaMac/LoRaMacFCntHandler.c \
../Src/LoRaMac/LoRaMacParser.c \
../Src/LoRaMac/LoRaMacSerializer.c \
../Src/LoRaMac/NvmCtxMgmt.c \
../Src/LoRaMac/aes.c \
../Src/LoRaMac/cmac.c \
../Src/LoRaMac/mag3110.c \
../Src/LoRaMac/mma8451.c \
../Src/LoRaMac/mpl3115.c \
../Src/LoRaMac/nvmm.c \
../Src/LoRaMac/pam7q.c \
../Src/LoRaMac/soft-se.c \
../Src/LoRaMac/sx1509.c \
../Src/LoRaMac/sx9500.c 

OBJS += \
./Src/LoRaMac/LoRaMac.o \
./Src/LoRaMac/LoRaMacAdr.o \
./Src/LoRaMac/LoRaMacClassB.o \
./Src/LoRaMac/LoRaMacCommands.o \
./Src/LoRaMac/LoRaMacConfirmQueue.o \
./Src/LoRaMac/LoRaMacCrypto.o \
./Src/LoRaMac/LoRaMacFCntHandler.o \
./Src/LoRaMac/LoRaMacParser.o \
./Src/LoRaMac/LoRaMacSerializer.o \
./Src/LoRaMac/NvmCtxMgmt.o \
./Src/LoRaMac/aes.o \
./Src/LoRaMac/cmac.o \
./Src/LoRaMac/mag3110.o \
./Src/LoRaMac/mma8451.o \
./Src/LoRaMac/mpl3115.o \
./Src/LoRaMac/nvmm.o \
./Src/LoRaMac/pam7q.o \
./Src/LoRaMac/soft-se.o \
./Src/LoRaMac/sx1509.o \
./Src/LoRaMac/sx9500.o 

C_DEPS += \
./Src/LoRaMac/LoRaMac.d \
./Src/LoRaMac/LoRaMacAdr.d \
./Src/LoRaMac/LoRaMacClassB.d \
./Src/LoRaMac/LoRaMacCommands.d \
./Src/LoRaMac/LoRaMacConfirmQueue.d \
./Src/LoRaMac/LoRaMacCrypto.d \
./Src/LoRaMac/LoRaMacFCntHandler.d \
./Src/LoRaMac/LoRaMacParser.d \
./Src/LoRaMac/LoRaMacSerializer.d \
./Src/LoRaMac/NvmCtxMgmt.d \
./Src/LoRaMac/aes.d \
./Src/LoRaMac/cmac.d \
./Src/LoRaMac/mag3110.d \
./Src/LoRaMac/mma8451.d \
./Src/LoRaMac/mpl3115.d \
./Src/LoRaMac/nvmm.d \
./Src/LoRaMac/pam7q.d \
./Src/LoRaMac/soft-se.d \
./Src/LoRaMac/sx1509.d \
./Src/LoRaMac/sx9500.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LoRaMac/%.o: ../Src/LoRaMac/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Src" -I"C:/Users/Matze/workspace/TrashLORA/Src/Board" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoraHandler" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoRaMac" -I"C:/Users/Matze/workspace/TrashLORA/Src/Sensoren" -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


