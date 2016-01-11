#include <stdio.h>
#include <stdlib.h>

extern unsigned long collatz(unsigned int);

int main(int argc, char* argv[]) {
	unsigned int collatz_num = 0;
	if(argc < 2) {
		puts("Gib bitte eine Zahl ein:");
		scanf("%u", &collatz_num);
	} else {
		collatz_num = atoi(argv[1]);
	}

	unsigned long collatz_sum = collatz(collatz_num);
	printf("Für die Zahl %u braucht man %lu Collatzschritte.\n", collatz_num, collatz_sum);

	return EXIT_SUCCESS;
}

