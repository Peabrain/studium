#include <stdio.h>
#include <stdlib.h>

extern unsigned long test(unsigned int);

int main(int argc, char* argv[]) {
	unsigned int test_num = 0;
	if(argc < 2) {
		puts("Gib bitte eine Zahl ein:");
		scanf("%u", &test_num);
	} else {
		test_num = atoi(argv[1]);
	}

	unsigned long test_sum = test(test_num);
	printf(" %u -> %lu \n", test_num, test_sum);

	return EXIT_SUCCESS;
}

