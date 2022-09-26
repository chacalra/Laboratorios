################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ejercicio\ del\ lab\ 5.c 

C_DEPS += \
./src/Ejercicio\ del\ lab\ 5.d 

OBJS += \
./src/Ejercicio\ del\ lab\ 5.o 


# Each subdirectory must supply rules for building sources it contributes
src/Ejercicio\ del\ lab\ 5.o: ../src/Ejercicio\ del\ lab\ 5.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Ejercicio del lab 5.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Ejercicio\ del\ lab\ 5.d ./src/Ejercicio\ del\ lab\ 5.o

.PHONY: clean-src

