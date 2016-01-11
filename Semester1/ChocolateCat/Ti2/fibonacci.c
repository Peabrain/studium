#include <stdio.h>
#include <stdlib.h>

extern unsigned int fib(unsigned int);

int main(int argc, char* argv[]) {
	unsigned int fib_num = 0;
	if(argc < 2) {
		puts("Gib bitte eine Zahl ein:");
		scanf("%u", &fib_num);
	} else {
		fib_num = atoi(argv[1]);
	}

	int fib_sum = fib(fib_num);
	printf("%u. Fibonacci Zahl: %d\n", fib_num, fib_sum);

	return EXIT_SUCCESS;
}

