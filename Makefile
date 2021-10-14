# Makefile pour cross compiler le code vers le cortex-m4
# Rajouter les fichier.o dans OBJS petit à petit

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
GDB = $(PREFIX)gdb

CFLAGS = -g -ffreestanding -O1 -Wall -Wextra
ASFLAGS = -g
LDFLAGS = -nostdlib -g -T ld_ram.lds
TARGET_ARCH = -mthumb -mcpu=cortex-m4
TARGET_MACH = $(TARGET_ARCH)

OBJS = main.o crt0.o memefunc.o init.o
EXE = main.elf

include $($(OBJS):%.o=%.d)

.PHONY: clean all connect debug objdump

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug : $(EXE)
	$(GDB) $<

objdump: $(EXE)
	$(PREFIX)objdump -d $(EXE)

clean:
	rm -f *.o
	rm -f *.elf
