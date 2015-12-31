PROGNAME	= fibonacci
ASM		= nasm
GCC		= gcc
all:
	$(ASM) -f elf64 $(PROGNAME).asm
	$(GCC) $(PROGNAME).o

clean:
	rm a.out
	rm $(PROGNAME).o

