################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/sklist.cpp \
../include/skstack.cpp 

CPP_DEPS += \
./include/sklist.d \
./include/skstack.d 

OBJS += \
./include/sklist.o \
./include/skstack.o 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.cpp include/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -nostdinc -Os -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-include

clean-include:
	-$(RM) ./include/sklist.d ./include/sklist.o ./include/skstack.d ./include/skstack.o

.PHONY: clean-include

