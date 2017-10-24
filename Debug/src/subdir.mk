################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FLModule.cpp \
../src/FLPort.cpp \
../src/Flaarlib.cpp 

OBJS += \
./src/FLModule.o \
./src/FLPort.o \
./src/Flaarlib.o 

CPP_DEPS += \
./src/FLModule.d \
./src/FLPort.d \
./src/Flaarlib.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -DFLAARLIB_DLL -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


