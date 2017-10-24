################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/FLModul_test.cpp \
../tests/FLPort_test.cpp \
../tests/Flaarlib_test.cpp 

OBJS += \
./tests/FLModul_test.o \
./tests/FLPort_test.o \
./tests/Flaarlib_test.o 

CPP_DEPS += \
./tests/FLModul_test.d \
./tests/FLPort_test.d \
./tests/Flaarlib_test.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


