################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/modules/InputModule.cpp 

OBJS += \
./src/modules/InputModule.o 

CPP_DEPS += \
./src/modules/InputModule.d 


# Each subdirectory must supply rules for building sources it contributes
src/modules/%.o: ../src/modules/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -DFLAARLIB_DLL -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


