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
# Use: make [TARGET]
#
# Build Targets:
#      all        - Build the executable and generate the map file
#      clean      - Remove all generated files
#      size       - Generate the size report for the executable
#      %.i        - Generate preprocessed source files
#      %.asm      - Generate assembly files
#      %.o        - Generate object files
#      compile-all- Compile all source files
#      build      - Build the executable
#      map        - Generate the map file
#      symbols    - List symbols using nm
#      dump       - Generate the disassembly of the executable
#
#------------------------------------------------------------------------------

#*************************************************************************

# Include source files and include paths
SOURCES = main.c \
          misc.c 

INCLUDES = -I.

# Define common flags and variables
$(info Building for MSP432 platform)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
NM = arm-none-eabi-nm
OBJDUMP = arm-none-eabi-objdump
CPU = cortex-m4
ARCH = thumb
SPECS = --specs=nosys.specs
LINKER_FILE =msp432p401r.lds
CFLAGS = -Wall -Werror -g -O0 -std=c99 \
         -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m \
         -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
         $(SPECS) -DMSP432 $(INCLUDES)
CPPFLAGS += $(INCLUDES)
LDFLAGS =-Wl,-Map,$(basename $@).map -T $(LINKER_FILE)
TARGET = c1m3.out
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
# Output file targets
.PHONY: all clean size compile-all build disasm map symbols dump

all: build map symbols dump

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
$(TARGET): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

   	


# Generate disassembly of the executable
.PHONY: dump
dump: $(TARGET)
	$(OBJDUMP) -d $< > $(basename $<).dump

# Clean target
.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS) *.i *.asm *.map *.d *.o *.sym *.dump

# Size report
.PHONY: size
size: $(TARGET)
	$(SIZE) $(TARGET)

# Generate the map file
.PHONY: map
map: $(TARGET)
	@echo "Map file generated during the build process."

# Generate symbol files
.PHONY: symbols
symbols: $(TARGET)
	$(NM) -C -S $(TARGET) > $(basename $(TARGET)).demangled.sym
	$(NM) -S $(TARGET) > $(basename $(TARGET)).sym
	for obj in $(OBJS); do \
		$(NM) -C -S $$obj > $$obj.demangled.sym; \
		$(NM) -S $$obj > $$obj.sym; \
	done
# Include dependency files
-include $(DEPS)

