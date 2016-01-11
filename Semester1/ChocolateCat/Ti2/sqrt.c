#include <stdio.h>
#include <stdlib.h>

extern unsigned int quadsqrt(unsigned int);

int main(int argc, char* argv[]) {
	unsigned int sqrt_num = 0;
	if(argc < 2) {
		puts("Gib bitte eine Zahl ein:");
		scanf("%u", &sqrt_num);
	} else {
		sqrt_num = atoi(argv[1]);
	}

	unsigned int sqrt_erg = quadsqrt(sqrt_num);
	printf("Quadratwurzel der Zahl %u ist: %u\n", sqrt_num, sqrt_erg);

	return EXIT_SUCCESS;
}

