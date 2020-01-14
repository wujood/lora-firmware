################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CayenneLpp.c \
../Src/FragDecoder.c \
../Src/LmHandler.c \
../Src/LmHandlerMsgDisplay.c \
../Src/LmhpClockSync.c \
../Src/LmhpCompliance.c \
../Src/LmhpFragmentation.c \
../Src/LmhpRemoteMcastSetup.c \
../Src/NvmCtxMgmt.c \
../Src/main.c \
../Src/syscalls.c \
../Src/system_stm32l4xx.c 

OBJS += \
./Src/CayenneLpp.o \
./Src/FragDecoder.o \
./Src/LmHandler.o \
./Src/LmHandlerMsgDisplay.o \
./Src/LmhpClockSync.o \
./Src/LmhpCompliance.o \
./Src/LmhpFragmentation.o \
./Src/LmhpRemoteMcastSetup.o \
./Src/NvmCtxMgmt.o \
./Src/main.o \
./Src/syscalls.o \
./Src/system_stm32l4xx.o 

C_DEPS += \
./Src/CayenneLpp.d \
./Src/FragDecoder.d \
./Src/LmHandler.d \
./Src/LmHandlerMsgDisplay.d \
./Src/LmhpClockSync.d \
./Src/LmhpCompliance.d \
./Src/LmhpFragmentation.d \
./Src/LmhpRemoteMcastSetup.d \
./Src/NvmCtxMgmt.d \
./Src/main.d \
./Src/syscalls.d \
./Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/NewFolder2/Inc" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


