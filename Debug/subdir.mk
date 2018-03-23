################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Display.cpp \
../Mesh.cpp \
../Shader.cpp \
../Texture.cpp \
../main.cpp 

C_SRCS += \
../stb_image.c 

OBJS += \
./Display.o \
./Mesh.o \
./Shader.o \
./Texture.o \
./main.o \
./stb_image.o 

CPP_DEPS += \
./Display.d \
./Mesh.d \
./Shader.d \
./Texture.d \
./main.d 

C_DEPS += \
./stb_image.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


