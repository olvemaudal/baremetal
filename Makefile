CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

#CFLAGS = -nostdlib -nostartfiles -ffreestanding
CFLAGS = -Wall -gdwarf-2 -O1 -mno-unaligned-access -mfloat-abi=softfp -mcpu=cortex-a9
ASFLAGS = -mfloat-abi=softfp -march=armv7-a -mcpu=cortex-a9 -mfpu=neon-fp16 --gdwarf2
LDFLAGS = -Ttext=0x00000000 -e _start -u _start 

TARGET = de1soc-display-demo

all: $(TARGET).elf

%.S: %.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.o: %.S
	$(AS) $(ASFLAGS) -o $@ $<

%.elf: %.o
	$(LD) $(LDFLAGS) -o $@ $<

clean:
	rm -f *.elf *.o
