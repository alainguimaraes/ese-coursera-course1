#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the Embedded Software Essentials Course 1 Module 2 Assignment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      all        - Build the executable and generate the map file
#      clean      - Remove all generated files
#      size       - Generate the size report for the executable
#      %.i        - Generate preprocessed source files
#      %.asm      - Generate assembly files
#      %.o        - Generate object files
#      %.d        - Generate dependency files
#      compile-all- Compile all source files
#      build      - Build the executable
#
# Platform Overrides:
#      PLATFORM=MSP432   - Build for the MSP432 platform
#      PLATFORM=HOST     - Build for the host platform
#
#------------------------------------------------------------------------------
#*************************************************************************

# Include source files and include paths
include sources.mk

# Set default platform to HOST
PLATFORM?=HOST
ifndef COURSE1
 COURSE1 = 1
endif   # Default to enabling COURSE1

# Define common flags and variables
CFLAGS += -Wall -Werror -g -O0 -std=c99
LDFLAGS += $(LDFLAGS_ARCH)
TARGET = Course1.out
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

# Platform-specific configurations
ifeq ($(PLATFORM),MSP432)
    	$(info Building for MSP432 platform)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LINKER_FILE =msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = --specs=nosys.specs
	OBJDUMP = arm-none-eabi-objdump
	CFLAGS += -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(SPECS) -DMSP432
	CPPFLAGS += $(INCLUDES_MSP432)
	LDFLAGS_ARCH = -Wl,-Map,$(basename $@).map -T $(LINKER_FILE)
else ifeq ($(PLATFORM),HOST)
    	$(info Building for HOST platform)
	CC = gcc
	LD = ld
	SIZE = size
	OBJDUMP = objdump
	CFLAGS += -DHOST
	CPPFLAGS += $(INCLUDES_HOST)
	LDFLAGS_ARCH = -Wl,-Map=$(TARGET).map -lc 
else
    $(error Unsupported platform: $(PLATFORM))
endif


# COURSE1 Flag (Now outside the platform ifeq blocks)
ifeq ($(COURSE1),1)  
    CFLAGS += -DCOURSE1  
endif

# VERBOSE Flag (Now outside the platform ifeq blocks)
ifeq ($(VERBOSE),1)
    CFLAGS += -DVERBOSE  
endif
# Output file targets
.PHONY: all clean size compile-all build disasm

all: build

# Generate preprocessed output
%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

# Generate assembly output
%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

# Generate object files and dependency files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

#Generate dependency files
%.d : %.c
	$(CC) $(CPPFLAGS) -M $< $(CFLAGS) -o $@

# Compile all object files
.PHONY: compile-all
compile-all: $(OBJS)

# Build target
.PHONY: build
build: $(TARGET)
	@$(MAKE) size

# Linking rule
$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@  $(OBJS)

# Generate disassembly of the executable
.PHONY: disasm
disasm: $(TARGET)
	$(OBJDUMP) -d $(TARGET) > $(basename $(TARGET)).asm

# Clean target
.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS) *.i *.asm *.map *.d *.o *.out

# Size report
size: $(TARGET)
	$(SIZE) $(TARGET)

# Include dependency files
-include $(DEPS)

