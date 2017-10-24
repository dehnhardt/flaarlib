################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/logger/Logger.cpp \
../src/logger/Logger_test.cpp 

OBJS += \
./src/logger/Logger.o \
./src/logger/Logger_test.o 

CPP_DEPS += \
./src/logger/Logger.d \
./src/logger/Logger_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/logger/%.o: ../src/logger/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


