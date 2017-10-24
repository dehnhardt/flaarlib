################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/util/CLog_test.cpp 

OBJS += \
./tests/util/CLog_test.o 

CPP_DEPS += \
./tests/util/CLog_test.d 


# Each subdirectory must supply rules for building sources it contributes
tests/util/%.o: ../tests/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


