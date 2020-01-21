################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LoraBib/LoRaMac.c \
../Src/LoraBib/LoRaMacAdr.c \
../Src/LoraBib/LoRaMacClassB.c \
../Src/LoraBib/LoRaMacCommands.c \
../Src/LoraBib/LoRaMacConfirmQueue.c \
../Src/LoraBib/LoRaMacCrypto.c \
../Src/LoraBib/LoRaMacFCntHandler.c \
../Src/LoraBib/LoRaMacParser.c \
../Src/LoraBib/LoRaMacSerializer.c \
../Src/LoraBib/Region.c \
../Src/LoraBib/RegionAS923.c \
../Src/LoraBib/RegionAU915.c \
../Src/LoraBib/RegionCN470.c \
../Src/LoraBib/RegionCN779.c \
../Src/LoraBib/RegionCommon.c \
../Src/LoraBib/RegionEU433.c \
../Src/LoraBib/RegionEU868.c \
../Src/LoraBib/RegionIN865.c \
../Src/LoraBib/RegionKR920.c \
../Src/LoraBib/RegionRU864.c \
../Src/LoraBib/RegionUS915.c \
../Src/LoraBib/adc-board.c \
../Src/LoraBib/adc.c \
../Src/LoraBib/aes.c \
../Src/LoraBib/bme280.c \
../Src/LoraBib/board.c \
../Src/LoraBib/cmac.c \
../Src/LoraBib/delay-board.c \
../Src/LoraBib/delay.c \
../Src/LoraBib/dragino14-board.c \
../Src/LoraBib/eeprom-board.c \
../Src/LoraBib/eeprom.c \
../Src/LoraBib/eeprom_emul.c \
../Src/LoraBib/fifo.c \
../Src/LoraBib/flash_interface.c \
../Src/LoraBib/gpio-board.c \
../Src/LoraBib/gpio-ioe.c \
../Src/LoraBib/gpio.c \
../Src/LoraBib/gps.c \
../Src/LoraBib/i2c-board.c \
../Src/LoraBib/i2c.c \
../Src/LoraBib/lpm-board.c \
../Src/LoraBib/mag3110.c \
../Src/LoraBib/mma8451.c \
../Src/LoraBib/mpl3115.c \
../Src/LoraBib/nvmm.c \
../Src/LoraBib/pam7q.c \
../Src/LoraBib/rtc-board.c \
../Src/LoraBib/sensors.c \
../Src/LoraBib/soft-se.c \
../Src/LoraBib/spi-board.c \
../Src/LoraBib/sx1276.c \
../Src/LoraBib/sx1509.c \
../Src/LoraBib/sx9500.c \
../Src/LoraBib/sysIrqHandlers.c \
../Src/LoraBib/systime.c \
../Src/LoraBib/timer.c \
../Src/LoraBib/uart-board.c \
../Src/LoraBib/uart.c \
../Src/LoraBib/utilities.c \
../Src/LoraBib/vl53l0x.c 

OBJS += \
./Src/LoraBib/LoRaMac.o \
./Src/LoraBib/LoRaMacAdr.o \
./Src/LoraBib/LoRaMacClassB.o \
./Src/LoraBib/LoRaMacCommands.o \
./Src/LoraBib/LoRaMacConfirmQueue.o \
./Src/LoraBib/LoRaMacCrypto.o \
./Src/LoraBib/LoRaMacFCntHandler.o \
./Src/LoraBib/LoRaMacParser.o \
./Src/LoraBib/LoRaMacSerializer.o \
./Src/LoraBib/Region.o \
./Src/LoraBib/RegionAS923.o \
./Src/LoraBib/RegionAU915.o \
./Src/LoraBib/RegionCN470.o \
./Src/LoraBib/RegionCN779.o \
./Src/LoraBib/RegionCommon.o \
./Src/LoraBib/RegionEU433.o \
./Src/LoraBib/RegionEU868.o \
./Src/LoraBib/RegionIN865.o \
./Src/LoraBib/RegionKR920.o \
./Src/LoraBib/RegionRU864.o \
./Src/LoraBib/RegionUS915.o \
./Src/LoraBib/adc-board.o \
./Src/LoraBib/adc.o \
./Src/LoraBib/aes.o \
./Src/LoraBib/bme280.o \
./Src/LoraBib/board.o \
./Src/LoraBib/cmac.o \
./Src/LoraBib/delay-board.o \
./Src/LoraBib/delay.o \
./Src/LoraBib/dragino14-board.o \
./Src/LoraBib/eeprom-board.o \
./Src/LoraBib/eeprom.o \
./Src/LoraBib/eeprom_emul.o \
./Src/LoraBib/fifo.o \
./Src/LoraBib/flash_interface.o \
./Src/LoraBib/gpio-board.o \
./Src/LoraBib/gpio-ioe.o \
./Src/LoraBib/gpio.o \
./Src/LoraBib/gps.o \
./Src/LoraBib/i2c-board.o \
./Src/LoraBib/i2c.o \
./Src/LoraBib/lpm-board.o \
./Src/LoraBib/mag3110.o \
./Src/LoraBib/mma8451.o \
./Src/LoraBib/mpl3115.o \
./Src/LoraBib/nvmm.o \
./Src/LoraBib/pam7q.o \
./Src/LoraBib/rtc-board.o \
./Src/LoraBib/sensors.o \
./Src/LoraBib/soft-se.o \
./Src/LoraBib/spi-board.o \
./Src/LoraBib/sx1276.o \
./Src/LoraBib/sx1509.o \
./Src/LoraBib/sx9500.o \
./Src/LoraBib/sysIrqHandlers.o \
./Src/LoraBib/systime.o \
./Src/LoraBib/timer.o \
./Src/LoraBib/uart-board.o \
./Src/LoraBib/uart.o \
./Src/LoraBib/utilities.o \
./Src/LoraBib/vl53l0x.o 

C_DEPS += \
./Src/LoraBib/LoRaMac.d \
./Src/LoraBib/LoRaMacAdr.d \
./Src/LoraBib/LoRaMacClassB.d \
./Src/LoraBib/LoRaMacCommands.d \
./Src/LoraBib/LoRaMacConfirmQueue.d \
./Src/LoraBib/LoRaMacCrypto.d \
./Src/LoraBib/LoRaMacFCntHandler.d \
./Src/LoraBib/LoRaMacParser.d \
./Src/LoraBib/LoRaMacSerializer.d \
./Src/LoraBib/Region.d \
./Src/LoraBib/RegionAS923.d \
./Src/LoraBib/RegionAU915.d \
./Src/LoraBib/RegionCN470.d \
./Src/LoraBib/RegionCN779.d \
./Src/LoraBib/RegionCommon.d \
./Src/LoraBib/RegionEU433.d \
./Src/LoraBib/RegionEU868.d \
./Src/LoraBib/RegionIN865.d \
./Src/LoraBib/RegionKR920.d \
./Src/LoraBib/RegionRU864.d \
./Src/LoraBib/RegionUS915.d \
./Src/LoraBib/adc-board.d \
./Src/LoraBib/adc.d \
./Src/LoraBib/aes.d \
./Src/LoraBib/bme280.d \
./Src/LoraBib/board.d \
./Src/LoraBib/cmac.d \
./Src/LoraBib/delay-board.d \
./Src/LoraBib/delay.d \
./Src/LoraBib/dragino14-board.d \
./Src/LoraBib/eeprom-board.d \
./Src/LoraBib/eeprom.d \
./Src/LoraBib/eeprom_emul.d \
./Src/LoraBib/fifo.d \
./Src/LoraBib/flash_interface.d \
./Src/LoraBib/gpio-board.d \
./Src/LoraBib/gpio-ioe.d \
./Src/LoraBib/gpio.d \
./Src/LoraBib/gps.d \
./Src/LoraBib/i2c-board.d \
./Src/LoraBib/i2c.d \
./Src/LoraBib/lpm-board.d \
./Src/LoraBib/mag3110.d \
./Src/LoraBib/mma8451.d \
./Src/LoraBib/mpl3115.d \
./Src/LoraBib/nvmm.d \
./Src/LoraBib/pam7q.d \
./Src/LoraBib/rtc-board.d \
./Src/LoraBib/sensors.d \
./Src/LoraBib/soft-se.d \
./Src/LoraBib/spi-board.d \
./Src/LoraBib/sx1276.d \
./Src/LoraBib/sx1509.d \
./Src/LoraBib/sx9500.d \
./Src/LoraBib/sysIrqHandlers.d \
./Src/LoraBib/systime.d \
./Src/LoraBib/timer.d \
./Src/LoraBib/uart-board.d \
./Src/LoraBib/uart.d \
./Src/LoraBib/utilities.d \
./Src/LoraBib/vl53l0x.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LoraBib/%.o: ../Src/LoraBib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/NewFolder2/Inc" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/NewFolder2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


