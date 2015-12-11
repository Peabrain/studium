FLG = -std=c99 -Wall -pedantic
SRC = calculator
prog: $(SRC).c $(SRC)_.asm
	nasm -f elf64 $(SRC)_.asm
	gcc $(SRC).c $(SRC)_.o $(FLG)
