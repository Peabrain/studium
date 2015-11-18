PROGNAME	= uebung1
ASM		= nasm
LINKER		= ld
all:
	$(ASM) -f elf64 $(PROGNAME).asm
	$(LINKER) $(PROGNAME).o

clean:
	rm a.out
	rm $(PROGNAME).o

