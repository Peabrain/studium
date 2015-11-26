// Rechnerarchitektur
// Übung 5
//
// Andreas Timmermann, Shima Shahadifar
// MtrNr: 4994606, 5018598
// Gruppe 2

#include <stdio.h>
#include <time.h>

long int square(long int);								// Deklaration der Assemblerfunktion

int	main()
{
	long int n = 0,a = 0;

	printf("Wurzelberechnung:\n Bitte geben Sie 'n' ein: ");
	if(scanf("%ld",&n) == 1)
	{
		a = square(n);
		printf("Rueckgabe der Assembler Funktionen: %lu\n",a);
	}

	return 0;
}

