// Andreas Timmermann und Shima Shahadifar, Tutorium 02 bei Christoph Van Heteren-Frese
#include <stdio.h>
#include <stdlib.h>

extern void insertion(char *buffer,int bufferelements);

int main(int argc, char* argv[])
{
	char test[] = "insertion";
	int len = sizeof(test) / sizeof(char);

	printf("Unsortiert:    %s\n",test);
	insertion(test,len);
	printf("InsertionSort: %s\n",test);
	return 0;
}
