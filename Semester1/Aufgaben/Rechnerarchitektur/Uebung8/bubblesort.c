//Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
#include <stdio.h>
#include <stdlib.h>

//es werden zwei Parameter an calculatorAdd bzw Sub übergeben, und es gibt einen Ausgabewert

extern void bubblesort(int *buffer,int bufferelements);

int main(int argc, char* argv[])
{
	int	test[] = {6,3,3,7,9,3,7,5,7,3,1,7,3,6,9};

	bubblesort(test,sizeof(test) / sizeof(int));
	return 0;
}
