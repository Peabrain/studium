stack: stack.o stack.c
	gcc -O2 -o $@ $^

%.o: %.asm
	nasm -f elf64 -o $@ $<
