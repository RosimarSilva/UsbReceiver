################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Config.c \
../source/Interrupcoes.c \
../source/UsbReceiver.c \
../source/mtb.c 

OBJS += \
./source/Config.o \
./source/Interrupcoes.o \
./source/UsbReceiver.o \
./source/mtb.o 

C_DEPS += \
./source/Config.d \
./source/Interrupcoes.d \
./source/UsbReceiver.d \
./source/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL33Z64VLH4 -DCPU_MKL33Z64VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver\board" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver\source" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver\drivers" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver\device" -I"C:\Users\Rosimar\Documents\MCUXpressoIDE_11.3.1_5262\workspace\UsbReceiver\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


