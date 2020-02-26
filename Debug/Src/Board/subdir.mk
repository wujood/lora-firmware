################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Board/adc-board.c \
../Src/Board/adc.c \
../Src/Board/board.c \
../Src/Board/delay-board.c \
../Src/Board/delay.c \
../Src/Board/eeprom-board.c \
../Src/Board/eeprom.c \
../Src/Board/eeprom_emul.c \
../Src/Board/fifo.c \
../Src/Board/flash_interface.c \
../Src/Board/gpio-board.c \
../Src/Board/gpio-ioe.c \
../Src/Board/gpio.c \
../Src/Board/gps.c \
../Src/Board/i2c-board.c \
../Src/Board/i2c.c \
../Src/Board/iwdg-board.c \
../Src/Board/lpm-board.c \
../Src/Board/rtc-board.c \
../Src/Board/spi-board.c \
../Src/Board/sysIrqHandlers.c \
../Src/Board/systime.c \
../Src/Board/timer.c \
../Src/Board/uart-board.c \
../Src/Board/uart.c \
../Src/Board/utilities.c 

OBJS += \
./Src/Board/adc-board.o \
./Src/Board/adc.o \
./Src/Board/board.o \
./Src/Board/delay-board.o \
./Src/Board/delay.o \
./Src/Board/eeprom-board.o \
./Src/Board/eeprom.o \
./Src/Board/eeprom_emul.o \
./Src/Board/fifo.o \
./Src/Board/flash_interface.o \
./Src/Board/gpio-board.o \
./Src/Board/gpio-ioe.o \
./Src/Board/gpio.o \
./Src/Board/gps.o \
./Src/Board/i2c-board.o \
./Src/Board/i2c.o \
./Src/Board/iwdg-board.o \
./Src/Board/lpm-board.o \
./Src/Board/rtc-board.o \
./Src/Board/spi-board.o \
./Src/Board/sysIrqHandlers.o \
./Src/Board/systime.o \
./Src/Board/timer.o \
./Src/Board/uart-board.o \
./Src/Board/uart.o \
./Src/Board/utilities.o 

C_DEPS += \
./Src/Board/adc-board.d \
./Src/Board/adc.d \
./Src/Board/board.d \
./Src/Board/delay-board.d \
./Src/Board/delay.d \
./Src/Board/eeprom-board.d \
./Src/Board/eeprom.d \
./Src/Board/eeprom_emul.d \
./Src/Board/fifo.d \
./Src/Board/flash_interface.d \
./Src/Board/gpio-board.d \
./Src/Board/gpio-ioe.d \
./Src/Board/gpio.d \
./Src/Board/gps.d \
./Src/Board/i2c-board.d \
./Src/Board/i2c.d \
./Src/Board/iwdg-board.d \
./Src/Board/lpm-board.d \
./Src/Board/rtc-board.d \
./Src/Board/spi-board.d \
./Src/Board/sysIrqHandlers.d \
./Src/Board/systime.d \
./Src/Board/timer.d \
./Src/Board/uart-board.d \
./Src/Board/uart.d \
./Src/Board/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Board/%.o: ../Src/Board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Matze/workspace/TrashLORA/Src" -I"C:/Users/Matze/workspace/TrashLORA/Src/Board" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoraHandler" -I"C:/Users/Matze/workspace/TrashLORA/Src/LoRaMac" -I"C:/Users/Matze/workspace/TrashLORA/Src/Sensoren" -I"C:/Users/Matze/workspace/TrashLORA/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/Matze/workspace/TrashLORA/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


