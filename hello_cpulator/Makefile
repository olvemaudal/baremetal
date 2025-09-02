# Compiler and Tools
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump

# Target and Source Files
TARGET = program
SRC = $(TARGET).c
ELF = $(TARGET).elf
BIN = $(TARGET).bin
MAP = $(TARGET).map

# CPU and Architecture Flags
CPU = -mcpu=cortex-a9 -marm -mthumb-interwork
CFLAGS = $(CPU) -Wall -O2 -ffreestanding -nostdlib -gdwarf-2 -O1 -mno-unaligned-access -mfloat-abi=softfp
LDFLAGS = -T linker.ld -nostdlib -Map=$(MAP)

# Default Target
all: $(ELF)

# Compile C source to object file
$(TARGET).o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object file to create ELF
$(ELF): $(TARGET).o
	$(LD) $(LDFLAGS) $< -o $@

# Generate binary file from ELF (optional)
$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

# Disassemble ELF for debugging (optional)
disassemble: $(ELF)
	$(OBJDUMP) -D $< > $(TARGET).asm

# Clean up build artifacts
clean:
	rm -f $(TARGET).o $(ELF) $(BIN) $(MAP) $(TARGET).asm

# Phony targets
.PHONY: all clean disassemble
