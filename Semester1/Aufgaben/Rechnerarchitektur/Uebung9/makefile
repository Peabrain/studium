FLG = -std=c99 -Wall -pedantic
prog: main.c fibonacci.asm
	nasm -f elf64 fibonacci.asm
	gcc main.c fibonacci.o $(FLG)
