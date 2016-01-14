//Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

#include <stdio.h>
#include <stdlib.h>

extern void insertionsort(char *buffer,int bufferelements);

int main(int argc, char* argv[])
{
	char test[] = "pfannekuchen";
	int len = sizeof(test) / sizeof(char);

	printf("Unsortiert:    %s\n",test);
	insertionsort(test,len);
	printf("InsertionSort: %s\n",test);
	return 0;
}
