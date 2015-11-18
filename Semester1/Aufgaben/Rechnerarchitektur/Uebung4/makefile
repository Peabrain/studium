SRC = uebung4
FLG = -std=c99 -Wall -pedantic

prog: $(SRC).c
	nasm -f elf64 $(SRC)_.asm
	gcc $(SRC).c $(SRC)_.o $(FLG)
