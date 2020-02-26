################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/TrashLora/LoraBib/LoRaMac.c \
../Src/TrashLora/LoraBib/LoRaMacAdr.c \
../Src/TrashLora/LoraBib/LoRaMacClassB.c \
../Src/TrashLora/LoraBib/LoRaMacCommands.c \
../Src/TrashLora/LoraBib/LoRaMacConfirmQueue.c \
../Src/TrashLora/LoraBib/LoRaMacCrypto.c \
../Src/TrashLora/LoraBib/LoRaMacParser.c \
../Src/TrashLora/LoraBib/LoRaMacSerializer.c \
../Src/TrashLora/LoraBib/NvmCtxMgmt.c \
../Src/TrashLora/LoraBib/Region.c \
../Src/TrashLora/LoraBib/RegionCommon.c \
../Src/TrashLora/LoraBib/RegionEU868.c \
../Src/TrashLora/LoraBib/adc-board.c \
../Src/TrashLora/LoraBib/adc.c \
../Src/TrashLora/LoraBib/aes.c \
../Src/TrashLora/LoraBib/board.c \
../Src/TrashLora/LoraBib/cmac.c \
../Src/TrashLora/LoraBib/delay-board.c \
../Src/TrashLora/LoraBib/delay.c \
../Src/TrashLora/LoraBib/eeprom-board.c \
../Src/TrashLora/LoraBib/eeprom.c \
../Src/TrashLora/LoraBib/eeprom_emul.c \
../Src/TrashLora/LoraBib/fifo.c \
../Src/TrashLora/LoraBib/flash_interface.c \
../Src/TrashLora/LoraBib/gpio-board.c \
../Src/TrashLora/LoraBib/gpio-ioe.c \
../Src/TrashLora/LoraBib/gpio.c \
../Src/TrashLora/LoraBib/gps.c \
../Src/TrashLora/LoraBib/i2c-board.c \
../Src/TrashLora/LoraBib/i2c.c \
../Src/TrashLora/LoraBib/lpm-board.c \
../Src/TrashLora/LoraBib/mag3110.c \
../Src/TrashLora/LoraBib/mma8451.c \
../Src/TrashLora/LoraBib/mpl3115.c \
../Src/TrashLora/LoraBib/nvmm.c \
../Src/TrashLora/LoraBib/pam7q.c \
../Src/TrashLora/LoraBib/rtc-board.c \
../Src/TrashLora/LoraBib/soft-se.c \
../Src/TrashLora/LoraBib/spi-board.c \
../Src/TrashLora/LoraBib/sx1276.c \
../Src/TrashLora/LoraBib/sx1276mb1mas-board.c \
../Src/TrashLora/LoraBib/sx1509.c \
../Src/TrashLora/LoraBib/sx9500.c \
../Src/TrashLora/LoraBib/sysIrqHandlers.c \
../Src/TrashLora/LoraBib/systime.c \
../Src/TrashLora/LoraBib/timer.c \
../Src/TrashLora/LoraBib/uart-board.c \
../Src/TrashLora/LoraBib/uart.c \
../Src/TrashLora/LoraBib/utilities.c 

OBJS += \
./Src/TrashLora/LoraBib/LoRaMac.o \
./Src/TrashLora/LoraBib/LoRaMacAdr.o \
./Src/TrashLora/LoraBib/LoRaMacClassB.o \
./Src/TrashLora/LoraBib/LoRaMacCommands.o \
./Src/TrashLora/LoraBib/LoRaMacConfirmQueue.o \
./Src/TrashLora/LoraBib/LoRaMacCrypto.o \
./Src/TrashLora/LoraBib/LoRaMacParser.o \
./Src/TrashLora/LoraBib/LoRaMacSerializer.o \
./Src/TrashLora/LoraBib/NvmCtxMgmt.o \
./Src/TrashLora/LoraBib/Region.o \
./Src/TrashLora/LoraBib/RegionCommon.o \
./Src/TrashLora/LoraBib/RegionEU868.o \
./Src/TrashLora/LoraBib/adc-board.o \
./Src/TrashLora/LoraBib/adc.o \
./Src/TrashLora/LoraBib/aes.o \
./Src/TrashLora/LoraBib/board.o \
./Src/TrashLora/LoraBib/cmac.o \
./Src/TrashLora/LoraBib/delay-board.o \
./Src/TrashLora/LoraBib/delay.o \
./Src/TrashLora/LoraBib/eeprom-board.o \
./Src/TrashLora/LoraBib/eeprom.o \
./Src/TrashLora/LoraBib/eeprom_emul.o \
./Src/TrashLora/LoraBib/fifo.o \
./Src/TrashLora/LoraBib/flash_interface.o \
./Src/TrashLora/LoraBib/gpio-board.o \
./Src/TrashLora/LoraBib/gpio-ioe.o \
./Src/TrashLora/LoraBib/gpio.o \
./Src/TrashLora/LoraBib/gps.o \
./Src/TrashLora/LoraBib/i2c-board.o \
./Src/TrashLora/LoraBib/i2c.o \
./Src/TrashLora/LoraBib/lpm-board.o \
./Src/TrashLora/LoraBib/mag3110.o \
./Src/TrashLora/LoraBib/mma8451.o \
./Src/TrashLora/LoraBib/mpl3115.o \
./Src/TrashLora/LoraBib/nvmm.o \
./Src/TrashLora/LoraBib/pam7q.o \
./Src/TrashLora/LoraBib/rtc-board.o \
./Src/TrashLora/LoraBib/soft-se.o \
./Src/TrashLora/LoraBib/spi-board.o \
./Src/TrashLora/LoraBib/sx1276.o \
./Src/TrashLora/LoraBib/sx1276mb1mas-board.o \
./Src/TrashLora/LoraBib/sx1509.o \
./Src/TrashLora/LoraBib/sx9500.o \
./Src/TrashLora/LoraBib/sysIrqHandlers.o \
./Src/TrashLora/LoraBib/systime.o \
./Src/TrashLora/LoraBib/timer.o \
./Src/TrashLora/LoraBib/uart-board.o \
./Src/TrashLora/LoraBib/uart.o \
./Src/TrashLora/LoraBib/utilities.o 

C_DEPS += \
./Src/TrashLora/LoraBib/LoRaMac.d \
./Src/TrashLora/LoraBib/LoRaMacAdr.d \
./Src/TrashLora/LoraBib/LoRaMacClassB.d \
./Src/TrashLora/LoraBib/LoRaMacCommands.d \
./Src/TrashLora/LoraBib/LoRaMacConfirmQueue.d \
./Src/TrashLora/LoraBib/LoRaMacCrypto.d \
./Src/TrashLora/LoraBib/LoRaMacParser.d \
./Src/TrashLora/LoraBib/LoRaMacSerializer.d \
./Src/TrashLora/LoraBib/NvmCtxMgmt.d \
./Src/TrashLora/LoraBib/Region.d \
./Src/TrashLora/LoraBib/RegionCommon.d \
./Src/TrashLora/LoraBib/RegionEU868.d \
./Src/TrashLora/LoraBib/adc-board.d \
./Src/TrashLora/LoraBib/adc.d \
./Src/TrashLora/LoraBib/aes.d \
./Src/TrashLora/LoraBib/board.d \
./Src/TrashLora/LoraBib/cmac.d \
./Src/TrashLora/LoraBib/delay-board.d \
./Src/TrashLora/LoraBib/delay.d \
./Src/TrashLora/LoraBib/eeprom-board.d \
./Src/TrashLora/LoraBib/eeprom.d \
./Src/TrashLora/LoraBib/eeprom_emul.d \
./Src/TrashLora/LoraBib/fifo.d \
./Src/TrashLora/LoraBib/flash_interface.d \
./Src/TrashLora/LoraBib/gpio-board.d \
./Src/TrashLora/LoraBib/gpio-ioe.d \
./Src/TrashLora/LoraBib/gpio.d \
./Src/TrashLora/LoraBib/gps.d \
./Src/TrashLora/LoraBib/i2c-board.d \
./Src/TrashLora/LoraBib/i2c.d \
./Src/TrashLora/LoraBib/lpm-board.d \
./Src/TrashLora/LoraBib/mag3110.d \
./Src/TrashLora/LoraBib/mma8451.d \
./Src/TrashLora/LoraBib/mpl3115.d \
./Src/TrashLora/LoraBib/nvmm.d \
./Src/TrashLora/LoraBib/pam7q.d \
./Src/TrashLora/LoraBib/rtc-board.d \
./Src/TrashLora/LoraBib/soft-se.d \
./Src/TrashLora/LoraBib/spi-board.d \
./Src/TrashLora/LoraBib/sx1276.d \
./Src/TrashLora/LoraBib/sx1276mb1mas-board.d \
./Src/TrashLora/LoraBib/sx1509.d \
./Src/TrashLora/LoraBib/sx9500.d \
./Src/TrashLora/LoraBib/sysIrqHandlers.d \
./Src/TrashLora/LoraBib/systime.d \
./Src/TrashLora/LoraBib/timer.d \
./Src/TrashLora/LoraBib/uart-board.d \
./Src/TrashLora/LoraBib/uart.d \
./Src/TrashLora/LoraBib/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Src/TrashLora/LoraBib/%.o: ../Src/TrashLora/LoraBib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Src/TrashLora/LoraBib" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


