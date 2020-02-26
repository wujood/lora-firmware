################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LoRaMac/Region/Region.c \
../Src/LoRaMac/Region/RegionAS923.c \
../Src/LoRaMac/Region/RegionAU915.c \
../Src/LoRaMac/Region/RegionCN470.c \
../Src/LoRaMac/Region/RegionCN779.c \
../Src/LoRaMac/Region/RegionCommon.c \
../Src/LoRaMac/Region/RegionEU433.c \
../Src/LoRaMac/Region/RegionEU868.c \
../Src/LoRaMac/Region/RegionIN865.c \
../Src/LoRaMac/Region/RegionKR920.c \
../Src/LoRaMac/Region/RegionRU864.c \
../Src/LoRaMac/Region/RegionUS915.c 

OBJS += \
./Src/LoRaMac/Region/Region.o \
./Src/LoRaMac/Region/RegionAS923.o \
./Src/LoRaMac/Region/RegionAU915.o \
./Src/LoRaMac/Region/RegionCN470.o \
./Src/LoRaMac/Region/RegionCN779.o \
./Src/LoRaMac/Region/RegionCommon.o \
./Src/LoRaMac/Region/RegionEU433.o \
./Src/LoRaMac/Region/RegionEU868.o \
./Src/LoRaMac/Region/RegionIN865.o \
./Src/LoRaMac/Region/RegionKR920.o \
./Src/LoRaMac/Region/RegionRU864.o \
./Src/LoRaMac/Region/RegionUS915.o 

C_DEPS += \
./Src/LoRaMac/Region/Region.d \
./Src/LoRaMac/Region/RegionAS923.d \
./Src/LoRaMac/Region/RegionAU915.d \
./Src/LoRaMac/Region/RegionCN470.d \
./Src/LoRaMac/Region/RegionCN779.d \
./Src/LoRaMac/Region/RegionCommon.d \
./Src/LoRaMac/Region/RegionEU433.d \
./Src/LoRaMac/Region/RegionEU868.d \
./Src/LoRaMac/Region/RegionIN865.d \
./Src/LoRaMac/Region/RegionKR920.d \
./Src/LoRaMac/Region/RegionRU864.d \
./Src/LoRaMac/Region/RegionUS915.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LoRaMac/Region/%.o: ../Src/LoRaMac/Region/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Src" -I"C:/Users/Matze/workspace/TrashLORA/Src/Board" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoraHandler" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoRaMac" -I"C:/Users/Matze/workspace/TrashLORA/Src/Sensoren" -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


