FLG = -std=c99 -Wall -pedantic
SRC = bubblesort
prog: $(SRC).c $(SRC)_.asm
	nasm -f elf64 $(SRC)_.asm
	gcc $(SRC).c $(SRC)_.o $(FLG)
